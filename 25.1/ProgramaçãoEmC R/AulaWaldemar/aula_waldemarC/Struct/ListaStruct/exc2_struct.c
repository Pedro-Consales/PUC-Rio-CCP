#include<stdio.h>


typedef struct sessao 
{ 

    int horas; 
    int minutos; 

} Sessao; 

typedef struct ingresso 
{ 

    int fila; 
    int assento; 
    char tipo; /* ´I´- inteira ou ´M´- meia */ 
    Sessao se; 

} Ingresso; 




float totalSessao(Ingresso* vetorDeIngressos, int qtdVendidos, Sessao sesh);


int main(void)
{

    Ingresso venda[] = { 
            {8,1,'M',{4,30}}, 
            {3,5,'M',{8,0}}, 
            {1,7,'I',{4,30}}, 
            {5,5,'I',{8,0}}, 
            {7,1,'M',{6,0}}, 
            {4,3,'I',{8,0}} 
            };

    Sessao sesh;
    float totSesh;
    int qtdVendidos = 6;

    sesh.horas = 8;
    sesh.minutos = 0;


    totSesh = totalSessao(venda, qtdVendidos, sesh);

    printf("O total arrecadado para a sessao das %d horas e %d minutos foi %.2f", sesh.horas,sesh.minutos, totSesh);

    return 0;
}


float totalSessao(Ingresso* vetorDeIngressos, int qtdVendidos, Sessao sesh)
{
    int totalSesh = 0;
    float v_ingresso = 30.0; 
    for(int i = 0; i < qtdVendidos; i++)
    {

        if(sesh.horas == vetorDeIngressos[i].se.horas && sesh.minutos == vetorDeIngressos[i].se.minutos )
        {
            if(vetorDeIngressos[i].tipo == 'I')
            {
                totalSesh += v_ingresso;
            }
            else if(vetorDeIngressos[i].tipo == 'M')
            {
                int meia = v_ingresso/2;
                totalSesh += meia;
            }
        }
    }
    return totalSesh;

}