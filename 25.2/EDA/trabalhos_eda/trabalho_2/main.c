#include <stdio.h>
#include <stdlib.h>

typedef struct aresta Aresta;

struct aresta{
    int   index_verticie_conectado; // vértice vizinho (1..10)
    float peso;                     // peso da aresta
    Aresta* prox_verticie;          // próximo nó da lista
}; 

// Insere aresta dirigida u -> v com peso 'peso'
// OBS: vértices são 1..10, vetor é 0..9 (por isso u-1)
void insere_aresta(Aresta* lista_verticies[], int u, int v, float peso)
{   
    Aresta* verticie_atual = lista_verticies[u-1];

    if (verticie_atual == NULL)
    {
        verticie_atual = (Aresta*)malloc(sizeof(Aresta));
        if (verticie_atual == NULL)
        {
            printf("Erro ao alocar memória para o verticie atual\n");
            exit(1);
        }

        verticie_atual->index_verticie_conectado = v;
        verticie_atual->peso = peso;
        verticie_atual->prox_verticie = NULL;

        lista_verticies[u-1] = verticie_atual;
    }
    else
    {
        Aresta* novo_vertice = (Aresta*)malloc(sizeof(Aresta));
        if (novo_vertice == NULL)
        {
            printf("Erro ao alocar memória para novo_vertice\n");
            exit(1);
        }

        novo_vertice->index_verticie_conectado = v;
        novo_vertice->peso = peso;
        novo_vertice->prox_verticie = verticie_atual;
        
        lista_verticies[u-1] = novo_vertice; 
    }
}

// Imprime a lista de adjacências
void imprime_grafo(Aresta* grafo[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Vetor (Vertice = %d):  ", i);

        Aresta* p = grafo[i-1];   // porque você usa u-1 no armazenamento

        if (p == NULL) {
            printf("(sem vizinhos)\n");
            continue;
        }

        printf("vizinhos -> ");
        while (p != NULL)
        {
            printf("%d(peso=%.0f) -> ", p->index_verticie_conectado, p->peso);
            p = p->prox_verticie;
        }

        printf("NULL\n");
    }
    printf("\n");
}

// BFS a partir de 'origem' (vértice 1..n)
// Imprime a ordem de visita
void bfs(Aresta* grafo[], int n, int origem)
{
    int visitado[11] = {0};
    int fila[100];           // fila simples
    int ini = 0, fim = 0;

    visitado[origem] = 1;
    fila[fim++] = origem;

    printf("BFS a partir do vertice %d: ", origem);

    while (ini < fim)
    {
        int u = fila[ini++];  
        printf("%d ", u);

        Aresta* p = grafo[u-1];  // u-1 por causa do vetor 0..9
        while (p != NULL)
        {
            int v = p->index_verticie_conectado;
            if (!visitado[v])
            {
                visitado[v] = 1;
                fila[fim++] = v;
            }
            p = p->prox_verticie;
        }
    }

    printf("\n\n");
}

// Dijkstra a partir de 'origem'
// devolve a menor distância de origem até cada vértice
void dijkstra(Aresta* grafo[], int n, int origem, float dist[])
{
    int usado[11] = {0};   // 1..10
    const float INF = 1e9;

    // inicializa distâncias
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[origem] = 0.0f;

    for (int k = 1; k <= n; k++)
    {
        int u = -1;
        float melhor = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!usado[i] && dist[i] < melhor)
            {
                melhor = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // não há mais alcançáveis
        usado[u] = 1;

        Aresta* p = grafo[u-1];
        while (p != NULL)
        {
            int v = p->index_verticie_conectado;
            float w = p->peso;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }

            p = p->prox_verticie;
        }
    }
}

int main(void)
{
    // Lista de Adjacências: 10 vértices => índices 0..9
    Aresta* grafo[10] = {
        NULL,NULL,NULL,NULL,NULL,
        NULL,NULL,NULL,NULL,NULL
    };

    // Vertice Num 1
    insere_aresta(grafo, 1, 3, 3.0f);
    insere_aresta(grafo, 1, 10, 1.0f);
    insere_aresta(grafo, 1, 8, 3.0f);
    insere_aresta(grafo, 1, 5, 4.0f);
    insere_aresta(grafo, 1, 9, 3.0f);

    // Vertice Num 2
    insere_aresta(grafo, 2, 3, 4.0f);
    insere_aresta(grafo, 2, 10, 1.0f);

    // Vertice Num 3
    insere_aresta(grafo, 3, 2, 4.0f);
    insere_aresta(grafo, 3, 10, 4.0f);
    insere_aresta(grafo, 3, 8, 2.0f);
    insere_aresta(grafo, 3, 4, 1.0f);
    insere_aresta(grafo, 3, 6, 1.0f);
    insere_aresta(grafo, 3, 9, 4.0f);
    insere_aresta(grafo, 3, 1, 3.0f);

    // Vertice Num 4
    insere_aresta(grafo, 4, 3, 1.0f);
    insere_aresta(grafo, 4, 5, 2.0f);
    insere_aresta(grafo, 4, 7, 2.0f);

    // Vertice Num 5
    insere_aresta(grafo, 5, 8, 4.0f);
    insere_aresta(grafo, 5, 1, 4.0f);
    insere_aresta(grafo, 5, 4, 2.0f);
    insere_aresta(grafo, 5, 7, 2.0f);
    
    // Vertice Num 6
    insere_aresta(grafo, 6, 3, 1.0f);
    insere_aresta(grafo, 6, 7, 3.0f);

    // Vertice Num 7
    insere_aresta(grafo, 7, 6, 3.0f);
    insere_aresta(grafo, 7, 4, 2.0f);
    insere_aresta(grafo, 7, 5, 2.0f);

    // Vertice Num 8
    insere_aresta(grafo, 8, 10, 2.0f);
    insere_aresta(grafo, 8, 3, 2.0f);
    insere_aresta(grafo, 8, 1, 3.0f);
    insere_aresta(grafo, 8, 9, 1.0f);
    insere_aresta(grafo, 8, 5, 4.0f);

    // Vertice Num 9
    insere_aresta(grafo, 9, 1, 3.0f);
    insere_aresta(grafo, 9, 3, 4.0f);
    insere_aresta(grafo, 9, 10, 4.0f);
    insere_aresta(grafo, 9, 8, 1.0f);

    // Vertice Num 10
    insere_aresta(grafo, 10, 2, 1.0f);
    insere_aresta(grafo, 10, 3, 4.0f);
    insere_aresta(grafo, 10, 1, 1.0f);
    insere_aresta(grafo, 10, 9, 4.0f);
    insere_aresta(grafo, 10, 8, 2.0f);

    // imprime lista de adjacência
    imprime_grafo(grafo, 10);

    // BFS a partir do vértice 3
    bfs(grafo, 10, 3);

    // Dijkstra a partir do vértice 3
    float dist[11];
    dijkstra(grafo, 10, 3, dist);

    printf("Menores distancias a partir do vertice 3:\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("3 -> %d = %.0f\n", i, dist[i]);
    }

    return 0;
}
