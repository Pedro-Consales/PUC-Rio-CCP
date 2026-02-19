//// 1. A avaliação de um vendedor de uma loja é mapeada no tipo estruturado Avaliacao abaixo:  
//
//// struct avaliacao 
//
//// {	float	valorVendidoNoMes; 
//
//// int	numeroDeFaltas; 
//
//// }; 
//
//// typedef  struct avaliacao  Avaliacao; 
//
//// Os dados de um vendedor são representados pelo tipo estruturado Vendedor abaixo: 
//
//// struct vendedor 
//
//// { 	int	 	inscricao; 
//
//// char  		nome[51]; 
//
//// float		salario_base; 
//
//// Avaliacao	aval; 
//
//// }; 
//
//// typedef struct  vendedor Vendedor; 
//
//
//
//// Escreva em C a função calculaExtra que recebe uma avaliação e retorna um valor (float) correspondente a um valor extra a ser acrescido ao salário
////  do vendedor no pagamento do mês. Esse valor extra deve ser computado da seguinte forma: 
//
//// Se o número de faltas é menor do que 2 e o valor vendido no mês é maior do que 2000, a função retorna 180. 
//
//// Se o número de faltas é maior ou igual a do 2 e menor do que 4 e o valor vendido é maior do que 2000, a função retorna 150. 
//
//// Se o número de faltas é maior ou igual a 4 e menor do que 6, mas o valor vendido é maior do que 5000, a função retorna 120. 
//
//// Do contrário a função retorna 0. 
//
//// Para a folha de pagamento da loja é utilizado um vetor de vendedores. Escreva em C a função calculaValorTotalDaFolha que recebe o número de vendedores e o vetor dos 
//// vendedores da loja e calcula qual o valor total que a loja deverá disponibilizar para pagamentos naquele mês, que será o resultado da soma dos valores a serem pagos 
//// a todos os vendedores (valor para cada vendedor: salario + extra). A função deve utilizar a função calculaExtra do item anterior. 
//
//// Escreva em C a função obtemRelacaoDemitidos, que recebe o número de vendedores e o vetor dos vendedores da loja e retorna um novo vetor de inteiros, alocado com o 
//// tamanho exato necessário, com as inscrições dos vendedores com número de faltas >= 10, que serão demitidos. A função deve também devolver em uma variável inteira, 
//// cujo endereço foi fornecido com argumento na chamada da função, o número de vendedores que serão demitidos. Caso não seja possível criar o novo vetor ou caso não 
//// existam vendedores com mais de 10 faltas, a função deve retornar NULL. 
//
//// Assumindo, para facilitar, que os valores vendidos no mês são todos diferentes, escreva a função obtemMelhorVendedor, que recebe o número de vendedores e o vetor 
//// dos vendedores da loja e retorna, sem alocar dinamicamente, nem usar qualquer outro vetor de char, um ponteiro para a cadeia contendo o nome do melhor vendedor da 
//// loja (o que tem o maior valor vendido no mês). 
//
//// Em seguida, implemente a função principal do programa utilizando como base a main definida abaixo.  
//
//// Text Box 
//
//
//
//
//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//struct avaliacao
//{
//    float valorVendidoNoMes;
//
//    int	numeroDeFaltas;
//
//};
//
//typedef  struct avaliacao  Avaliacao;
//
//
//struct vendedor
//{
//    int	 	inscricao;
//
//    char  		nome[51];
//
//    float		salario_base;
//
//    Avaliacao	aval;
//};
//
//typedef struct  vendedor Vendedor;
//
//
//
//
//float calculaExtra(Avaliacao aval) {
//
//    if ((aval.numeroDeFaltas) < 2 && (aval.valorVendidoNoMes > 2000)) {
//
//        return 180;
//
//    }
//    else if (((aval.numeroDeFaltas) >= 2 && (aval.numeroDeFaltas) < 4) && (aval.valorVendidoNoMes > 2000)) {
//
//        return 150;
//
//    }
//    else if (((aval.numeroDeFaltas >= 4) && (aval.numeroDeFaltas < 6)) && (aval.valorVendidoNoMes > 5000)) {
//
//        return 120;
//
//    }
//    else {
//
//        return 0;
//
//    }
//}
//
//
//float calculaValorTotalDaFolha(int qtdVendedores, Vendedor* vVendedor) {
//
//    int i;
//    float soma;
//
//    soma = 0.0;
//    for (i = 0; i < qtdVendedores; i++) {
//
//        soma = soma + (vVendedor[i].salario_base + calculaExtra(vVendedor[i].aval));
//
//    }
//
//    return soma;
//}
//
//
//int* obtemRelacaoDemitidos(int qtdVendedores, Vendedor* vVendedor, int* numDeDemitidos) {
//
//    int i;
//
//    int* vetorDemitidos;
//
//    int contadorDemitidos = 0;
//    for (i = 0; i < qtdVendedores; i++) {
//
//        if ((vVendedor[i].aval.numeroDeFaltas) >= 10) {
//
//            contadorDemitidos++;
//
//        }
//    }
//
//    if (contadorDemitidos == 0) {
//
//        *numDeDemitidos = 0;
//
//        return NULL;
//
//    }
//
//    *numDeDemitidos = contadorDemitidos;
//
//    vetorDemitidos = (int*)malloc(contadorDemitidos * sizeof(int));
//
//    int index = 0;
//    for (i = 0;i < qtdVendedores;i++) {
//
//        if (vVendedor[i].aval.numeroDeFaltas >= 10) {
//
//            vetorDemitidos[index] = vVendedor[i].inscricao;
//            index++;
//        }
//    }
//
//
//    return vetorDemitidos;
//
//}
//
//
//char* obtemMelhorVendedor(int qtdVendedores, Vendedor* vVendedor) {
//
//    int i;
//    char* nomeMelhorVendedor = vVendedor[0].nome;
//    int maiorValorVendido = vVendedor[0].aval.valorVendidoNoMes;
//
//    for (i = 1;i < qtdVendedores;i++) {
//
//        if (vVendedor[i].aval.valorVendidoNoMes > maiorValorVendido) {
//
//            maiorValorVendido = vVendedor[i].aval.valorVendidoNoMes;
//            nomeMelhorVendedor = vVendedor[i].nome;
//        }
//    }
//    return nomeMelhorVendedor;
//}
//
//
//
//int main(void) {
//
//
//    int i;
//    int* vetorDemitidos;
//    int qtdDemitidos;
//
//    Vendedor vVendedor[10] = { {1,"Ana Silva", 1000, {3000,1}},
//                            {2, "Pedro Duarte", 2000,{3010,3}},
//                            {3, "Joao Filho", 1000, {3020,4}},
//                            {4, "Maria Gomes", 3000, {3030,15}},
//                            {5, "Silvio Lins", 1000, {6000,15}},
//                            {6, "Marcia Morais",2000, {6010,3}},
//                            {7, "Bruno Rodrigues", 3000, {6020,4}},
//                            {8, "Thais Silva", 4000, {6030,7}},
//                            {9, "Ricardo Costa", 5000, {3040,7}},
//                            {10, "Julia Neves", 10000, {1000,0}} };
//
//    float receitaTotal = calculaValorTotalDaFolha(10, vVendedor);
//
//    printf("A receita total da empresa gasta sera de: %.2f R$\n", receitaTotal);
//
//    printf("\n");
//
//    vetorDemitidos = obtemRelacaoDemitidos(10, vVendedor, &qtdDemitidos);
//
//    printf("Os funcinados demitidos serao: ");
//    for (i = 0; i < qtdDemitidos; i++) {
//
//        printf("%d ", vetorDemitidos[i]);
//
//    }
//
//    printf("\n");
//
//    char* nomeMelhroVendedor = obtemMelhorVendedor(10, vVendedor);
//
//    printf("\nO melhor vendedor foi: %s", nomeMelhroVendedor);
//
//
//
//
//    return 0;
//
//}

