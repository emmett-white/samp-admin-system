// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_ban
    #undef _inc_admin_ban
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_ban_included
    #endinput
#endif
#define _admin_ban_included

// variables
static
    __gPlayerBanReason[MAX_PLAYERS][0x40],
    __bannedPlayers;

// functions
/**
  * <param name="targetid">The player who'll be banned from the server</param>
  * <param name="adminid">The player who'll ban the player (targetid)</param>
  * <param name="reason">The reason why player will be banned..</param>
 */
stock Admin_BanPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const reason[] = "N/A", {Float,_}:...)
{
    if (adminid == INVALID_PLAYER_ID) {
        CallLocalFunction("Admin_BanPlayer", "dds", targetid, adminid, string: "N/A");
        
        strcopy(__gPlayerBanReason[targetid], string: "N/A");
        BanEx(targetid, string: reason);

        ++__bannedPlayers;

        return 1;
    }

    strcopy(__gPlayerBanReason[targetid], string: reason);
    BanEx(targetid, string: reason);

    ++__bannedPlayers;

    return 1;
}

/**
  * <param name="targetid">The player who'll be banned from the server by ip</param>
  * <param name="adminid">The player who'll ban the player ip (targetid)</param>
  * <param name="ip_addr">Player IP Address..</param>
  * <param name="reason">The reason why player will be banned by ip..</param>
 */
stock Admin_BanPlayerIP(const targetid, const adminid = INVALID_PLAYER_ID, const ip_addr[], const reason[] = "N/A", {Float,_}:...)
{
    new ip_fmt[32];

    if (adminid == INVALID_PLAYER_ID) {
        CallLocalFunction("Admin_BanPlayerIP", "ddss", targetid, adminid, string: ip_addr, string: "N/A");
        strcopy(__gPlayerBanReason[targetid], string: "N/A");
        
        format(ip_fmt, sizeof ip_fmt, "banip %s", string: ip_addr);    
        SendRconCommand(ip_fmt);

        ++__bannedPlayers;

        return 1;
    }

    strcopy(__gPlayerBanReason[targetid], string: reason);

    format(ip_fmt, sizeof ip_fmt, "banip %s", string: ip_addr);    
    SendRconCommand(string: ip_fmt);

    ++__bannedPlayers;

    return 1;
}

/**
  * <summary>Returns the reason why the player has been banned from the server</summary>
 */
stock Admin_GetPlayerBanReason(const playerid)
{
    return string: __gPlayerBanReason[playerid];
}

/**
  * <summary>Returns the number of banned players</summary>
 */
stock Admin_GetTotalBanned()
{
    return __bannedPlayers;
}