/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "czmq.h"
#include "org_zeromq_czmq_Zcertstore.h"

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1new (JNIEnv *env, jclass c, jstring location)
{
    char *location_ = (char *) (*env)->GetStringUTFChars (env, location, NULL);
    //  Disable CZMQ signal handling; allow Java to deal with it
    zsys_handler_set (NULL);
    jlong new_ = (jlong) (intptr_t) zcertstore_new (location_);
    (*env)->ReleaseStringUTFChars (env, location, location_);
    return new_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1destroy (JNIEnv *env, jclass c, jlong self)
{
    zcertstore_destroy ((zcertstore_t **) &self);
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1lookup (JNIEnv *env, jclass c, jlong self, jstring public_key)
{
    char *public_key_ = (char *) (*env)->GetStringUTFChars (env, public_key, NULL);
    jlong lookup_ = (jlong) (intptr_t) zcertstore_lookup ((zcertstore_t *) (intptr_t) self, public_key_);
    (*env)->ReleaseStringUTFChars (env, public_key, public_key_);
    return lookup_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1insert (JNIEnv *env, jclass c, jlong self, jlong cert_p)
{
    zcertstore_insert ((zcertstore_t *) (intptr_t) self, (zcert_t **) (intptr_t) &cert_p);
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1empty (JNIEnv *env, jclass c, jlong self)
{
    zcertstore_empty ((zcertstore_t *) (intptr_t) self);
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1print (JNIEnv *env, jclass c, jlong self)
{
    zcertstore_print ((zcertstore_t *) (intptr_t) self);
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1certs (JNIEnv *env, jclass c, jlong self)
{
    jlong certs_ = (jlong) (intptr_t) zcertstore_certs ((zcertstore_t *) (intptr_t) self);
    return certs_;
}

JNIEXPORT jlong JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1state (JNIEnv *env, jclass c, jlong self)
{
    jlong state_ = (jlong) (intptr_t) zcertstore_state ((zcertstore_t *) (intptr_t) self);
    return state_;
}

JNIEXPORT void JNICALL
Java_org_zeromq_czmq_Zcertstore__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zcertstore_test ((bool) verbose);
}