//============================================================================================================================================================================================





// 2. COM PONTEIRO !!!!! A avaliação de um vendedor de uma loja é mapeada no tipo estruturado Avaliacao abaixo:  

// struct avaliacao 

// {	float	valorVendidoNoMes; 

// int	numeroDeFaltas; 

// }; 

// typedef  struct avaliacao  Avaliacao; 

// Os dados de um vendedor são representados pelo tipo estruturado Vendedor abaixo: 

// struct vendedor 

// { 	int	 	inscricao; 

// char  		nome[51]; 

// float		salário-base; 

// Avaliacao	aval; 

// }; 

// typedef struct  vendedor Vendedor; 





// Escreva em C a função calculaExtra que recebe uma avaliação e retorna um valor (float) correspondente a um valor extra a ser acrescido ao salário do 
// vendedor no pagamento do mês. Esse valor extra deve ser computado da seguinte forma: 


// Se o número de faltas é menor do que 2 e o valor vendido no mês é maior do que 2000, a função retorna 180. 


// Se o número de faltas é maior ou igual a do 2 e menor do que 4 e o valor vendido é maior do que 2000, a função retorna 150. 


// Se o número de faltas é maior ou igual a 4 e menor do que 6, mas o valor vendido é maior do que 5000, a função retorna 120. 


