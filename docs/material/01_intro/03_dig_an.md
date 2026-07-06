# 1.3 - Codifica analogica e digitale

Nella [lezione precedente](02_data_repr.md) abbiamo classificato i dati in tipi (categorici, ordinali, numerici) e visto come rappresentarli come numeri interi. Ora dobbiamo fare un passo avanti: quei numeri devono essere rappresentati *fisicamente* all'interno di un calcolatore reale.

Cerchiamo di capire cosa questa necessità implichi. Un computer, per quanto potente ed avanzato, ha una capacità di memorizzazione *finita*. Ciò significa, in altre parole, che la quantità di dati che è possibile immagazzinarvi non può andare oltre un certo quantitativo, per grande che questo sia. Questo è contrario ai principi fisici del mondo che ci circonda, che risulta essere composto da un numero *praticamente* infinito di informazioni.

!!!warning "Finitezza del mondo"
    Prima di imbracciare torce e forconi, i fisici vorranno porre particolare accento alla parola *praticamente*.

La conseguenza di questa contraddizione è che *non è possibile immagazzinare tutta l'informazione del mondo reale all'interno di un calcolatore elettronico*. Possiamo, però, codificarla in maniera tale che risulti essere (*virtualmente*) indistinguibile; per farlo, però, dovremo introdurre i concetti di *segnali* e *codifica analogica* e *digitale*.

## Segnali e codifica

### Segnali analogici

I segnali analogici sono quelli propri del mondo che ci circonda. Un esempio è la voce umana, così come la musica, o ancora tutto ciò che vediamo. Questi segnali sono *continui*: in analogia con il concetto matematico di funzione continua, li possiamo esperire senza particolari "salti". Ciò implica quindi che la struttura dell'entità informativa sia definita all'interno di un certo range di numeri *reali*, e possa quindi assumere un insieme *praticamente* infinito di valori.

Un segnale analogico, per essere trasmesso, deve essere *codificato*, ovvero tradotto in qualche altro tipo di segnale gestibile dall'apparato di trasmissione e/o ricezione. Pensiamo ai telefoni di una volta: questi non prevedevano certo un "magico" altoparlante che interconnetteva i due interlocutori, ma un vero e proprio circuito, che collegava il microfono nel nostro apparecchio all'altoparlante di quello del nostro amico (e viceversa), lungo il quale veniva trasmesso il segnale relativo alla voce dei conversanti. Questo circuito, ovviamente, non aveva alcun calcolatore al suo interno: doveva limitarsi a replicare una versione *compatta* della nostra voce da un capo all'altro, per cui era necessario trovare un modo per farlo senza perdere troppa informazione presente nel segnale originario. Il modo per farlo era modificare questo segnale agendo sulla sua rappresentazione in frequenza, ampiezza, o fase.

!!!tip "Modulazione"
    Tutto sarà più chiaro quando vi interfaccerete con materie come Teoria dei Segnali e Comunicazioni Elettriche. O forse no.

Ora, la codifica analogica permette di mantenere una certa *analogia* tra la struttura dell'entità di informazione originaria e quella codificata. Tuttavia, è una codifica difficile da gestire, prona ad interferenze, rumore e ad un fenomeno chiamato *aliasing* (di cui parleremo meglio tra poco). Inoltre, non è adatta a situazioni nelle quali il segnale può essere rappresentato sotto un'altra forma, non continua, ma *numerica*. In questi casi, è necessario guardare alla *codifica digitale*.

### Segnali digitali

Continuiamo con la comunicazione telefonica, e pensiamo a come avviene al giorno d'oggi. I nostri smartphone hanno al loro interno un microfono, un altoparlante ed un'antenna, che ricreano a grandi linee ciò che c'era nei telefoni di una volta. Oltre ciò, tuttavia, dispongono anche di un *computer*, che può essere sfruttato per codificare l'informazione della nostra voce (in trasmissione) o quella del nostro interlocutore (in ricezione). Per farlo, possiamo pensare di codificare il segnale analogico in ingresso (o uscita) in maniera *digitale*, convertendolo quindi da un'onda meccanica a valori continui in un insieme di *numeri*, i quali saranno trasmessi in maniera più semplice ed efficace sulla rete di telecomunicazioni.

Il concetto alla base della codifica digitale è quindi questo: prendere un'informazione analogica, selezionare un numero *finito* (ma appropriato) di configurazioni distinte ammissibili, e rappresentare l'informazione iniziale all'interno di una di queste configurazioni. In questo caso, dato che stiamo "discretizzando" un valore analogico, si fa spesso il paragone con una funzione di tipo *discreto*.

