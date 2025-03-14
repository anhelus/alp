# 1.7.2 - Le operazioni fondamentali dell'algebra booleana

Le tre operazioni fondamentali dell'algebra di Boole sono quelle di $AND$, $OR$ e $NOT$. Queste operazioni ci permettono di verificare la veridicità di predicati composti di complessità arbitraria: ad esempio, nel caso [visto in precedenza](01_intro.md), i tre predicati semplici sono combinati tra loro utilizzando una regola di tipo $AND$.

Approfondiamo ognuna di queste regole nel dettaglio.

## L'operazione di AND logico

L'operazione di *AND* logico è un'operazione di tipo *binario* chiamata anche *prodotto logico*. Il fatto che l'operazione *AND* sia binaria implica che siano coinvolti due predicati: riprendendo il nostro esempio, il primo predicato potrebbe essere *la palla è dentro la scatola*, mentre il secondo *la palla è verde*. Combinandoli, potremo scrivere che:

$$
la palla è dentro la scatola AND la palla è verde
$$

il che equivarrà a dire che la palla verde è dentro la scatola.

Appare quindi evidente come il prodotto logico non sia altro se non una funzione che permette di "comporre" diversi predicati semplici, andando a definire una condizione composta che risulta essere *vera* se e solo se tutti i predicati semplici al suo interno sono a loro volta veri. Per comprendere quest'ultima affermazione diamo un'occhiata alla figura successiva, nella quale la palla è adesso gialla.

![ball_box_yellow](./images/ball_box_fake.png)

In questo caso, la palla è sempre all'interno della scatola, quindi il predicato *la palla è dentro la scatola* continuerà ad essere vero. Tuttavia, il predicato *la palla è verde* non sarà più verificato, in quanto la palla avrà il colore giallo; di conseguenza, il prodotto logico, rappresentativo della *concomitanza* delle singole affermazioni, non sarà più vero.

Queste considerazioni ci permettono di scrivere la cosiddetta *tabella delle verità*, ovvero una tabella nella quale possiamo diagrammare tutti i possibili stati assumibili dai predicati atomici, assieme al corrispondente stato assunto dal predicato composto.

La costruzione della tabella delle verità è strettamente dipendente dal numero di predicati semplici implicati nell'operazione valutata. Nel caso del prodotto logico, l'operazione è di tipo binario, per cui abbiamo due predicati atomici che, per comodità, chiameremo $p_1$ e $p_2$. Ovviamente, le possibili combinazioni di questi predicati sono date dal prodotto cartesiano dei possibili stati che ciascuno può assumere (*vero* e *falso*); di conseguenza, essendo due gli stati assumibili da $p_1$, e due quelli assumibili da $p_2$, avremo un totale di $n_c = 2 \cdot 2 = 4$ possibili combinazioni. Stante questa valutazione, potremo costruire la tabella delle verità in questo modo: avremo in primis due colonne, una per ciascun predicato semplice, più una ulteriore colonna per rappresentare il valore assunto dal predicato composto a partire dai valori corrispondenti dei predicati semplici. Per quello che riguarda il numero di righe, invece, queste saranno quattro, ovvero tutte quelle necessarie a diagrammare le possibili combinazioni assunte dai predicati semplici, con la corrispondente combinazione assunta dal predicato composto. Il risultato per l'AND logico è il seguente.

| $p_1$ | $p_2$ | $\times$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $0$ |
| $1$ | $0$ | $0$ |
| $1$ | $1$ | $1$ |

La tabella rispecchia ciò che abbiamo detto in precedenza, ovvero che il prodotto è vero soltanto se i due predicati semplici sono veri. Associando, al solito, il valore $1$ alla verità, ed il valore $0$ al falso, vediamo come la tabella delle verità faccia in modo che il risultato sia $1$ soltanto se $p_1=1$ e $p_2=1$. In definitiva, possiamo dedurre che:

!!!quote "Prodotto logico"
    L'output atteso del prodotto logico sarà *vero* se e solo se $p_1$ è vero e $p_2$ è vero. In caso contrario, l'output atteso del prodotto logico sarà *falso*.

Proviamo a vedere cosa accade nella nostra situazione, sostituendo $p_1$ e $p_2$ con i valori "effettivi" del predicato:

