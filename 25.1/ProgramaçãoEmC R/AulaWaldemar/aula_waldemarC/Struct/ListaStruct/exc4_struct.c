#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct produto
{

    int cod;
    char nome[15];
    float preco;
    int quantiade;

};
typedef struct produto Produto;

struct pedido 
{
    int cod_produto;
    int quantidade;
};
typedef struct pedido Pedido;

Produto* criaProduto(int cod, char* nome, float preco, int quantidade);

int main(void)
{

   // ...existing code...

    // Preenchendo o vetor de pedidos diretamente:
    Pedido vetorDePedidos[8] = {
        {123, 10},    // Arroz, quantidade disponível
        {124, 5},     // Feijao, quantidade disponível
        {125, 60},    // Macarrao, quantidade igual ao estoque
        {126, 100},   // Acucar, quantidade maior que estoque
        {127, 1},     // Sal, quantidade disponível
        {128, 51},    // Cafe, quantidade maior que estoque
        {999, 1},     // Produto inexistente
        {130, 40}     // Oleo, quantidade igual ao estoque
    };

// ...remova ou comente o bloco do scanf...
// for(int i = 0; i < 8; i++) { ... }

    Produto* vetorDeProdutos[10];

    vetorDeProdutos[0] = criaProduto(123, "Arroz", 5.50, 100);
    vetorDeProdutos[1] = criaProduto(124, "Feijao", 7.20, 80);
    vetorDeProdutos[2] = criaProduto(125, "Macarrao", 4.00, 60);
    vetorDeProdutos[3] = criaProduto(126, "Acucar", 3.80, 90);
    vetorDeProdutos[4] = criaProduto(127, "Sal", 2.50, 120);
    vetorDeProdutos[5] = criaProduto(128, "Cafe", 8.90, 50);
    vetorDeProdutos[6] = criaProduto(129, "Leite", 4.70, 70);
    vetorDeProdutos[7] = criaProduto(130, "Oleo", 6.30, 40);
    vetorDeProdutos[8] = criaProduto(131, "Farinha", 3.60, 55);
    vetorDeProdutos[9] = criaProduto(132, "Biscoito", 2.80, 75);


    // for(int i = 0; i < 8; i++)
    // {

    //     printf("Digite um codigo para o produto %d: ", i+1);
    //     scanf("%d", &vetorDePedidos[i].cod_produto);

    //     printf("\n");

    //     printf("Digite uma quantiade para o produto %d: ", i+1);
    //     scanf("%d", &vetorDePedidos[i].quantidade);

    //     printf("\n\n");
    // }

    
    int encontrado;
    for(int i = 0; i < 8; i++)
    {

        printf("===================\n\n");

        Pedido pedidoAtual = vetorDePedidos[i];
        encontrado = 0;

        for(int j = 0; j < 10; j++)
        {
            Produto* produtoAtual = vetorDeProdutos[j];
            

            if(pedidoAtual.cod_produto == produtoAtual->cod)
            {
                encontrado = 1;
                if(pedidoAtual.quantidade <= produtoAtual->quantiade && produtoAtual->quantiade != 0)
                {

                    printf("O produto %s de cod %d tem a quantidade em estoque!\n", produtoAtual->nome, produtoAtual->cod);
                    produtoAtual->quantiade = produtoAtual->quantiade - pedidoAtual.quantidade; 

                }
                else 
                {

                    printf("Não possue estoque necessario para o produto %s de cod %d \n", produtoAtual->nome, produtoAtual->cod);

                }
                break;

            }
        }
        if(encontrado == 0)
        {

            printf("Não encontramos produto com esse codigo (%d)\n", pedidoAtual.cod_produto);
        }
    }
    return 0;
}

Produto* criaProduto(int cod, char* nome, float preco, int quantidade)
{
    Produto* nvProduto = (Produto*)malloc(sizeof(Produto));

    nvProduto->cod = cod;
    strcpy(nvProduto->nome, nome);
    nvProduto->preco = preco;
    nvProduto->quantiade = quantidade;

    return nvProduto;
}
