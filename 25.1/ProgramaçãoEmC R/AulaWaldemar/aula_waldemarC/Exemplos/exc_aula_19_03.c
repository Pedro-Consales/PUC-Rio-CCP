#include <stdio.h>
#include <math.h>

#define Pi 3.14

//Cabeçalho

float vol_Esfera(float raio_esfera);
float vol_Cilindro(float raio_cil, float altura);
float vol_Calota(float raio_calota, float altura);
float vol_Peca(float altura, float raio_esfera, float raio_cilindro, float raio_calota, float altura_calota);

//Cabeçalho


int main(void)
{

    float volume_Esfera = vol_Esfera(4);
    float volume_Cilindro = vol_Cilindro(2,4);
    float volume_Calota = vol_Calota(2,2);
    float volume_Peca = vol_Peca(4 , 4 ,  2,  2,  2);

    printf("Volume da esfera: %.2f\n", volume_Esfera);
    printf("Volume da cilindro: %.2f\n", volume_Cilindro);
    printf("Volume da calota: %.2f\n", volume_Calota);
    printf("Volume da peca: %.2f\n", volume_Peca);

    return 0;

}

float vol_Esfera(float raio_esfera)
{
    float volume = 4/3 * Pi * pow(raio_esfera,3);

    return volume;

}

float vol_Cilindro(float raio_cil, float altura_cil)
{
    float volume = Pi * pow(raio_cil,2) * altura_cil;

    return volume;
}

float vol_Calota(float raio_calota, float altura_calota)
{
    float volume = 1/3 * Pi * pow(altura_calota,2) * (3*raio_calota - altura_calota);  //Não funcionou ??

    return volume;

}

float vol_Peca(float altura, float raio_esfera, float raio_cilindro, float raio_calota, float altura_calota)
{
    float volume = vol_Esfera(raio_esfera) - vol_Cilindro(altura, raio_cilindro) - 2* vol_Calota(raio_calota, altura_calota);

    return volume;

}