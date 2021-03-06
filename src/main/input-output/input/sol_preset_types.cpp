//
// Created by thecharlesblake on 11/14/17.
//

#include <iostream>
#include "sol_preset_types.h"
using namespace std;

string sol_preset_types::get(const string& s) {
    return mp[s];
}

bool sol_preset_types::is_valid_preset(const string& s) {
    return mp.count(s) > 0;
}

map<string, string> sol_preset_types::mp = {
        {
                "default",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "any-suit",
    "spaces policy": "any",
    "diagonal deal": false,
    "move built group": "no",
    "move built group policy": "same-as-build",
    "face up cards": "all"
  },
  "foundations": {
    "present": true,
    "initial cards": "none",
    "base card": "A",
    "removable": false,
    "only complete pile moves": false
  },
  "hole": false,
  "cells": {
    "count": 0
  },
  "stock": {
    "size": 0,
    "deal type": "waste",
    "deal count": 1,
    "redeal": false
  },
  "reserve": {
    "size": 0,
    "stacked": false
  },
  "accordion": {
    "size": 0,
    "moves": [],
    "build policies": []
  },
  "sequences": {
    "count": 0,
    "direction": "L",
    "build policy": "same-suit",
    "fixed suit": false
  },
  "max rank": 13,
  "two decks": false
}
)"

        },
        {
                "spanish-patience",

                R"(
{
  "tableau piles": {
    "count": 13
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "simple-spanish-patience",

                R"(
{
  "tableau piles": {
    "count": 3
  },
  "foundations": {
    "removable": true
  },
  "max rank": 2
}
)"

        },
        {
                "free-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "simple-free-cell",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black"
  },
  "cells": {
    "count": 1
  },
  "max rank": 4
}
)"

        },
        {
                "bakers-dozen",

                R"(
{
  "tableau piles": {
    "count": 13,
    "spaces policy": "no-build"
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "simple-bakers-dozen",

                R"(
{
  "tableau piles": {
    "count": 3,
    "spaces policy": "no-build"
  },
  "foundations": {
    "removable": true
  },
  "max rank": 3
}
)"

        },
        {
                "black-hole",

                R"(
{
  "tableau piles": {
    "count": 17,
    "build policy": "no-build"
  },
  "foundations": {
    "present": false
  },
  "hole": true
}
)"

        },
        {
                "simple-black-hole",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "no-build"
  },
  "foundations": {
    "present": false
  },
  "hole": true,
  "max rank": 5
}
)"

        },
        {
                "fortunes-favor",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "same-suit",
    "spaces policy": "auto-waste-then-stock"
  },
  "foundations": {
     "initial cards": "all"
  },
  "stock": {
     "size": 36
  }
}
)"

        },
        {
                "simple-fortunes-favor",

                R"(
{
  "tableau piles": {
    "count": 3,
    "build policy": "same-suit"
  },
  "foundations": {
     "initial cards": "all"
  },
  "stock": {
     "size": 3
  },
  "max rank": 4
}
)"

        },
        {
                "flower-garden",

                R"(
{
  "tableau piles": {
    "count": 6
  },
  "reserve": {
    "size": 16
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "simple-flower-garden",

                R"(
{
  "tableau piles": {
    "count": 3
  },
  "reserve": {
    "size": 3
  },
  "foundations": {
    "removable": true
  },
  "max rank": 3
}
)"

        },
        {
                "canfield",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black",
    "move built group": "whole-pile",
    "spaces policy": "auto-reserve-then-waste"
  },
  "foundations": {
    "initial cards": "one",
    "base card": "random"
  },
  "stock": {
    "size": 34,
    "deal count": 3,
    "redeal": true
  },
  "reserve": {
    "size": 13,
    "stacked": true
  }
}
)"

        },
        {
                "simple-canfield",

                R"(
{
  "tableau piles": {
    "count": 3,
    "build policy": "red-black",
    "move built group": "whole-pile",
    "spaces policy": "auto-reserve-then-waste"
  },
  "foundations": {
    "initial cards": "one",
    "base card": "random"
  },
  "stock": {
    "size": 6,
    "deal count": 3,
    "redeal": true
  },
  "reserve": {
    "size": 2,
    "stacked": true
  },
  "max rank": 3
}
)"

        },
        {
                "somerset",

                R"(
{
  "tableau piles": {
    "count": 10,
    "build policy": "red-black",
    "diagonal deal": true
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "simple-somerset",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black",
    "diagonal deal": true
  },
  "foundations": {
    "removable": true
  },
  "max rank": 2
}
)"

        },
        {
                "alpha-star",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "same-suit",
    "move built group": "yes"
  },
  "foundations": {
    "initial cards": "all"
  }
}
)"

        },
        {
                "simple-alpha-star",

                R"(
{
  "tableau piles": {
    "count": 3,
    "build policy": "same-suit",
    "move built group": "yes"
  },
  "foundations": {
    "initial cards": "all"
  },
  "max rank": 6
}
)"

        },
        {
                "spider",

                R"(
{
  "tableau piles": {
    "count": 10,
    "build policy": "any-suit",
    "move built group": "yes",
    "move built group policy": "same-suit",
    "face up cards": "top"
  },
  "foundations": {
    "only complete pile moves": true
  },
  "stock": {
    "size": 50,
    "deal type": "tableau piles"
  },
  "two decks": true
}
)"

        },
        {
                "simple-spider",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "any-suit",
    "move built group": "yes",
    "move built group policy": "same-suit",
    "face up cards": "top"
  },
  "foundations": {
    "only complete pile moves": true
  },
  "stock": {
    "size": 12,
    "deal type": "tableau piles"
  },
  "two decks": true,
  "max rank": 3
}
)"

        },

        {
                "simple-klondike",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "stock": {
    "size": 6,
    "deal count": 3,
    "redeal": true
  },
  "max rank": 4
}
)"
        },
        // --- END OF 'CANONICAL' GAMES ---

        {
                "raglan",

                R"(
{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black",
    "diagonal deal": true
  },
  "reserve": {
    "size": 6
  },
  "foundations": {
    "removable": true,
    "initial cards": "all"
  }
}
)"

        },

        {
                "klondike-deal-1",

                R"(
{
  "tableau piles": {
    "count": 7,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 24,
    "deal count": 1,
    "redeal": true
  }
}
)"

        },

        {
                "klondike",

                R"(
{
  "tableau piles": {
    "count": 7,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 24,
    "deal count": 3,
    "redeal": true
  }
}
)"

        },
        {
                "alina",

                R"(
{
  "tableau piles": {
    "count": 13,
    "build policy": "any-suit",
    "spaces policy": "no-build"
  },
  "foundations": {
    "removable": true
  },
  "cells": {
    "count": 1
  }
}
)"

        },
        {
                "castles-of-spain",

                R"(
{
  "tableau piles": {
    "count": 13,
    "build policy": "red-black"
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "delta-star",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "same-suit"
  },
  "foundations": {
    "initial cards": "all"
  }
}
)"

        },
        {
                "martha",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "red-black"
  },
  "foundations": {
    "initial cards": "all",
    "removable": true
  }
}
)"

        },
        {
                "one-cell",

                R"(
{
  "tableau piles": {
    "count": 13,
    "build policy": "red-black"
  },
  "foundations": {
    "initial cards": "all",
    "removable": true
  },
  "cells": {
    "count": 1
  }
}
)"

        },
        {
                "two-cell",

                R"(
{
  "tableau piles": {
    "count": 13,
    "build policy": "red-black"
  },
  "foundations": {
    "initial cards": "all",
    "removable": true
  },
  "cells": {
    "count": 2
  }
}
)"

        },
        {
                "free-cell-3-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black"
  },
  "cells": {
    "count": 3
  }
}
)"

        },
        {
                "free-cell-2-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black"
  },
  "cells": {
    "count": 2
  }
}
)"

        },
        {
                "free-cell-1-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black"
  },
  "cells": {
    "count": 1
  }
}
)"

        },
        {
                "free-cell-0-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black"
  }
}
)"

        },
        {
                "free-cell-7-pile",

                R"(
{
  "tableau piles": {
    "count": 7,
    "build policy": "red-black"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "free-cell-6-pile",

                R"(
{
  "tableau piles": {
    "count": 6,
    "build policy": "red-black"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "free-cell-5-pile",

                R"(
{
  "tableau piles": {
    "count": 5,
    "build policy": "red-black"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "free-cell-4-pile",

                R"(
{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "bakers-game",

                R"(
{
  "tableau piles": {
    "build policy": "same-suit"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "eight-off",

                R"(
{
  "tableau piles": {
    "build policy": "same-suit",
    "spaces policy": "kings"
  },
  "cells": {
    "count": 8,
    "pre-filled": 4
  }
}
)"

        },
        {
                "eight-off-any-card-spaces",

                R"(
{
  "tableau piles": {
    "build policy": "same-suit"
  },
  "cells": {
    "count": 8
  }
}
)"

        },
        {
                "fore-cell",

                R"(
{
  "tableau piles": {
    "build policy": "red-black",
    "spaces policy": "kings"
  },
  "cells": {
    "count": 4,
    "pre-filled": 4
  }
}
)"

        },
        {
                "fore-cell-same-suit",

                R"(
{
  "tableau piles": {
    "build policy": "same-suit",
    "spaces policy": "kings"
  },
  "cells": {
    "count": 4,
    "pre-filled": 4
  }
}
)"

        },
        {
                "penguin",
                R"(

{
  "tableau piles": {
    "count": 7,
    "build policy": "same-suit",
    "move built group": "yes",
    "spaces policy": "kings"
  },
  "cells": {
    "count": 7
  },
  "foundations": {
    "initial cards": "all"
  }
}
)"

        },
        {
                "sea-towers",
                R"(

{
  "tableau piles": {
    "count": 10,
    "build policy": "same-suit",
    "move built group": "yes",
    "spaces policy": "kings"
  },
  "cells": {
    "count": 4
  }
}
)"

        },
        {
                "duchess",
                R"(

{
  "tableau piles": {
    "count": 4,
    "build policy": "red-black",
    "move built group": "yes"
  },
  "foundations": {
    "initial cards": "all"
  },
  "reserve": {
    "size": 12
  },
  "stock": {
    "size": 36
  }
}
)"

        },
        {
                "chameleon",
                R"(

{
  "tableau piles": {
    "count": 3,
    "build policy": "any-suit",
    "move built group": "yes"
  },
  "reserve": {
    "size": 13,
    "stacked": true
  },
  "stock": {
    "size": 36
  }
}
)"

        },
        {
                "fan",
                R"(

{
  "tableau piles": {
    "count": 18,
    "build policy": "same-suit",
    "spaces policy": "kings"
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "scotch-patience",
                R"(

{
  "tableau piles": {
    "count": 18,
    "build policy": "red-black",
    "spaces policy": "no-build"
  },
  "foundations": {
    "removable": true
  }
}
)"

        },
        {
                "blind-alleys",
                R"(

{
  "tableau piles": {
    "count": 6,
    "build policy": "red-black",
    "move built group": "yes"
  },
  "foundations": {
    "initial cards": "all",
    "removable": true
  },
  "stock": {
    "size": 30
  }
}
)"

        },
        {
                "east-haven",
                R"(

{
  "tableau piles": {
    "count": 7,
    "build policy": "red-black",
    "move built group": "yes",
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 31,
    "deal type": "tableau piles"
  }
}
)"

        },
        {
                "northwest-territory",
                R"(

{
  "tableau piles": {
    "build policy": "red-black",
    "move built group": "yes",
    "spaces policy": "kings",
    "diagonal deal": true
  },
  "foundations": {
    "removable": true
  },
  "reserve": {
    "size": 16
  }
}
)"

        },
        {
                "king-albert",
                R"(

{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black",
    "diagonal deal": true
  },
  "foundations": {
    "removable": true
  },
  "reserve": {
    "size": 7
  }
}
)"

        },
        {
                "spiderette",

                R"(
{
  "tableau piles": {
    "count": 7,
    "build policy": "any-suit",
    "move built group": "yes",
    "move built group policy": "same-suit",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "only complete pile moves": true
  },
  "stock": {
    "size": 24,
    "deal type": "tableau piles"
  }
}
)"

        },
        {
                "will-o-the-wisp",

                R"(
{
  "tableau piles": {
    "count": 7,
    "build policy": "any-suit",
    "move built group": "yes",
    "move built group policy": "same-suit"
  },
  "foundations": {
    "only complete pile moves": true
  },
  "stock": {
    "size": 31,
    "deal type": "tableau piles"
  }
}
)"

        },
        {
                "simple-simon",

                R"(
{
  "tableau piles": {
    "count": 10,
    "diagonal deal": true,
    "move built group": "yes",
    "move built group policy": "same-suit"
  },
  "foundations": {
    "only complete pile moves": true
  }
}
)"

        },
        {
                "gaps",

                R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "sequences": {
    "count": 4,
    "direction": "L",
    "build policy": "same-suit",
    "fixed suit": false
  }
}
)"

        },
        {
            "gaps-basic-variant",

                    R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "sequences": {
    "count": 4,
    "direction": "L",
    "build policy": "same-suit",
    "fixed suit": true
  }
}
)"

        },
        {
                "simple-gaps",

                R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "sequences": {
    "count": 4,
    "direction": "L",
    "build policy": "same-suit"
  },
  "max rank": 4
}
)"

        },
        {
                "simple-accordion",

                R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "accordion": {
    "size": 10,
    "moves": ["L1", "L3"],
    "build policies": ["same-suit", "same-rank"]
  }
}
)"

        },
        {
                "accordion-knuth",

                R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "accordion": {
    "size": 18,
    "moves": ["L1", "L3"],
    "build policies": ["same-suit", "same-rank"]
  }
}
)"

        },
        {
                "accordion",

                R"(
{
  "foundations": {
    "present": false
  },
  "tableau piles": {
    "count": 0
  },
  "accordion": {
    "size": 52,
    "moves": ["L1", "L3"],
    "build policies": ["same-suit", "same-rank"]
  }
}
)"

        },
        {
                "forty-theives",

                R"(
{
  "tableau piles": {
    "count": 10,
    "build policy": "same-suit"
  },
  "stock": {
    "size": 64,
    "redeal": false
  },
  "two decks": true
}
)"

        },
        {
                "lucas",

                R"(
{
  "tableau piles": {
    "count": 13,
    "build policy": "same-suit"
  },
  "stock": {
    "size": 61,
    "redeal": false
  },
  "foundations": {
     "initial cards": "all"
  },
  "two decks": true
}
)"

        },
        {
                "maria",

                R"(
{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black"
  },
  "stock": {
    "size": 68,
    "redeal": false
  },
  "two decks": true
}
)"

        },
        {
                "limited",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "same-suit"
  },
  "stock": {
    "size": 68,
    "redeal": false
  },
  "two decks": true
}
)"

        },
        {
                "streets",

                R"(
{
  "tableau piles": {
    "count": 10,
    "build policy": "red-black"
  },
  "stock": {
    "size": 64,
    "redeal": false
  },
  "two decks": true
}
)"

        },
        {
                "rank-and-file",

                R"(
{
  "tableau piles": {
    "count": 10,
    "build policy": "red-black",
    "face up cards": "top",
    "move built group": "yes"
  },
  "stock": {
    "size": 64,
    "redeal": false
  },
  "two decks": true
}
)"

        },
        {
                "american-toad",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "same-suit",
    "move built group": "whole-pile",
    "spaces policy": "auto-reserve-then-waste"
  },
  "foundations": {
    "initial cards": "one",
    "base card": "random"
  },
  "stock": {
    "size": 75,
    "deal count": 1,
    "redeal": false
  },
  "reserve": {
    "size": 20,
    "stacked": true
  },
  "two decks": true
}
)"

        },

        {
                "gargantua",

                R"(
{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 59,
    "deal count": 1,
    "redeal": false
  },
  "two decks": true
}
)"

        },

        {
                "gargantua-redeal",

                R"(
{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 59,
    "deal count": 1,
    "redeal": true
  },
  "two decks": true
}
)"

        },

        {
                "ultra-klondike-2-deck",

                R"(
{
  "tableau piles": {
    "count": 12,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 26,
    "deal count": 3,
    "redeal": true
  },
  "two decks": true
}
)"

        },

        {
                "american-canister",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "red-black",
    "move built group": "yes",
    "spaces policy": "any"
  }
}
)"

        },

        {
                "british-canister",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "red-black",
    "move built group": "no",
    "spaces policy": "kings"
  }
}
)"

        },

        {
                "canister-warfield",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "any-suit",
    "move built group": "yes",
    "spaces policy": "any"
  }
}
)"

        },

        {
                "beleaguered-castle",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "any-suit"
  },
  "foundations": {
    "initial cards": "all"
  }
}
)"

        },

        {
                "klondike-two-deck-9",

                R"(
{
  "tableau piles": {
    "count": 9,
    "build policy": "red-black",
    "spaces policy": "kings",
    "move built group": "yes",
    "diagonal deal": true,
    "face up cards": "top"
  },
  "foundations": {
    "removable": true
  },
  "stock": {
    "size": 59,
    "deal count": 3,
    "redeal": true
  },
  "two decks": true
}
)"

        },

        {
                "streets-and-alleys",

                R"(
{
  "tableau piles": {
    "count": 8,
    "build policy": "any-suit"
  },
  "foundations": {
    "initial cards": "none"
  }
}
)"

        },

        {
                "worm-hole",

                R"(
{
  "tableau piles": {
    "count": 17,
    "build policy": "no-build"
  },
  "foundations": {
    "present": false
  },
  "cells": {
    "count": 1
  },
  "hole": true
}    
)"

        }
};

void sol_preset_types::print_available_games() {
    cout << "The following game types can be supplied to solvitaire using the "
            "'--type [name of game]' option:\n\n";
    for (auto const& x : mp) {
        cout << x.first << "\n";
    }
    cout << "\nUse the '--describe-game-rules [name of game]' option for an "
            "overview of the rules of each game:\n";
}

void sol_preset_types::describe_game_rules(string game) {
    auto rules_it = mp.find(game);
    if (rules_it == end(mp)) {
        cout << "'" << game << "' is not a valid game type. "
                "Enter '--available-game-types' for a "
                "list of the games presets that can be solved\n";
    } else {
        cout << "The rules of '" << game << "' are as follows:"
             << rules_it->second;

        if (game != "default") {
            cout << "\nTo see the default values of the JSON fields not covered "
                    "here, enter '--describe-game-rules default'\n";
        }
    }
}
