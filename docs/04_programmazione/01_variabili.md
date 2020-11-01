Abbiamo già accennato al concetto di *variabile* nella parte introduttiva del corso, dove lo abbiamo definito come *dato di supporto*.

Questo suggerisce che una variabile non sia né un dato di ingresso al nostro programma, né un risultato atteso; è piuttosto una rappresentazione dello *stato interno* dell'algoritmo ad un dato istante.

E' facile osservare come le variabili siano di un'utilità estrema. Pensiamo ad esempio alla possibilità di inserire un contatore all'interno del nostro programma, che conti (ad esempio) il numero di operazioni eseguite, oppure ad una variabile di supporto, che ci permetta di modellare dei valori intermedi durante l'esecuzione di calcoli complessi.

La variabile, come indica il nome stesso, può *variare* durante l'esecuzione del programma. Ne esiste quindi una "controparte", assimilabile però dal punto di vista concettuale, chiamata *costante*: questa, ovviamente, non varia durante l'esecuzione del programma, ed è utilizzata per caratterizzare (ad esempio) delle costanti matematiche come il $\pi$.

!!! note "Nota sulle costanti"
	Normalmente, le costanti matematiche sono già caratterizzate all'interno del linguaggio di programmazione. Tuttavia, l'uso delle costanti deve essere valutato a seconda del programma, tenendo presente che la scelta tra variabile e costante è, molto spesso, soltanto da intendersi come *aiuto* al programmatore.

## Dichiarazione ed inizializzazione

La procedura per poter utilizzare una variabile si articola in due step fondamentali.

Il primo è la *dichiarazione* della variabile, operazione mediante la quale il computer "viene a conoscenza" dell'esistenza della variabile, associandovi un *identificatore* (o *nome*) ed un *tipo* (ci ritorneremo a breve).

Per esempio, ecco come è possibile dichiarare una variabile chiamata `numero` che rappresenta un numero intero in linguaggio C:

```c
int numero;
```

Una volta dichiarata la variabile, è necessario associarle un valore. Per farlo, si usa la procedura di *inizializzazione*, sfruttando l'operatore di assegnamento `=`. Ad esempio, assegnamo alla variabile `numero` il valore `1`:

```c
numero = 1;
```

E' possibile combinare le procedure di dichiarazione ed inizializzazione in un'unica istruzione:

```c
int altro_numero = 2;
```

## Tipo della variabile

Per *tipo* della variabile si intende il *formato* associato alla stessa, che ne influenza di conseguenza i valori che questa può rappresentare. I linguaggi di programmazione utilizzano quindi questo tipo di soluzione per differenziare (ad esempio) valori numerici di tipo intero da valori numerici di tipo reale, oppure ancora valori booleani da caratteri.

### Importanza del tipo

Tenere in conto il tipo di dato durante lo sviluppo di un programma è estremamente importante principalmente per due ragioni.

#### 1. Flusso logico del programma

La prima è legata alla *gestione del flusso logico del programma*. Immaginiamo, infatti, di dover sommare due numeri reali `x` ed `y`, e di voler associare il valore risultante da questa operazione alla variabile `z`, che però è di tipo intero:

```c
float x = 1.1;
float y = 1.2; 
int z;
z = x + y;
```

E' facile comprendere come, nonostante il valore atteso di `z` sia pari a `2.3`, avremo in realtà `2` a causa del fatto che `z` è un valore intero, con un errore di troncamento pari a `0.3`. Questo, ovviamente, nel caso in cui il programma venga comunque compilato: infatti, se il linguaggio impone un controllo stringente sul tipo di dato, è probabile che la procedura di compilazione non vada a buon fine.

##### Strani errori e come trovarli

E' importante stare attenti a situazioni nelle quali si sommano degli interi a dei caratteri. Ricordiamo infatti che ogni carattere ha una rappresentazione numerica associata in un determinato formato; quindi, in un linguaggio "particolarmente" permissivo, potrebbe essere concesso sommare un `intero` ad un `char`, ottenendo però risultati inaspettati.

Ad esempio, provando ad eseguire questa addizione:

```c
int x = 1;
char y = '1';

int z = x + y;
```

il valore di `z` ottenuto non sarà pari a 2, ma a 50!

#### 2. Quantità di memoria allocata per la variabile

Il tipo di dato ha forti implicazioni sulla quantità di memoria utilizzata da ogni variabile, e quindi sul numero di valori che è possibile rappresentare. La seguente tabella riporta queste associazioni per alcuni tipi di dato comunemente utilizzati.

| Denominazione | Spazio occupato | Descrizione |
| ------------- | --------------- | ----------- |
| `short` | 16 bit | Rappresenta un tipo di dato intero con precisione a 16 bit. |
| `int` | 32 bit | Rappresenta un dato di tipo intero con segno. |
| `uint` | 32 bit | Rappresenta un tipo di dato intero senza segno (*unsigned*) |
| `long` | 64 bit | Rappresenta un tipo di dato intero con precisione a 64 bit. |
| `float` | 32 bit | Rappresenta un tipo di dato reale con precisione a 32 bit. |
| `double` | 64 bit | Rappresenta un tipo di dato reale con precisione a 64 bit. |
| `bool` | 1 bit | Rappresenta un valore nell'algebra booleana (ovvero uno `0` o un `1`). |
| `char` | 1 byte | Rappresenta un singolo carattere. |

E' quindi importante scegliere il tipo di dato adatto alla specifica situazione. Se siamo sicuri, ad esempio, che tratteremo solo interi inferiori al 100, potremmo scegliere un formato di tipo `short` per risparmiare quanta più memoria possibile.

Cosa accadrebbe però se "infrangessimo" il limite massimo di valori degli short, ovvero $2^{16}$?

In questo caso, ovviamente, il tipo di dato (e quindi il quantitativo di memoria riservato per la variabile) non cambierebbe; ciò significa che avremmo un errore di troncamento legato al fatto che ogni valore superiore a $2^{16}$ (per la cronaca, 65.536) sarebbe approssimato (o meglio, *troncato*) proprio a quest'ultimo.

!!! note "Tipizzazione forte e debole"
	E' importante porre particolare attenzione alla *tipizzazione* offerta dal linguaggio in uso. In un linguaggio a tipizzazione forte, come il C, è **sempre** necessario specificare il tipo della variabile, ed è opportuno tenerne strettamente conto durante l'intero arco di esecuzione del programma. I linguaggi a tipizzazione debole, invece, come il Python, sono più permissivi da questo punto di vista. Tuttavia, laddove scrivere un programma in un linguaggio a tipizzazione debole può essere più semplice, è comunque facile ritrovarsi in situazioni inattese, in quanto al programmatore non verranno date indicazioni *a priori* sulla correttezza del flusso di esecuzione del programma.