// Do contrário a função retorna 0. 



// Para a folha de pagamento da loja é utilizado um vetor de vendedores. Escreva em C a função calculaValorTotalDaFolha que recebe o 
// número de vendedores e o vetor dos vendedores da loja e calcula qual o valor total que a loja deverá disponibilizar para pagamentos naquele mês, 
// que será o resultado da soma dos valores a serem pagos a todos os vendedores (valor para cada vendedor : salario + extra). 
// A função deve utilizar a função calculaExtra do item anterior. 

// Escreva em C a função obtemRelacaoDemitidos, que recebe o número de vendedores e o vetor dos vendedores da loja e !!retorna um novo vetor de ponteiros 
// (endereços) para vendedores!!, alocado com o tamanho exato necessário, !!com os ponteiros (endereços) !! dos vendedores com número de faltas >= 10, que serão demitidos. 
// A função deve também devolver em uma variável inteira, cujo endereço foi fornecido com argumento na chamada da função, o número de vendedores que serão demitidos. 
// Caso não seja possível criar o novo vetor ou caso não existam vendedores com mais de 10 faltas, a função deve retornar NULL. 

// Assumindo, para facilitar, que os valores vendidos no mês são todos diferentes, escreva a função obtemMelhorVendedor, que recebe o número de vendedores e o
//  vetor dos vendedores da loja e retorna, sem alocar dinamicamente, nem usar qualquer outro vetor de char, um ponteiro para a cadeia contendo o nome do melhor 
//  vendedor da loja (o que tem o maior valor vendido no mês). 

// Em seguida, implemente a função principal do programa utilizando como base a main definida abaixo


