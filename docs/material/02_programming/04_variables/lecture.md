# 2.4 Le variabili

Comprendere il concetto di *variabile* è fondamentale (o, per meglio dire, *propedeutico*) all'acquisizione dei fondamentali della programmazione.

Per capire di cosa si tratta, possiamo analizzare il significato della parola nella lingua italiana: intuitivamente, una variabile rappresenta una *quantità* (o, in maniera molto più "lasca", un dato) a cui è "concesso" di variare durante l'esecuzione del programma. Risulta importantissimo sottolineare come una variabile non sia quindi necessariamente un dato di ingresso o un risultato atteso: si tratta piuttosto di una rappresentazione (parziale) dello stato interno del programma ad un dato istante.

Una variabile può essere quindi qualsiasi dato contenuto nel nostro programma: ci sono variabili che contano il numero di operazioni eseguite, ad esempio, oppure ancora variabili di supporto, che ci permettono di memorizzare stati intermedi durante l'esecuzione di iterazioni complesse.

!!!note "Nota"
    Non tutti i dati contenuti in un programma sono delle variabili: esistono anche delle *costanti*, che si differenziano dalle variabili per la caratteristica di *non* poter variare durante l'esecuzione del programma. Di solito, le costanti vengono utilizzate per modellare valori ben definiti, come ad esempio il $\pi$.

## Dichiarare ed inizializzare una variabile

Per poter utilizzare una variabile all'interno del nostro programma dovremo seguire due step fondamentali, *indipendentemente dal linguaggio di programmazione scelto*. In particolare:

* nel primo step, chiamato *dichiarazione* della variabile, dovremo "informare" il programma dell'esistenza della stessa, associandovi un *identificatore* (ovvero, un nome) ed il *tipo* di dato rappresentato dalla stessa;
* nel secondo step, chiamato *inizializzazione*, dovremo assegnare un valore iniziale alla nostra variabile, in accordo ovviamente al tipo di dato utilizzato.

Ad esempio, per dichiarare una variabile di tipo `type` chiamata `identifier`, dovremo usare una sintassi di questo tipo:

```c
type identifier;
```

Successivamente, potremo inizializzare la variabile `identifier` con il valore `value`:

```c
identifier = value;
```

Le due operazioni non sono necessariamente separate, e possono essere combinate in un'unica istruzione.

```c
type identifier = value;
```

!!!note "Nota"
    Vedremo un gran numero di esempi pratici di dichiarazione ed inizializzazione.

## Identificatore della variabile

In genere, la scelta dell'identificatore da associare ad una variabile lascia vasta libertà di scelta al programmatore. Tuttavia, occorre tenere a mente che, indipendentemente dal linguaggio, non sarà possibile usare come identificatore una keyword (ad esempio, non è possibile chiamare una variabile `if` o `long`); inoltre, è fortemente consigliato attenersi allo *styling code* del linguaggio.

Facciamo un paio di esempi. Il linguaggio Java, che non tratteremo, adotta per convenzione uno styling code chiamato *camel case*, che prevede che parole consecutive siano unite tra di loro, con l'iniziale di ogni parola successiva alla prima in maiuscolo. Ad esempio:

```java
int integerVariable = 1;
```

Python, invece, utilizza per convenzione lo stile *snake case*, che prevede che parole consecutive siano "unite" mediante un simbolo di underscore, lasciando tutte le lettere minuscole:

```python
integer_variable = 1
```

!!!note "Sulla scelta del nome"
    La scelta del nome da assegnare ad una variabile *non* è casuale. Il suggerimento è quello di assegnare nomi *esplicativi*, oltre che *univoci*: ad esempio, un contatore chiamato `cnt` sarà sicuramente più riconoscibile di un contatore chiamato `pippo_joy`.

## Tipo della variabile

Il tipo della variabile definisce il tipo di dato associato alla stessa; come abbiamo visto nella [lezione 4](../07_data_structures/01_intro/lecture.md), quindi, ciò influenzerà il range di valori che questa può rappresentare. Ponderare adeguatamente il tipo di dato da usare per una variabile è quindi *estremamente importante*, principalmente per due ragioni:

1. *flusso logico*;
2. *complessità computazionale spaziale*.

Partiamo dal flusso logico. Immaginiamo di dover sommare tra loro due numeri reali`x` ed `y`, e di voler associare il valore risultante da questa operazione alla variabile `z`. Al momento della scrittura del codice, decidiamo di assegnare (correttamente) il tipo `float` ad `x` ed `y` ma, per una disattenzione, assegnamo il tipo `int` alla variabile `z`:

```c
float x = 1.1;
float y = 1.2; 
int z;
z = x + y;
```

Cosa accadrà? Consideriamo che il valore che ci attendiamo che `z` assuma è pari `2.3`: tuttavia, avremo come output `2`, principalmente a causa del tipo di `z`. Ciò comporterà quindi un *errore di troncamento* pari a `0.3`.

Per quello che riguarda invece la complessità computazionale spaziale, ricordiamo, sempre dalla lezione 4, che ogni tipo di dato richiede una quantità di memoria differente, ma al tempo stesso permette di memorizzare un range di valori più o meno ampio.

Questa caratteristica può e deve essere usata a nostro vantaggio: infatti, qualora fossimo sicuri che le nostre variabili intere assumono *sempre* valori compresi tra 0 e 100, potremmo utilizzare dati di tipo `byte`. Tuttavia, se per qualche motivo una variabile si trovasse ad assumere un valore *superiore* a 256, avremmo un *errore di buffer overflow*, che porterebbe la variabile a "ritornare" a zero, con conseguenze facilmente intuibili.

!!!note "Curiosità"
    Errori di questo tipo possono portare ad esiti catastrofici. Ad esempio, nel 1995, il razzo spaziale [Ariane 5 esplose 39 secondi dopo il lancio](https://www.laserfiche.com/ecmblog/whats-worst-software-bug-history/) perché nel software di controllo dell'altitudine era stato usato un intero a 16 bit piuttosto che a 64 bit.
