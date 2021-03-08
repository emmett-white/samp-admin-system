#include <a_samp>
#include "admin-system.inc"

main()
{
    // printf("%d", GetMaxAdminLevel());
    // new playerid = 0;
    // SetPlayerAdminLevel(playerid, 4);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid, 5);
    // printf("%d", GetPlayerAdminLevel(playerid));
    // SetPlayerAdminLevel(playerid, -1);
    // printf("%d", GetPlayerAdminLevel(playerid));

    // new playerid;
    // KickPlayer(playerid, "Test");
    // printf("reason: %s total: %d", GetPlayerKickReason(playerid), GetTotalKick());
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

// ADMIN_COMMAND:[1]kick(playerid, const params[])
// {
//     extract params -> new targetid, string: reason[64]; else {
//         return SendClientMessage(playerid, -1, "/kick [targetid] [reason]");
//     }

//     KickPlayer(targetid, reason);

//     new string[64];
//     format(string, sizeof string, "Reason: %s | Total: %d", GetPlayerKickReason(targetid), GetTotalKick());
//     SendClientMessage(playerid, -1, string);

//     return 1;
// }