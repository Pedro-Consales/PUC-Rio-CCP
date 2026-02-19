#include<stdio.h>
#include<string.h>


int main(void)
{

    FILE* arqEntrada = fopen("arqvBixTex.txt", "r");
    if (arqEntrada == NULL)
        exit(1);

    char titulo[126];
    char autor[126];
    int nMax;
    int nMin;
    int year;

    //Maneira 1)
    // fscanf(arqEntrada, " %*[^\n]\n"); //Para cada linha que eu não quero ler eu tenho que fazer uma estapa de não armazenamento;  %*[^=]=
    // fscanf(arqEntrada, " author = { %[^}]},", autor);

    fscanf(arqEntrada, " %*[^=]= {%[^}]},", autor); // Não leia, até você encontrar um =, consoma o = e a paritr daí, leia até encontrar um }, consoma } e a vígula seguinte
    fscanf(arqEntrada, " %*[^=]= {%[^}]},", titulo);

    // fscanf(arqEntrada, " %*[^=]= {%*[^}]},");//Pula a linha toda //Existe outra lógica para pular a linha toda?
    // fscanf(arqEntrada, " %*[^=]= {%*[^}]},");//Pula a linha toda
    fscanf(arqEntrada, " %*[^\n]\n");
    fscanf(arqEntrada, " %*[^\n]\n");

    fscanf(arqEntrada, " %*[^=]= {%d-%d},", &nMin, &nMax);
    fscanf(arqEntrada, " %*[^=]= {%d},", &year);

    printf("%s\n\n", titulo);
    printf("%s, ", autor);
    printf("%d pages, ", (nMax - nMin));
    printf("%d", year);

    fclose(arqEntrada);

    return 0;
}