//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//struct avaliacao
//{
//    float valorVendidoNoMes;
//
//    int	numeroDeFaltas;
//
//};
//
//typedef  struct avaliacao  Avaliacao;
//
//
//
//struct vendedor
//{
//    int	 	inscricao;
//
//    char  		nome[51];
//
//    float		salarioBase;
//
//    Avaliacao	aval;
//
//};
//
//typedef struct vendedor Vendedor;
//
//
//int calculaExtra(Avaliacao aval);
//float calculaValorTotalFolha(int qtdVededores, Vendedor* vetorVendedores);
//Vendedor** obtemRelacaoDemitido(int qtdVendedores, Vendedor* vetorVendedores, int* numDemitidos);
//char* obtemMelhorVendedor(int qtdVendedores, Vendedor* vVendedores);
//
//int main(void) {
//
//    Vendedor vVendedor[10] = { {1,"Ana Silva", 1000, {3000,1}},
//                               {2, "Pedro Duarte", 2000,{3010,3}},
//                               {3, "Joao Filho", 1000, {3020,4}},
//                               {4, "Maria Gomes", 3000, {3030,15}},
//                               {5, "Silvio Lins", 1000, {6000,15}},
//                               {6, "Marcia Morais",2000, {6010,3}},
//                               {7, "Bruno Rodrigues", 3000, {6020,4}},
//                               {8, "Thais Silva", 4000, {6030,7}},
//                               {9, "Ricardo Costa", 5000, {3040,7}},
//                               {10, "Julia Neves", 10000, {1000,0}} };
//
//
//    int numDemitidos;
//
//    float valorTotalFolha = calculaValorTotalFolha(10, vVendedor);
//
//    printf("O valor total da folha salarial da empresa eh: %.2f\n\n", valorTotalFolha);
//
//    Vendedor** demitidos = obtemRelacaoDemitido(10, vVendedor, &numDemitidos);
//
//    int i;
//
//    for (i = 0;i < numDemitidos;i++) {
//
//        printf("O nome do demitido eh: %s\n", demitidos[i]->nome);
//
//    }
//
//    char* nomeMelhorVendedor = obtemMelhorVendedor(10, vVendedor);
//
//
//    printf("O nome do melhor vendedor eh: %s\n\n", nomeMelhorVendedor);
//
//}
//
//
//
//int calculaExtra(Avaliacao aval) {
//
//    if (aval.numeroDeFaltas < 2) {
//        if (aval.valorVendidoNoMes > 2000) {
//
//            return 180;
//
//        }
//    }
//    else if (aval.numeroDeFaltas < 4) {
//        if (aval.valorVendidoNoMes > 2000) {
//
//            return 150;
//
//        }
//    }
//    else if (aval.numeroDeFaltas < 6) {
//        if (aval.valorVendidoNoMes = 5000) {
//
//            return 120;
//
//        }
//
//    }
//    else {
//
//        return 0;
//
//    }
//}
//
//
//
//
//float calculaValorTotalFolha(int qtdVededores, Vendedor* vetorVendedores) {
//
//    int i;
//
//    float somaSalarios;
//
//    somaSalarios = 0.0;
//    for (i = 0;i < qtdVededores;i++) {
//
//
//        somaSalarios = somaSalarios + (vetorVendedores[i].salarioBase + calculaExtra(vetorVendedores[i].aval));
//
//
//    }
//    return somaSalarios;
//}
//
//
//Vendedor** obtemRelacaoDemitido(int qtdVendedores, Vendedor* vetorVendedores, int* numDemitidos) {
//
//    *numDemitidos = 0;
//    int i;
//
//    for (i = 0;i < qtdVendedores;i++) {
//
//        if (vetorVendedores[i].aval.numeroDeFaltas >= 10) {
//
//            (*numDemitidos)++;
//
//        }
//    }
//
//    if (*numDemitidos == 0) {
//
//        return NULL;
//
//    }
//
//    Vendedor** demitidos = (Vendedor**)malloc((*numDemitidos) * sizeof(Vendedor*));
//
//    if (demitidos == NULL) {
//
//        return NULL;
//
//    }
//
//    int j;
//    j = 0;
//    for (i = 0; i < qtdVendedores;i++) {
//
//        if (vetorVendedores[i].aval.numeroDeFaltas >= 10) {
//
//            demitidos[j] = &vetorVendedores[i];
//            j++;
//        }
//
//
//    }
//    return demitidos;
//}
//
//// Assumindo, para facilitar, que os valores vendidos no mês são todos diferentes, escreva a função obtemMelhorVendedor, que recebe o número de vendedores e o
////  vetor dos vendedores da loja e retorna, sem alocar dinamicamente, nem usar qualquer outro vetor de char, um ponteiro para a cadeia contendo o nome do melhor 
////  vendedor da loja (o que tem o maior valor vendido no mês). 
//
//
//char* obtemMelhorVendedor(int qtdVendedores, Vendedor* vVendedores) {
//
//    char** nome;
//    int i;
//
//    for (i = 0; i < qtdVendedores; i++) {
//
//        int maiorValorVendido = 0;
//        if (vVendedores[i].aval.valorVendidoNoMes > maiorValorVendido) {
//
//            maiorValorVendido = vVendedores[i].aval.valorVendidoNoMes;
//            nome = &vVendedores[i].nome;
//
//        }
//    }
//
//    return nome;
//}





