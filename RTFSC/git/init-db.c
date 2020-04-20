#include "cache.h"

int main(int argc, char **argv) {
    char *sha1_dir = getenv(DB_ENVIRONMENT), *path;
    int len, i, fd;

    /*
     * [BWbwchen]
     * check whether there was a .dircache exist
     */
    if (mkdir(".dircache", 0700) < 0) {
        perror("unable to create .dircache");
        exit(1);
    }

    /*
     * If you want to, you can share the DB area with any number of branches.
     * That has advantages: you can save space by sharing all the SHA1 objects.
     * On the other hand, it might just make lookup slower and messier. You
     * be the judge.
     */
    /*
     * [BWbwchen]
     * check whether there was a DB_ENVIRONMENT,
     * it means should it manage db with other by a dircache (?
     */
    sha1_dir = getenv(DB_ENVIRONMENT);
    if (sha1_dir) {
        struct stat st;
        if (!stat(sha1_dir, &st) < 0 && S_ISDIR(st.st_mode)) return;
        fprintf(stderr, "DB_ENVIRONMENT set to bad directory %s: ", sha1_dir);
    }

    /*
     * The default case is to have a DB per managed directory.
     */
    /*
     * [BWbwchen]
     * create cache directory
     */
    sha1_dir = DEFAULT_DB_ENVIRONMENT;
    fprintf(stderr, "defaulting to private storage area\n");
    len = strlen(sha1_dir);
    if (mkdir(sha1_dir, 0700) < 0) {
        if (errno != EEXIST) {
            perror(sha1_dir);
            exit(1);
        }
    }
    /*
     * [BWbwchen]
     * TODO: why malloc(len + 40), +40 ???
     * create lots of directory in .dircache/objects
     */
    path = malloc(len + 40);
    memcpy(path, sha1_dir, len);
    for (i = 0; i < 256; i++) {
        sprintf(path + len, "/%02x", i);
        if (mkdir(path, 0700) < 0) {
            if (errno != EEXIST) {
                perror(path);
                exit(1);
            }
        }
    }
    return 0;
}
