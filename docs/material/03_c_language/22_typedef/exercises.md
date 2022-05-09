# E21 - `Struct`, `typedef` ed `union`

## Esercizio E21.1

Scrivere un programma che definisca una `struct` per gli studenti, rappresentante nome, cognome ed età, ed una `union` per il voto di un esame, che può essere intero o reale. Mostrarne il funzionamento in un'apposita funzione `main()`.

### Soluzione S21.1

Ecco una possibile soluzione.

```c
#pragma warning(disable: 4996)
#include <stdio.h>

typedef struct studente
{
	char nome[20];
	char cognome[20];
	int eta;
} STUDENTE;

typedef union voto_esame
{
	int voto_int;
	double voto_double;
} VOTO_ESAME;

int main() {
	// Accedo mediante l'operatore punto
	STUDENTE primo_studente = { "", "", 0 };

	// Popolo
	printf("Inserire il nome: ");
	if (scanf("%s", primo_studente.nome) <= 0)
		return -1;
	printf("Inserire il cognome: ");
	if (scanf("%s", primo_studente.cognome) <= 0)
		return -1;
	printf("Inserire l'eta': ");
	if (scanf("%d", &primo_studente.eta) <= 0)
		return -1;

	printf("Nome: %s - Cognome: %s - Eta: %d\n", primo_studente.nome, primo_studente.cognome, primo_studente.eta);

	// Accedo mediante puntatore
	STUDENTE secondo_studente = { "", "", 0 };
	STUDENTE* puntatore_studente = &secondo_studente;

	// Popolo
	printf("Inserire un nuovo nome: ");
	if (scanf("%s", puntatore_studente->nome) <= 0)
		return -1;
	printf("Inserire un nuovo cognome: ");
	if (scanf("%s", puntatore_studente->cognome) <= 0)
		return -1;
	printf("Inserire una nuova eta': ");
	if (scanf("%d", &puntatore_studente->eta) <= 0)
		return -1;

	printf("Nome: %s - Cognome: %s - Eta: %d\n", secondo_studente.nome, secondo_studente.cognome, secondo_studente.eta);

	// Definisco la union
	VOTO_ESAME voto_primo_esame = { 0 };
	VOTO_ESAME voto_secondo_esame = { 0.0 };
	VOTO_ESAME* puntatore_primo_esame = &voto_primo_esame;

	printf("Inserire il voto (intero) per il primo esame: ");
	if (scanf("%d", &voto_primo_esame.voto_int) <= 0)
		return -1;

	printf("Inserire il voto (decimale) per il secondo esame: ");
	if (scanf("%lf", &voto_secondo_esame.voto_double) <= 0)
		return -1;

	printf("Aggiornare il voto (decimale) per il primo esame: ");
	if (scanf("%lf", &puntatore_primo_esame->voto_double) <= 0)
		return -1;

	printf("Il voto per il primo esame e' %d (intero) e %lf (decimale)\n", voto_primo_esame.voto_int, voto_primo_esame.voto_double);

    return 0;
}
```
