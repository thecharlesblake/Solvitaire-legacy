//
// Created by thecharlesblake on 1/3/18.
//

#include <vector>
#include <algorithm>

#include "rules_parser.h"
#include "json_helper.h"
#include "../sol_preset_types.h"
#include "../../../game/card.h"

using namespace std;
using namespace rapidjson;

////////////
// Static //
////////////

typedef sol_rules::build_policy pol;
typedef sol_rules::spaces_policy s_pol;
typedef sol_rules::stock_deal_type sdt;

const sol_rules rules_parser::from_file(const string rules_file) {
    sol_rules sr = get_default();
    Document d = json_helper::get_file_json(rules_file);

    modify_sol_rules(sr, d);

    return sr;
}

const sol_rules rules_parser::from_preset(const string sol_type) {
    sol_rules sr = get_default();

    const string preset_json = sol_preset_types::get(sol_type);

    Document d;
    d.Parse(preset_json.c_str());
    assert(!d.HasParseError());

    modify_sol_rules(sr, d);
    return sr;
}

sol_rules rules_parser::get_default() {
    sol_rules sr;
    const string default_json = sol_preset_types::get("default");

    Document d;
    d.Parse(default_json.c_str());
    assert(!d.HasParseError());

    modify_sol_rules(sr, d);
    return sr;
}

void rules_parser::modify_sol_rules(sol_rules& sr, Document& d) {

    if (!d.IsObject()) {
        json_helper::json_parse_err("JSON doc must be object");
    }

    if (d.HasMember("tableau piles")) {
        if (d["tableau piles"].IsObject()) {

            if (d["tableau piles"].HasMember("count")) {
                if (d["tableau piles"]["count"].IsInt()) {
                    sr.tableau_pile_count = static_cast<uint8_t>(d["tableau piles"]["count"].GetInt());
                    if (sr.tableau_pile_count > 52) {
                        json_helper::json_parse_warning("[tableau piles][count] may be too high");
                    }
                } else {
                    json_helper::json_parse_err("[tableau piles][count] must be an integer");
                }
            }

            if (d["tableau piles"].HasMember("build policy")) {
                if (d["tableau piles"]["build policy"].IsString()) {
                    string bp_str = d["tableau piles"]["build policy"].GetString();

                    if (bp_str == "any-suit") {
                        sr.build_pol = pol::ANY_SUIT;
                    } else if (bp_str == "red-black") {
                        sr.build_pol = pol::RED_BLACK;
                    } else if (bp_str == "same-suit") {
                        sr.build_pol = pol::SAME_SUIT;
                    } else if (bp_str == "no-build") {
                        sr.build_pol = pol::NO_BUILD;
                    } else {
                        json_helper::json_parse_err("[tableau piles][build policy] is invalid");
                    }

                } else {
                    json_helper::json_parse_err("[tableau piles][build policy] must be an string");
                }
            }

            if (d["tableau piles"].HasMember("spaces policy")) {
                if (d["tableau piles"]["spaces policy"].IsString()) {
                    string sp_str = d["tableau piles"]["spaces policy"].GetString();

                    if (sp_str == "any") {
                        sr.spaces_pol = s_pol::ANY;
                    } else if (sp_str == "no-build") {
                        sr.spaces_pol = s_pol::NO_BUILD;
                    } else {
                        json_helper::json_parse_err("[tableau piles][spaces policy] is invalid");
                    }

                } else {
                    json_helper::json_parse_err("[tableau piles][spaces policy] must be an string");
                }
            }

            if (d["tableau piles"].HasMember("move built group")) {
                if (d["tableau piles"]["move built group"].IsBool()) {
                    sr.move_built_group = d["tableau piles"]["move built group"].GetBool();
                } else {
                    json_helper::json_parse_err("[tableau piles][move built group] must be a boolean");
                }
            }

            if (d["tableau piles"].HasMember("diagonal deal")) {
                if (d["tableau piles"]["diagonal deal"].IsBool()) {
                    sr.diagonal_deal = d["tableau piles"]["diagonal deal"].GetBool();
                } else {
                    json_helper::json_parse_err("[tableau piles][diagonal deal] must be a boolean");
                }
            }

        } else {
            json_helper::json_parse_err("[tableau piles] must be an object");
        }
    }

    if (d.HasMember("max rank")) {
        if (d["max rank"].IsInt()) {
            sr.max_rank = static_cast<card::rank_t>(d["max rank"].GetInt());
            if (sr.max_rank > 13) {
                json_helper::json_parse_err("[max rank] must be a valid rank");
            }
        } else {
            json_helper::json_parse_err("[max rank] must be an integer");
        }
    }

    if (d.HasMember("two decks")) {
        if (d["two decks"].IsBool()) {
            sr.two_decks = d["two decks"].GetBool();
        } else {
            json_helper::json_parse_err("[two decks] must be a boolean");
        }
    }

    if (d.HasMember("hole")) {
        if (d["hole"].IsBool()) {
            sr.hole = d["hole"].GetBool();
        } else {
            json_helper::json_parse_err("[hole] must be a boolean");
        }
    }

    if (d.HasMember("foundations")) {
        if (d["foundations"].IsBool()) {
            sr.foundations = d["foundations"].GetBool();
        } else {
            json_helper::json_parse_err("[foundations] must be a boolean");
        }
    }

    if (!sr.hole && !sr.foundations) {
        json_helper::json_parse_err("one of [hole] and [foundations] must be true");
    }

    if (d.HasMember("foundations initial card")) {
        if (d["foundations initial card"].IsBool()) {
            sr.foundations_init_card = d["foundations initial card"].GetBool();
        } else {
            json_helper::json_parse_err("[foundations initial card] must be a boolean");
        }
    }

    if (d.HasMember("foundations removable")) {
        if (d["foundations removable"].IsBool()) {
            sr.foundations_removable = d["foundations removable"].GetBool();
        } else {
            json_helper::json_parse_err("[foundations removable] must be a boolean");
        }
    }

    if (d.HasMember("cells")) {
        if (d["cells"].IsInt()) {
            sr.cells = static_cast<uint8_t>(d["cells"].GetInt());
        } else {
            json_helper::json_parse_err("[cells] must be an integer");
        }
    }

    if (d.HasMember("stock size")) {
        if (d["stock size"].IsInt()) {
            sr.stock_size = static_cast<uint8_t>(d["stock size"].GetInt());
        } else {
            json_helper::json_parse_err("[stock size] must be an integer");
        }
    }

    if (d.HasMember("stock deal type")) {
        if (d["stock deal type"].IsString()) {
            if(string(d["stock deal type"].GetString()) == "waste") {
                sr.stock_deal_t = sdt::WASTE;
            } else {
                sr.stock_deal_t = sdt::TABLEAU_PILES;
            }
        } else {
            json_helper::json_parse_err("[stock deal type] must be a string");
        }
    }

    if (d.HasMember("reserve size")) {
        if (d["reserve size"].IsInt()) {
            sr.reserve_size = static_cast<uint8_t>(d["reserve size"].GetInt());
        } else {
            json_helper::json_parse_err("[reserve size] must be an integer");
        }
    }

    if (d.HasMember("reserve stacked")) {
        if (d["reserve stacked"].IsBool()) {
            sr.reserve_stacked = d["reserve stacked"].GetBool();
        } else {
            json_helper::json_parse_err("[reserve stacked] must be a boolean");
        }
    }
}