* se *la palla NON è dentro la scatola* e *la palla NON è verde*, allora il predicato derivante dal prodotto logico *la palla è dentro la scatola E la palla è verde* è FALSO;
* se *la palla NON è dentro la scatola* e *la palla è verde*, allora il predicato derivante dal prodotto logico *la palla è dentro la scatola E la palla è verde* è FALSO;
* se *la palla è dentro la scatola* e *la palla NON è verde*, allora il predicato derivante dal prodotto logico *la palla è dentro la scatola E la palla è verde* è FALSO;
* se e solo se *la palla è dentro la scatola* e *la palla è verde*, allora il predicato derivante dal prodotto logico *la palla è dentro la scatola E la palla è verde* è VERO.

Al prodotto logico è associata una *porta logica*, mostrata nella figura sottostante, rappresentativa della forma grafica convenzionalmente associata.

![and_port](./images/and_port.png)

!!!tip "Perché prodotto?"
    Il lettore più attento si starà chiedendo da dove derivi la dicitura *prodotto*. Per capirlo, basta osservare la tabella delle verità: il risultato sarà $1$ soltanto quando entrambi i predicati hanno valore $1$, proprio come il classico prodotto algebrico.

## L'operazione di OR logico

L'operazione di *OR* logico è un'operazione di tipo *binario* chiamata anche *somma logica*. Così come il prodotto, anche la somma logica implica il coinvolgimento di due predicati, ma il funzionamento è (come ovvio) leggermente differente. Cerchiamo di comprenderla usando i predicati già introdotti.

In precedenza, infatti, abbiamo introdotto due possibili colori per la nostra palla, ovvero il verde ed il giallo. Questo implica che *la palla è verde* OPPURE *la palla è gialla*. Queste due condizioni sono mutualmente esclusive: nel nostro mondo, quindi, la palla non può contemporaneamente essere gialla e verde. Questo può essere modellato secondo questa tabella delle verità:

| $p_1$ | $p_2$ | $+$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $1$ |
| $1$ | $0$ | $1$ |
| $1$ | $1$ | $1$ |

Cerchiamo anche in questo caso di comprendere cosa accada basandoci su valori di $p_1$ e $p_2$ "comprensibili":

* se *la palla NON è gialla* e *la palla NON è verde*, allora il predicato derivante dalla somma logica *la palla è gialla OPPURE la palla è verde* è FALSO;
* se *la palla NON è gialla* ma *la palla è verde*, allora il predicato derivante dalla somma logica *la palla è gialla OPPURE la palla è verde* è VERO;
* se *la palla è gialla* ma *la palla NON è verde*, allora il predicato derivante dalla somma logica *la palla è gialla OPPURE la palla è verde* è VERO;
* se *la palla è gialla* ma *la palla è verde*, allora il predicato derivante dalla somma logica *la palla è gialla OPPURE la palla è verde* è VERO;

Da ciò deriva la definizione della somma logica.

!!!quote "Somma logica"
    L'output atteso della somma logica sarà *vero* se *almeno uno* tra i predicati $p_1$ e $p_2$ risulta essere vero, e falso altrimenti.

Anche alla somma logica è associata una porta, mostrata nella figura successiva.

![or_port](./images/or_port.png)

!!!tip "Perché somma?"
    Il fatto che questa operazione sia detta di *somma* deriva dal fatto che, così come per il prodotto, il risultato sia in qualche modo riconducibile a quello ottenibile seguendo le regole dell'aritmetica standard.

## L'operazione di NOT logico

L'operazione di *NOT* logico è definita come *negazione logica*. A differenza delle operazioni di *AND* ed *OR*, la *NOT* è un'operazione unaria che, prevedibilmente, interessa un unico predicato, che sarà *negato* a valle dell'applicazione dell'operazione.

Capirne il funzionamento è semplice: ad esempio, negare il fatto che *la palla è dentro la scatola* implica che la palla non sia dentro la scatola, e viceversa. Dal punto di vista della tabella della verità, la *NOT* è esplicitata come segue.

| $A$ | $\overline{A}$ |
| - | - |
| $0$ | $1$ |
| $1$ | $0$ |

Anche alla negazione logica è associata una porta, mostrata nella figura successiva.

![not_port](./images/not_port.png)
