#include <stdio.h>
#include <stdlib.h>


//feito por
//Pedro Consales 2410238
//Gabriel Castro 2421177

// define o tamanho da tabela primo logo depois de 1200
#define TAM 1201

// constante usada para espalhar melhor as chaves no cálculo da hash
#define CONSTANTE 466

// função hash principal: método da divisão com constante multiplicativa
int hash_principal(long long chave) {
    // retorna o resto da divisão da multiplicação por CONSTANTE
    return (chave * CONSTANTE) % TAM;
}

// função hash secundária: usada no duplo hashing (evita agrupamento de colisões)
int hash_secundaria(long long chave) {
    // o +1 garante que o passo nunca será zero
    return 1 + (chave % (TAM - 1));
}

// inicializa a tabela colocando zeros (marca de posição vazia)
void inicializar(long long vetor[]) {
    for (int i = 0; i < TAM; i++) {
        vetor[i] = 0; // posição livre
    }
}

// insere uma nova chave na tabela usando endereçamento aberto com duplo hashing
void inserir(long long vetor[], long long chave, int *colisoes) {
    int pos_inicial = hash_principal(chave); // calcula o índice inicial
    int passo = hash_secundaria(chave);      // calcula o passo (incremento)
    int pos = pos_inicial;                   // posição corrente começa na inicial
    int tentativas = 0;                      // contador de tentativas (para o duplo hash)

    // enquanto a posição estiver ocupada, houve colisão
    while (vetor[pos] != 0) {
        (*colisoes)++;                       // incrementa o número total de colisões
        tentativas++;                        // incrementa a tentativa
        // fórmula clássica do duplo hash: h(x, k) = (h'(x) + k * h''(x)) mod m
        pos = (pos_inicial + tentativas * passo) % TAM;
    }

    vetor[pos] = chave; // achou posição livre → insere a chave
}

int main() {
    long long tabela[TAM];
    inicializar(tabela); // zera a tabela antes de usar

    // abre o arquivo com os CPFs (um por linha)
    FILE *arquivo = fopen("cpfs.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: não foi possível abrir o arquivo 'cpfs.txt'\n");
        return 1;
    }

    long long cpf_lido;          // variável para armazenar o CPF atual
    int total_chaves = 0;        // contador de quantas chaves já foram inseridas
    int total_colisoes = 0;      // contador global de colisões

    printf("Chaves Inseridas × Colisões\n\n");

    // lê o arquivo até o fim
    while (fscanf(arquivo, "%lld", &cpf_lido) == 1) {
        total_chaves++; // incrementa número de chaves
        inserir(tabela, cpf_lido, &total_colisoes); // insere na tabela

        // mostra o progresso a cada 100 inserções
        if (total_chaves % 100 == 0) {
            printf("Inseridas: %-4d | Colisões acumuladas: %d\n", total_chaves, total_colisoes);
        }
    }

    fclose(arquivo); // fecha o arquivo
    return 0;        // fim do programa
}
