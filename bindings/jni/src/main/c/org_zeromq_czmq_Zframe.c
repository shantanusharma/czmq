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
#include "../../native/include/org_zeromq_czmq_Zframe.h"

JNIEXPORT jlong JNICALL
Java_zframe__1_1new (JNIEnv *env, jclass c, jbyteArray data, jlong size)
{
    byte *data_ = (byte *) (*env)->GetByteArrayElements (env, data, 0);
    jlong new_ = (jlong) zframe_new (data_, (size_t) size);
    (*env)->ReleaseByteArrayElements (env, data, (jbyte *) data_, 0);
    return new_;
}

JNIEXPORT void JNICALL
Java_zframe__1_1destroy (JNIEnv *env, jclass c, jlong self_p)
{
    zframe_destroy ((zframe_t **) &self_p);
}

JNIEXPORT jlong JNICALL
Java_zframe__1_1new_empty (JNIEnv *env, jclass c)
{
    jlong new_empty_ = (jlong) zframe_new_empty ();
    return new_empty_;
}

JNIEXPORT jlong JNICALL
Java_zframe__1_1from (JNIEnv *env, jclass c, jstring string)
{
    char *string_ = (char *) (*env)->GetStringUTFChars (env, string, NULL);
    jlong from_ = (jlong) zframe_from (string_);
    (*env)->ReleaseStringUTFChars (env, string, string_);
    return from_;
}

JNIEXPORT jlong JNICALL
Java_zframe__1_1recv (JNIEnv *env, jclass c, jlong source)
{
    jlong recv_ = (jlong) zframe_recv ((void *) source);
    return recv_;
}

JNIEXPORT jint JNICALL
Java_zframe__1_1send (JNIEnv *env, jclass c, jlong self_p, jlong dest, jint flags)
{
    jint send_ = (jint) zframe_send ((zframe_t **) &self_p, (void *) dest, (int) flags);
    return send_;
}

JNIEXPORT jlong JNICALL
Java_zframe__1_1size (JNIEnv *env, jclass c, jlong self)
{
    jlong size_ = (jlong) zframe_size ((zframe_t *) self);
    return size_;
}

JNIEXPORT jbytearray JNICALL
Java_zframe__1_1data (JNIEnv *env, jclass c, jlong self)
{
    byte *data_ = (byte *) zframe_data ((zframe_t *) self);
    return (jlong) data_;
}

JNIEXPORT jlong JNICALL
Java_zframe__1_1dup (JNIEnv *env, jclass c, jlong self)
{
    jlong dup_ = (jlong) zframe_dup ((zframe_t *) self);
    return dup_;
}

JNIEXPORT jstring JNICALL
Java_zframe__1_1strhex (JNIEnv *env, jclass c, jlong self)
{
    char *strhex_ = (char *) zframe_strhex ((zframe_t *) self);
    jstring string = (*env)->NewStringUTF (env, strhex_);
    zstr_free (&strhex_);
    return string;
}

JNIEXPORT jstring JNICALL
Java_zframe__1_1strdup (JNIEnv *env, jclass c, jlong self)
{
    char *strdup_ = (char *) zframe_strdup ((zframe_t *) self);
    jstring string = (*env)->NewStringUTF (env, strdup_);
    zstr_free (&strdup_);
    return string;
}

JNIEXPORT jboolean JNICALL
Java_zframe__1_1streq (JNIEnv *env, jclass c, jlong self, jstring string)
{
    char *string_ = (char *) (*env)->GetStringUTFChars (env, string, NULL);
    jboolean streq_ = (jboolean) zframe_streq ((zframe_t *) self, string_);
    (*env)->ReleaseStringUTFChars (env, string, string_);
    return streq_;
}

JNIEXPORT jint JNICALL
Java_zframe__1_1more (JNIEnv *env, jclass c, jlong self)
{
    jint more_ = (jint) zframe_more ((zframe_t *) self);
    return more_;
}

JNIEXPORT void JNICALL
Java_zframe__1_1set_more (JNIEnv *env, jclass c, jlong self, jint more)
{
    zframe_set_more ((zframe_t *) self, (int) more);
}

JNIEXPORT jint JNICALL
Java_zframe__1_1routing_id (JNIEnv *env, jclass c, jlong self)
{
    jint routing_id_ = (jint) zframe_routing_id ((zframe_t *) self);
    return routing_id_;
}

JNIEXPORT void JNICALL
Java_zframe__1_1set_routing_id (JNIEnv *env, jclass c, jlong self, jint routing_id)
{
    zframe_set_routing_id ((zframe_t *) self, (uint32_t) routing_id);
}

JNIEXPORT jboolean JNICALL
Java_zframe__1_1eq (JNIEnv *env, jclass c, jlong self, jlong other)
{
    jboolean eq_ = (jboolean) zframe_eq ((zframe_t *) self, (zframe_t *) other);
    return eq_;
}

JNIEXPORT void JNICALL
Java_zframe__1_1reset (JNIEnv *env, jclass c, jlong self, jbyteArray data, jlong size)
{
    byte *data_ = (byte *) (*env)->GetByteArrayElements (env, data, 0);
    zframe_reset ((zframe_t *) self, data_, (size_t) size);
    (*env)->ReleaseByteArrayElements (env, data, (jbyte *) data_, 0);
}

JNIEXPORT void JNICALL
Java_zframe__1_1print (JNIEnv *env, jclass c, jlong self, jstring prefix)
{
    char *prefix_ = (char *) (*env)->GetStringUTFChars (env, prefix, NULL);
    zframe_print ((zframe_t *) self, prefix_);
    (*env)->ReleaseStringUTFChars (env, prefix, prefix_);
}

JNIEXPORT jboolean JNICALL
Java_zframe__1_1is (JNIEnv *env, jclass c, jlong self)
{
    jboolean is_ = (jboolean) zframe_is ((void *) self);
    return is_;
}

JNIEXPORT void JNICALL
Java_zframe__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zframe_test ((bool) verbose);
}

