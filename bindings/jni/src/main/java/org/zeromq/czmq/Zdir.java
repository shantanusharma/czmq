/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
package org.zeromq.czmq;

public class Zdir implements AutoCloseable {
    static {
        try {
            System.loadLibrary ("czmqjni");
        }
        catch (Exception e) {
            System.exit (-1);
        }
    }
    long self;

    /*
    Create a new directory item that loads in the full tree of the specified
    path, optionally located under some parent path. If parent is "-", then 
    loads only the top-level directory, and does not use parent as a path.  
    */
    native static long __init (String path, String parent);
    public Zdir (String path, String parent) {
        /*  TODO: if __init fails, self is null...  */
        self = __init (path, parent);
    }
    /*
    Destroy a directory tree and all children it contains.
    */
    native static void __destroy (long self);
    @Override
    public void close() {
        __destroy (self);
        self = 0;
    }
    /*
    Return directory path
    */
    native static String __path (long self);
    public String path (long self) {
        return Zdir.__path (self);
    }
    /*
    Return last modification time for directory.
    */
    native static long __modified (long self);
    public long modified (long self) {
        return Zdir.__modified (self);
    }
    /*
    Return total hierarchy size, in bytes of data contained in all files
    in the directory tree.                                              
    */
    native static long __cursize (long self);
    public long cursize (long self) {
        return Zdir.__cursize (self);
    }
    /*
    Return directory count
    */
    native static long __count (long self);
    public long count (long self) {
        return Zdir.__count (self);
    }
    /*
    Returns a sorted list of zfile objects; Each entry in the list is a pointer
    to a zfile_t item already allocated in the zdir tree. Do not destroy the   
    original zdir tree until you are done with this list.                      
    */
    native static Zlist __list (long self);
    public Zlist list (long self) {
        return Zdir.__list (self);
    }
    /*
    Remove directory, optionally including all files that it contains, at  
    all levels. If force is false, will only remove the directory if empty.
    If force is true, will remove all files and all subdirectories.        
    */
    native static void __remove (long self, boolean force);
    public void remove (long self, boolean force) {
        return Zdir.__remove (self, force);
    }
    /*
    Calculate differences between two versions of a directory tree.    
    Returns a list of zdir_patch_t patches. Either older or newer may  
    be null, indicating the directory is empty/absent. If alias is set,
    generates virtual filename (minus path, plus alias).               
    */
    native static Zlist __diff (Zdir older, Zdir newer, String alias);
    public Zlist diff (Zdir older, Zdir newer, String alias) {
        return Zdir.__diff (older, newer, alias);
    }
    /*
    Return full contents of directory as a zdir_patch list.
    */
    native static Zlist __resync (long self, String alias);
    public Zlist resync (long self, String alias) {
        return Zdir.__resync (self, alias);
    }
    /*
    Load directory cache; returns a hash table containing the SHA-1 digests
    of every file in the tree. The cache is saved between runs in .cache.  
    */
    native static Zhash __cache (long self);
    public Zhash cache (long self) {
        return Zdir.__cache (self);
    }
    /*
    Print contents of directory to stdout
    */
    native static void __print (long self, int indent);
    public void print (long self, int indent) {
        return Zdir.__print (self, indent);
    }
    /*
    Create a new zdir_watch actor instance:                       
                                                                  
        zactor_t *watch = zactor_new (zdir_watch, NULL);          
                                                                  
    Destroy zdir_watch instance:                                  
                                                                  
        zactor_destroy (&watch);                                  
                                                                  
    Enable verbose logging of commands and activity:              
                                                                  
        zstr_send (watch, "VERBOSE");                             
                                                                  
    Subscribe to changes to a directory path:                     
                                                                  
        zsock_send (watch, "ss", "SUBSCRIBE", "directory_path");  
                                                                  
    Unsubscribe from changes to a directory path:                 
                                                                  
        zsock_send (watch, "ss", "UNSUBSCRIBE", "directory_path");
                                                                  
    Receive directory changes:                                    
        zsock_recv (watch, "sp", &path, &patches);                
                                                                  
        // Delete the received data.                              
        free (path);                                              
        zlist_destroy (&patches);                                 
    */
    native static void __watch (Zsock pipe, void * unused);
    public void watch (Zsock pipe, void * unused) {
        return Zdir.__watch (pipe, unused);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public void test (boolean verbose) {
        return Zdir.__test (verbose);
    }
}
