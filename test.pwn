#include <a_samp>
#include "admin-system.inc"

main()
{
    new playerid;
    printf("%d", Admin_GetMaxAdminLevel());
    Admin_SetPlayerAdminLevel(playerid, 4);
    printf("%d", Admin_GetPlayerAdminLevel(playerid));
    Admin_SetPlayerAdminLevel(playerid);
    printf("%d", Admin_GetPlayerAdminLevel(playerid));
    Admin_SetPlayerAdminLevel(playerid, 5);
    printf("%d", Admin_GetPlayerAdminLevel(playerid));
    Admin_SetPlayerAdminLevel(playerid, -1);
    printf("%d", Admin_GetPlayerAdminLevel(playerid));
    Admin_KickPlayer(playerid, .reason = "Test");
    printf("reason: %s total: %d", Admin_GetPlayerKickReason(playerid), Admin_GetTotalKicked());
    Admin_KickPlayer(playerid, 4, "Test");
    printf("%s", Admin_GetPlayerKickReason(playerid));
    Admin_BanPlayer(playerid);
    printf("%s %d", Admin_GetPlayerBanReason(playerid), Admin_GetTotalBanned());
    Admin_MutePlayer(playerid, 4, 10);
    printf("Muted: %d | Reason: %s | Total muted: %d", Admin_IsPlayerMuted(playerid), Admin_GetPlayerMutedReason(playerid), Admin_GetTotalMuted());
    new playeridd = 5;
    Admin_MutePlayer(playeridd, 4, 4, "Test");
    printf("Muted: %d | Reason: %s | Total muted: %d", Admin_IsPlayerMuted(playeridd), Admin_GetPlayerMutedReason(playeridd), Admin_GetTotalMuted());
    Admin_MutePlayer(playerid, 4);
    printf("Muted: %d | Reason: %s | Total muted: %d", Admin_IsPlayerMuted(playerid), Admin_GetPlayerMutedReason(playerid), Admin_GetTotalMuted());
    Admin_SetPlayerAdminLevel(playerid, 4, 40);
    printf("%d", Admin_GetPlayerAdminCode(playerid));
    Admin_SetPlayerAdminCode(playerid, 4485409);
    printf("%d", Admin_GetPlayerAdminCode(playerid));
}

// Test commands
ADMIN_COMMAND:[MIN_ADMIN_LEVEL]setadmin(playerid, const params[])
{
    Admin_SetPlayerAdminLevel(playerid, 4);

    return 1;
}

ADMIN_COMMAND:[4]test(playerid, const params[])
{
    SendClientMessage(playerid, -1, "called");

    return 1;
}