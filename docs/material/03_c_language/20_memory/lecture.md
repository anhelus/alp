# 20 - Allocazione statica e dinamica della memoria

La memoria di un calcolatore è tipicamente divisa in tre sezioni:

* la *heap*, ovvero una parte di memoria richiamabile all'occorrenza dal programmatore;
* lo *stack*, nel quale le variabili vengono dichiarate, inizializzate a runtime, e che agisce secondo una logica LIFO;
* la *code section*, dove viene memorizzato il programma a runtime.

Questa disposizione della memoria ci permette quindi di allocarla (ovvero *assegnarla*) secondo due modalità, ovvero *statica* e *dinamica*.

## 20.1 - Allocazione statica della memoria

L'allocazione statica della memoria prevede che il programma in esecuzione abbia una dimesione prefissata a compile time, la quale non può essere in alcun modo modificata a runtime. Ovviamente, ciò implica che il programmatore sia in grado di definire esattamente a priori i requisiti del suo programma in termini di memoria. 

Un esempio di allocazione statica della memoria è il seguente:

```c
int main()
{
    int a;      // prealloco 4 byte
    long b;     // prealloco 8 byte
}
```

Nel codice precedente dichiariamo due variabili, per le quali saranno allocate, rispettivamente, 32 e 64 bit all'interno dello stack. A runtime, a meno che non siano specificate delle apposite operazioni di cast, la quantità di memoria allocata *non* verrà modificata, e sarà liberata in automatico soltanto al termine dell'esecuzione dello stesso.

Riassumiamo quindi i vantaggi e gli svantaggi dell'allocazione statica.

| Vantaggi | Svantaggi |
| -------- | --------- |
| Semplicità di utilizzo.</br>Delega al compilatore dell'allocazione della memoria.</br>Efficiente a runtime. | Memoria non necessariamente utilizzata al meglio (specie con array).</br>Necessità di conoscere a priori i requisiti in termini di memoria.</br>Impossibilità di riallocare la memoria a runtime. |

## 20.2 - Allocazione dinamica della memoria

A differenza dell'allocazione statica, nell'allocazione dinamica è il programmatore a controllare quanta memoria viene allocata. Inoltre, in questo caso, viene utilizzata la memoria heap, e non lo stack. L'allocazione dinamica prevede quindi che la memoria non sia allocata a priori, ovvero a compile time, ma piuttosto a runtime; di conseguenza, può essere sia assegnata, sia liberata, e farlo in maniera corretta comporta un utilizzo più efficiente della memoria stessa.

Dal punto di vista pratico, la libreria `stdlib.h` offre una serie di funzioni che permettono l'allocazione dinamica della memoria, che vediamo di seguito.

### 20.2.1 - La funzione `malloc`

La funzione `malloc` permette di allocare un certo quantitativo di memoria a runtime, specificando come parametro passato alla funzione il numero di byte da allocare. Quindi, ad esempio:

```c
int num_values = 10;
int *p = (int*) malloc(num_values);
```

Grazie all'istruzione precedente, avremo allocato spazio sufficiente a contenere dieci numeri interi a quattro byte, ovvero quaranta byte.

Inoltre, è opportuno notare come la `malloc` restituisca in uscita un indirizzo di memoria; in questo caso, quindi, è necessario effettuare un casting a puntatore ad intero.

### 20.2.2 - La funzione `calloc`

La funzione `calloc` offre un vantaggio rispetto alla `malloc`, inizializzando gli elementi allocati in modo che questi assumano un valore pari a zero. La sintassi è la seguente:

```c
int num_values = 10;
int *p = (int*) calloc(num_values, sizeof(int))
```

Notiamo subito come vi sia una prima differenza rispetto alla `malloc` legata al fatto che la funzione accetta due parametri, ovvero il numero di oggetti per i quali è richiesta l'allocazione, e la dimensione di ciascun oggetto. Anche in questo caso, la funzione restituisce un indirizzo di memoria.

### 20.2.3 - La funzione `realloc`

La funzione `realloc` ci permette di riutilizzare o estendere la memoria che abbiamo allocato in precedenza mediante la `malloc` o la `calloc`. In tal senso, la funzione accetta due argomenti, ovvero il tipo del puntatore precedentemente allocato, ed il numero di nuovi elementi da allocare.

### 20.2.4 - La funzione `free`

Una delle cose più importanti da tenere a mente quando abbiamo a che fare con l'allocazione dinamica è che la memoria deve essere sempre rilasciata qualora non sia più richiesta. Ciò avviene di solito in maniera automatica al termine dell'esecuzione del programma; tuttavia, è consigliato effettuare tale rilascio *sempre* in maniera esplicita. Per farlo, dobbiamo utilizzare la funzione `free`, passando come argomento il puntatore all'indirizzo di memoria che desideriamo liberare.

Facciamo adesso un esempio completo:

```c linenums="1"
#include <stdlib.h>
  
int main()
{
    int *p;
    int *p = (int*) malloc(5 * sizeof(int));
    free(p);
    return 0;
}
```

Nel codice precedente:

* alla riga 5, dichiariamo un puntatore ad intero `p`;
* il puntatore viene memorizzato nello stack, e punta all'indirizzo del primo valore di memoria disponibile nell'heap grazie alla `malloc` (riga 6);
* una volta terminata la serie di istruzioni da eseguire, la memoria puntata da `p` viene rilasciata mediante la `free`.

Anche per l'allocazione dinamica possiamo riassumere vantaggi e svantaggi.

| Vantaggi | Svantaggi |
| -------- | --------- |
| Allocazione della memoria fatta a runtime.</br>Possibilità di allocare, deallocare e riallocare ulteriore memoria alla bisogna.</br> | Maggior tempo di esecuzione richiesto per l'allocazione dinamica.</br>Necessità di gestire la deallocazione della memoria in forma esplicita. |