//===========================================================================================================================================================================================




//3. 


// Exercício struct Circulo – dinâmico 



// Represente pontos 2D como sendo um tipo estruturado Ponto composto por dois floats. Depois defina Circulo como sendo um tipo estruturado contendo um ponteiro para 
//Ponto como sendo o centro do círculo e um raio (float). Escreva e teste as seguintes funções: 



// Uma função que cria um novo círculo recebendo as coordenadas de um ponto e um valor de raio e retornando um ponteiro para Circulo. 

// Uma função que imprime os componentes de um Circulo. 

// Uma função que calcula a área de um Circulo. 



// Faça os testes de memória adequados e libere todas as memórias alocadas tão logo seja possível. 


//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define pi 3.14
//
//
//struct ponto
//{
//
//    float x;
//    float y;
//
//};
//
//typedef struct ponto Ponto;
//
//struct circulo
//{
//
//    float raio;
//    Ponto* pt;
//
//
//};
//
//typedef struct circulo Circulo;
//
//
//
//Circulo* criaNovoCirculo(float x, float y, float raio);
//void imprimeComponentes(Circulo* c);
//float calculaArea(Circulo* c);
//
//
//int main(void) {
//
//    float raio = 2.0;
//    float x = 0.0;
//    float y = 0.0;
//    Ponto p;
//
//    Circulo* c = criaNovoCirculo(x, y, raio);
//    imprimeComponentes(c);
//    float area = calculaArea(c);
//
//    printf("A area do circulo eh: %.2f", area);
//
//
//}
//
//
//
//
//
//
//// Uma função que cria um novo círculo recebendo as coordenadas de um ponto e um valor de raio e retornando um ponteiro para Circulo. 
//
//Circulo* criaNovoCirculo(float x, float y, float raio) {
//
//    Ponto* tmp = (Ponto*)malloc(sizeof(Ponto));
//    tmp->x = x;
//    tmp->y = y;
//
//    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
//
//    c->pt = tmp;
//    c->raio = raio;
//    return c;
//}
//
//// Uma função que imprime os componentes de um Circulo. 
//
//void imprimeComponentes(Circulo* c) {
//
//    printf("A coordenada X eh: %.2f\n", c->pt->x);
//
//    printf("A coordenada Y eh: %.2f\n", c->pt->y);
//
//    printf("O RAIO eh: %.2f", c->raio);
//
//
//    return;
//}
//
//
//
//// Uma função que calcula a área de um Circulo. 
//
//float calculaArea(Circulo* c) {
//
//    float r;
//    float area;
//
//    r = c->raio;
//
//    area =  pi * pow(r,2);
//
//    return area;
//}

//#=============================================================================================================================================================


//4)

// Considere o tipo Candidato abaixo: 

// struct candidato 

// {	int	inscricao; 

// char	nome[51]; 

// int	idade; 

// float	nota; 

// }; 

// typedef struct candidato Candidato; 



// Escreva as funções: 

// a) criaCandidato: que recebe uma inscrição, um nome, uma idade e uma nota, e cria, com alocação dinâmica, um novo candidato, preenchendo seus campos. 
// A função retorna o endereço do novo candidato criado, ou, caso não tenha sido possível criar o candidato, a função retorna NULL; 