### Un vantaggio su tutti: il rumore

La scelta della codifica digitale pone un insieme di vantaggi non indifferenti, che compensano la maggiore complessità delle tecniche e degli apparati coinvolti. Il vantaggio principale, però, sta nella *robustezza al rumore*.

Immaginiamo di voler fare una telefonata dal nostro smartphone: la ricezione sarà sicuramente differente tra una stanza schermata ed una zona nelle vicinanze di un'antenna per telecomunicazioni. In altri termini, l'ambiente circostante può introdurre del *rumore* nell'informazione gestita e trasmessa da un sistema *fisico* come lo smartphone o, per rimanere più vicini al nostro ambito, il computer.

Ciò è evidentemente un problema in caso di rappresentazione analogica, in quanto questa, come già detto, è *continua*: ciò implica la presenza di un numero potenzialmente infinito di possibili "configurazioni" dell'informazione che, se alterate, sarebbero più difficili da ricondurre allo stato originario. Una rappresentazione discreta come quella digitale, invece, limita il numero di possibili configurazioni, rendendo quindi più semplice isolare l'informazione originaria dal rumore.

## Campionamento e quantizzazione

Immaginiamo di visualizzare il segnale analogico associato alla nostra voce. Per farlo, pensiamo a quali informazioni vengono veicolate, ed al modo in cui lo sono. Intuitivamente, avremo due componenti: una potenzialmente "illimitata", data dal "tempo" associato all'emissione di un particolare suono, ed un'altra "limitata" all'interno di un range, associata (ad esempio) all'intensità del nostro tono. 

!!!tip "Rappresentare la voce"
    Ovviamente, potremmo estendere questa analisi ad altri "assi", come ad esempio la frequenza della nostra voce, ma, per semplicità, evitiamo.

Questa rappresentazione può essere visualizzata su un semplice piano cartesiano, in cui all'asse delle ascisse viene associato il tempo $t$, mentre all'asse delle ordinate l'intensità della nostra voce a quel determinato istante temporale.

Ora, è facile verificare come questa informazione sia continua *su entrambi gli assi*: abbiamo infiniti valori sull'asse temporale, ma anche sull'asse delle intensità, nonostante questi siano comunque limitati ad un certo range. Per digitalizzare il segnale, quindi, dovremo effettuare due operazioni: la prima prevederà l'isolamento di un certo numero di *campioni* rilevanti nel tempo, mentre la seconda andrà ad assegnare a tali campioni dei valori fissi, suddividendo l'intervallo iniziale in un numero più o meno elevato di *quanti* di informazione.

In breve, dovremo dapprima *campionare* il segnale, misurandolo ad intervalli regolari, per poi *quantizzarlo*, suddividendo il range in cui possono ricadere questi valori in $N$ possibili intervalli, anch'essi regolari, ognuno dei quali rappresentato da un unico valore in uscita (ad esempio, quello medio).

!!!example "Esempio: campionamento di un segnale"
    Immaginiamo un segnale che varia tra $0$ e $10$ volt, e decidiamo di quantizzarlo in $5$ intervalli (quindi $N=5$, ogni quanto vale $2$V). Se campioniamo il segnale a $4$ istanti di tempo e otteniamo i valori $1.3$V, $6.7$V, $9.1$V, $4.2$V, dopo la quantizzazione avremo rispettivamente $0$V (intervallo $0-2$), $6$V (intervallo $6-8$), $10$V (intervallo $8-10$), $4$V (intervallo $4-6$). L'informazione originale è approssimata, ma rappresentabile con soli $3$ bit.

!!!info "Il teorema di Nyquist"
    Per poter ricostruire fedelmente un segnale analogico a partire dai suoi campioni digitali, è necessario campionarlo ad una frequenza almeno doppia rispetto alla frequenza massima presente nel segnale stesso. Se si campiona a una frequenza inferiore, si incorre in un fenomeno chiamato *aliasing* (lo stesso accennato prima), che produce artefatti e distorsioni.

## Conclusioni

Abbiamo accennato in breve alla differenza tra segnale (e codifica) analogico e digitale. Tuttavia, manca ancora un pezzo al nostro puzzle, che vedremo nella prossima lezione, relativo al [sistema numerico](04_num_sis.md) che usiamo per rappresentare la nostra codifica.
