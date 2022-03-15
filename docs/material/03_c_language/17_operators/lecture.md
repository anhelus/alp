# 17 - Operatori in C

In matematica, un operatore è comunemente inteso come una _azione_ su uno o più dati, o _operandi_. Un semplice esempio è dato dai comuni operatori di tipo aritmetico, come quello di somma, che permette (appunto) di sommare le quantità a destra e sinistra dell'operatore `+`.

In questa lezione approfondiremo il concetto di operatore, e ne vedremo alcuni tra i più utilizzati nel linguaggio C.

## 17.1 - Operatori ed espressioni

Generalmente, nei linguaggi di programmazione esistono due tipi di operatori:

- gli operatori _binari_, che agiscono su di una coppia di dati (normalmente a sinistra ed a destra dell'operatore);
- gli operatori _unari_, che agiscono su un singolo dato.

In particolare, il dato a sinistra dell'operatore è chiamato _l-value_, mentre quello a destra dell'operatore è detto _r-value_.

Gli operatori possono essere concatenati all'interno di un'_espressione_, intesa quindi come sequenza di operatori regolata da due principi:

- il principio di _precedenza_, valente soltanto in caso di più operatori, che prevede che le operazioni ad essere eseguite per prime siano quelle tra parentesi tonde, e che successivamente si segua un ordine da sinistra verso destra;
- il principio di _associatività_ indica l'ordine con cui sono valutati gli operatori, anche in questo caso prevalentemente da sinistra verso destra.

## 17.2 - L'operatore di assegnazione

L'operatore di assegnazione, contraddistinto dal simbolo uguale `=`, permette di assegnare un dato valore ad una variabile. Abbiamo già usato questo operatore più volte in fase di inizializzazione:

```c
int a = 10;
char c = 'b';
```

Importantissimo sottolineare come l'operatore di assegnazione _non valuti il valore di una variabile_, ma si limiti ad assegnarne uno nuovo.

## 17.3 - Gli operatori matematici

Gli operatori matematici sono quelli coinvolti in tutte le operazioni di tipo aritmetico che è possibile effettuare in C, e sono riassunti nella seguente tabella.

| Operatore | Spiegazione                              |
| --------- | ---------------------------------------- |
| `+`       | Somma l-value ed r-value.                |
| `-`       | Sottrae r-value ad l-value.              |
| `/`       | Divide l-value per r-value.              |
| `*`       | Moltiplica l-value per r-value.          |
| `%`       | Calcola il modulo in r-value di l-value. |
| `^`       | Eleva l-value ad r-value.                |

Particolarmente interessante è l'operatore di modulo `%`: questo, infatti, restituisce il resto della divisione tra l-value ed r-value. Ad esempio:

```c
int a = 5 % 2; // risultato: 1
int b = 12 % 4; // risultato: 0
int c = 17 % 13; // risultato: 4
```

Di estrema importanza sono anche gli operatori di confronto, riassunti nella seguente tabella.

| Operatore | Spiegazione                                            |
| --------- | ------------------------------------------------------ |
| `==`      | Verifica che l-value sia uguale ad r-value.            |
| `>`       | Verifica che l-value sia maggiore di r-value.          |
| `<`       | Verifica che l-value sia minore di r-value.            |
| `>=`      | Verifica che l-value sia maggiore o uguale ad r-value. |
| `<=`      | Verifica che l-value sia minore o uguale ad r-value.   |

Interessante notare come questi operatori restituiscano un _valore di verità_, ovvero un _vero_ o un _falso_ a seconda del fatto che la condizione sia rispettata o meno.

## 17.3 - Operatori booleani

Gli operatori booleani regolano le interazioni relative all'algebra di Boole, ovvero quella che gestisce variabili che possono assumere soltanto due valori: _vero_, convenzionalmente associato al valore 1, e _falso_, convenzionalmente associato al valore 0.

Vediamo insieme quali operazioni fondamentali sono definite dalla logica booleana.

### 17.3.1 - Cenni di logica booleana

#### 17.3.1.1 - Operatori binari

##### 17.3.1.1 - Operazione di `AND` logico

L'operazione di `AND` logico prevede che il risultato sia vero se e solo se sia l-value che r-value sono veri. Di conseguenza, vale la seguente tabella:

| l-value | r-value | Risultato |
| ------- | ------- | --------- |
| 0       | 0       | 0         |
| 0       | 1       | 0         |
| 1       | 0       | 0         |
| 1       | 1       | 1         |

##### 17.3.1.1.2 - Operazione di `OR` logico

L'operazione di `OR` logico prevede che il risultato sia vero se e solo se almeno uno tra l-value ed r-value è vero. Di conseguenza, vale la seguente tabella:

| l-value | r-value | Risultato |
| ------- | ------- | --------- |
| 0       | 0       | 0         |
| 0       | 1       | 1         |
| 1       | 0       | 1         |
| 1       | 1       | 1         |

##### 17.3.1.1.3 - Operazione di `XOR` logico

L'operazione di `XOR` (_eXclusive OR_) logico prevede che il risultato sia vero se e solo se _esattamente_ uno tra l-value ed r-value è vero. Di conseguenza, vale la seguente tabella:

| l-value | r-value | Risultato |
| ------- | ------- | --------- |
| 0       | 0       | 0         |
| 0       | 1       | 1         |
| 1       | 0       | 1         |
| 1       | 1       | 0         |

#### 17.3.1.2 - Operatori logici unari

##### 17.3.1.2.1 - Operazione di `NOT` logico

L'unico operatore logico unario è l'operatore di `NOT` logico, che prevede che venga "negato" il valore in ingresso all'operatore. Di conseguenza, vale la seguente tabella:

| value | Risultato |
| ----- | --------- |
| 0     | 1         |
| 1     | 0         |

### 17.3.2 - Operatori logici nel linguaggio C

Il linguaggio C mette a disposizione un operatore per la maggior parte delle operazioni logiche. Detti operatori sono riassunti nella seguente tabella.

| Operazione | Operatore |
| ---------- | --------- |
| AND        | `&&`      |
| OR         | `||`      |
| NOT        | `!`       |

Per quello che riguarda lo XOR, questo non è messo direttamente a disposizione come operatore logico dal linguaggio C. Tuttavia, è possibile ricavarlo come combinazione degli altri operatori fondamentali: farlo è lasciato al lettore.

!!!tip "Suggerimento"
    Provate a fare un AND dei risultati delle operazioni di AND ed OR.

## 17.4 - Operatori logici binari

Un altro tipo di operatore logico presente nel C è quello _binario_, che opera non più a livello dell'intero dato, ma a livello di rappresentazione in termini di bit. Nella tabella successiva sono mostrati i principali operatori di questo tipo:

| Operatore | Descrizione   |
| --------- | ------------- |
| `>>`      | Right shift   |
| `<<`      | Left shift    |
| `&`       | AND bit a bit |
| `|`       | OR bit a bit  |
| `^`       | XOR bit a bit |

Soffermiamoci per un attimo sugli operatori di scorrimento. Questi, in buona sostanza, equivalgono a dividere (_right shift_) o moltiplicare (_left shift_) il nostro numero in rappresentazione binaria per 2 elevato all'r-value specificato sull'operatore. Se, ad esempio, abbiamo una variabile di tipo `byte` pari a 4, e quindi rappresentata in binario ad otto bit come:

```c
int 4 = 00000010;
```

applicando gli operatori di left shift e right shift otterremo, rispettivamente:

```c
a >> 1; // 00000010 / 2 = 00000001
a << 1; // 00000010 * 2 = 00000100
```

Per quello che riguarda invece gli operatori binari, questi funzionano esattamente come gli operatori logici classici, ma operano bit a bit. Ad esempio:

| Operatore | `a`      | `b`      | `risultato` |
| --------- | -------- | -------- | ----------- |
| `&`       | 10001011 | 01011010 | 00001010    |
| `|`       | 10001011 | 01011010 | 11011011    |
| `^`       | 10001011 | 01011010 | 11010001    |

## 17.5 - Conversione di tipo

Chiudiamo il discorso sugli operatori parlando dell'operazione di _conversione di tipo_, conosciuta anche come _casting_.

Come suggerisce il nome stesso, questa operazione permette di convertire un dato da un tipo (ad esempio, intero) ad un altro (ad esempio, float). Ovviamente, questa operazione deve tenere conto non solo delle differenze di formato, ma anche in termini di memoria occupata.

La conversione può essere di due tipi:

- nella conversione _implicita_, gli operatori matematici trattati in precedenza effettuano una conversione "automatica", semplificando di solito i tipi più complessi;
- nella conversione _esplicita_, è il programmatore che effettua la conversione mediante l'operazione di casting.

Vediamo alcuni esempi applicativi, partendo dalla conversione implicita. Provando a sommare due `float` ed associare al risultato una variabile di tipo `int`, avviene una conversione implicita.

```c
int a = 3.2 + 4.2; // il risultato sarà "troncato" a 7
```

Un'altra situazione nella quale avviene una conversione implicita è quella in cui si prova ad assegnare ad uno `short`, il cui valore massimo gestibile è 65535, un valore superiore; in questo caso, il valore verrà automaticamente troncato al limite massimo.

```c
ushort s = 9999999; // sarà troncato a 65.535
```

Per ciò che riguarda la conversione esplicita, invece, dobbiamo usare l'operatore di casting, che consiste nella specifica del tipo destinazione tra parentesi tonde. Ad esempio, per convertire un `int` in `float`:

```c
int a = 3;
float b = (float) a;
```

!!!warning "Nota sulle conversioni di tipo"
    In generale, è consigliabile _evitare_, per quanto possibile, di effettuare delle conversioni di tipo esplicite. Ovviamente, anche l'uso di conversioni di tipo in forma implicita è sconsigliato, perché conduce spesso ad errori di troncamento che, nel migliore dei casi, possono portare a risultati non attesi (e, nel peggiore, compromettere il funzionamento del software).
