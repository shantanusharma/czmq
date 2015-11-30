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
#include "../../native/include/org_zeromq_czmq_Zhash.h"

JNIEXPORT jlong JNICALL
Java_zhash__1_1new (JNIEnv *env, jclass c)
{
    jlong new_ = (jlong) zhash_new ();
    return new_;
}

JNIEXPORT void JNICALL
Java_zhash__1_1destroy (JNIEnv *env, jclass c, jlong self_p)
{
    zhash_destroy ((zhash_t **) &self_p);
}

JNIEXPORT jint JNICALL
Java_zhash__1_1insert (JNIEnv *env, jclass c, jlong self, jstring key, jlong item)
{
    char *key_ = (char *) (*env)->GetStringUTFChars (env, key, NULL);
    jint insert_ = (jint) zhash_insert ((zhash_t *) self, key_, (void *) item);
    (*env)->ReleaseStringUTFChars (env, key, key_);
    return insert_;
}

JNIEXPORT void JNICALL
Java_zhash__1_1update (JNIEnv *env, jclass c, jlong self, jstring key, jlong item)
{
    char *key_ = (char *) (*env)->GetStringUTFChars (env, key, NULL);
    zhash_update ((zhash_t *) self, key_, (void *) item);
    (*env)->ReleaseStringUTFChars (env, key, key_);
}

JNIEXPORT void JNICALL
Java_zhash__1_1delete (JNIEnv *env, jclass c, jlong self, jstring key)
{
    char *key_ = (char *) (*env)->GetStringUTFChars (env, key, NULL);
    zhash_delete ((zhash_t *) self, key_);
    (*env)->ReleaseStringUTFChars (env, key, key_);
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1lookup (JNIEnv *env, jclass c, jlong self, jstring key)
{
    char *key_ = (char *) (*env)->GetStringUTFChars (env, key, NULL);
    jlong lookup_ = (jlong) zhash_lookup ((zhash_t *) self, key_);
    (*env)->ReleaseStringUTFChars (env, key, key_);
    return lookup_;
}

JNIEXPORT jint JNICALL
Java_zhash__1_1rename (JNIEnv *env, jclass c, jlong self, jstring old_key, jstring new_key)
{
    char *old_key_ = (char *) (*env)->GetStringUTFChars (env, old_key, NULL);
    char *new_key_ = (char *) (*env)->GetStringUTFChars (env, new_key, NULL);
    jint rename_ = (jint) zhash_rename ((zhash_t *) self, old_key_, new_key_);
    (*env)->ReleaseStringUTFChars (env, old_key, old_key_);
    (*env)->ReleaseStringUTFChars (env, new_key, new_key_);
    return rename_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1size (JNIEnv *env, jclass c, jlong self)
{
    jlong size_ = (jlong) zhash_size ((zhash_t *) self);
    return size_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1dup (JNIEnv *env, jclass c, jlong self)
{
    jlong dup_ = (jlong) zhash_dup ((zhash_t *) self);
    return dup_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1keys (JNIEnv *env, jclass c, jlong self)
{
    jlong keys_ = (jlong) zhash_keys ((zhash_t *) self);
    return keys_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1first (JNIEnv *env, jclass c, jlong self)
{
    jlong first_ = (jlong) zhash_first ((zhash_t *) self);
    return first_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1next (JNIEnv *env, jclass c, jlong self)
{
    jlong next_ = (jlong) zhash_next ((zhash_t *) self);
    return next_;
}

JNIEXPORT jstring JNICALL
Java_zhash__1_1cursor (JNIEnv *env, jclass c, jlong self)
{
    char *cursor_ = (char *) zhash_cursor ((zhash_t *) self);
    jstring string = (*env)->NewStringUTF (env, cursor_);
    return string;
}

JNIEXPORT void JNICALL
Java_zhash__1_1comment (JNIEnv *env, jclass c, jlong self, jstring format)
{
    char *format_ = (char *) (*env)->GetStringUTFChars (env, format, NULL);
    zhash_comment ((zhash_t *) self, "%s", format_);
    (*env)->ReleaseStringUTFChars (env, format, format_);
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1pack (JNIEnv *env, jclass c, jlong self)
{
    jlong pack_ = (jlong) zhash_pack ((zhash_t *) self);
    return pack_;
}

JNIEXPORT jlong JNICALL
Java_zhash__1_1unpack (JNIEnv *env, jclass c, jlong frame)
{
    jlong unpack_ = (jlong) zhash_unpack ((zframe_t *) frame);
    return unpack_;
}

JNIEXPORT jint JNICALL
Java_zhash__1_1save (JNIEnv *env, jclass c, jlong self, jstring filename)
{
    char *filename_ = (char *) (*env)->GetStringUTFChars (env, filename, NULL);
    jint save_ = (jint) zhash_save ((zhash_t *) self, filename_);
    (*env)->ReleaseStringUTFChars (env, filename, filename_);
    return save_;
}

JNIEXPORT jint JNICALL
Java_zhash__1_1load (JNIEnv *env, jclass c, jlong self, jstring filename)
{
    char *filename_ = (char *) (*env)->GetStringUTFChars (env, filename, NULL);
    jint load_ = (jint) zhash_load ((zhash_t *) self, filename_);
    (*env)->ReleaseStringUTFChars (env, filename, filename_);
    return load_;
}

JNIEXPORT jint JNICALL
Java_zhash__1_1refresh (JNIEnv *env, jclass c, jlong self)
{
    jint refresh_ = (jint) zhash_refresh ((zhash_t *) self);
    return refresh_;
}

JNIEXPORT void JNICALL
Java_zhash__1_1autofree (JNIEnv *env, jclass c, jlong self)
{
    zhash_autofree ((zhash_t *) self);
}

JNIEXPORT void JNICALL
Java_zhash__1_1test (JNIEnv *env, jclass c, jboolean verbose)
{
    zhash_test ((bool) verbose);
}

