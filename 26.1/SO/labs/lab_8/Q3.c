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

long tamanho_diretorio(char* pathname){
    int count,i;
    struct direct **files;
    int file_select();

    printf("Current Working Directory = %s\n",pathname);
    count = scandir( pathname, &files, file_select, alphasort);
    /* If no files found, make a non-selectable menu item */
    if (count <= 0) {
        printf("No files in this directory\n"); return 0;
    }
    long size_tot = 0;
    for (i=1;i<count+1;++i) {
        char tempPath[MAXPATHLEN];
        struct stat buf;

        strcpy(tempPath, pathname);
        strcat(tempPath, "/");
        strcat(tempPath, files[i-1]->d_name);

        stat(tempPath, &buf);

        size_tot += buf.st_size;

        if(files[i-1]->d_type == DT_DIR){
            size_tot += tamanho_diretorio(tempPath);
        }
    }

    printf("tamanho somado até dir %s: %ld\n", pathname,size_tot);

    for (i=1;i<count+1;++i){
        free(files[i]);
    }
    free(files);

    return size_tot;
}

int main() {
    char pathname[MAXPATHLEN];
    

    if (getwd(pathname) == NULL ) {
        printf("Error getting path\n"); exit(0);
    }
    long size_tot = tamanho_diretorio(pathname);
    
    printf("tamanho total: %ld\n", size_tot);

    return 0;
    }