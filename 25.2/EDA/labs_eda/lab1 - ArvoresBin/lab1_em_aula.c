// Calcular o n-ésimo termo da série de Fibonacci de forma iterativa e recursiva.

// Série de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, ...

// Comparar os tempos de execução das funções, indicando a menos eficiente e justificando porque você acha que ela é menos eficiente. Essa comparação deve constar do relatório (em .pdf). Faça uma comparação gráfica dos tempos de execução para diferentes números de termos.

// Para comparar o tempo de execução das funções use a biblioteca time.h, função time ou a função gettimeofday (essa não é da time.h). Consulte a web para conhecer o uso destas funções.


#include <stdio.h>
#include <time.h>


int fibonacci_interativa(int num_termos)
{

    int num_ant = 0, num_pos = 1, num_atual = 0;

    if (num_termos == 0) return 0;
    if (num_termos == 1) return 1;

    for(int i = 2; i < num_termos; i++)
    {
        num_atual = num_ant + num_pos;

        num_ant = num_pos;

        num_pos = num_atual;
       
    }

    return num_atual;
}


int fibonacci_recursiva(int num_termos)
{
    
    if (num_termos == 0)
    {
        return 0;
    }
    else if (num_termos == 1)
    {
        return 1;  
    } 
    else
    {
        return fibonacci_recursiva(num_termos-1) + fibonacci_recursiva(num_termos-2);
    }
}



int main(void)
{

    int n = 45;
    int resultado;
    clock_t inicio, fim;
    double tempo;

    // --- Iterativa ---
    inicio = clock();
    resultado = fibonacci_interativa(n);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Iterativa: F(%d) = %d, tempo = %f segundos\n", n, resultado, tempo);

    // --- Recursiva ---
    inicio = clock();
    resultado = fibonacci_recursiva(n);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Recursiva: F(%d) = %d, tempo = %f segundos\n", n, resultado, tempo);

    return 0;
}




//    // --- Iterativa ---
//    inicio = time(NULL);
//    resultado = fibonacci_interativa(n);
//    fim = time(NULL);
//    tempo = difftime(fim, inicio); // diferença em segundos
//    printf("Iterativa: F(%d) = %d, tempo = %.0f segundos\n", n, resultado, tempo);

//    // --- Recursiva ---
//    inicio = time(NULL);
//    resultado = fibonacci_recursiva(n);
//    fim = time(NULL);
//    tempo = difftime(fim, inicio);
//    printf("Recursiva: F(%d) = %d, tempo = %.0f segundos\n", n, resultado, tempo);