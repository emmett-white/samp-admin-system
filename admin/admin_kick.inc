// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_kick
    #undef _inc_admin_kick
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_kick_included
    #endinput
#endif
#define _admin_kick_included

// variables
static
    __gPlayerKickReason[MAX_PLAYERS][0x40],
    __kickedPlayers;

// functions
/**
  * <param name="targetid">The player who'll be kicked from the server</param>
  * <param name="adminid">The player who'll kick the player (targetid)</param>
  * <param name="reason">The reason why player will be kicked..</param>
 */
stock Admin_KickPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const reason[] = "N/A", {Float,_}:...)
{
    if (adminid == INVALID_PLAYER_ID) {
        CallLocalFunction("Admin_KickPlayer", "dds", targetid, adminid, string: "N/A");
        strcopy(__gPlayerKickReason[targetid], string: "N/A");

        ++__kickedPlayers;

        return 1;
    }

    strcopy(__gPlayerKickReason[targetid], string: reason);
    Kick(targetid);

    ++__kickedPlayers;

    return 1;
}

/**
  * <summary>Returns the reason why the player has been kicked from the server</summary>
 */
stock Admin_GetPlayerKickReason(const playerid)
{
    return string: __gPlayerKickReason[playerid];
}

/**
  * <summary>Returns the number of kicked players</summary>
 */
stock Admin_GetTotalKicked()
{
    return __kickedPlayers;
}