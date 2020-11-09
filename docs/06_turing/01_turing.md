## Modelli di calcolo

Prima di specializzarci nella costruzione di algoritmi (e poi di programmi) per un particolare calcolatore è bene convincersi che non esiste un unico modello di calcolo.

Ogni modello richiede un differente approccio alla soluzione dei problemi, proponendo un modello teorico di macchina di calcolo (esecutore) con caratteristiche e capacità differenti.

Basarsi su un modello di macchina astratta è necessario per poter confrontare l'efficienza di due differenti algoritmi, a prescindere dalla loro implementazione e dalla velocità del computer su cui eseguiremo il programma codificato in linguaggio macchina.

Basandoci su un modello di calcolo astratto, ma semplificato, è più semplice dimostrare in termini rigorosi la correttezza di un detertminato algoritmo.

## Macchina di Turing

Ideata nel 1936 dal matematico inglese Alan Turing, una delle figure più iomportanti che hanno contribuito alla definizione ed allo sviluppo dell'informatica.

E' una macchina astratta basata su due componenti:

* un nastro infinito (da questa caratteristica ne segue il fatto che la macchina di Turing non è realizzabile nella pratica) su cui la macchina può leggere e scrivere mediante 
* una testina di lettura e scrittura che, scorrendo sul nastro, è in grado di kleggerne e modificarne il contenuto

La macchina di Turing è un Automa a Stati Finiti Deterministico.

Il funzionamento della macchina è basato sul cambiamento di stato sulla base del contenuto (del simbolo) che è presente sul nastro in corrispondenza della testina di lettura/scrittura.

Dopo aver letto il contenuto della posizione corrente del nastro, la macchina, sulla base dello stato in cui si trova, è in grado di passare in un altro stato, scrivere qualcosa enlla posizione corrente del nastro, ed infine spostarsi a destra o a sinistra sul nastro stesso.

Il *nasto è infinito*, mentre gli stati sono in quantità finita (è un automa a stati finiti deterministico).

Il fatto che sia deterministico sta ad indicare che ad ogni coppia "stato/simbolo" che viene incontrata dalla macchina è univocmaente detremrinata l'azione e lo stato compiuto dalla macchina stessa. In questo modo la macchina può eseguire solo un'operazione per volta.



# problemi

per ogni problema che si intende risolvere è necessario progettare una macchina di Turing adeguata.

Per farlo è necessario definrie:

* l'alfabeto dei simboi che è possibile leggeere e scrivere sul nastro infinito
* gli stati in cui si può torvare la macchina
* le transizioni da uno stato ad un altro
* lo stato iiziale ed un insieme di stati finali

Per rappresentare l'automa possiamo disegnare un grafo degli stati, ovvvero una matrice di transizione.

*Esempio*

Letta una stringa di caratteri alfabetici, stabilire se termina con la lettera "a"

*Alfabeto*: a,b,c, ..., x, y, z, # (con # fine della stringa)

Strategia risolutiva

* Partendo dal primo carattere della stringa, scorrere verso destra il nastro fino a quando non incontro il carattere #
* ogni volta che trovo un carattere a la macchina si pone in uno stato di preallarme (S_1) e torna nello stato di "quiete (S_o) quando incontra una lettera dalla b alla z.

Se quando incontra il # si trova nello stato So allora la stringa non termina con la lettera a, e passa in $S_2$. Altrimenti, se si trova in $S_1$, vuol dire che la stringa termian con la lettera *a* e passa in $S3$.

TODO: grafo degli stati

La matrice di transizione è la seguente

|   | $S_0$ | $S_1$ | $S_2$ | $S_3$ |
| - | ----- | ----- | ----- | ----- |
| a | -, $D_x$, $S_1$ | -, $D_x$, $S_1$, | / | / |
| b-z | -, $D_x$, $S_0$ | -, $D_x$, $S_0$ | / | / |
| # | -, -, $S_2$ | -, -, $S_3$ | **No** | **Sì** |

## Tesi di Church-Turing

Anche assumendo altri modelli di calcolo, diversi dalla macchina di Turing, si afferma che tutti questi modelli sono fra loro equivalenti.

Un problema calcolabile secondo il modello della macchina di Turing è calcolabile anche rispetto ad altri modelli.


