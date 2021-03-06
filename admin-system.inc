// credits: Mergevos
// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_admin_system
    #undef _inc_admin_system
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_system_included
    #endinput
#endif
#define _admin_system_included

// modules
#if !defined _admin_funcs_included
    #include <admin_functions>
#endif

#if !defined _admin_kick_included
    #include <admin_kick>
#endif

#if !defined _admin_ban_included
    #include <admin_ban>
#endif

#if !defined _admin_mute_included
    #include <admin_mute>
#endif

#if !defined _admin_jail_included
    #include <admin_jail>
#endif