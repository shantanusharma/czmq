/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "czmq.h"
#include "../../native/include/org_zeromq_czmq_Zpoller.h"

JNIEXPORT jlong JNICALL
Java_zpoller__1_1new (JNIEnv *env, jclass c, jlong reader)
{
    jlong new_ = (jlong) zpoller_new ((void *) reader);
    return new_;
}

JNIEXPORT void JNICALL
Java_zpoller__1_1destroy (JNIEnv *env, jclass c, jlong self_p)
{
    zpoller_destroy ((zpoller_t **) &self_p);
}

JNIEXPORT jint JNICALL
Java_zpoller__1_1add (JNIEnv *env, jclass c, jlong self, jlong reader)
{
    jint add_ = (jint) zpoller_add ((zpoller_t *) self, (void *) reader);
    return add_;
}

JNIEXPORT jint JNICALL
Java_zpoller__1_1remove (JNIEnv *env, jclass c, jlong self, jlong reader)
{
    jint remove_ = (jint) zpoller_remove ((zpoller_t *) self, (void *) reader);
    return remove_;
}

JNIEXPORT jlong JNICALL
Java_zpoller__1_1wait (JNIEnv *env, jclass c, jlong self, jint timeout)
{
    jlong wait_ = (jlong) zpoller_wait ((zpoller_t *) self, (int) timeout);
    return wait_;
}

JNIEXPORT jboolean JNICALL
Java_zpoller__1_1expired (JNIEnv *env, jclass c, jlong self)
{
    jboolean expired_ = (jboolean) zpoller_expired ((zpoller_t *) self);
    return expired_;
}

JNIEXPORT jboolean JNICALL
Java_zpoller__1_1terminated (JNIEnv *env, jclass c, jlong self)
{
    jboolean terminated_ = (jboolean) zpoller_terminated ((zpoller_t *) self);
    return terminated_;
}

JNIEXPORT void JNICALL
Java_zpoller__1_1ignore_interrupts (JNIEnv *env, jclass c, jlong self)
{
    zpoller_ignore_interrupts ((zpoller_t *) self);
}

JNIEXPORT void JNICALL
Java_zpoller__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zpoller_test ((bool) verbose);
}

