# 18 - Array in C

Nella [lezione 10](../../01_intro/10_data_structures/lecture.md) abbiamo introdotto il concetto di array in questo modo:

!!!quote "Definizione di array"
    Un array contiene una sequenza di elementi, tipicamente dello stesso tipo, ed organizzati seguendo un ordine specifico, "esplorabile" mediante il concetto di *indice*.

La maggior parte dei linguaggi di programmazione offre un'implementazione nativa di questa struttura dati; ovviamente, il C non fa eccezione.

## 18.1 - Concetti fondamentali sugli array in C

Un array ad $n$ elementi è caratterizzato in C da degli indici che vanno da $0$ ad $n-1$. In altre parole, per accedere al primo elemento dell'array dovremo richiamare l'indice $0$, per accedere al secondo dovremo richiamare l'indice $1$, e così via fino all'indice $n-1$, da usare per accedere all'$n$-mo elemento. Importante sottolineare anche che il valore di $n$, ovvero la *dimensione* dell'array, è predefinito ed invariabile: provare a modificare il numero di elementi di un array, infatti, equivale a crearne uno nuovo.

Vediamo però adesso come sia possibile creare un nuovo array, o anche accedere ai singoli elementi dello stesso.

### 18.2 - Operatori notevoli sugli array

### 18.2.1 - L'operatore `[]`

L'operatore `[]` (ovvero, la coppia di parentesi quadre) viene usato per la definizione ed inizializzazione di un nuovo array. Supponiamo, ad esempio, di voler dichiarare un nuovo array contenente 5 numeri interi; per farlo, potremo usare questa notazione:

```c
int mio_array[5];
```

In sostanza, la dichiarazione assume quindi una forma del tipo:

```c
array_type array_id[size];
```

con `array_type` tipo degli elementi dell'array, `array_id` identificatore dell'array, e `size` numero di elementi dello stesso.

!!!note "Nota"
    In buona sostanza, la dichiarazione di un array è praticamente analoga a quella di una variabile.

Analogamente, anche l'inizializzazione di un array può avvenire contestualmente alla dichiarazione:

```c
int mio_array[5] = {1, 2, 3, 4, 5};
```

Notiamo anche come i valori associati ai membri dell'array siano indicati tra parentesi graffe. In questo caso, possiamo anche omettere la dimensione dell'array, che sarà automaticamente inferita dall'r-value:

```c
int mio_array[] = {1, 2, 3, 4, 5};
```

!!!note "Nota"
    Un array *non* è un l-value, quindi un'espressione del tipo `mio_array = {1, 2, 3, 4, 5};` non è da ritenersi valida.

L'operatore `[]` è usato anche per scrivere o leggere i singoli elementi dell'array. Infatti, l'istruzione:

```c
mio_array[3] = 10;
```

ci permette di sovrascrivere l'elemento in posizione `4` dell'array, che adesso sarà pari a `[1, 2, 3, 10, 5]`. Utilizzando invece la notazione:

```c
int a = mio_array[2];
```

assegneremo alla variabile di tipo intero `a` il valore `3`.

## 18.2.2 - L'operatore `sizeof`

Il linguaggio C mette a disposizione l'operatore `sizeof` per conoscere il numero complessivo di byte occupato in memoria dall'array.

!!!note "Nota"
    Importantissimo sottolineare come l'operatore `sizeof` restituisca le dimensioni in memoria e non il numero di elementi dell'array!

## 18.3 - Array multidimensionali

Il linguaggio C permette di creare degli array di dimensionalità arbitraria.

!!!note "Nota"
    Ad esempio, una matrice è un array di dimensionalità pari a due.

Per far questo, possiamo utilizzare una notazione del tipo:

```c
array_type array_id[size_1][size_2];
```

A parte l'uso ripetuto dell'operatore `[]`, valgono esattamente le stesse regole usate per gli array monodimensionali. Di conseguenza, per definire una matrice $3 \times 3$ a valori in $\mathbb{R}$, potremo scrivere:

```c
float matrix[3][3];
```

mentre per inizializzarla:

```c
float matrix [3][3] = { {2.0, 0.0, 1.0}, {1.0, 3.0, 2.0}, {4.0, 3.0, 3.0} };
```

ed infine per accedere all'elemento in posizione $(1, 2)$:

```c
int el = matrix[0][1];
```

## 18.4 - Array e stringhe

Una *stringa* altro non è se non una *sequenza* di caratteri.

Interessante notare come le stringhe *non* siano dati di tipo primitivo; tuttavia, sono estremamente utilizzate, per cui il loro supporto è presente in praticamente ogni linguaggio di programmazione. Per capirci, una delle funzioni "fondamentali" del C, come la `printf`, accetta una stringa.

Data la loro natura, le stringhe sono rappresentate come degli array di char *null terminated*. Questo concetto è estremamente peculiare: infatti, affinché un array sia riconosciuto come stringa, deve essere composto soltanto da char e, inoltre, *il suo ultimo elemento deve essere un null value*. 

Facciamo un esempio:

```c linenums="1"
char valid_string[6] = {'a', 'b', 'c', 'd', 'e', null};
char non_valid_string[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
```

In questo esempio, l'array `valid_string` sarà considerato dal compilatore come una stringa, mentre l'arryay `non_valid_string` sarà un array di tipo char a sei elementi.

Ovviamente, usare una notazione come la precedente per scrivere un array risulta oltremodo scomodo, per cui si preferisce utilizzare i doppi apici:

```c
char string_with_quotes[10] = "abcdef";
```

In questo caso, ovviamente, il terminatore `null` sarà aggiunto automaticamente.

!!!tip "Conversione da stringa a tipo numerico"
    Non è possibile effettuare *nativamente* la conversione da stringa a numero intero o float. In tal senso, si utilizzano due funzioni, definite nell'header `stdlib.h`, ovvero `atoi` ed `atof`, che convertono una stringa rispettivamente in intero e float.

!!!tip "Conversione da tipo numerico a stringa"
    Per convertire da tipo numerico a stringa, invece, possiamo usare la funzione `sprintf`, definita in `stdio.h`. Questa funzione, che restituisce una stringa in uscita, può accettare degli interi o dei float da inserire all'interno dell'output mediante delle apposite *format string*. Ad esempio, per convertire il numero 10, potremmo usare l'istruzione `sprintf(out_string, "%d", 10);`.

## 18.5 - Esercizi

1. Esercizio 1: un tensore è un array ad 𝑛 dimensioni contenente valori arbitrari. Creare due tensori di dimensioni 3×3×3, uno contenente valori interi, e l’altro contenente valori in formato double. Usare l’operatore sizeof per confrontarne lo spazio occupato in memoria, e visualizzare a schermo tutti i valori dell’array più ‘pesante’.
2. Esercizio 2: scriviamo un programma che, data in ingresso una stringa rappresentativa di un numero 𝑥, con 𝑥 numero reale o naturale, chiami l’adeguata funzione per convertirlo in una variabile di tipo numerico. Utilizziamo poi il risultato restituito dalla funzione sprintf per visualizzare a schermo il valore della stringa associata ad 𝑥.
