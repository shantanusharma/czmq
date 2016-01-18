/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZclock::QZclock (zclock_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Sleep for a number of milliseconds
void QZclock::sleep (int msecs)
{
    zclock_sleep (msecs);
    
}

///
//  Return current system clock as milliseconds. Note that this clock can  
//  jump backwards (if the system clock is changed) so is unsafe to use for
//  timers and time offsets. Use zclock_mono for that instead.             
int64_t QZclock::time ()
{
    int64_t rv = zclock_time ();
    return rv;
}

///
//  Return current monotonic clock in milliseconds. Use this when you compute
//  time offsets. The monotonic clock is not affected by system changes and  
//  so will never be reset backwards, unlike a system clock.                 
int64_t QZclock::mono ()
{
    int64_t rv = zclock_mono ();
    return rv;
}

///
//  Return current monotonic clock in microseconds. Use this when you compute
//  time offsets. The monotonic clock is not affected by system changes and  
//  so will never be reset backwards, unlike a system clock.                 
int64_t QZclock::usecs ()
{
    int64_t rv = zclock_usecs ();
    return rv;
}

///
//  Return formatted date/time as fresh string. Free using zstr_free().
QString QZclock::timestr ()
{
    char *retStr_ = zclock_timestr ();
    QString rv = QString (retStr_);
    zstr_free (&retStr_);
    return rv;
}

///
//  Self test of this class.
void QZclock::test (bool verbose)
{
    zclock_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
