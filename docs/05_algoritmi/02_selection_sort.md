## Introduzione al problema

Ordinare una lista di elementi (ovviamente dello stesso tipo) può aiutare ad individuare rapidamente un certo elemento della stessa. In tal senso, esistono diversi algoritmi, chiamati *algoritmi di ordinamento* (o, in inglese, *sorting algorithms*).

Il primo, e più semplice, algoritmo di ordinamento è chiamato *selection sort*. Per comprenderne il funzionamento, ricorriamo (al solito) ai nostri cari Alice e Bob.

## Descrizione dell'algoritmo

Il selection sort è un algoritmo *iterativo*: ad ogni iterazione, viene analizzato un elemento della lista

L'idea alla base del selection sort è quella di *scambia

Invece di sviluppare il tema d’anno di Informatica, Alice e Bob decidono di prendersi il pomeriggio libero, e si imbattono nel vecchio mazzo di carte del cugino di Bob.

“Alice, ricordi il caffè che ho perso l’altra volta? Beh, ho in mente un modo per riaverlo indietro.”
“Dimmi pure. Cosa hai in mente?”
“Scommetto che non riesci a trovare una maniera algoritmica per ordinare questo vecchio mazzo.”
“Scommessa accettata.”

Alice, che ricordiamo essere una assidua frequentatrice del corso di Informatica, inizia facendo queste mosse.

Per prima cosa, dispone tutte le carte presenti nel mazzo lungo un’unica fila. A quel punto, inizia a cercare la carta più piccola, e la posiziona al primo posto.
Successivamente, suddivide la fila in due: a sinistra mette le carte già ordinate (ovvero, la prima carta), ed a destra quelle ancora da ordinare.
A quel punto, prende dalla fila di destra la carta più piccola, e la posiziona immediatamente a destra dell’ultimo elemento della fila di sinistra. Fatto questo, reitera questa procedura fino a che la fila di destra non è completamente vuota, mentre quella di sinistra ha al suo interno tutte le carte ordinate.

“Ok, Alice, hai ordinato le carte, ma non vedo alcun algoritmo.”
“E’ qui che ti sbagli, mio caro.”

Ed Alice, pregustando la vittoria, elenca a Bob le istruzioni che ha eseguito, dimostrando che la procedura che ha eseguito è modellabile secondo l’algoritmo di selection sort.

Sia x un array di n elementi interi.
Associare ad i il primo indice dell’array (0), ed a j l’ultimo (n-1).
Associare ad una variabile il valore di x(0), e supporre che sia il valore minore.
Confrontare tutti gli elementi di x(k), con k che va da 1 ad n - 1, con x(0). Aggiornare il valore di x(0) nel caso x(k) minore di x (0).
Incrementare di 1 il valore di i.
Ritornare all’istruzione 4 fino a che i == j.

Un esempio pratico
Immaginiamo di avere un array con valori [12, 4, 8, 7, 2]. Per prima cosa, vediamo che il valore di i sarà pari a 0, mentre j sarà pari a 4.

A questo punto, poniamo min = x(0) = 12. Vediamo che x(1) = 4 è minore di 12, per cui il valore min viene aggiornato, e risulta essere pari a 4. Andiamo avanti, e compiamo soltanto un altro aggiornamento, ovvero quando vediamo che x(4) minore di min. A questo punto, inseriamo x(0) all’estrema sinistra (posizione i).

Aggiorniamo il valore di i ad 1, e reiteriamo la procedura, fino ad ottenere l’array finale:

[12, 4, 8, 7, 2]
i = 0; j = 4;
min = x(0) = 12;
min = x(4) = 2;
new = [2, 12, 4, 8, 7]
i = 1;
min = x(1) = 12;
min = x(2) = 4;
new = [2, 4, 12, 8, 7]
i = 2;
min = x(2) = 12;
min = x(4) = 7;
new = [2, 4, 7, 12, 8]
i = 3;
min = x(3) = 12;
min = x(4) = 8;
new = [2, 4, 7, 8, 12]
return

TODO FLOW CHART

Analisi dell’algoritmo
Il selection sort itera su tutti gli indici di un array. Supponiamo di avere un array di n elementi; avremo (ovviamente) n indici.

Per capire quante operazioni sono necessarie per completare l’operazione di ordinamento, dobbiamo contare il numero di confronti necessari ad individuare l’elemento minore attualmente presente nell’array. In particolare, alla prima iterazione, quando i = 0, avremo la necessità di effettuare n operazioni, una per ogni elemento dell’array. Alla seconda iterazione, quando i = 1, dovremo fare n - 1 confronti; alla terza, basteranno n - 2 confronti, e così via. Ciò significa che avremo bisogno di n + (n-1) + … + 2 + 1 confronti; ciò equivale ad una serie aritmetica pari a (n^2/2) + n/2. La complessità di caso peggiore tiene però conto di un limite asintoticamente superiore di questa serie, che è pari ad n^2; ciò significa che saremo in una situazione per cui la complessità computazionale è pari ad O(n^2).

Nota 
Una complessità di questo tipo ci permette di notare che il tempo richiesto all’esecuzione dell’algoritmo cresce molto velocemente al crescere del numero di elementi dell’array. Con n = 10, infatti, avremo bisogno di 100 unità di tempo. Supponendo che un’unità di tempo sia pari ad un microsecondo, avremo bisogno di 0.1 secondi. Se n = 100, allora avremo bisogno di 10 secondi. Se n = 1.000, invece, avremo bisogno di 1.000 secondi (ovvero quasi 17 minuti!).
