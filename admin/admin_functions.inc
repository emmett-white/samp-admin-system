// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_funcs
    #undef _inc_admin_funcs
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_funcs_included
    #endinput
#endif
#define _admin_funcs_included

// settings
#if !defined MIN_ADMIN_LEVEL
    #define MIN_ADMIN_LEVEL 0
#endif

#if !defined MAX_ADMIN_LEVEL
    #define MAX_ADMIN_LEVEL 4
#endif

// variables
static
    __gPlayerAdminLevel[MAX_PLAYERS] = MIN_ADMIN_LEVEL;

// functions
/**
  * <summary>Returns the value of the max admin level</summary>
 */
stock GetMaxAdminLevel()
{
    return MAX_ADMIN_LEVEL;
}

/**
  * <summary>This function sets the admin level to the player you want to set</summary>
  * <param name="playerid">The player who'll became the administrator</param>
  * <param name="level">Administrator level...</param>
 */
stock SetPlayerAdminLevel(const playerid, const level = 0)
{
    if (!(MIN_ADMIN_LEVEL <= level <= MAX_ADMIN_LEVEL)) {
        return 0;
    }

    __gPlayerAdminLevel[playerid] = level;

    return 1;
}

/**
  * <summary>Returns the current admin level of the player</summary>
 */
stock GetPlayerAdminLevel(const playerid)
{
    return __gPlayerAdminLevel[playerid];
}