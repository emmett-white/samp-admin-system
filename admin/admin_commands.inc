// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_cmds
    #undef _inc_admin_cmds
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_cmds_included
    #endinput
#endif
#define _admin_cmds_included

#tryinclude <YSI_Coding\y_hooks>
#tryinclude <sscanf2>

// settings
#define PLAYER_COMMAND:%1(%2) forward cmd_%1(%2); public cmd_%1(%2)
#define ADMIN_COMMAND:[%0]%1(%2,%3) PLAYER_COMMAND:%1(%2,%3) if (Admin_GetPlayerAdminLevel(%2) < %0) return 0; else

// hook callback
hook OnPlayerCommandText(playerid, cmdtext[])
{
	new
		cmd[30],
		params[127],
		cmdfunction[64],
		result = 1;

	sscanf(cmdtext, "s[30]s[127]", cmd, params);

	for (new i, j = strlen(cmd); i < j; ++i) {
		cmd[i] = tolower(cmd[i]);
	}

	format(cmdfunction, 64, "cmd_%s", cmd[1]);

	if(funcidx(cmdfunction) == -1) {
		new
			iLvl = Admin_GetPlayerAdminLevel(playerid),
			iLoop = MAX_ADMIN_LEVEL;

		while(iLoop > 0) {
			format(cmdfunction, 64, "acmd_%s_%d", cmd[1], iLoop);

			if(funcidx(cmdfunction) != -1) {
				break;
			}

			iLoop--;
		}

		if(iLoop == 0) {
			result = MIN_ADMIN_LEVEL;
		}

		if(iLvl < iLoop) {
			result = MAX_ADMIN_LEVEL;
		}
	}

	if(result == 1) {
		if(isnull(params)) {
			result = CallLocalFunction(cmdfunction, "is", playerid, "\1");
		}

		else {
			result = CallLocalFunction(cmdfunction, "is", playerid, params);
		}
	}
	
	return 1;
}