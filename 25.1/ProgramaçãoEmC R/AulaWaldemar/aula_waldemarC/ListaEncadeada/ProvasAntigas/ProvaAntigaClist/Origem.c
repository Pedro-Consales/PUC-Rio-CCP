#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define ALPHA 26


typedef struct clist Clist;
struct clist
{
    char* nome;
    int id;
    float nota;
    Clist* prox;
};


typedef struct cadastro Cadastro;
struct cadastro
{

    Clist* lista[ALPHA];

};


Cadastro* criaCadastro(void);
int insere(Cadastro* c, char* nome, int id, float rating);
void exibeCadastro(Cadastro* c);
float averageRating(Cadastro* c);
void liberaCadastro(Cadastro* c);

int main(void)
{
    float media;
    Cadastro* a = criaCadastro();

    insere(a,"Fiona", 101, 2.0); 
    insere(a, "Zelda", 102, 5.0);
    insere(a, "Ada Lovelace", 103, 4.5);
    insere(a, "Fred", 104, 3.0);
    insere(a, "Ahsoka", 105, 5.0);
    insere(a, "Fani", 106, 4.0);

    exibeCadastro(a);

    media = averageRating(a);

    printf("\n\nAverageRating: %.2f\n\n", media);

    liberaCadastro(a);



    return 0;
}


Cadastro* criaCadastro(void)
{
    Cadastro* c = (Cadastro*)malloc(sizeof(Cadastro));
    if (c == NULL) {
        printf("Erro ao alocar memoria para cadastro");
        exit(1);
    }

    for (int i = 0; i < ALPHA; i++)
    {
        c->lista[i] = NULL;
    }

    return c;
}


int insere(Cadastro* c, char* nome, int id, float rating)
{
    Clist* p = (Clist*)malloc(sizeof(Clist));
    if (p == NULL) {
        printf("Erro ao alocar memoria para elemento");
        return 0;
    }
    int tamStr = strlen(nome);
    p->nome = (char*)malloc((tamStr + 1) * sizeof(char));
    if (p->nome == NULL) {
        printf("Erro ao alocar memoria para nome do elemento");
        return 0;
    }


    strcpy(p->nome, nome);// Se quiser que seja assim, tem que dar malloc, ou tem que estar alocado na struct
    p->id = id;
    p->nota = rating;

    p->prox = NULL;



    char letra = 'A';
    for (int i = 0; i < ALPHA; i++)
    {

        if (letra == nome[0])
        {
         
            Clist* l = c->lista[i];
            if (c->lista[i] == NULL)
                c->lista[i] = p;

            else
            {
                while (l->prox != NULL)
                    l = l->prox;

                l->prox = p;
            }

            break;
        }
        letra++;

    }
    return 1;
}



void exibeCadastro(Cadastro* c)
{

    char letra = 'A';
    for (int i = 0; i < ALPHA; i++)
    {
        Clist* p = c->lista[i];
        printf("%c:\n", letra);
        if (p != NULL)
        {
            while (p != NULL)
            {
                printf("    %s: %d %.1f\n", p->nome, p->id, p->nota);
                p = p->prox;
            }
        }
        letra++;
    }
}

float averageRating(Cadastro*c)
{
    int contElementos = 0;
    float soma = 0;
    for (int i = 0; i < ALPHA; i++)
    {
        Clist* p = c->lista[i];

        if (p != NULL)
        {
            while (p != NULL)
            {
                soma += p->nota;
                contElementos++;
                p = p->prox;
            }
        }
    }
    return soma / contElementos;
}


void liberaCadastro(Cadastro* c)
{
    Clist* p;
    for (int i = 0; i < ALPHA; i++)
    {
        p = c->lista[i];
        Clist* temp;
        while (p != NULL)
        {
                temp = p->prox;
                printf("Liberando o cadastro: %s\n", p->nome);
                free(p->nome);
                free(p);
                printf("Liberado!\n\n");

                p = temp;
        }
    }
    free(c);
    printf("\n\nTodos os cadastros liberados");
}