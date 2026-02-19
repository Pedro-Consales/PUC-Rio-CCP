#include <stdio.h>

int retorna_volumeCaixa(int baseCaixa, int larguraCaixa, int alturaCaixa) {

	int volumeCaixa;

	volumeCaixa = baseCaixa * larguraCaixa * alturaCaixa;



	return volumeCaixa;

}

int retorna_volumeCilindro(int raio, int alturaCilindro) {

	int pi;
	int volumeCilindro;

	pi = 3;
	

	volumeCilindro = (pi *(raio*raio) * alturaCilindro);

	return volumeCilindro;

}