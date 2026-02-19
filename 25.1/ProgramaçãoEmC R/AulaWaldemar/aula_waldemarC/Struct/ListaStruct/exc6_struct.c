#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ingrediente 
{ 

    char nome[21]; 
    int qtd; 

} Ingrediente; 


typedef struct receita
{ 
    char nome[26]; 
    int n; 
    Ingrediente v[10]; 

} Receita;

Receita* criaReceita(char* nome, int n, Ingrediente** ingrediente);
Ingrediente* criaIngregiente(char* nome, int qtd);
void procuraReceita(Receita** vetorDeReceitas, int qtdReceitas);
void resetLista(Ingrediente** vetorDeIngredientes, int qtdIngredientes);
void procuraIngrediente(Receita** vetorDeReceitas, int qtdReceitas);

int main(void)
{   
    Receita* vetorReceitas[5];
    Ingrediente* vetorDeIngredientes[10];

    vetorDeIngredientes[0] =  criaIngregiente("Sal", 5);
    vetorDeIngredientes[1] =  criaIngregiente("Acucar", 2);
    vetorReceitas[0] = criaReceita("Bolo", 2, vetorDeIngredientes);

    resetLista(vetorDeIngredientes, 2);

    vetorDeIngredientes[0] = criaIngregiente("Mussarela", 5);
    vetorDeIngredientes[1] = criaIngregiente("Molho De Tomate", 1);
    vetorDeIngredientes[2] = criaIngregiente("Oregano", 2);
    vetorReceitas[1] = criaReceita("Pizza", 3, vetorDeIngredientes);

    resetLista(vetorDeIngredientes, 3);
    

    procuraReceita(vetorReceitas, 5);

    procuraIngrediente(vetorReceitas, 5);


    return 0;
}

Receita* criaReceita(char* nome, int n, Ingrediente** ingrediente)
{
    Receita* receita = (Receita*)malloc(sizeof(Receita));

    strcpy(receita->nome, nome);
    receita->n = n;

    for(int i = 0; i < n; i++)
    {
        strcpy(receita->v[i].nome, ingrediente[i]->nome); 
        receita->v[i].qtd = ingrediente[i]->qtd;
    }
    return receita;
}


Ingrediente* criaIngregiente(char* nome, int qtd)
{
    Ingrediente* ing = (Ingrediente*)malloc(sizeof(Receita));

    strcpy(ing->nome, nome);
    ing->qtd = qtd;

    return ing;
}

void procuraReceita(Receita** vetorDeReceitas, int qtdReceitas)
{
    char nome[50];
    printf("Digite o nome da receita que voce deseja procurar: ");
    scanf("%s", nome);

    printf("\n\n");

    for(int i = 0; i < qtdReceitas; i++)
    {
        Receita* recAtt = vetorDeReceitas[i]; //Receita atual
        if(strcmp(vetorDeReceitas[i]->nome, nome) == 0)
        {

            printf("Receita Encontrada!\n");
            printf("Nome: %s\n", recAtt->nome);
            printf("Quantiade de Ingredientes: %d\n\n", recAtt->n);
            printf("Ingredientes:\n");
            for(int j = 0; j < recAtt->n; j++)
            {
                printf("    '%s'\n", recAtt->v[j].nome);
                printf("    %d un\n\n", recAtt->v[i].qtd);
            };
            return;
        }
    }
    printf("Receita nao encontrada!");
    return;
}

void resetLista(Ingrediente** vetorDeIngredientes, int qtdIngredientes)
{
    for (int i = 0; i < qtdIngredientes; i++)
    {
        free(vetorDeIngredientes[i]);
    }

}

void procuraIngrediente(Receita** vetorDeReceitas, int qtdReceitas)
{
    char nome[50];
    printf("Digite o nome do ingrediente que voce deseja procurar: ");
    scanf("%s", nome);

    Receita** nvVetorDeReceitas = (Receita**)malloc(5*sizeof(Receita*));

    printf("\n\n");

    int k = 0;
    int existe = 0;
    for(int i = 0; i < qtdReceitas; i++)
    {
        Receita* recAtt = vetorDeReceitas[i]; //Receita atual
   
        for(int j = 0; j < recAtt->n; j++)
        {
            if(strcpy(recAtt->v[j].nome, nome) == 0)
            {
                printf("Encontrei");
                nvVetorDeReceitas[k] = recAtt;
                existe = 1;
                k++;
            }
        }
    }
    if(existe != 1)
    {
        printf("Não existe receita que utiliza o ingrediente %s", nome);
    }
    else
    {
        printf("Encontramos o ingrediente %s nas receitas de: \n", nome);
        for(int i = 0; i < (k+1); i++)
        {

            printf("A receita: %s\n", nvVetorDeReceitas[i]->nome);

        }

    }
}
