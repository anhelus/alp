# E15 - Nozioni fondamentali su C

## Esercizio E15.1

Definire il programma *Matematicamente* in modo che sia composto da:

* una libreria *trigonometria*, al cui interno ci siano le funzioni `coseno` e `seno` per il calcolo, rispettivamente, del *coseno a partire dal seno* e del *seno a partire dal coseno*;
* una libreria *aritmetica*, composta dalle funzioni `aggiungi` e `moltiplica`;
* un file `main.c` all'interno del quale si richiamano le funzioni presenti nelle precedenti librerie.

### Soluzione S15.1

Ecco una possibile soluzione.

Per la libreria *trigonometria*:

```c
// trigonometria.h
#ifndef TRIGONOMETRIA_H
#define TRIGONOMETRIA_H

float coseno(float seno);
float seno(float coseno);

#endif // !TRIGONOMETRIA_H
```

```c
// trigonometria.c
#include "trigonometria.h"
#include <math.h>
#include <stdio.h>

float seno(float coseno) {
	float sin_quad = 1 - (coseno * coseno);
	printf("%f\n", sin_quad);
	return sqrtf(sin_quad);
}

float coseno(float seno) {
	float cos_quad = 1 - (seno * seno);
	return sqrtf(cos_quad);
}
```

Per la libreria *aritmetica*:

```c
// aritmetica.h
#ifndef ARITMETICA_H
#define ARITMETICA_H

int aggiungi(int a, int b);
int moltiplica(int a, int b);

#endif // !ARITMETICA_H
```

```c
// aritmetica.c
#include "aritmetica.h"

int aggiungi(int a, int b) {
	return a + b;
}

int moltiplica(int a, int b) {
	return a * b;
}
```

Ecco un esempio di file `main.c`:

```c
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
```