// b) exibeTodosCandidatos: a função recebe um vetor de ponteiros para candidatos e o número de candidatos, exibindo os dados de todos os candidatos; 

// c) buscaInscricao: a função recebe um vetor de ponteiros para candidatos, o número de candidatos e uma inscrição. A função retorna o endereço do candidato, 
// se ele for encontrado, ou NULL, caso contrário. 

// Use a função main abaixo para testar as funções desenvolvidas. 





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidato

{
    int	inscricao;

    char nome[51];

    int	idade;

    float nota;

};

typedef struct candidato Candidato;

Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota);
void  exibeTodosCandidatos(Candidato** vCandidatos, int qtdCandidatos);
Candidato* buscaCandidato(Candidato** vetPontCandidatos, int qtdCandidatos, int inscricao);

int main(void)

{

    Candidato* vpcandidato[8];

    int i;



    vpcandidato[0] = criaCandidato(444, "Luiz", 34, 7.8f);

    vpcandidato[1] = criaCandidato(111, "Rita", 56, 8.8f);

    vpcandidato[2] = criaCandidato(999, "Rute", 32, 7.1f);

    vpcandidato[3] = criaCandidato(555, "Dina", 27, 6.4f);

    vpcandidato[4] = criaCandidato(777, "Lana", 35, 5.3f);

    vpcandidato[5] = criaCandidato(666, "Tais", 29, 9.8f);

    vpcandidato[6] = criaCandidato(222, "Cris", 31, 7.2f);

    vpcandidato[7] = criaCandidato(333, "Vera", 44, 5.4f);



    exibeTodosCandidatos(vpcandidato, 8);



    /* inclua aqui a parte referente ao teste da função buscaInscricao: leitura de uma inscrição, chamada da função e exibição dos dados do candidato, se encontrado    */



    for (i = 0; i < 8; i++) {

        free(vpcandidato[i]);


    }




    return 0;

}





// a) criaCandidato: que recebe uma inscrição, um nome, uma idade e uma nota, e cria, com alocação dinâmica, um novo candidato, preenchendo seus campos. 
// A função retorna o endereço do novo candidato criado, ou, caso não tenha sido possível criar o candidato, a função retorna NULL; 

Candidato* criaCandidato(int inscricao, char* nome, int idade, float nota) {

    Candidato* nvCandidato = (Candidato*)malloc(sizeof(Candidato));

    if (nvCandidato == NULL) {

        return NULL;

    }

    nvCandidato->inscricao = inscricao;
    strcpy(nvCandidato->nome, nome);
    nvCandidato->idade = idade;
    nvCandidato->nota = nota;

    return nvCandidato;
}

//b) exibeTodosCandidatos: a função recebe um vetor de ponteiros para candidatos e o número de candidatos, exibindo os dados de todos os candidatos; 

void exibeTodosCandidatos(Candidato** vCandidatos, int qtdCandidatos) {


    int i;

    i = 0;

    for (i = 0;i < qtdCandidatos;i++) {

        printf("Candidato %d : /inscricao: %d / nome: %s / idade: %d / nota: %.2f \n\n", i + 1, vCandidatos[i]->inscricao, vCandidatos[i]->nome, vCandidatos[i]->idade, vCandidatos[i]->nota);

    }
}

//buscaInscricao: a função recebe um vetor de ponteiros para candidatos, o número de candidatos e uma inscrição. A função retorna o endereço do candidato, 
// se ele for encontrado, ou NULL, caso contrário.

Candidato* buscaCandidato(Candidato** vetPontCandidatos, int qtdCandidatos, int inscricao) {

    int i;
    for (i = 0;i < qtdCandidatos;i++) {

        if (vetPontCandidatos[i]->inscricao == inscricao) {

            return vetPontCandidatos[i];

        }
    }
    return NULL;
}