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

int file_select(const struct direct *entry) {
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
        return (FALSE);
    else
        return (TRUE);
}

void listar_diretorio(char *pathname, int level) {
    int count, i;
    struct direct **files;

    count = scandir(pathname, &files, file_select, alphasort);
    if (count <= 0) return;

    for (i = 0; i < count; i++) {
        char tempPath[MAXPATHLEN];
        struct stat buf;

        strcpy(tempPath, pathname);
        strcat(tempPath, "/");
        strcat(tempPath, files[i]->d_name);

        stat(tempPath, &buf);

        if (files[i]->d_type == DT_DIR) {
            // Diretório: imprime com colchetes e entra recursivamente
            printf("%*s[%s]\n", level * 2, "", files[i]->d_name);
            listar_diretorio(tempPath, level + 1);
        } else {
            // Arquivo comum: imprime com indentação
            printf("%*s%s\n", level * 2, "", files[i]->d_name);
        }

        free(files[i]);
    }
    free(files);
}

int main() {
    char pathname[MAXPATHLEN];

    if (getwd(pathname) == NULL) {
        printf("Error getting path\n");
        return 1;
    }

    // Pega só o nome do diretório atual para exibir na raiz
    char *dirname = strrchr(pathname, '/');
    dirname = dirname ? dirname + 1 : pathname;

    printf("[%s]\n", dirname);
    listar_diretorio(pathname, 1);

    return 0;
}