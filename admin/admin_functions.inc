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
    __gPlayerAdminLevel[MAX_PLAYERS] = MIN_ADMIN_LEVEL,
    __gPlayerAdminCode[MAX_PLAYERS];

// functions
/**
  * <summary>Returns the value of the max admin level</summary>
 */
stock Admin_GetMaxAdminLevel()
{
    return MAX_ADMIN_LEVEL;
}

/**
  * <summary>This function sets the admin level to the player you want to set</summary>
  * <param name="playerid">The player who'll became the administrator</param>
  * <param name="level">Administrator level...</param>
 */
stock Admin_SetPlayerAdminLevel(const playerid, const level = 0, const code = 0)
{
    if (!(MIN_ADMIN_LEVEL <= level <= MAX_ADMIN_LEVEL)) {
        return 0;
    }

    __gPlayerAdminLevel[playerid] = level;
    __gPlayerAdminCode[playerid] = code;

    return 1;
}

/**
  * <summary>This function sets the admin code to the player you want to set</summary>
  * <param name="playerid">The administrator to whom the code will be set</param>
  * <param name="level">Administrator code...</param>
 */
stock Admin_SetPlayerAdminCode(const playerid, const code = 0)
{
    return __gPlayerAdminCode[playerid] = code;
}

/**
  * <summary>Returns the current admin level of the player</summary>
 */
stock Admin_GetPlayerAdminLevel(const playerid)
{
    return __gPlayerAdminLevel[playerid];
}

/**
  * <summary>Returns the player's admin code</summary>
 */
stock Admin_GetPlayerAdminCode(const playerid)
{
    return __gPlayerAdminCode[playerid];
}