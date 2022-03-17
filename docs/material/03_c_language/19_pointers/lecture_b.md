# 19 - Puntatori

## 19.1 - Allocazione statica e dinamica della memoria

Abbiamo detto che la memoria di un calcolatore è divisa in piccole unità chiamate byte.

La memoria è divisa in tre sezioni.

Nella *heap*, vi è una parte non organizzata, e trattata come risorsa da richiedre all'occorrenza. Non è possibile richiedrela con un puntatore.

nello stack, viene memorizzata le variabili temporanee create da una funzione. Nello stack, le variabili sono dichiarate, memorizzate ed inizializzate a runtime. Lo stack si chiama in questo modo perché segue, appunto, la pila (LIFO).

nella code section, quando il programma è eseguito, sarà portato nella memoria principale. Questo programma sarà quindi memorizzato nella sezione *code*.A seconda del programma, vedremo se utilizzare lo stack o l'heap.

Possiamo quindi allocare la memoria in due modi, statico e dinamico.

### 19.1.1 - Allocazione statica della memoria

Nell'allocazione statica della memoria, quando il programma viene eseguito, la dimensione del programma viene fissata, e non può essere ulteriormente cambiato. di conseguenza, i rquisiti esatti devono essere conosciuti a priori. L'allocazione e la deallicazione della memoria saranno effettuate automaticamentedal compilatore. Quando tutto viene fatto a compile time, o prima del run time, viene chiamata *allocazione statica della memoria*.

Ad esempio:

```c
int main()
{
    int a; // prealloco 2 byte
    long b; // prealloco 4 byte
}
```

Spiegazione:

* questo codice dichiara due variabili. Qyi l'assunto è che int prende due byte (16 bit) mentre long prende 4 byte di memoria. Questi valori dipendono dal compilatore.

TODO: questi valori sono doppi!

* queste variabili saranno memorizzate nella sezione relativa allo stack. Per ogni funzione nel programma, prenderà alcune parti dello stack (chiamate stack frame) e saranno cancellate dal compilatore quando non in uso.

svantaggi:

* semplice da usare
* allocazione e deallocazione fatte dal compilatore
* tempo di esecuzione efficiente
* usa lo stack

svantaggi:

* spreco di memoria
* bisogna sapere i requisiti esatti in termini di memoria
* la memoria non può essere rinominata dopo l'inizializzazione

### 19.1.2 - Allocazione dinamica della memoria

Nell'allocazione dinamica della memoria, l'allocazione ed iniziallizazione delle dimensioni sono fatte dal programmatore. La memoria è gestita, e viene fornita di puntatori che putano ad uno spazio di memoria appena allocata chiamato heap. La heap non è organizzata, ed è trattata come una risorsa richiesta "on-demand".

feature chiave:

* memoria allocata dinamicamente a runtime
* si rialloca la dimensione della memoria se necessario
* nessuno spreco di memoria

Esistono apposite funzioni disponibili nella libreria stdlib.h che ci aiutano ad allocare dinamicamente la memoria.

* malloc(): la funzione più semplice che alloca memoria a runtime è chiamata malloc(). Vi è la necessità di specificare il numero di byte di memora che sono richiesti per l'allocazione come argomento, e la funzione restituisce l'indirizzo del primo byte di memoria restituito sotto forma di puntatore.

```c
int num_values = 10;            // diciamo che ci sono dieci valori da allocare
int *p = (int*) malloc(num_values);  // allochiamo dieci valori
```

Notiamo poi il casto (int*), che converte l'indirizzo restituito dalla funzione a puntatore ad inero.

La calloc() offre alcuni vantaggi rispetto alla malloc(). Alloca la memoria come un numero di elementi di una data dimensione. nizializza la memoria che è allocata in modo che tutti i byte siano a zero. La funzione accetta due argomenti:

* il numero di oggetti per i quali è richiesto lo spazio
* la dimensione di ogni oggetto

La sintassi è:

```c
int *p = (int*)calloc(n_items, sizeof(int))
```

la funzione realloc() ci permette di riutilizzare o estendere la memoria che abbiamo allocato in precedenza usando malloc() o calloc(). In tal senso, la funzione accetta due argomenti, ovvero il tipo del puntatore precedentemente allocato, ed il numero di nuovi elementi per la loro dimensione.

Notiamo che quando la memoria è allocata dinamicamente, dovrebbe essere sempre rilasciata quando non è più richiesta. La memoria allocata sull'heap sarà automaticamente liberata quando il programma termina, ma è sempre meglio rilasciare in modo esplicito la memoria una volta terminato, anche se è poco prima della fine del programma. 

Ad esempio:

```c
// C program to illustrate the concept
// of memory allocation
#include <iostream>
using namespace std;
  
// Driver Code
void main()
{
    int* p; // 2 bytes
    P = (int*)malloc(5 * sizeof(int));
    free(p);
}
```

Nel caso precedente:

* viene dichiarato un puntatore p. Assumiamo che il puntatore p prende due byte di memoria e di nuovo dipende dal compilatore.
* questo puntatore è memorizzato nello stack, e punta all'indizzo del primo indice allocato nell'heap. La memoria heap non può essere usata direttamente ma con l'aiuto del putatore può essere acceduta.
* quando il programma non viene usato, la memoria deve essere deallocata, o causerà un memory leak.

vantaggi:

* l'allocazione dinamica è fatta a runtime
* possiamo allocare (creare) ulteriore spazio quando ne abbiamo bisogno
* la memoria può essere delalocata e riallocata quando necessario

svantaggi:

* dato che la memoria è allocata a runtime, è richiesto più tempo per farlo
* la memoria deve essere liberata dopo che l'utente ha fnito, per evitare bug.
