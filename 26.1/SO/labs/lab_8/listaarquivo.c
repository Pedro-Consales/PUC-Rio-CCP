#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
extern int alphasort();
char pathname[MAXPATHLEN];

#define FALSE 0
#define TRUE 1

int file_select(const struct direct *entry){
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
    return (FALSE);
    else
    return (TRUE);
}

int main() {
    int count,i;
    struct direct **files;
    int file_select();
    char pathname[100];
    

    if (getwd(pathname) == NULL ) {
        printf("Error getting path\n"); exit(0);
    }
    printf("Current Working Directory = %s\n",pathname);
    count = scandir( pathname, &files, file_select, alphasort);
    /* If no files found, make a non-selectable menu item */
    if (count <= 0) {
        printf("No files in this directory\n"); exit(0);
    }
    printf("Number of files = %d\n",count);
    for (i=1;i<count+1;++i) {
        char tempPath[MAXPATHLEN];
        struct stat buf;

        strcpy(tempPath, pathname);
        strcat(tempPath, "/");
        strcat(tempPath, files[i-1]->d_name);

        stat(tempPath, &buf);

        printf("%s\tinode %ld\tsize: %ld\tage: %ld days\n", files[i-1]->d_name, files[i-1]->d_ino, buf.st_size, (long)(difftime(buf.st_ctime, time(NULL))/86400));
    }
    printf("\n"); /* flush buffer */

    for (i=1;i<count+1;++i){
        free(files[i]);
    }
    free(files);

    return 0;
}