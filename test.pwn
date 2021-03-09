#include <a_samp>
#include "admin-system.inc"

main()
{
    new playerid;
    printf("%d", GetMaxAdminLevel());
    SetPlayerAdminLevel(playerid, 4);
    printf("%d", GetPlayerAdminLevel(playerid));
    SetPlayerAdminLevel(playerid);
    printf("%d", GetPlayerAdminLevel(playerid));
    SetPlayerAdminLevel(playerid, 5);
    printf("%d", GetPlayerAdminLevel(playerid));
    SetPlayerAdminLevel(playerid, -1);
    printf("%d", GetPlayerAdminLevel(playerid));
    KickPlayer(playerid, .reason = "Test");
    printf("reason: %s total: %d", GetPlayerKickReason(playerid), GetTotalKick());
    KickPlayer(playerid, 4, "Test");
    printf("%s", GetPlayerKickReason(playerid));
    BanPlayer(playerid);
    printf("%s %d", GetPlayerBanReason(playerid), GetTotalBan());
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