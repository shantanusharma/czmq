/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZstr::QZstr (zstr_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Receive C string from socket. Caller must free returned string using
//  zstr_free(). Returns NULL if the context is being terminated or the 
//  process was interrupted.                                            
QString QZstr::recv (void *source)
{
    char *retStr_ = zstr_recv (source);
    QString rv = QString (retStr_);
    free (retStr_);;
    return rv;
}

///
//  Send a C string to a socket, as a frame. The string is sent without 
//  trailing null byte; to read this you can use zstr_recv, or a similar
//  method that adds a null terminator on the received string. String   
//  may be NULL, which is sent as "".                                   
int QZstr::send (void *dest, const QString &string)
{
    int rv = zstr_send (dest, string.toUtf8().data());
    return rv;
}

///
//  Send a C string to a socket, as zstr_send(), with a MORE flag, so that
//  you can send further strings in the same multi-part message.          
int QZstr::sendm (void *dest, const QString &string)
{
    int rv = zstr_sendm (dest, string.toUtf8().data());
    return rv;
}

///
//  Send a formatted string to a socket. Note that you should NOT use
//  user-supplied strings in the format (they may contain '%' which  
//  will create security holes).                                     
int QZstr::sendf (void *dest, const QString &param)
{
    int rv = zstr_sendf (dest, "%s", param.toUtf8().data());
    return rv;
}

///
//  Send a formatted string to a socket, as for zstr_sendf(), with a      
//  MORE flag, so that you can send further strings in the same multi-part
//  message.                                                              
int QZstr::sendfm (void *dest, const QString &param)
{
    int rv = zstr_sendfm (dest, "%s", param.toUtf8().data());
    return rv;
}

///
//  Self test of this class.
void QZstr::test (bool verbose)
{
    zstr_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
