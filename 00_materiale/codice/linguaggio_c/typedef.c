#include <stdio.h>



int main() {

typedef int* int_pointer;
int a = 10;
int_pointer ip = &a;


	// Definizione di una struct studente
	typedef struct studente {
		char nome[32];
		char cognome[32];
		int matricola;
	} STUDENTE;

	STUDENTE tizio;

	STUDENTE* tp = &tizio;

	char nome_estratto[32] = tp->nome;

	typedef union lettura_sensore {
		long lettura_intera;
		double lettura_reale;
	} LETTURA_SENSORE;

	// Creazione di un'istanza di studente

}