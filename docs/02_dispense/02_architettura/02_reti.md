## Reti di telecomunicazione: cosa sono ed a che servono?

Nell'ultima lezione, abbiamo introdotto le principali caratteristiche dell'architettura interna di un calcolatore. Il naturale step successivo è quindi chiedersi *come possano comunicare tra loro due (o più) calcolatori*.

Ed è a questo scopo che sono state introdotte le *reti di telecomunicazione*.

### Alcune definizioni

#### Commutazione di circuito vs. commutazione di pacchetto

Le reti a *commutazione di circuito* stabiliscono una connessione fisica tra il mittente ed il destinatario. Un esempio di rete a commutazione di circuito sono le vecchie reti telefoniche, nelle quali veniva creato appunto un circuito fisico tra i due capi della comunicazione.

Le reti a *commutazione di pacchetto* invece non stabiliscono una connessione fisica tra il mittente ed il destinatario, ma fanno sì che siano i dispositivi di rete ad instradare i dati, opportunamente suddivisi in *pacchetti*, tra il mittente ed il destinatario.

#### Topologia di rete

### Standardizzazione

Affinché due calcolatori scambino dati (il che, nel gergo comune, significa "*affinchè due computer parlino tra loro*") è necessario che entrambi si adeguino ad uno standard di comunicazione.

Pensiamoci un attimo: saremmo forse in grado di capire ciò che dice il nostro docente di Informatica se non avessimo un protocollo di comunicazione comune?

!!! nota "Nota"
	Se alla domanda precedente avete risposto di *no*, la colpa è sicuramente vostra e non del docente di Informatica, che risulta essere chiaro, comprensibile, affabile e disponibile.

Lo scambio di dati tra due computer è inoltre molto più complesso rispetto alla comunicazione verbale: infatti, prevede che ciascuno dei due computer sia in grado di:

* *presentare* i dati scambiati all'utente finale;
* *identificare* sia il mittente sia il destinatario dei dati stessi;
* *codificare* i dati sotto forma di segnale fisico da inviare su degli opportuni canali di comunicazione fisici.

E' inoltre necessario che la comunicazione sia indipendente dal tipo di dispositivo utilizzato: se ci pensate, alcuni di voi seguono le lezioni da un iPad, altri dal proprio smartphone, altri ancora dal proprio laptop o PC desktop.

Abbiamo quindi una serie di vincoli da rispettare affinché due o più dispositivi comunichino. Ed è stato proprio questo il punto di partenza dal quale è stato definito un modello concettuale volto a *caratterizzare* e *standardizzare* la comunicazione tra dispositivi, indipendentemente dalle tecnologie adottate, ovvero il modello *ISO/OSI*.

## Il modello ISO/OSI

*OSI* è un acronimo che sta per *Open Systems Interconnection*, ed indica un modello sviluppato tenendo come obiettivo finale l'interoperabilità di diversi sistemi di comunicazione grazie a protocolli di comunicazione *standardizzati*. La storia del modello OSI nasce negli anni '70, in cui venne sviluppato per supportare la standardizzazione dei diversi tipi di rete di calcolatori emergenti. Negli anni '80, il modello venne adottato dall'*International Organization for Standardization* (*ISO*), ed assunse il nome di *modello ISO/OSI*.

Il modello ISO/OSI suddivide il flusso dei dati in un sistema di comunicazione in sette diversi livelli ad astrazione crescente, partendo dall'implementazione fisica della trasmissione dei bit sul canale comunicativo, per arrivare alla rappresentazione dei dati ad alto livello (ovvero quello che viene "presentato" all'utente).

E' importante sottolineare alcune caratteristiche del modello ISO/OSI. In primis, per quello che riguarda una singola macchina, ogni layer comunica esclusivamente con:

* il livello sottostante, di cui sfrutta le funzionalità;
* il livello sovrastante, cui fornisce una serie di funzionalità;

Nella comunicazione tra due macchine, invece, ogni layer comunica con il suo *pari* (*peer*): ad esempio, il layer fisico della macchina A parlerà soltanto con il layer fisico della macchina B; il layer di rete della macchina A solo con quello di rete della macchina B, e via dicendo.

### I livelli del modello ISO/OSI

Diamo ora una panoramica dei diversi livelli descritti dal modello.

#### Livello 1: Livello fisico

