#include<stdio.h>
#include<string.h>
#include<stdlib.h>


union valor
{
    int i;
    double r;
    char* s;
};
typedef union valor Valor;

enum type
{
    T_INT,
    T_DOUBLE,
    T_STRING
};
typedef enum type Type;


struct var
{
    char* nome;
    Type t;
    Valor val;
};
typedef struct var Sensores;

Sensores criaInteiro(char* nome, int i);
Sensores criaReal(char* nome, double r);
Sensores criaString(char* nome, char* status);
void imprimeSensores(int n, Sensores* v);
int buscaSensor(int n, Sensores* v, char* nome);
void liberaSensores(int n, Sensores* v);

int main(void)
{

    
    Sensores vetor[5];

    vetor[0] = criaInteiro("Sensor A", 100);
    vetor[1] = criaInteiro("Sensor B", 25);
    vetor[2] = criaReal("Sensor C", 23.5);
    vetor[3] = criaString("Sensor E", "OK");
    vetor[4] = criaReal("Sensor F", 5.3);
    

    imprimeSensores(5, vetor);

    int n;
    n = buscaSensor(5, vetor, "Sensor B");

    if(n != -1) printf("O index desse elemento eh: %d", n);
    else printf("Nao ha niguem igual ao elemento que voce procura");

    liberaSensores(5,vetor);

    return 0;
}


Sensores criaInteiro(char* nome, int i)
{
    int tamNome = strlen(nome); 
    Sensores sens;
    sens.nome = (char*)malloc((tamNome+1)*sizeof(char));
    if(sens.nome ==  NULL) exit(1);
    strcpy(sens.nome,nome); //Guarda o nome do sensor;
    sens.val.i = i;
    sens.t = T_INT;

    return sens;
}


Sensores criaReal(char* nome, double r)
{
    int tamNome = strlen(nome); 
    Sensores sens;
    sens.nome = (char*)malloc((tamNome+1)*sizeof(char));
    if(sens.nome ==  NULL) exit(1);
    strcpy(sens.nome,nome); //Guarda o nome do sensor;
    sens.val.r = r;
    sens.t = T_DOUBLE;

    return sens;
}


Sensores criaString(char* nome, char* status)
{
    int tamNome = strlen(nome); 
    Sensores sens;
    sens.nome = (char*)malloc((tamNome+1)*sizeof(char));
    if(sens.nome ==  NULL) exit(1);

    strcpy(sens.nome,nome); //Guarda o nome do sensor;
    
    sens.t = T_STRING;

    int tamStr = strlen(status);
    sens.val.s = (char*)malloc((tamStr+1)*sizeof(char));
    if(sens.val.s ==  NULL) exit(1);
    
    strcpy(sens.val.s, status);

    return sens;
}

void imprimeSensores(int n, Sensores* v)
{

    for(int i = 0; i < n; i++)
    {
        switch(v[i].t)
        {
            case T_INT:
                printf("%d\n", v[i].val.i);
            break;

            case T_DOUBLE:
                printf("%f\n", v[i].val.r);
            break;
            
            case T_STRING:
                printf("%s\n", v[i].val.s);
            break;
        }
    }
}


int buscaSensor(int n, Sensores* v, char* nome)
{

    for(int i = 0; i < n; i++)
    {
        if(strcmp(v[i].nome, nome) == 0) return i;
    }
    return -1;
}

void liberaSensores(int n, Sensores* v)
{
    for(int i = 0; i < n; i++)
    {
        free(v[i].nome);

        if(v[i].t == T_STRING)
            free(v[i].val.s);
    }
}
