#include <stdio.h>
#include "aritmetica.h"
#include "trigonometria.h"

int main() {
	int somma;
	int prodotto;
	int i = 2;
	int j = 3;
	somma = aggiungi(i, j);
	prodotto = moltiplica(i, j);
	printf("La somma e' %d\n", somma);
	printf("Il prodotto e' %d\n", prodotto);

	float cos;
	cos = coseno(0.5);
	printf("Il coseno e' %f\n", cos);
	float sin;
	sin = seno(0.5);
	printf("Il seno e' %f\n", sin);
}