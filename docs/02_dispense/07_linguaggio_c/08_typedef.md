Nel linguaggio C, le struct sono usate per raggrupapre diversi tipi di varaibili sotto lo stesso nome. Ad esempio, potremmo creare una struttura "persona", fatta da due stringhe ed un intero.

```c
struct persona
{
	char *nome;
	char *cognome;
	int eta;
};
```

Con la dichiarazione della struttura abbiamno creato un nuovo tipo chiamato persona. Prima di poter usare il tipo telefono, occorre creare una variabile del tipo telefono. Ad esempio:

```c
#include <stdio.h>

struct persona
{
	char *nome;
	char *cognome;
	int eta;
};

int main()
{
	struct persona pippo;

	return 0;
}
```

Per accedere ai membri della struttura persona, dobbiamo inserire un punto tra il nome della struttura e quello della variabile.

```c
#include <stdio.h>

struct persona
{
	char *nome;
	char *cognome;
	int eta;
};

int main()
{
	struct persona studente;

	studente.nome = "Piero";
	studente.cognome = "Scamarcio";
	studente.eta = 19;

	printf("Lo studente %s %s ha %d anni\n", studente.name, studente.cognome, studente.eta);

	return 0;
}
```

## typedef

Le definizioni di tipo rendono anche possibile creare i nostri tipi di variabile. Ad esempio, possiamo creare un tipo che rappresenta un puntatore a double.

```c
#include <stdio.h>

typedef double* double_pointer;

int main() {
	double val = 0.0;
	double_pointer pointer = &val;
	printf("Il valore del puntatore e': %p", pointer);
	return 0;
}
```

Questa tecnica può anche essere estesa alle struct. Ciò significa che:

```c
#include <stdio.h>

typedef struct persona
{
	char *nome;
	char *cognome;
	int eta;
}PERSONA;

int main()
{
	PERSONA pippo;

	return 0;
}
```

otiamo che il nome del tipo associaot alla sturttura è quello indicato in maiuscolo immediatamente dopo alla stessa.

### Puntatori a strutture

Possiamo usare anche dei puntatori a strutture. In questo caso, per accedere alla singola proprietà della struct, dovremo usare l'operatore _infix_ (->)

```c
#include <stdio.h>

typedef struct persona
{
	char *nome;
	char *cognome;
	int eta;
} PERSONA;

int main()
{
	PERSONA studente;
	PERSONA* puntatore_studente;

	studente->nome = "Piero";
	// Prima era studente.nome!
	studente->cognome = "Scamarcio";
	studente->eta = 19;

	printf("Lo studente %s %s ha %d anni\n", studente->name, studente->cognome, studente->eta);

	return 0;
}
```

### Union

Le union sono analoghe alle struct dal punto di vista della sintassi, semplicemente però implementano delle strutture dati differenti. Un esempio è il seguente.

```c
#include<stdio.h>

typedef union lettura_sensore {
	double d;
	int i;
}LETTURA_SENSORE;

int main()
{
	LETTURA_SENSORE lettura;
	lettura.d = 12.0;
	lettura.i = 5;
}
```
