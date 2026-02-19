#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct paciente Paciente;
typedef struct fila Fila;
struct paciente
{
    char status;
    int ordem;
    char* cor_prioridade;
    Paciente *prox;
};


struct fila
{
    Paciente* p_incial;
};




//Cabeçalho
Fila* criaFila();
Paciente* insere(Fila* fila, char* cor_prioridade, int ordem, char status);
void removePaciente(Fila* fila, int ordem, char status);
void imprimeFila(Fila* fila);

int main(void)
{
    Fila* fila = criaFila();

    FILE* arqEntrada = fopen("entrada.txt", "rt");
    if(arqEntrada == NULL)
    {
        printf("Erro ao abrir arquivo");
        fclose(arqEntrada);
        exit(1);
    }
    

    char status;
    int ordem;
    char cor_prioridade[18];
    while (fscanf(arqEntrada, " %c-%d-%17s", &status, &ordem, cor_prioridade) == 3) {
        if(status == 'c')
        {
            printf("Elemento: (%c-%d-%s) entrou na fila!\n", status, ordem, cor_prioridade);
            insere(fila, cor_prioridade, ordem, status);
            imprimeFila(fila);
            printf("\n");
        }
        else if(status == 'a')
        {   
            printf("Elemento: (%c-%d-%s) saiu na fila!\n", status, ordem, cor_prioridade);
            removePaciente(fila, ordem, status);
            imprimeFila(fila);
            printf("\n");
        }
        
    }
    fclose(arqEntrada);
    return 0;
}


Fila* criaFila()
{
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if(fila == NULL)
    {
        printf("Erro ao aolcar memoria para a fila de pacientes");
        exit(1);
    }

    fila->p_incial = NULL;

    return fila;
}


Paciente* insere(Fila* fila, char* cor_prioridade, int ordem, char status)
{
    Paciente* novo_paceinte = (Paciente*)malloc(sizeof(Paciente));
    if(novo_paceinte == NULL)
    {
        printf("Erro ao aolcar memoria para novo paciente");
        exit(1);
    }

    novo_paceinte->status = status;
    novo_paceinte->ordem = ordem;
    int tam_str_cor = strlen(cor_prioridade);
    novo_paceinte->cor_prioridade = (char*)malloc((tam_str_cor+1)*sizeof(char));
    if (novo_paceinte->cor_prioridade == NULL) {
        printf("Erro ao aolcar memoria para cor_prioridade");
        free(novo_paceinte);
        exit(1);
    }
    strcpy(novo_paceinte->cor_prioridade, cor_prioridade);
    novo_paceinte->prox = NULL;

    //Criei o paceinte acima 57-73

    
    if(fila->p_incial == NULL)//Se a fila não tem primeiro elemento é porque está vazia
    {
        fila->p_incial = novo_paceinte; //Add o primeiro
        return novo_paceinte;
    }

    int prio_novo = (strcmp(novo_paceinte->cor_prioridade, "vermelha") == 0) ? 3 : (strcmp(novo_paceinte->cor_prioridade, "amarela") == 0) ? 2 : 1; //Calcula a prioridade do novo paciente

    Paciente* no_pai = NULL;
    Paciente* p = fila->p_incial;
    while (p != NULL)
    {
        int prio_p = (strcmp(p->cor_prioridade, "vermelha") == 0) ? 3 : (strcmp(p->cor_prioridade, "amarela") == 0) ? 2 : 1; //Calcula a prioridade do paciente atual na fila

        if(prio_p > prio_novo || (prio_p == prio_novo && p->ordem <= novo_paceinte->ordem))
        {
            no_pai = p;
            p = p->prox;
            continue;   
        }
        break;
    }

    if(no_pai == NULL) //Insere na frente
    {
        novo_paceinte->prox = fila->p_incial;
        fila->p_incial = novo_paceinte;
    }

    else
    {
        novo_paceinte->prox = p;
        no_pai->prox = novo_paceinte;
    }   

    return novo_paceinte;

}

void removePaciente(Fila* fila, int ordem, char status) {
    Paciente *pai = NULL, *p = fila->p_incial;
    
    // Procurar o paciente pela ordem
    while (p != NULL && p->ordem != ordem) {
        pai = p;        // pai fica ATRÁS de p
        p = p->prox;
    }
    
    // Se encontrou o paciente
    if (p != NULL) {
        if (pai == NULL) {
            // Remover primeiro nó
            fila->p_incial = p->prox;
        } else {
            // Remover nó do meio/fim
            pai->prox = p->prox;
        }
        
        free(p->cor_prioridade);
        free(p);
    }
}


void imprimeFila(Fila* fila)
{
    Paciente* p = fila->p_incial;
    if(fila->p_incial == NULL)
    {
        printf("Fila Vazia!");
        return;
    }

    while (p != NULL)
    {
        printf("%d - %s\n", p->ordem, p->cor_prioridade);
        p = p->prox;
    }
    return;
}
