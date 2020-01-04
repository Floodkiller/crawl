#pragma once

enum pledge_type
{
    PLEDGE_NONE = 0,                // No pledge/vanilla Crawl
    
    // Tournament challenges
    PLEDGE_BRUTE_FORCE,             // Cannot worship gods
    PLEDGE_EXPLORER,                // Can only pick up orb with 15 runes, cannot leave rune floors without getting the rune
    PLEDGE_NATURES_ALLY,            // Can only enter Tomb after getting orb, can only leave dungeon with golden rune
    PLEDGE_AVARICE,                 // Can only enter non-rune branches (except Zot), Abyss, and Dis until obtaining iron rune
    PLEDGE_LORD_OF_DARKNESS,        // Cannot enter Lair, Orcish Mines, or Vaults
    PLEDGE_SPITEFUL,                // Start the game worshipping Ru. Become champion of Ru, then abandon him. 
                                    //     No entering branches other than Temple, Lair, or Abyss until then.
    PLEDGE_CONQUEROR,               // Must win the game in under 50,000 turns
    PLEDGE_ASCETIC,                 // Cannot use potions or scrolls until obtaining a rune (except slimy or abyssal)
    PLEDGE_LOREKEEPER,              // Cannot raise skills to 13 or higher, no worshipping Ashenzari
    PLEDGE_VOW_OF_COURAGE,          // Cannot enter Depths or Zot without 6 runes
    PLEDGE_RUTHLESS_EFFICIENCY,     // Die at experience level 20, no sacrificing experience with Ru
    PLEDGE_DESCENT_INTO_MADNESS,    // Cannot pick up the orb until leaving the bottom floor of a ziggurat
    PLEDGE_HARVEST,                 // Cannot leave a floor voluntarily until all unique monsters on it are dead or banished
    PLEDGE_ANGEL_OF_JUSTICE,        // Cannot pick up orb until all unique Pan/Hell lords are dead,
                                    //     attempting to pick up orb will spawn unspawned Pan lords
    PLEDGE_CHAOS,                   // Start the game worshipping Xom, cannot abandon Xom

    // Goon inspired challenges
    PLEDGE_HAUNTING,                // All floors have a 10% chance to generate a ghostly champion of LogicNinja
    PLEDGE_PEER_PRESSURE,           // All food and chunks mutate player when eaten
    PLEDGE_HERETIC,                 // Divine retribution from a random god (except current or allied) when picking up a rune
    
    NUM_PLEDGES,                    // always after last pledge
    
    PLEDGE_UNKNOWN,                     // Bad pledge check
};
