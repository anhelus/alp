// programma.c
#include <stdio.h>
#include "aritmetica.h"

int main() {
	int somma = aggiungi(2, 3);
	int prodotto = moltiplica(2, 3);
	printf();
	printf("La somma di 2 e 3 e': %d \n", somma);
	printf("Il prodotto di 2 per 3 e': %d \n", prodotto);
}