# 4 - Algebra booleana

## 4.1 - I circuiti elettronici digitali.

I circuiti elettronici digitali sono costruiti con elementi caratterizzati soltanto da due possibili stati di funzionamento, ovvero *alto* e *basso*.

I dispositivi elettronici a due stati di funzionamento sono giustificati da due fattori:

* facilità di realizzazione da un lato
* dall'altro, qualsiasi informazione può essere rappresentata mediante una successione di valori alti e bassi o, equivalentemente, 1 e 0

I segnali binari, corrispondenti ai due livelli di funzionaemnto degli elementi costitutivi del calcolatori, vengono trattati mediante l'algebra di Boole, introdotta da George Boole.

## 4.2 - L'algebra di Boole

L'algebra di Boole venne introdotta nel XIX secolo da Boole per analizzare algebricamente problemi di calcolo proposizionale, al fine di studiare le leggi del pensiero.

L'algebra di Boole è fondata su un insieme di teoremi e regole che goveranon le operazioni logiche e che ne consentono una rappresentazione matematica.

Sull'algebra di Boole si basa l'elettronica digitale ed il suo sviluppo.

L'algebra di Boole contempla due costanti 0 e 1, rispettivamente falso e vero. I due stati sono mutualmente esclusivi: ciò significa che si escludono a vicenda.

In pratica, possono descrivere lo stato di apertura (0) o chiusura di un generico contatto, o di un circuito a più contatti.

Sui valori booleani si definiscono diverse operazioni, tra cui le più importanti sono AND, OR, NOT e XOR.

Le operazioni AND ed OR sono di tipo binario, assieme alla XOR, mentre l'operazione NOT è unaria.

Nella valutazione delle espressioni booleane esiste una relazione di precedenza tra gli oepratori NOT, AND e OR, nell'ordine in cui sono stati elencati.

Gli operatori dell'algebra booleana possono essere rappresentati in vari modi.

Spesso sono descritti semplicemente come AND, OR e NOT. Nella descrizione dei circuiti appaiono sotto forma di porte logiche. In matematica si usa + per OR e x per AND, mentre si rappresenta il NOT con una barra posta sopra l'espressione che viene negata.

### 4.2.1 - L'operazione di AND

L'operazione di $AND$ è definita anche come *prodotto logico*. In particolare, il valore del prodotto logico è pari al simbolo $1$ se e solo se il valore di entrambi gli operandi coinvolti è pari ad $1$.

| A | B | $\times$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $0$ |
| $1$ | $0$ | $0$ |
| $1$ | $1$ | $1$ |

![and_port](./images/and_port.png)

### 4.2.2 - L'operazione di OR

L'operazione $OR$ è anche definita come *somma logica*.

In particolare, il valore della somma logica è il simbolo $1$ se e solo se almeno uno dei due operandi ha valore $1$.

| A | B | $+$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $1$ |
| $1$ | $0$ | $1$ |
| $1$ | $1$ | $1$ |

![or_port](./images/or_port.png)

### 4.2.3 - L'operazione NOT

L'operazione $NOT$ è definita come *negazione logica*.

In particolare, l'operatore inverte il valore della costante su cui opera.

| A | $\hat{A}$ |
| - | - |
| $0$ | $0$ |
| $0$ | $1$ |
| $1$ | $0$ |
| $1$ | $1$ |
