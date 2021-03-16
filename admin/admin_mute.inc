// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_mute
    #undef _inc_admin_mute
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_mute_included
    #endinput
#endif
#define _admin_mute_included

// variables
static
    __gPlayerMuteReason[MAX_PLAYERS][0x40],
    __gPlayerMuteTime[MAX_PLAYERS],
    bool: __gPlayerMuted[MAX_PLAYERS],
    
    __mutedPlayers;

// functions
/**
  * <param name="targetid">The player who'll be muted</param>
  * <param name="adminid">The player who'll mute the player (targetid)</param>
  * <param name="minutes">The time how long the player will be muted</param>
  * <param name="reason">The reason why player will be muted..</param>
 */
stock Admin_MutePlayer(const targetid, const adminid = INVALID_PLAYER_ID, const minutes = 0, const reason[] = "N/A", {Float,_}:...)
{
    if (adminid == INVALID_PLAYER_ID) {
        CallLocalFunction("Admin_MutePlayer", "ddds", targetid, adminid, minutes, string: "N/A");
        strcopy(__gPlayerMuteReason[targetid], string: "N/A");

        __gPlayerMuted[targetid] = (!minutes ? (false) : (true));
        __gPlayerMuteTime[targetid] = minutes;
        __mutedPlayers = (!minutes ? (--__mutedPlayers) : (++__mutedPlayers));

        return 1;
    }

    if (Admin_IsPlayerMuted(targetid) && minutes) {
        return 0;
    }

    strcopy(__gPlayerMuteReason[targetid], string: reason);

    __gPlayerMuted[targetid] = (!minutes ? (false) : (true));
    __gPlayerMuteTime[targetid] = minutes;
    __mutedPlayers = (!minutes ? (--__mutedPlayers) : (++__mutedPlayers));

    return 1;
}

/**
  * <summary>Returns the reason why the player has been muted</summary>
 */
stock Admin_GetPlayerMutedReason(const playerid)
{
    return string: __gPlayerMuteReason[playerid];
}

/**
  * <summary>Returns the number of muted players</summary>
 */
stock Admin_GetTotalMuted()
{
    return __mutedPlayers;
}

/**
  * <summary>Returns the mute status of the player</summary>
 */
stock Admin_IsPlayerMuted(const playerid)
{
    return bool: (__gPlayerMuted[playerid] ? (true) : (false));
}

/**
  * <summary>Returns the time how long is player muted in minutes</summary>
 */
stock Admin_GetPlayerMuteTime(const playerid)
{
    return __gPlayerMuteTime[playerid];
}