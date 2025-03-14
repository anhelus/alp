# 1.3 - Codifica analogica e digitale

Nella [lezione precedente](03_dig_an.md) abbiamo introdotto i diversi tipi di dato che possono essere sfruttati per la rappresentazione dell'informazione. Abbiamo però accennato anche ad un limite intrinseco di questa rappresentazione, ovvero la necessità di poterla rappresentare *all'interno di un calcolatore reale*.

Cerchiamo di capire cosa questa necessità implichi. Un computer, per quanto potente ed avanzato, ha una capacità di memorizzazione *finita*. Ciò significa, in altre parole, che la quantità di dati che è possibile immagazzinarvi non può andare oltre un certo quantitativo, per grande che questo sia. Questo è contrario ai principi fisici del mondo che ci circonda, che risulta essere composto da un numero *praticamente* infinito di informazioni.

!!!warning "Finitezza del mondo"
    Prima di imbracciare torce e forconi, i fisici vorranno porre particolare accento alla parola *praticamente*.

La conseguenza di questa contraddizione è che *non è possibile immagazzinare tutta l'informazione del mondo reale all'interno di un calcolatore elettronico*. Possiamo, però, codificarla in maniera tale che risulti essere (*virtualmente*) indistinguibile; per farlo, però, dovremo introdurre i concetti di *segnali* e *codifica analogica* e *digitale*.

## Segnali e codifica

### Segnali analogici

I segnali analogici sono quelli propri del mondo che ci circonda. Un esempio è la voce umana, così come la musica, o ancora tutto ciò che vediamo. Questi segnali sono *continui*: in analogia con il concetto matematico di funzione continua, li possiamo esperire senza particolari "salti". Ciò implica quindi che la struttura dell'entità informativa sia definita all'interno di un certo range di numeri *reali*, e possa quindi assumere un insieme *praticamente* infinito di valori.

Un segnale analogico, per essere trasmesso, deve essere *codificato*, ovvero tradotto in qualche altro tipo di segnale gestibile dall'apparato di trasmissione e/o ricezione. Pensiamo ai telefoni di una volta: questi non prevedevano certo un "magico" altoparlante che interconnetteva i due interlocutori, ma un vero e proprio circuito, che collegava il microfono nel nostro apparecchio all'altoparlante di quello del nostro amico (e viceversa), lungo il quale veniva trasmesso il segnale relativo alla voce dei conversanti. Questo circuito, ovviamente, non aveva alcun calcolatore al suo interno: doveva limitarsi a replicare una versione *compatta* della nostra voce da un capo all'altro, per cui era necessario trovare un modo per farlo senza perdere troppa dell'informazione presente nel segnale originario. Il modo per farlo era modificare questo segnale agendo sulla sua rappresentazione in frequenza, ampiezza, o fase.

!!!tip "Modulazione"
    Tutto sarà più chiaro quando vi interfaccerete con materie come Teoria dei Segnali e Comunicazioni Elettriche. O forse no.

Ora, la codifica analogica permette di mantenere una certa *analogia* tra la struttura dell'entità di informazione originaria e quella codificata. Tuttavia, è una codifica difficile da gestire, prona ad interferenze, rumore e ad un fenomeno chiamato *aliasing*. Inoltre, non è adatta a situazioni nelle quali il segnale può essere rappresentato sotto un'altra forma, non continua, ma *numerica*. In questi casi, è necessario guardare alla *codifica digitale*.

### Segnali digitali

Continuiamo con la comunicazione telefonica, e pensiamo a come avviene al giorno d'oggi. I nostri smartphone hanno al loro interno un microfono, un altoparlante ed un'antenna, che ricreano a grandi linee ciò che c'era nei telefoni di una volta. Oltre ciò, tuttavia, dispongono anche di un *computer*, che può essere sfruttato per codificare l'informazione della nostra voce (in trasmissione) o quella del nostro interlocutore (in ricezione). Per farlo, possiamo pensare di codificare il segnale analogico in ingresso (o uscita) in maniera *digitale*, convertendolo quindi da un'onda meccanica a valori continui in un insieme di *numeri*, i quali saranno trasmessi in maniera più semplice ed efficace sulla rete di telecomunicazioni.

