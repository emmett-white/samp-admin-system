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

#if !defined _admin_cmds_included
    #include <admin_commands>
#endif