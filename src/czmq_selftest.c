/*  =========================================================================
    czmq_selftest.c - run selftests

    Runs all selftests.

    -------------------------------------------------------------------------
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
    =========================================================================
*/

#include "czmq_classes.h"

typedef struct {
    const char *testname;
    void (*test) (bool);
} test_item_t;

static test_item_t
all_tests [] = {
    { "zactor", zactor_test },
    { "zarmour", zarmour_test },
    { "zcert", zcert_test },
    { "zcertstore", zcertstore_test },
    { "zchunk", zchunk_test },
    { "zclock", zclock_test },
    { "zconfig", zconfig_test },
    { "zdigest", zdigest_test },
    { "zdir", zdir_test },
    { "zdir_patch", zdir_patch_test },
    { "zfile", zfile_test },
    { "zframe", zframe_test },
    { "zhash", zhash_test },
    { "zhashx", zhashx_test },
    { "ziflist", ziflist_test },
    { "zlist", zlist_test },
    { "zlistx", zlistx_test },
    { "zloop", zloop_test },
    { "zmsg", zmsg_test },
    { "zpoller", zpoller_test },
    { "zsock", zsock_test },
    { "zstr", zstr_test },
    { "zuuid", zuuid_test },
    { "zauth", zauth_test },
    { "zbeacon", zbeacon_test },
    { "zgossip", zgossip_test },
    { "zmonitor", zmonitor_test },
    { "zproxy", zproxy_test },
    { "zrex", zrex_test },
    { "zsys", zsys_test },
    { "zgossip_msg", zgossip_msg_test },
    { "zauth_v2", zauth_v2_test },
    { "zbeacon_v2", zbeacon_v2_test },
    { "zctx", zctx_test },
    { "zmonitor_v2", zmonitor_v2_test },
    { "zmutex", zmutex_test },
    { "zproxy_v2", zproxy_v2_test },
    { "zsocket", zsocket_test },
    { "zsockopt", zsockopt_test },
    { "zthread", zthread_test },
#ifdef WITH_DRAFTS
    { "zproc", zproc_test },
    { "ztrie", ztrie_test },
#endif // WITH_DRAFTS
    {0, 0}          //  Sentinel
};

//  -------------------------------------------------------------------------
//  Test whether a test is available.
//  Return a pointer to a test_item_t if available, NULL otherwise.
//

test_item_t *
test_available (const char *testname)
{
    test_item_t *item;
    for (item = all_tests; item->test; item++) {
        if (streq (testname, item->testname))
            return item;
    }
    return NULL;
}

//  -------------------------------------------------------------------------
//  Run all tests.
//

static void
test_runall (bool verbose)
{
    test_item_t *item;
    printf ("Running czmq selftests...\n");
    for (item = all_tests; item->test; item++)
        item->test (verbose);

    printf ("Tests passed OK\n");
}

int
main (int argc, char **argv)
{
    bool verbose = false;
    test_item_t *test = 0;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-h")) {
            puts ("czmq_selftest.c [options] ...");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --number / -n          report number of tests");
            puts ("  --list / -l            list all tests");
            puts ("  --test / -t [name]     run only test 'name'");
            puts ("  --continue / -c        continue on exception (on Windows)");
            return 0;
        }
        if (streq (argv [argn], "--verbose")
        ||  streq (argv [argn], "-v"))
            verbose = true;
        else
        if (streq (argv [argn], "--number")
        ||  streq (argv [argn], "-n")) {
            puts ("42");
            return 0;
        }
        else
        if (streq (argv [argn], "--list")
        ||  streq (argv [argn], "-l")) {
            puts ("Available tests:");
            puts ("    zactor");
            puts ("    zarmour");
            puts ("    zcert");
            puts ("    zcertstore");
            puts ("    zchunk");
            puts ("    zclock");
            puts ("    zconfig");
            puts ("    zdigest");
            puts ("    zdir");
            puts ("    zdir_patch");
            puts ("    zfile");
            puts ("    zframe");
            puts ("    zhash");
            puts ("    zhashx");
            puts ("    ziflist");
            puts ("    zlist");
            puts ("    zlistx");
            puts ("    zloop");
            puts ("    zmsg");
            puts ("    zpoller");
            puts ("    zproc");
            puts ("    zsock");
            puts ("    zstr");
            puts ("    ztrie");
            puts ("    zuuid");
            puts ("    zauth");
            puts ("    zbeacon");
            puts ("    zgossip");
            puts ("    zmonitor");
            puts ("    zproxy");
            puts ("    zrex");
            puts ("    zsys");
            puts ("    zgossip_msg");
            puts ("    zauth_v2");
            puts ("    zbeacon_v2");
            puts ("    zctx");
            puts ("    zmonitor_v2");
            puts ("    zmutex");
            puts ("    zproxy_v2");
            puts ("    zsocket");
            puts ("    zsockopt");
            puts ("    zthread");
            return 0;
        }
        else
        if (streq (argv [argn], "--test")
        ||  streq (argv [argn], "-t")) {
            argn++;
            if (argn >= argc) {
                fprintf (stderr, "--test needs an argument\n");
                return 1;
            }
            test = test_available (argv [argn]);
            if (!test) {
                fprintf (stderr, "%s not valid, use --list to show tests\n", argv [argn]);
                return 1;
            }
        }
        else
        if (streq (argv [argn], "--continue")
        ||  streq (argv [argn], "-c")) {
#ifdef _MSC_VER
            //  When receiving an abort signal, only print to stderr (no dialog)
            _set_abort_behavior (0, _WRITE_ABORT_MSG);
#endif
        }
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    if (test) {
        printf ("Running czmq test '%s'...\n", test->testname);
        test->test (verbose);
    }
    else
        test_runall (verbose);

    return 0;
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
