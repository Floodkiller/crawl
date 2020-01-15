/**
 * @file
 * @brief Misc pledge functions.
**/

#include "AppHdr.h"

#include "pledge.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "item-prop.h"
#include "libutil.h" // map_find
#include "stringutil.h"
 
struct pledge_def
{
    string name;
    string morgue_line;
    vector<string> rcfile_options;
};

/*
 * Entry format:
 *   row  0: pledge enum
 *   row  1: pledge name
 *   row  2: morgue file line
 *   row  3: rcfile option names
 */
 
static map<pledge_type, pledge_def> _pledge_data = {
    
{ PLEDGE_NONE, {
    "None",
    "You have taken no pledge.",
    {"none"},
} },

{ PLEDGE_BRUTE_FORCE, {
    "Brute Force",
    "You have taken the pledge of Brute Force.",
    {"brute", "brute force", "bruteforce"},
} },

{ PLEDGE_EXPLORER, {
    "Explorer",
    "You have taken the pledge of the Explorer.",
    {"explorer"},
} },

{ PLEDGE_NATURES_ALLY, {
    "Nature's Ally",
    "You have taken the pledge of Nature's Ally.",
    {"nature", "natures ally", "naturesally"},
} },

{ PLEDGE_AVARICE, {
    "Avarice",
    "You have taken the pledge of Avarice.",
    {"avarice"},
} },

{ PLEDGE_LORD_OF_DARKNESS, {
    "Darkness",
    "You have taken the pledge of Darkness.",
    {"darkness", "lord of darkness", "lordofdarkness"},
} },

{ PLEDGE_SPITEFUL, {
    "Spiteful",
    "You have taken the pledge of the Spiteful.",
    {"spiteful"},
} },

{ PLEDGE_CONQUEROR, {
    "Conqueror",
    "You have taken the pledge of the Conqueror.",
    {"conqueror"},
} },

{ PLEDGE_ASCETIC, {
    "Ascetic",
    "You have taken the pledge of the Ascetic.",
    {"ascetic"},
} },

{ PLEDGE_LOREKEEPER, {
    "Lorekeeper",
    "You have taken the pledge of the Lorekeeper.",
    {"lorekeeper"},
} },

{ PLEDGE_VOW_OF_COURAGE, {
    "Courage",
    "You have taken the pledge of Courage.",
    {"courage", "vow of courage", "vowofcourage"},
} },

{ PLEDGE_RUTHLESS_EFFICIENCY, {
    "Efficiency",
    "You have taken the pledge of Ruthless Efficiency.",
    {"ruthless", "ruthless efficiency", "ruthlessefficiency"},
} },

{ PLEDGE_DESCENT_INTO_MADNESS, {
    "Madness",
    "You have taken the pledge of Madness.",
    {"madness", "descent into madness", "descentintomadness"},
} },

{ PLEDGE_HARVEST, {
    "Harvest",
    "You have taken the pledge of the Harvest.",
    {"harvest"},
} },

{ PLEDGE_ANGEL_OF_JUSTICE, {
    "Justice",
    "You have taken the pledge of Justice.",
    {"justice", "angel of justice", "angelofjustice"},
} },

{ PLEDGE_CHAOS, {
    "Chaos",
    "You have taken the pledge of Chaos.",
    {"chaos"},
} },

// TODO: Implement
//{ PLEDGE_HAUNTING, {
//    "Haunting",
//    "You have taken the pledge of Haunting.",
//    {"haunting"},
//} },

{ PLEDGE_PEER_PRESSURE, {
    "Peer Pressure",
    "You have taken the pledge of Peer Pressure.",
    {"purple", "pressure", "peer pressure", "peerpressure"},
} },

{ PLEDGE_HERETIC, {
    "Heretic",
    "You have taken the pledge of the Heretic.",
    {"heretic"},
} },

{ PLEDGE_UNKNOWN, {
    "Unknown",
    "Buggy pledge.",
    {"unknown"},
} },
    
};

static const pledge_def& _get_pledge_def(pledge_type pledge)
{
    if (pledge != PLEDGE_UNKNOWN)
        ASSERT_RANGE(pledge, 0, NUM_PLEDGES);
    return _pledge_data.at(pledge);
}

string get_pledge_name(pledge_type pledge)
{
    const pledge_def& def = _get_pledge_def(pledge);
    return def.name;
}

string get_pledge_morgue_line(pledge_type pledge)
{
    const pledge_def& def = _get_pledge_def(pledge);
    return def.morgue_line;
}

static bool _string_in_rcfile_options(pledge_type pledge, const string &str)
{
    return find(_get_pledge_def(pledge).rcfile_options.begin(),
                _get_pledge_def(pledge).rcfile_options.end(),
                str) != _get_pledge_def(pledge).rcfile_options.end();
}

// Change rcfile option entry into pledge_type
pledge_type rcfile_str_to_pledge(const string &str)
{
    pledge_type pledge;
    string str_nospace = lowercase_string(str);
    remove_whitespace(str_nospace);

    for (int i = 0; i < NUM_PLEDGES; ++i)
    {
        pledge = static_cast<pledge_type>(i);
        if (_string_in_rcfile_options(pledge, str_nospace))
            return pledge;
    }

    // Could not find pledge, return PLEDGE_UNKNOWN
    return PLEDGE_UNKNOWN;
}

// Change name into pledge_type (logfile support)
pledge_type name_to_pledge(const string &str)
{
    pledge_type pledge;

    for (int i = 0; i < NUM_PLEDGES; ++i)
    {
        pledge = static_cast<pledge_type>(i);
        if (str == get_pledge_name(pledge))
            return pledge;
    }

    // Could not find pledge, return PLEDGE_UNKNOWN
    return PLEDGE_UNKNOWN;
}
