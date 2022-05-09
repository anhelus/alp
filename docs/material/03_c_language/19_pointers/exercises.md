# E19 - I puntatori

## Esercizio E19.1

Definire mediante un'apposita struttura di librerie delle funzioni che:

* mostrino l'indirizzo di una variabile intera o in formato `double`;
* verifichino che il valore dereferenziato da un puntatore coincida con la variabile;
* mostrino la differenza tra passaggio per valore e passaggio per reference;
* descrivano un puntatore a void.

### Soluzione E19.1

Ecco una possibile soluzione, organizzata creando un'apposita libreria *puntatori*.

```c
// puntatori.h
#ifndef PUNTATORI_H
#define PUNTATORI_H

void mostra_puntatore_intero(int intero);
void mostra_puntatore_double(double decimale);
int deferenzia_compara_intero(int* puntatore_intero, int comparato);
double deferenzia_compara_decimale(double* puntatore_decimale, double comparato);
int* restituisci_puntatore(int intero);
void puntatore_a_void(char ch);

#endif // !PUNTATORI_H
```

```c
// puntatori.c
#include <stdio.h>
#include "puntatori.h"

void mostra_puntatore_intero(int intero) {
	int* puntatore = &intero;
	printf("L'indirizzo della variabile e': %p\n", puntatore);
}

void mostra_puntatore_double(double decimale) {
	double* puntatore = &decimale;
	printf("L'indirizzo della variabile e': %p\n", puntatore);
}

int* restituisci_puntatore(int intero) {
	return &intero;
}

int deferenzia_compara_intero(int* puntatore_intero, int comparato) {
	int puntato = *puntatore_intero;
	if (puntato == comparato) {
		printf("La comparazione ha avuto successo!\n");
	}
	return puntato;
}

double deferenzia_compara_decimale(double* puntatore_decimale, double comparato) {
	double puntato = *puntatore_decimale;
	if (puntato == comparato) {
		printf("La comparazione ha avuto successo!\n");
	}
	return puntato;
}

void puntatore_a_void(char ch) {
	void* puntatore;
	puntatore = &ch;
	printf("Il puntatore a void ha indirizzo: %p\n", puntatore_a_void);
	char* puntatore_a_char = (char*)puntatore;
	// Dereferenziazione
	printf("La variabile originaria e': %c\n", *puntatore_a_char);
}
```

```c
// main.c
#include <stdio.h>
#include "puntatori.h"
#include "puntatori_funzione.h"

int main() {
    // Parte 1
	int a = 1;
	double b = 0.1;
	mostra_puntatore_intero(a);
	mostra_puntatore_double(b);

    // Parte 2
	int c = deferenzia_compara_intero(&a, a);
	double d = deferenzia_compara_decimale(&b, b);

	// Parte 3
	int* p = restituisci_puntatore(a);
	if (p == &a) {
		printf("I puntatori combaciano!\n");
	}
	else {
		printf("I puntatori non combaciano!\n");
	}

	// Parte 4
	puntatore_a_void('c');

    return 0;
}
```
