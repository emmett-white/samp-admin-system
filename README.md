# samp-admin-system

[![sampctl](https://img.shields.io/badge/sampctl-samp--admin--system-2f2f2f.svg?style=for-the-badge)](https://github.com/emmett-white/samp-admin-system)

## Installation

Simply install to your project:

```bash
sampctl package install emmett-white/samp-admin-system
```

Include in your code and begin using the library:

```pawn
#include <admin-system>
```

## Info

### Systems
---
| Systems | Status |
|--|--|
| Kick system | ✅ |
| Ban system | ✅ |
| Mute system | ✅ |
| Jail system | ✅ |
---

### Functions
```c
stock Admin_GetMaxAdminLevel()
stock Admin_SetPlayerAdminLevel(const playerid, const level = 0, const code = 0)
stock Admin_SetPlayerAdminCode(const playerid, const code = 0)
stock Admin_GetPlayerAdminLevel(const playerid)
stock Admin_GetPlayerAdminCode(const playerid)

stock Admin_KickPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const string: reason[] = "N/A")
stock Admin_GetPlayerKickReason(const playerid)
stock Admin_GetTotalKicked()

stock Admin_BanPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const string: reason[] = "N/A")
stock Admin_GetPlayerBanReason(const playerid)
stock Admin_GetTotalBanned()

stock Admin_MutePlayer(const targetid, const adminid = INVALID_PLAYER_ID, const minutes = 0, const string: reason[] = "N/A")
stock Admin_GetPlayerMutedReason(const playerid)
stock Admin_GetTotalMuted()
stock Admin_IsPlayerMuted(const playerid)
stock Admin_GetPlayerMuteTime(const playerid)

stock Admin_JailPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const minutes = 0, const string: reason[] = "N/A", Float: jail_pos_x = 0.0, Float: jail_pos_y = 0.0, Float: jail_pos_z = 0.0, Float: jail_pos_a = 0.0, const jail_vw = -1, const jail_int = -1)
stock Admin_GetPlayerJailReason(const playerid)
stock Admin_GetTotalJailed()
stock Admin_IsPlayerJailed(const playerid)
stock Admin_GetPlayerJailTime(const playerid)
```
---

## Usage (+commands example)
### How to set admin to the player?
```c
CMD:setadmin(playerid, const params[])
{
    if (Admin_GetPlayerAdminLevel(playerid) < MAX_ADMIN_LEVEL) {
        return 0;
    }

    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, level, code; else {
        return SendClientMessage(playerid, -1, "/setadmin <targetid> <level> <code>");
    }

    if (!(MIN_ADMIN_LEVEL <= level <= MAX_ADMIN_LEVEL)) {
        return 0;
    }

    Admin_SetPlayerAdminLevel(targetid, level, code);
    va_SendClientMessage(
        targetid, -1,
        "Admin Level: %d | Code: %d", Admin_GetPlayerAdminLevel(targetid), Admin_GetPlayerAdminCode(targetid)
    );

    return 1;
}
```
### How to kick player(s)
```c
CMD:kick(playerid, const params[])
{
    if (Admin_GetPlayerAdminLevel(playerid) < 1) {
        return 0;
    }

    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/kick <targetid> <reason>");
    }

    Admin_KickPlayer(targetid, playerid, reason);

    return 1;
}
```
### How to ban player(s)
```c
CMD:ban(playerid, const params[])
{
    if (Admin_GetPlayerAdminLevel(playerid) < 1) {
        return 0;
    }

    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/ban <targetid> <reason>");
    }

    Admin_anPlayer(targetid, playerid, reason);

    return 1;
}
```

### How to mute player(s)
```c
CMD:mute(playerid, const params[])
{
    if (Admin_GetPlayerAdminLevel(playerid) < 1) {
        return 0;
    }

    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, minutes, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/mute <targetid> <minutes> <reason>");
    }

    Admin_MutePlayer(targetid, playerid, minutes, reason);

    return 1;
}

// To un-mute player just set minutes to 0...
__gPlayerMuted[targetid] = (!minutes ? (false) : (true)); // if minutes = 0 the player will not be muted..
```

### How to jail player(s)
```c
CMD:jail(playerid, const params[])
{
    if (Admin_GetPlayerAdminLevel(playerid) < 1) {
        return 0;
    }

    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, minutes, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/jail <targetid> <minutes> <reason>");
    }

    Admin_JailPlayer(targetid, playerid, minutes, reason);

    return 1;
}

// To un-jail player just set minutes to 0...
__gPlayerJailed[targetid] = (!minutes ? (false) : (true)); // if minutes = 0 the player will not be jailed..
```
---

## Testing

To test, simply run the package:

```bash
sampctl package run
```