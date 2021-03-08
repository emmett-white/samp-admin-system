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
  * <param name="playerid">The player who'll be kicked from the server</param>
  * <param name="reason">The reason why player will be kicked..</param>
 */
stock KickPlayer(const playerid, const string: reason[] = "")
{
    strcopy(__gPlayerKickReason[playerid], reason);
    Kick(playerid);

    ++__kickedPlayers;

    return 1;
}

/**
  * <summary>Returns the reason why the player has been kicked from the server.</summary>
 */
stock GetPlayerKickReason(const playerid)
{
    return __gPlayerKickReason[playerid];
}

/**
  * <summary>Returns the number of kicked players</summary>
 */
stock GetTotalKick()
{
    return __kickedPlayers;
}