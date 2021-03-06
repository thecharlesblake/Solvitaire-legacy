//
// Created by thecharlesblake on 07/06/18.
//

#include "game_state.h"
#include "../sol_rules.h"


typedef sol_rules::build_policy pol;
typedef game_state::streamliner_options sos;
typedef sol_rules::stock_deal_type sdt;
typedef sol_rules::spaces_policy s_pol;

using std::max;
using boost::optional;

bool game_state::is_valid_auto_foundation_move(pile::ref target_pile) const {
    if (rules.foundations_only_comp_piles || rules.two_decks)
        return false;
    else if (   stream_opts     == sos::AUTO_FOUNDATIONS
             || stream_opts     == sos::BOTH
             || rules.build_pol == pol::NO_BUILD
             || rules.build_pol == pol::SAME_SUIT)
        return true;

    card::suit_t target_suit(target_pile - foundations.front());
    card::rank_t move_up_rank = piles[target_pile].empty()
                               ? card::rank_t(1)
                               : foundation_base_convert(piles[target_pile].top_card().get_rank() + card::rank_t(1));

    // The card to be moved up
    card move_up_card(target_suit, move_up_rank);

    // The max difference between the 'move up' card and the foundations of the
    // same colour and the other colour
    int same_rank_diff = 0;
    int other_rank_diff = 0;
    for (pile::ref pr : foundations) {
        if (pr == target_pile) continue;

        card::suit_t s(pr - foundations.front());
        card::rank_t r = piles[pr].empty() ? card::rank_t(0)
                                           : foundation_base_convert(piles[pr].top_card().get_rank());
        card c(s, r);

        auto rank_diff = int(move_up_card.get_rank() - r);
        if (move_up_card.get_suit() == c.get_suit()
            || (rules.build_pol == pol::RED_BLACK
                && move_up_card.get_colour() == c.get_colour())) {
            same_rank_diff = rank_diff;
        } else {
            other_rank_diff = max(other_rank_diff, rank_diff);
        }
    }

    bool other_within_1 = other_rank_diff <= 1;
    bool other_within_2 = other_rank_diff <= 2;
    bool same_within_3 = same_rank_diff <= 3;

    if (rules.build_pol == pol::RED_BLACK) {
        return other_within_1 || (other_within_2 && same_within_3);
    } else {
        assert(rules.build_pol == pol::ANY_SUIT);
        return other_within_2;
    }
}

// Returns a dominance move if one is available
optional<move> game_state::get_dominance_move() const {
#ifndef NO_AUTO_FOUNDATIONS
    if (rules.spaces_pol == s_pol::AUTO_RESERVE_THEN_WASTE) {
        optional<move> arm = auto_reserve_move();
        if (arm) return arm;
    } else if (rules.spaces_pol == s_pol::AUTO_WASTE_THEN_STOCK) {
        optional<move> awsm = auto_waste_stock_move();
        if (awsm) return awsm;
    }

    // If there are 2 decks or no foundations, return
    if (!rules.foundations_present || rules.two_decks)
        return boost::none;

    // Cycles through the piles and sees if any cards can be automatically moved
    // to the foundations
    for (pile::ref pr = 0; pr < piles.size(); pr++) {
        // Don't move foundation cards, hole, waste or stock cards to the foundations
        if ((pr >= foundations.front() && pr <= foundations.back())
            || (rules.hole && pr == hole)
            || (rules.stock_size > 0 && pr == stock)
            || (rules.stock_size > 0 && rules.stock_deal_t == sdt::WASTE && pr == waste)
            || (piles[pr].empty())) {
            continue;
        }

        card c = piles[pr].top_card();
        pile::ref target_foundation = foundations[c.get_suit()];

        // If the card is the right rank and the auto-move boolean is true, then
        // returns the move
        card::rank_t target_rank = piles[target_foundation].empty()
                                   ? card::rank_t(1)
                                   : foundation_base_convert(piles[target_foundation].top_card().get_rank() + card::rank_t(1));
        if (target_rank == foundation_base_convert(c.get_rank()) &&
            auto_foundation_moves[c.get_suit()]) {
            move m(move::mtype::dominance, pr, target_foundation);

            // If this dominance move reveals a card, adds this to the move
            if (piles[pr].size() > 1 && piles[pr][1].is_face_down())
                m.make_reveal_move();

            return m;
        }
    }
#endif

    return boost::none;
}

optional<move> game_state::auto_reserve_move() const {
    if (rules.spaces_pol == s_pol::AUTO_RESERVE_THEN_WASTE && !piles[reserve.front()].empty()) {
        for (auto to : tableau_piles) {
            if (piles[to].empty()) {
                return move(move::mtype::dominance, reserve.front(), to);
            }
        }
    }
    return boost::none;
}

optional<move> game_state::auto_waste_stock_move() const {
    if (!piles[waste].empty()) {
        for (auto to : tableau_piles) {
            if (piles[to].empty()) {
                return move(move::mtype::dominance, waste, to);
            }
        }
    } else if (!piles[stock].empty()) {
        for (auto to : tableau_piles) {
            if (piles[to].empty()) {
                return move(move::mtype::dominance, stock, to);
            }
        }
    }
    return boost::none;
}

bool game_state::is_ordered_pile(pile::ref pr) const {
    if (piles[pr].size() != rules.max_rank) return false;

    card::suit_t s = piles[pr][0].get_suit();
    for (card::rank_t r = 0; r < rules.max_rank; r++) {
        if (piles[pr][r] != card(s, card::rank_t(r + 1))) return false;
    }
    return true;
}

// For games where the foundations can be removed from, this dominance blocks
// the foundations being removed from if the card that were to be removed would
// go 'automatically' up
bool game_state::dominance_blocks_foundation_move(pile::ref target_pile) {
    assert(!piles[target_pile].empty());

    card target_card = piles[target_pile].top_card();
    piles[target_pile].take();

    bool blocked = is_valid_auto_foundation_move(target_pile);
    piles[target_pile].place(target_card);

    return blocked;
}

// Decides which 'auto foundation' booleans should be 'true' currently
void game_state::update_auto_foundation_moves(pile::ref target_pile) {
    // If there are no foundations, or this is not a foundation move, do nothing
    if (!rules.foundations_present
        || target_pile < foundations.front()
        || target_pile > foundations.back()) {
        return;
    }

    // Turns the 'auto' boolean for the target foundation false

    for (pile::ref pr : foundations) {
        auto_foundation_moves[pr] = is_valid_auto_foundation_move(pr);
    }
}

card::rank_t game_state::foundation_base_convert(card::rank_t r) const {
    card::rank_t s = r - (foundations_base - card::rank_t(1));
    if (s < 1) s += rules.max_rank;
    return s;
}