Il *layer fisico* è responsabile per la trasmissione e ricezione di dati grezzi (*raw*) tra due dispositivi. Per farlo, sfrutta un mezzo di trasmissione fisico (come ad esempio una guida d'onda o delle onde radio).

La sua funzione principale è quella di convertire i bit digitali in segnali di tipo elettrico, radio od ottico. Le specifiche del layer includono caratteristiche come livelli di tensione da utilizzare, bit rate, distanza massima di trasmissione, schema di modulazione dei dati e via dicendo.

Permette inoltre di definire tre modalità di trasmissione su un canale:

* *simplex*: in questo caso, la trasmissione è monodirezionale, senza che il ricevitore si alterni con il trasmettitore (e viceversa);
* *half-duplex*: in questo caso, la modalità di trasmissione è bidirezionale, ma il ricevitore si alterna con il trasmettitore (ovvero, la comunicazione non può avvenire contemporaneamente in entrambe le direzioni);
* *full-duplex*: in questo caso, la modalità di trasmissione è bidirezionale, e la comunicazione può avvenire contemporaneamente in entrambe le direzioni.

Questi includono dei pin, tensioni, impedenze di linea, specifiche dei cavi, timing del segmale e frequenza per i dispositivi wireless. Il controllo del bit rate è fatto a livello fisico e può definire delle modalità di trasmissione come *simplex*,  half-duplex o full duplex.

#### Livello 2: Livello data link

Il livello *data link* è quello che si occupa di stabilire un "collegamento" tra due diversi nodi. In particolare:

* individua e corregge gli errori che avvengono a livello fisico;
* definisce come vengono instaurate e terminate le connessioni;
* controlla il flusso dati.

##### Il progetto IEEE 802

Il progetto IEEE 802 definisce, relativamente soprattutto al livello data link, un insieme di standard per le reti locali, in inglese *Local Area Networks* (*LAN*).

In tal senso, la definizione data dal progetto IEEE 802 di rete locale è la seguente:

!!! quote LAN
	*Una LAN è un sistema di comunicazione che permette ad apparecchiature indipendenti di comunicare fra loro entro un'area delimitata usando un canale fisico a velocità elevata e con basso tasso di errore.*

Notiamo che la LAN non è quindi limitata nell'ambito (domestico, commerciale, industriale) né nelle tecnologie utilizzate: gli unici limiti sono l'area di interesse (giocoforza limitata), velocità ed affidabilità della comunicazione.

Il progetto IEEE 802 ha quindi suddiviso il livello data link in due diversi sottolivelli:

* il livello *Medium Access Control* (*MAC*) verifica come i dispositivi di rete accedono al mezzo fisico;
* il livello *Logical Link  Control* (*LLC*) controlla gli errori e sincronizza i frame.

Concretamente, esistono diversi protocolli definiti nell'ambito del progetto IEEE 802, che sono usati nelle comunicazioni di tutti i giorni. Un esempio sono le reti Ethernet, che aderiscono allo standard 802.3, e le reti WiFi, che aderiscono a diverse versioni dello standard 802.11 (arrivato di recente alla revisione *p*).

#### Livello 3: livello di rete

Il livello di *rete* definisce come trasferire sequenze di lunghezza arbitraria (*pacchetti*) tra due nodi connessi in reti differenti, laddove per *rete* si potrebbe intendere sia una singola LAN, sia l'interconnessione di diverse LAN.

E' sul concetto di *rete* che è necessario focalizzarsi. Infatti, ogni dispositivo in rete è comunemente detto *nodo*, e può trasferire messaggi agli altri nodi semplicemente specificando l'indirizzo degli stessi (oltre che ovviamente il messaggio); saranno i dispositivi di rete a trovar eil modo di consegnare il messaggio al destiantario, magari instradandolo attraverso i nodi intermedi.

Notiamo anche che la consegna dei messaggi a livello di rete non è strettamente *affidabile*; questo comporta quindi che i messaggi potrebbero essere persi, ed è quindi necessario prevedere altri meccanismi per garantire l'affidabilità della comunicazione.

#### Livello 4: livello di trasporto

Il livello di *trasporto* è quello delegato a garantire questa affidabilità mediante opportuni meccanismi di controllo di flusso e di errore.

Il modello ISO/OSI definisce cinque classi di protocolli a livello di trasporto, in base ai tipi di meccanismi di controllo dell'affidabilità. Si va dalla classe *TP0*, progettata per essere implementata su connessioni supposte *error-free*, ed i cui protocolli non forniscono alcun meccanismo per la gestione degli errori, fino alla classe *TP4*, che è quella che ricorda più da vicino i protocolli maggiormente usati a livello di trasporto in Internet.

#### Livello 5: livello di sessione

Il livello di sessione si occupa di controllare il "dialogo", ovvero le *connessioni*, tra i diversi computer, gestendone, tra le altre cose, l'inizializzazione e la chiusura.

#### Livello 6: livello di presentazione

Nel modello ISO/OSI, il livello di presentazione si occupa di stabilire un *contesto* tra due diverse entità, all'interno del quale le due possono comunicare *pur usando semantica e sentassi differenti*.

Il livello di presentazione funziona quindi un po' come un *traduttore*: fa in modo che due applicazioni, anche differenti, siano in grado di comunicare tra loro, fornendo una sorta di "dizionario" (o, più correttamente, *mappatura*) tra i linguaggi da loro compresi. E' anche per questo motivo che alle volte il livello di presentazione è anche chiamato *syntax layer*.

Oltre alla funzione di mapping, il livello di presentazione ne offre anche di altre, tra cui quella più importante è quella delegata alla compressione dei dati.

#### Livello 7: Livello applicativo

Il livello applicativo è quello più vicino all'utente, ed interagisce direttamente con gli applicativi software da questo utilizzati. E' importante sottolineare che la specifica di questi programmi *ricade al di fuori dell'ambito del modello ISO/OSI*; di conseguenza, le specifiche (ad esempio) del browser o di un'app per smartphone non saranno mai dettate dallo standard. 

Quest'ultima considerazione ci permette di distinguere tra *applicazione* ed *entità* legata all'applicazione: ad esempio, in un sito di prenotazione degli alberghi ci possono essere due entità, una che usa un protocollo a livello applicativo per comunicare con gli utenti, ed un'altra che usa un protocollo a livello applicativo per salvare i dati su un database remoto. Nessuna di queste due entità ha però a che fare con l'applicazione stessa, che è definita dalla *logica di business* (in questo caso, la prenotazione degli alberghi).

## Lo standard del mondo reale: lo stack TCP/IP

Il modello ISO/OSI non trova riscontro diretto nelle applicazioni reali: piuttosto, è l'*Internet Protocol Suite*, o *stack TCP/IP*, lo stack protocollare usato ed implementato su Internet. Come vedremo, la denominazione *stack TCP/IP* deriva direttamente dal nome dei due principali protocolli su cui è basato lo stack, ovvero il *Transmission Control Protocol* (*TCP*) e l'*Internet Protocol* (*IP*).

### I livelli dello stack TCP/IP

A differenza del modello ISO/OSI, lo stack TCP/IP è organizzato in quattro diversi livelli, più o meno riconducibili a quelli dell'ISO/OSI. Questi sono, dal più basso al più alto, il *livello link*, il *livello internet*, il *livello trasporto* ed il *livello applicativo*. Vediamoli di seguito.

#### Livello 1: Livello link

Il *livello link* si occupa di gestire la connessione limitatamente all'ambito della rete locale cui un host è collegato. Il *link*, o *collegamento*, include quindi tutti gli host che è possibile raggiungere senza dover coinvolgere un *router* (che è il dispositivo che permette la connessione tra diverse reti locali). Va da sé che la dimensione del link è determinata dal progetto della rete stessa.

Nel confronto con il modello ISO/OSI, il livello link racchiude le funzionalità corrispondenti a quelle del secondo layer (ovvero il *data link*). E' importante sottolieare come l'effettiva implementazione del progetto IEEE 802 sia avvenuta proprio a questo livello.

#### Livello 2: Livello internet

La comunicazione tra diverse reti richiede che i dati siano correttamente instradati dalla rete iniziale a quella di destinazione, secondo un processo chiamato *routing* e supportato dall'identificazione degli indirizzi degli host coinvolti mediante il sistema degli *indirizzi IP*.

Il livello internet fornisce una comunicazione *non* affidabile su reti differenti, garantendo l'inoltro dei pacchetti mediante dei dispositivi chiamati router. Il livello permette quindi l'interoperabilità di reti eterogenee, e definisce Internet nel modo in cui la conosciamo oggi.

Il protocollo principale usato a questo livello è l'*Internet Protocol*, che definisce due diversi sistemi di indirizzamento per l'identificazione degli host sulla rete. Il sistema originario di indirizzamento è chiamato *Internet Protocol version 4* (*IPv4*), ed usa un indirizzo a 32 bit per identificare un numero massimo di $2^32$ host.

Ovviamente, con il progressivo diffondersi delle reti di telecomunicazione, questo valore ha rappresentato un limite, che è stato dapprima arginato inserendo diverse classi di indirizzi riservati alle macchine interne ad ogni LAN, per poi essere superato nel 1998 mediante la standardizzazione dell'Internet Protocol version 6 (IPv6), che usa indirizzi a 128 bit.

Tuttavia, nonostante le schede di rete in grado di supportare IPv6 esistano dal 2006 circa, l'IPv4 è ancora il protocollo di comunicazione maggiormente utilizzato.

#### Livello 3: Livello di trasporto

Il livello di *trasporto* permette di creare dei "canali dati", che le applicazioni usano per lo scambio di messaggi specifici per determinati task.

La connettività può essere implementata sia come *connection-oriented*, mediante il protocollo TCP, o *connectionless*, mediante il protocollo UDP.

E' possibile fornire canali di trasmissione specifici per diversi processi mediante il concetto di *porta di rete*, ovvero la creazione di un costrutto logico numerico allocato specificamente per ognuno dei canali di comunicazione necessari. E' importante notare come, per molti servizi, questi numeri di porta siano stati standardizzati, in modo che i computer client possano indirizzare servizi specifici senza necessitare di tecniche di *service discovery*. Ad esempio, l'utilizzo standard del protocollo HTTP prevede il coinvolgimento della porta 80, mentre il protocollo SSH la porta 22.

Il layer di trasporto dello stack TCP/IP corrisponde approssimativamente al quarto livello del modello OSI, chiamato transport layer.

##### Trasmission Control Protocol

Il protocollo TCP è un protocollo *connection-oriented* che risolve i problemi di affidabilità che possono riscontrarsi nella fornitura di un flusso di byte affidabile. In particolare, il TCP garantisce che:

* i dati arrivino in ordine;
* i dati siano correttamente ricevuti;
* i dati duplicati siano scartati;
* i pacchetti persi o scartati siano nuovamente inviati;
* la congestione del traffico sia adeguatamente controllata.

##### User Datagram Protocol

Il protocollo *UDP* (*User Datagram Protocol*) è, a differenza del TCP, un protocollo *connectionless*, e si occupa di fornire una trasmissione dati non affidabile ma, non includendo il controllo degli errori tipico di TCP, più veloce. L'UDP è tipicamente usato per applicazioni legate allo streaming (audio, video e VoIP), dove l'arrivo in tempo dei dati è più importante dell'effettiva consegna degli stessi. Altri tipi di applicazioni sono quelle che prevedono esclusivamente semplici cicli di richiesta/risposta.

#### Livello 4: Livello applicativo

Il livello *applicativo* include i protocolli usati dalla maggior part edelle applicazioni per fornire servizi all'utente. Questi possono includere servizi di supporto di rete, come protocolli per il routing e la configurazione di rete. Un esempio di protocollo a livello applicativo sono l*Hypertext Transfer Protocol* (*HTTP*). I dati codificati secondo i protocolli a livello applicativo vengono quindi incapsulati in unità a livello di trasporto (ad esempio, in formato TCP o UDP), per poi venire ulteriormente incapsulati man mano che si scende verso il layer fisico.

E' interessante notare come lo stack TCP/IP non specifichi la formattazione e la presentazione dei dati, e non definisca dei layer aggiuntivi tra quello applicativo e di trasporto.

Per quello che riguarda la comunicazione con il livello di trasporto (e quelli sottostanti), il livello applicativo tratta quest'ultimo come una *black box*: non si occupa quindi dei dettagli implementativi dello stesso, anche se è a conoscenza di alcune informazioni fondamentali come indirizzo IP e numero di porta utilizzati.

Dal punto di vista del confronto con il modello ISO/OSI, possiamo dire che il layer applicativo del modello TCP/IP è spesso comparato ad una combinazione dei livelli di sessione, presentazione ed applicazione del primo.
