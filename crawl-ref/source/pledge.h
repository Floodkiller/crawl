/**
 * @file
 * @brief Misc pledge functions.
**/

#pragma once

#include <set>

#include "pledge-type.h"

string get_pledge_name(pledge_type pledge);
string get_pledge_morgue_line(pledge_type pledge);
pledge_type rcfile_str_to_pledge(const string &str);
pledge_type name_to_pledge(const string &str);
