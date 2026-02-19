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

    Type t;
    Valor val;

};
typedef struct var Var;


Var criaInteiro(int i);
Var criaReal(double r);
Var criaString(char* s);
void imprime(int n, Var* v);
int busca(int n, Var *v, Var x);
void liberaMemoria(int n, Var* v);


int main(void)
{

    Var vetor[5];

    vetor[0] = criaInteiro(2);
    vetor[1] = criaInteiro(3);
    vetor[2] = criaReal(2.3);
    vetor[3] = criaString("alo");
    vetor[4] = criaReal(5.3);
    

    imprime(5, vetor);

    int n;

    Var x;
    x.t = T_INT;
    x.val.i = 2;

    n = busca(5, vetor, x);

    if(n != -1) printf("O index desse elemento eh: %d", n);
    else printf("Nao ha niguem igual ao elemento que voce procura");

    liberaMemoria(5,vetor);

    return 0;
}

Var criaInteiro(int i)
{
    Var v;
    v.t = T_INT;
    v.val.i = i;
    return v;
}

Var criaReal(double r)
{
    Var v;
    v.t = T_DOUBLE;
    v.val.r = r;
    return v;
}


Var criaString(char* s)
{
    int tamStr = strlen(s);
    Var v;
    v.t = T_STRING;
    v.val.s = (char*)malloc((tamStr+1)*sizeof(char));
    strcpy(v.val.s,s);
    return v;
}

void imprime(int n, Var* v)
{
    
    for(int i = 0; i < n; i++)
    {
        switch (v[i].t)
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


int busca(int n, Var *v, Var x)
{

    for(int i = 0; i < n; i++)
    {

        if(v[i].t == x.t)
        {
            switch (v[i].t)
            {
            case T_INT:
                if(v[i].val.i == x.val.i) return i;
                break;
            case T_DOUBLE:
                if(v[i].val.r == x.val.r) return i;
                break;
            case T_STRING:
                if(strcmp(v[i].val.s, x.val.s) == 0) return i;
                break;
            default:
                break;
            }
        
        }
    }
    return -1;
}

void liberaMemoria(int n, Var* v)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i].t == T_STRING)
        {
            free(v[i].val.s);
        }
    }
}