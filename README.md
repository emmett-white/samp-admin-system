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
stock GetMaxAdminLevel()
stock SetPlayerAdminLevel(const playerid, const level = 0, const code = 0)
stock SetPlayerAdminCode(const playerid, const code = 0)
stock GetPlayerAdminLevel(const playerid)
stock GetPlayerAdminCode(const playerid)

stock KickPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const string: reason[] = "N/A")
stock GetPlayerKickReason(const playerid)
stock GetTotalKicked()

stock BanPlayer(const targetid, const adminid = INVALID_PLAYER_ID, const string: reason[] = "N/A")
stock GetPlayerBanReason(const playerid)
stock GetTotalBanned()

stock MutePlayer(const targetid, const adminid = INVALID_PLAYER_ID, const minutes = 0, const string: reason[] = "N/A")
stock GetPlayerMutedReason(const playerid)
stock GetTotalMuted()
stock IsPlayerMuted(const playerid)
```
---

## Usage (+commands example)
### How to set admin to the player?
```c
ADMIN_COMMAND:[MAX_ADMIN_LEVEL]setadmin(playerid, const params[])
{
    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, level, code; else {
        return SendClientMessage(playerid, -1, "/setadmin <targetid> <level> <code>");
    }

    if (!(MIN_ADMIN_LEVEL <= level <= MAX_ADMIN_LEVEL)) {
        return 0;
    }

    SetPlayerAdminLevel(targetid, level, code);
    va_SendClientMessage(
        targetid, -1,
        "Admin Level: %d | Code: %d", GetPlayerAdminLevel(targetid), GetPlayerAdminCode(targetid)
    );

    return 1;
}
```
### How to kick player(s)
```c
ADMIN_COMMAND:[1]kick(playerid, const params[])
{
    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/kick <targetid> <reason>");
    }

    KickPlayer(targetid, playerid, reason);

    return 1;
}
```
### How to ban player(s)
```c
ADMIN_COMMAND:[1]ban(playerid, const params[])
{
    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/ban <targetid> <reason>");
    }

    BanPlayer(targetid, playerid, reason);

    return 1;
}
```

### How to mute player(s)
```c
ADMIN_COMMAND:[1]mute(playerid, const params[])
{
    // Example with sscanf (Y_Less sscanf)
    extract params -> new targetid, minutes, string: reason[64]; else {
        return SendClientMessage(playerid, -1, "/mute <targetid> <minutes> <reason>");
    }

    MutePlayer(targetid, playerid, minutes, reason);

    return 1;
}

// To un-mute just set minutes to 0...
__gPlayerMuted[targetid] = (!minutes ? (false) : (true)); // if minutes = 0 the player will not be muted..
```
---

## Testing

To test, simply run the package:

```bash
sampctl package run
```