Il concetto alla base della codifica digitale è quindi questo: prendere un'informazione analogica, selezionare un numero *finito* (ma appropriato) di configurazioni distinte ammissibili, e rappresentare l'informazione iniziale all'interno di una di queste configurazioni. In questo caso, dato che stiamo "discretizzando" un valore analogico, si fa spesso il paragone con una funzione di tipo *discreto*.

### Un vantaggio su tutti: il rumore

La scelta della codifica digitale pone un insieme di vantaggi non indifferente, che compensano la maggiore complessità delle tecniche e degli apparati coinvolti. Il vantaggio principale, però, sta nella *robustezza al rumore*.

Immaginiamo di voler fare una telefonata dal nostro smartphone: la ricezione sarà sicuramente differente tra una stanza schermata ed una zona nelle vicinanze di un'antenna per telecomunicazioni. In altri termini, l'ambiente circostante può introdurre del *rumore* nell'informazione gestita e trasmessa da un sistema *fisico* come lo smartphone o, per rimanere più vicini al nostro ambito, il computer.

Ciò è evidentemente un problema in caso di rappresentazione analogica, in quanto questa, come già detto, è *continua*: ciò implica la presenza di un numero potenzialmente infinito di possibili "configurazioni" dell'informazione che, se alterate, sarebbero più difficili da ricondurre allo stato originario. Una rappresentazione discreta come quella digitale, invece, limita il numero di possibili configurazioni, rendendo quindi più semplice isolare l'informazione originaria dal rumore.

## Campionamento e quantizzazione

Immaginiamo di visualizzare il segnale analogico associato alla nostra voce. Per farlo, pensiamo a quali informazioni vengono veicolate, ed al modo in cui lo sono. Intuitivamente, avremo due componenti: una potenzialmente "illimitata", data dal "tempo" associato all'emissione di un particolare suono, ed un'altra "limitata" all'interno di un range, associata (ad esempio) all'intensità del nostro tono. 

!!!tip "Rappresentare la voce"
    Ovviamente, potremmo estendere questa analisi ad altri "assi", come ad esempio la frequenza della nostra voce, ma, per semplicità, evitiamo.

Questa rappresentazione può essere visualizzata su un semplice piano cartesiano, in cui all'asse delle ascisse viene associato il tempo $t$, mentre all'asse delle ordinate l'intensità della nostra voce a quel determinato istante temporale.

Ora, è facile verificare come questa informazione sia continua *su entrambi gli assi*: abbiamo infiniti valori sull'asse temporale, ma anche sull'asse delle intensità, nonostante questi siano comunque limitati ad un certo range. Per digitalizzare il segnale, quindi, dovremo effettuare due operazioni: la prima prevederà l'isolamento di un certo numero di *campioni* rilevanti nel tempo, mentre la seconda andrà ad assegnare a tali campioni dei valori fissi, suddividendo l'intervallo iniziale in un numero più o meno elevato di *quanti* di informazione.

In breve, dovremo dapprima *campionare* il segnale, misurandolo ad intervalli regolari, per poi *quantizzarlo*, suddividendo il range in cui possono ricadere questi valori in $N$ possibili intervalli, anch'essi regolari, ognuno dei quali rappresentato da un unico valore in uscita (ad esempio, quello medio).

## Conclusioni

Abbiamo accennato in breve alla differenza tra segnale (e codifica) analogico e digitale. Tuttavia, manca ancora un pezzo al nostro puzzle, che vedremo nella prossima lezione, relativo al [sistema numerico](04_num_sis.md) che usiamo per rapprentare la nostra codifica.
