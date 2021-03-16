// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_jail
    #undef _inc_admin_jail
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_jail_included
    #endinput
#endif
#define _admin_jail_included

// variables
static
    __gPlayerJailedReason[MAX_PLAYERS][0x40],
    __gPlayerJailTime[MAX_PLAYERS],
    __jailedPlayers,

    bool: __gPlayerJailed[MAX_PLAYERS];

// functions
/**
  * <param name="targetid">The player who'll be jailed</param>
  * <param name="adminid">The player who'll jail the player (targetid)</param>
  * <param name="minutes">The time how long the player will be jailed</param>
  * <param name="reason">The reason why player will be jailed..</param>
  * <param name="jail_pos_x">Player X position</param>
  * <param name="jail_pos_y">Player Y position</param>
  * <param name="jail_pos_z">Player Z position</param>
  * <param name="jail_pos_a">Player angle</param>
  * <param name="jail_vw">Player virtual world id</param>
  * <param name="jail_int">Player interior id</param>
 */
stock Admin_JailPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const minutes = 0, const reason[] = "N/A", Float: jail_pos_x = 0.0, Float: jail_pos_y = 0.0, Float: jail_pos_z = 0.0, Float: jail_pos_a = 0.0, const jail_vw = -1, const jail_int = -1, {Float,_}:...)
{
    if (adminid == INVALID_PLAYER_ID) {
        CallLocalFunction(
            "Admin_JailPlayer", "dddsffffdd",
            targetid, adminid, minutes, string: "N/A",
            jail_pos_x, jail_pos_y, jail_pos_z, jail_pos_a, jail_vw, jail_int
        );

        strcopy(__gPlayerJailedReason[targetid], string: "N/A");
        SetPlayerPos(targetid, jail_pos_x, jail_pos_y, jail_pos_z);
        SetPlayerFacingAngle(targetid, jail_pos_a);
        SetPlayerVirtualWorld(targetid, jail_vw);
        SetPlayerInterior(targetid, jail_int);

        __gPlayerJailed[targetid] = (!minutes ? (false) : (true));
        __gPlayerJailTime[targetid] = minutes;
        __jailedPlayers = (!minutes ? (--__jailedPlayers) : (++__jailedPlayers));

        return 1;
    }

    strcopy(__gPlayerJailedReason[targetid], reason);
    SetPlayerPos(targetid, jail_pos_x, jail_pos_y, jail_pos_z);
    SetPlayerFacingAngle(targetid, jail_pos_a);
    SetPlayerVirtualWorld(targetid, jail_vw);
    SetPlayerInterior(targetid, jail_int);

    __gPlayerJailed[targetid] = (!minutes ? (false) : (true));
    __gPlayerJailTime[targetid] = minutes;
    __jailedPlayers = (!minutes ? (--__jailedPlayers) : (++__jailedPlayers));

    return 1;
}

/**
  * <summary>Returns the reason why the player has been jailed</summary>
 */
stock Admin_GetPlayerJailReason(const playerid)
{
    return string: __gPlayerJailedReason[playerid];
}

/**
  * <summary>Returns the number of jailed players</summary>
 */
stock Admin_GetTotalJailed()
{
    return __jailedPlayers;
}

/**
  * <summary>Returns the jail status of the player</summary>
 */
stock Admin_IsPlayerJailed(const playerid)
{
    return bool: (__gPlayerJailed[playerid] ? (true) : (false));
}

/**
  * <summary>Returns the time how long is player jailed in minutes</summary>
 */
stock Admin_GetPlayerJailTime(const playerid)
{
    return __gPlayerJailTime[playerid];
}