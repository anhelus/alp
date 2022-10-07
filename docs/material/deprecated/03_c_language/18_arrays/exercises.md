# E18 - Array

## Esercizio E18.1

Un tensore è un array ad $n$ dimensioni contenente valori arbitrari. Creare due tensori di dimensioni $3 \times 3 \times 3$, uno contenente valori itneri, e l'altro contenente valori in formato `double`. Utilizzare l'operatore `sizeof` per confrontare lo spazio occupato in memoria dai due tenosri, e visualizzare a schermo tutti i valori dell'array più "pesante".

### Soluzione S18.1

```c
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main() {
	int tensore_interi[3][3][3];
	double tensore_decimali[3][3][3];
	int contatore_interi = 1;
	double contatore_double = 1.0;
	// Popolo i tensori
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				tensore_interi[i][j][k] = contatore_interi;
				contatore_interi++;
				tensore_decimali[i][j][k] = contatore_double;
				contatore_double++;
			}
		}
	}

	// Stampo a schermo
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("L'elemento in posizione [i][j][k] per il tensore di interi e' %d\n", tensore_interi[i][j][k]);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("L'elemento in posizione [i][j][k] per il tensore di decimali e' %f\t", tensore_decimali[i][j][k]);
			}
		}
	}

	if (sizeof(tensore_decimali) > sizeof(tensore_interi)) {
		printf("La dimensione del tensore di decimali e': %d\n", sizeof(tensore_decimali));
	}
	else {
		printf("La dimensione del tensore di interi e': %d\n", sizeof(tensore_interi));
	}
    return 0;
}
```

## Esercizio E18.2

Scriviamo un programma che, data in ingresso una stringa rappresentativa di un numero $x$, con $x$ numero reale o naturale, chiami l’adeguata funzione per convertirlo in una variabile di tipo numerico. Utilizziamo poi il risultato restituito dalla funzione `sprintf` per visualizzare a schermo il valore della stringa associata ad $x$.

### Soluzione S18.2

```c
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void determina_intero_decimale(char numero[5]) {
	char stringa[32];
	int length = 5;
	for (int i = 0; i < length; i++) {
		if (numero[i] == '.') {
			double valore = atof(numero);
			sprintf(stringa, "Il numero %f e' reale\n", valore);
			printf(stringa);
			return;
		}
	}
	int valore = atoi(numero);
	sprintf(stringa, "Il numero %d e' un intero\n", valore);
	printf(stringa);
}

int main() {
	char intero[5] = "10";
	char decimale[5] = "1.1";
	determina_intero_decimale(intero);
	determina_intero_decimale(decimale);
    return 0;
}
```
