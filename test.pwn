#include <a_samp>
#include "admin-system.inc"

main()
{
    // new playerid;
    // printf("%d", GetMaxAdminLevel());
    // SetPlayerAdminLevel(playerid, 4);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid, 5);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid, -1);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // KickPlayer(playerid, .reason = "Test");
    // printf("reason: %s total: %d", GetPlayerKickReason(playerid), GetTotalKicked());
    // KickPlayer(playerid, 4, "Test");
    // printf("%s", GetPlayerKickReason(playerid));
    // BanPlayer(playerid);
    // printf("%s %d", GetPlayerBanReason(playerid), GetTotalBanned());
    // MutePlayer(playerid, 4, 10);
    // printf("Muted: %d | Reason: %s | Total muted: %d", IsPlayerMuted(playerid), GetPlayerMutedReason(playerid), GetTotalMuted());
    // new playeridd = 5;
    // MutePlayer(playeridd, 4, 4, "Test");
    // printf("Muted: %d | Reason: %s | Total muted: %d", IsPlayerMuted(playeridd), GetPlayerMutedReason(playeridd), GetTotalMuted());
    // MutePlayer(playerid, 4);
    // printf("Muted: %d | Reason: %s | Total muted: %d", IsPlayerMuted(playerid), GetPlayerMutedReason(playerid), GetTotalMuted());
    // SetPlayerAdminLevel(playerid, 4, 40);
    // printf("%d", GetPlayerAdminCode(playerid));
    // SetPlayerAdminCode(playerid, 4485409);
    // printf("%d", GetPlayerAdminCode(playerid));
}

// Test commands
ADMIN_COMMAND:[MIN_ADMIN_LEVEL]setadmin(playerid, const params[])
{
    SetPlayerAdminLevel(playerid, 4);

    return 1;
}

ADMIN_COMMAND:[4]test(playerid, const params[])
{
    SendClientMessage(playerid, -1, "called");

    return 1;
}