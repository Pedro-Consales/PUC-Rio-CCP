#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>


#define DB_SIZE    1000
#define CACHE_SIZE 100
#define LOG_FILE   "log.txt"

#define DB_DELAY_US 500   // 0.5ms por acesso pode diminuir para ir mais rápido


typedef struct {
    int    key;  // chave do registro (0..999)
    int    value;   // valor armazenado
    time_t timestamp;  // quando foi gravado/acessado
} CacheEntry;


int        banco[DB_SIZE]; // banco de dados simulado
CacheEntry cache[CACHE_SIZE];  // array do cache
int        cache_valido[CACHE_SIZE]; // 1 = slot ocupado, 0 = vazio


long hits   = 0;
long misses = 0;
long total  = 0;

// Flag para indicar que o cache foi limpo via sinal (volatile para ler sempre direto da memória)
volatile int cache_limpo_flag = 0;




void db_init() {
    for (int i = 0; i < DB_SIZE; i++) {
        banco[i] = i + 1;  
    }
    printf("[DB] Banco de dados inicializado com %d entradas.\n", DB_SIZE);
}


int db_read(int key) {
    if (key < 0 || key >= DB_SIZE) return -1;
    usleep(DB_DELAY_US);
    return banco[key];
}


void db_write(int key, int new_value) {
    if (key < 0 || key >= DB_SIZE) return;
    usleep(DB_DELAY_US); 
    banco[key] = new_value;
}



// Inicializa o cache (marca todos os slots como inválidos)
void cache_init() {
    memset(cache_valido, 0, sizeof(cache_valido));
    printf("[CACHE] Cache inicializado (%d entradas).\n", CACHE_SIZE);
}

// Limpa o cache — chamada pelo sinal SIGUSR1
// Para limpar o cache: kill -SIGUSR1 <PID>
void cache_clear() {
    memset(cache_valido, 0, sizeof(cache_valido));
    printf("\n[CACHE] *** Cache limpo pelo sinal! ***\n");
    printf("[CACHE] Continuando a leitura do banco diretamente...\n\n");
}

// Calcula o índice no cache para uma dada key
int cache_index(int key) {
    return key % CACHE_SIZE;
}

// Tenta ler do cache. Retorna 1 (HIT) ou 0 (MISS).
int cache_get(int key, int *out_value) {
    int idx = cache_index(key);

    if (cache_valido[idx] && cache[idx].key == key) {

        *out_value = cache[idx].value;
        cache[idx].timestamp = time(NULL);
        return 1;  
    }
    return 0; 
}

// Insere ou atualiza uma entrada no cache
void cache_put(int key, int value) {
    int idx = cache_index(key);

    cache[idx].key       = key;
    cache[idx].value     = value;
    cache[idx].timestamp = time(NULL);
    cache_valido[idx]    = 1;
}

// Invalida (remove) uma entrada específica do cache
void cache_invalidate(int key) {
    int idx = cache_index(key);
    if (cache_valido[idx] && cache[idx].key == key) {
        cache_valido[idx] = 0;
    }
}

// Handler do sinal SIGUSR1
// No macOS o Ctrl+Z é interceptado pelo terminal antes de chegar ao processo,
// por isso usamos SIGUSR1. Para disparar: kill -SIGUSR1 <PID>
void handler_sigusr1(int sig) {
    cache_clear();
    cache_limpo_flag = 1;
    signal(SIGUSR1, handler_sigusr1);
}


int cache_aside_read(int key) {
    int value;
    total++;

    if (cache_get(key, &value)) {
        hits++;
        return value;
    }

    misses++;
    value = db_read(key);
    cache_put(key, value);
    return value;
}

// Operação de ESCRITA com Cache-aside
void cache_aside_write(int key, int new_value) {
    total++;
    db_write(key, new_value);
    cache_invalidate(key);  
}


void processar_log() {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        perror("[ERRO] Não foi possível abrir log.txt");
        printf("       Execute log_gen primeiro para gerar o arquivo.\n");
        exit(1);
    }

    char   linha[64];
    char   linhas[10000][64];  
    int    total_linhas = 0;

    while (fgets(linha, sizeof(linha), fp) != NULL && total_linhas < 10000) {
        strncpy(linhas[total_linhas], linha, sizeof(linha));
        total_linhas++;
    }
    fclose(fp);

    printf("[LOG] %d operações carregadas do %s.\n\n", total_linhas, LOG_FILE);
    printf("[INFO] Para limpar o cache: kill -SIGUSR1 <PID>. Ctrl+C para sair.\n\n");

    int i = 0;

    while (1) {
        int key, value;

        if (cache_limpo_flag) {
            cache_limpo_flag = 0;
        }

        int resultado;
        if (sscanf(linhas[i], " R, %d", &key) == 1) {
            long hits_antes = hits;
            resultado = cache_aside_read(key);
            printf("[R] key=%d  valor=%d  [%s]  hits=%ld misses=%ld\n",
                   key, resultado,
                   (hits > hits_antes) ? "HIT" : "MISS",
                   hits, misses);

        } else if (sscanf(linhas[i], " W, %d, %d", &value, &key) == 2) {
            cache_aside_write(key, value);
            printf("[W] key=%d  novo_valor=%d  (banco atualizado, cache invalidado)\n",
                   key, value);
        }

        i = (i + 1) % total_linhas;

        usleep(100000);  // 100ms entre operações — prints mais lentos para acompanhar
    }
}


int main() {
    printf("=== Cache-aside Caching | Starting ===\n\n");

    // SIGUSR1 em vez de SIGTSTP pois no macOS o terminal intercepta o Ctrl+Z
    // Para limpar o cache pode rodar  em outro terminal: kill -SIGUSR1 $(pgrep exc2_exe)
    signal(SIGUSR1, handler_sigusr1);

    db_init();
    cache_init();

    printf("\n");

    processar_log();

    return 0;
}