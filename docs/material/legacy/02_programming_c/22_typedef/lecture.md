# 21 - `Struct`, `typedef` ed `union`

Abbiamo visto come il linguaggio C consenta l'utilizzo di una serie di tipi di dati primitivi. Tuttavia, consentirci soltanto questo sarebbe in un certo senso "limitante": ad esempio, potremmo voler creare una singola variabile che rappresenti una persona, senza dover necessariamente "far proliferare" tutta una serie di sottovariabili contenenti, ad esempio, nome, cognome ed età.

Per ovviare a questa limitazione, quindi, il C ci mette a disposizione un particolare costrutto rappresentativo di una struttura dati definita dall'utente; come prevedibile, tale costrutto va sotto il nome di `struct`.

## 21.1 - Le `struct`

I più attenti ricorderanno come abbiamo già visto il concetto di *struct* durante il nostro excursus sulle [strutture dati](../../01_intro/10_data_structures/lecture.md); ovviamente, le `struct` C rappresentano un'implementazione di questa classe di strutture dati, e permettono quindi di "raggruppare" diverse variabili tra loro.

Ad esempio, potremmo creare una `struct` che serva a caratterizzare una persona:

```c
struct persona
{
	char *nome;
	char *cognome;
	int eta;
};
```

In generale, quindi, una `struct` è definita nel modo che segue:

```c
struct NOME_STRUCT
{
	tipo_variabile_1 id_variabile_1;
	tipo_variabile_2 id_variabile_2;
	// ...
	tipo_variabile_n id_variabile_n;
}
```

Nel nostro esempio, una variabile associata alla struct `persona` avrà quindi un array di `char` relativo al nome, un array di `char` relativo al cognome, ed un `int` relativo all'età.

Proviamo adesso ad utilizzare questa `struct`:

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
	return 0;
}
```

Abbiamo creato una variabile di "tipo" persona. Potremo accedere a ciascuna delle "sottovariabili", o membri, della `struct` utilizzando l'operatore *dot* (punto):

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

	studente.nome = "John";
	studente.cognome = "Doe";
	studente.eta = 19;

	printf("Lo studente %s %s ha %d anni\n", studente.name, studente.cognome, studente.eta);

	return 0;
}
```

Abbiamo quindi visto come l'accesso mediante l'operatore punto valga sia in lettura, sia in scrittura.

### 22.1.1 - Puntatori a `struct`

Possiamo anche definire dei puntatori ad una struttura. In questo caso, però, per accedre alla singola proprietà della `struct`, dovremo utilizzare _infix_ (->)

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
	PERSONA* puntatore_studente;

	puntatore_studente->nome = "John";
	puntatore_studente->cognome = "Doe";
	puntatore_studente->eta = 19;

	printf("Lo studente %s %s ha %d anni\n", studente->name, studente->cognome, studente->eta);

	return 0;
}
```

## 22.2 - Definizione di tipo con `typedef`

Abbiamo visto come le `struct` ci permettano di "associare" diverse variabili tra loro, definendo dei veri e propri "tipi" composti da diverse variabili appartenenti a tipi primitivi. Il passo successivo, quindi, è quello di "formalizzare" queste strutture; per farlo, il linguaggio C ci mette a disposizione la parola chiave `typedef` che, come suggerisce il nome stesso, consente di creare un tipo definito dall'utente.

Ad esempio, potremmo creare un tipo da associare alla `struct` persona:

```c
typedef struct persona
{
	char *nome;
	char *cognome;
	int eta;
} TIPO_PERSONA;
```

In questo caso, l'identificativo associato alla `struct` rimane `persona` (in minuscolo), mentre il tipo definito a partire dalla `struct persona` sarà `TIPO_PERSONA`.

Potremo quindi creare una variabile di tipo `TIPO_PERSONA` proprio come se fosse una variabile di tipo primitivo:

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
	PERSONA studente;
	// altre istruzioni
	return 0;
}
```

Sottolineamo come la definizione di un tipo non sia vincolata ad una struct. Ad esempio, potremmo definire un tipo che rappresenta un puntatore ad intero.

```c
#include <stdio.h>

typedef int* int_pointer;

int main() {
	int val = 0.0;
	int_pointer pointer = &val;
	printf("Il valore del puntatore e': %p", pointer);
	return 0;
}
```

## 22.3 - Le `union`

Quando abbiamo parlato di strutture dati abbiamo visto, oltre alle *struct*, le *union*. Prevedibilmente, il C ci mette a disposizione oggetti di questo tipo, che risultano essere sintatticamente analoghi alle `struct`, ma che tuttavia implementano una struttura dati di tipo differente. Vediamo un rapido esempio.

```c
#include<stdio.h>

typedef union lettura_sensore {
	double d;
	int i;
} LETTURA_SENSORE;

int main()
{
	LETTURA_SENSORE lettura;
	lettura.d = 12.0;
	lettura.i = 5;
}
```

TODO: puntatore, printf
