# Architettura dei calcolatori

Immaginiamo di dover guidare un'automobile per andare da un punto $A$ ad un punto $B$. Indipendentemente dal percorso che vorremo seguire, o dal mezzo a disposizione, potremo essere abbastanza confidenti a riguardo del fatto che la nostra automobile avrà un volante, quattro (o più!) ruote, un motore (di qualsiasi tipo), e due o più pedali per accelerare e frenare. In altre parole, le automobili sono tutte più o meno basate su un'*architettura comune*.

Ciò avviene per molti degli oggetti che adoperiamo comunemente: il frigorifero, ad esempio, avrà sempre degli scompartimenti, uno o più sportelli, ed una pompa di calore, così come gli edifici in cui viviamo e lavoriamo. Di conseguenza, è facile dedurre che anche i calcolatori si basino su uno schema di massima condiviso, declinato poi nello specifico al variare di fattori quali produttore, sistema operativo, e via discorrendo.

Storicamente, i primi calcolatori utilizzavano un'architettura *fixed program*, ovvero *fissa*. In altre parole, i primi calcolatori erano programmati (anche meccanicamente) per eseguire un'unica funzione, e non potevano essere in alcun modo espansi o riprogrammati. Un esempio basilare di un calcolatore a programmazione fissa sono le calcolatrici non programmabili. Va da sè che l'utilizzabilità di un calcolatore di questo tipo è, giocoforza, limitata, e profondamente inadatta a come indendiamo il computer al giorno d'oggi. Pensiamo ad esempio a cosa accadrebbe se avessimo degli smartphone fixed program: dovremmo portare con noi almeno due telefoni, uno per effettuare le chiamate, ed uno per inviare messaggi!

!!!warning "Smartphone fixed program"
    L'esempio precedente è volutamente esagerato, e la realtà è molto più complessa di questa ovvia semplificazione.

Per ovviare a quello che, se non superato, sarebbe stato un ostacolo insormontabile alla pervasiva diffusione odierna dei computer, venne quindi introdotto il concetto di computer *stored program*, ovvero macchine riprogrammabili alla bisogna, ed adattabili a task differenti. Tale concetto venne per la prima volta introdotto dall'*architettura di Von Neumann*.

## Architettura di Von Neumann

L'*architettura di Von Neumann* venne teorizzata dal matematico ungherese John Von Neumann (del quale, come ovvio, eredita il nome) nel Secondo Dopoguerra, come modello di architettura di calcolatore *stored program* in grado di eseguire essenzialmente operazioni di tipo matematico interfacciandosi con il mondo esterno mediante opportuni supporti. In pratica, l'architettura di Von Neumann poteva combinare dei *dati* in modi *eterogenei* basandosi su un insieme di *istruzioni* dinamico e dipendente dal programma eseguito in quello specifico istante.

Per far questo, l'architettura proposta da Von Neumann è caratterizzata da tre componenti fondamentali, ovvero l'unità di elaborazione principale (in inglese *central processing unit*, o *CPU*), la *memoria*, e l'*interfaccia di input/output* (I/O); tutte queste componenti saranno tra loro collegate medinate il cosiddetto *bus di sistema*. Vediamole più nel dettaglio.

##### Central Processing Unit

La CPU è il "cuore" (o forse più propriamente il *cervello*) dell'architettura di Von Neumann. Il compito della CPU è "semplice": combinare tra loro dei *dati* seguendo determinate *istruzioni*. In pratica, la CPU è l'elemento dell'architettura che si occuperà, ad esempio, di verificare che $2$ sommato a $3$ faccia $5$, o che $-1$ sia uguale a sè stesso. Per farlo, la CPU si affida a tre diverse componenti:

* un'unità di controllo (*control unit*, CU), delegata alla gestione di tutti i segnali di controllo del processore. Nella pratica, la CPU si occupa di controllare il flusso di istruzioni e dati all'interno del processore, coordinando quindi le attività delle altre due componenti;
* un'unità aritmetico - logica (*arithmetic logical unit*, ALU), che si occupa di gestire tutte le operazioni di natura aritmetica e logica che la CPU può effettuare;
* una serie di *registri*, ovvero delle aree nelle quali la CPU può memorizzare tutta una serie di informazioni.

DA QUI




I registri si riferiscono a aree di memorizzazione ad alta velocità nella CPU. I dati elaborati dalla CPU sono estratti dai registri. Ci sono diversi tipi di registri usati nelle architeture.
- Accumualtore: meomoirizza i risultati dei calcoli fatti dall'ALU. Mantiene i risultati intermedi delle operazioni aritmentiche e logiche. Agisce come locazione temporanea di memoria su un dispositivo.
- Program Counter (PC) tiene traccia delle posizioni di memoria dell'istruzione successiv ada eseguire. Il PC quindi passa questo indirizzo successivo al Memory Address Register.
- Il Memory Address Register memorizza le posizioni in memoria delle istruzioni che devono essere estratte dalla memoria, o memorizzate.
- Current Instruction Register (CIR): memorizza le istruzioni di ppiù recente estrazione mentre attende che vengano codificate ed eseguite.
- Instruction Buffer Register (IBR): l'istruzione che non deve essere eseguita immediatamente viene messa in questo registro.


La CPU è l'unità centrale di elaborazione o, in altre parole, il *cervello* del computer, ed è delegata ad eseguire le istruzioni di calcolo, coordinando contestualmente le altre componenti del sistema. La CPU è a sua volta composta da una *Arithmetic Logic Unit* (ALU), che effettua tutte le operazioni aritmetiche e di logica booleana, ed una *Control Unit* (CU), responsabile per il controllo del funzionamento delle altre componenti. In particolare, la supervisione delle altre componenti avviene mediante un circuito "temporizzatore", comunemente chiamato *clock di sistema*.


ALU (Unità Aritmetico Logica): esegue le operazioni matematiche e logiche (addizione binaria, AND e OR) richieste dalle istruzioni;
Unità di Controllo: legge le istruzioni, le decodifica e le esegue ed effettua i controlli delle attività necessarie per l’esecuzione
Registri: sono molto veloci e con una capacità ridotta, costituiscono una memoria speciale (di supporto) per l’ALU poiché contengono le istruzioni di controllo necessarie per il suo funzionamento e i risultati temporanei delle elaborazioni.
La CPU esegue i programmi memorizzati nella memoria centrale procedendo nel modo seguente:
– estrae le istruzioni del programma dalla memoria
– le interpreta
– le esegue una dopo l’altra, fino ad ottenere il risultato

Quindi, affinché un computer possa svolgere un compito, deve eseguire un programma sull’insieme dei dati ricevuti in input, cioè deve manipolare i dati in input secondo l’elenco delle istruzioni, fino al raggiungimento della soluzione del problema.
Benché in memoria ci siano più dati e istruzioni, il processore li estrae uno alla volta e li elabora uno alla volta.

La velocità della CPU viene misurata in Megahertz (1 milione di cicli al secondo) o Gigahertz (1 miliardo di cicli al secondo).

##### Memoria centrale
La memoria
La Memoria contiene i dati e i programmi e la sua capacità è espressa in multipli del Byte.
Il Byte è una sequenza di otto bit, che insieme rappresentano un singolo carattere alfabetico e/o numerico. Le dimensioni della memoria sono espresse come multipli molto più grandi:
– Kilobytes (1.024 bytes),
– Megabytes (1.024 Kilobytes),
– GigaBytes (1.024 Megabytes),
– TeraBytes (1.024 Gigabytes).

I dispositivi di memoria possono essere suddivisi in più classi, in dipendenza della capacità e della velocità. Esistono due classi principali: la memoria centrale e la memoria secondaria.

La memoria Centrale ha una funzione di supporto alla CPU perché fornisce (ad alta velocità) le istruzioni del programma in esecuzione e i dati su cui operare. È composta da un insieme di locazioni (celle), ciascuna delle quali può memorizzare una parte delle informazioni. Ad ogni locazione è associato un indirizzo (ossia un numero che la identifica univocamente). La memoria centrale si suddivide in due componenti:

ROM (Read Only Memory): memoria di sola lettura, cioè i dati non sono modificabili dall’utente. È una memoria permanente (conserva le informazioni anche dopo lo spegnimento del computer) e contiene i programmi fondamentali per l’avvio del computer, noti come BIOS (che interagiscono con i circuiti della macchina).
RAM (Random Access Memory): memoria ad accesso casuale e di tipo volatile, cioè il suo contenuto va perso quando si spegne il computer. Contiene i dati (intermedi e finali delle elaborazioni) e le istruzioni dei programmi in esecuzione.
La memoria EPROM (Electric Programmable ROM) è paragonabile alla memoria ROM cui si è accennato in precedenza, ma, diversamente da quest’ultima, consente in particolari condizioni la modifica dei dati in essa contenuti. Ovviamente, qualsiasi modifica operata determina sostanziali modifiche nel funzionamento del computer, per cui la stessa non può essere oggetto di improvvisazione e deve essere affidata soltanto ad utenti esperti.

La memoria CACHE è invece destinata ad ospitare dati di frequente utilizzo, e consente un accesso più veloce a informazioni di recente acquisite e visualizzate; è il caso, ad esempio, dei dati cui si ha avuto accesso per mezzo di Internet. È una memoria molto utile e può essere “svuotata” a piacimento dall’utente, al fine di renderla disponibile per ulteriori archiviazioni temporanee.

La Memoria secondaria (o di massa) è più lenta, ha una elevata capacità di immagazzinare i dati (di uso non frequente) ed è stabile, ossia mantiene la memorizzazione delle informazioni anche dopo lo spegnimento del computer, per questo è utilizzata per la memorizzazione permanente di dati e programmi.


Memoria
Per quanto riguarda la memoria del computer, una prima distinzione si può fare tra memoria principale e memoria secondaria. La RAM (Random Access Memory) è la memoria centrale, può essere considerata una delle memorie principali assieme ai registri ed alla cache. La RAM riveste un ruolo fondamentale nell’architettura di Von Neumann: tutte le istruzioni ed i dati devono risiedere in RAM per poter essere utilizzati dalla CPU. La RAM è però volatile, dunque le informazioni in essa contenute si perderanno allo spegnimento del computer. Memorie volatili sono anche i registri, fra cui citiamo i registri MAR, MDR, PC, IR e PSW, che assumono un ruolo fondamentale nel ciclo delle istruzioni macchina, affrontato in questo post. 

Può essere classificata come memoria principale anche la ROM (Read Only Memory), che è una memoria persistente a sola lettura. La ROM contiene il programma di bootstrap, ovvero il programma che consente al sistema di avviarsi e caricare il software principale, che tipicamente è il sistema operativo.

Per quanto riguarda la memoria secondaria, citiamo il disco rigido (hard disk) ed i dischi a stato solido (SSD), sui quali vengono conservati dati e programmi in maniera persistente. Essendo persistenti, in tali dischi i dati si mantengono anche dopo lo spegnimento del computer.


##### Dispositivi di input/output


Input/Output
Gli hard disk, assieme ai lettori CD/DVD, alle tastiere, ai mouse, alle webcam, possono inoltre essere considerati dispositivi di input dell’architettura. Dispositivi di output sono invece stampanti e schermi. Dunque, i dispositivi di input servono ad inserire dati e/o a dare comandi al sistema, mentre i dispositivi di output servono a comunicare all’utente i dati elaborati dalla macchina. I vari dispositivi (detti anche periferiche) sono diversi tra loro e dunque necessitano di un’interfaccia comune per poter comunicare con gli altri componenti dell’architettura. Tale interfaccia è appunto l’interfaccia di I/O.

Dispositivi di I/O
I Dispositivi di Input/Output (o periferiche), sotto il controllo e coordinamento del processore, consentono l’interazione tra il computer e l’utente (più in generale, l’interazione tra il computer e l’ambiente), in particolare consentono l’immissione dei dati all’interno del computer e la comunicazione all’esterno dei risultati ottenuti con l’elaborazione.

Per unità di Input si intende un dispositivo che consente di immettere dei dati nel computer. Per unità di Output si intende un dispositivo che riceve dal sistema i risultati dell’elaborazione dei dati e li trasmette all’utente.

Esistono infine unità periferiche che svolgono entrambe le funzioni di input e output, per esempio:

Modem: è un dispositivo di ricetrasmissione, cioè che consente la comunicazione di più computer utilizzando la linea telefonica;
Monitor touch screen: è un dispositivo costituito da uno schermo ed un digitalizzatore, che consente all’utente di interagire con l’interfaccia grafica mediante apposita penna/stilo o con le dita.



##### Bus di sistema

Bus
Infine, il bus è il canale di comunicazione che permette di collegare tra loro i componenti dell’architettura, consentendo il transito delle informazioni. In particolare, nell’architettura di Von Neumann possiamo distinguere diverse linee nel bus di sistema:

bus di controllo, per abilitare la memoria in lettura o scrittura
bus di indirizzi, per individuare gli indirizzi di memoria
bus dati, per contenere i dati da leggere o scrivere
Una particolarità dell’architettura di Von Neumann è che istruzioni e dati viaggiano senza distinzione all’interno dell’unico bus di sistema presente. Questo non avviene invece nell'architettura Harvard, su cui sono basati i più famosi microcontrollori moderni, come ad esempio Arduino. Arduino è sicuramente uno dei microcontrollori più utilizzati in ambito didattico.




Analizziamo singolarmente ciascuna delle componenti.

Processore
Il processore (CPU, Central Processing Unit) è un interprete di istruzioni, costituito da tre componenti:









L'architettura di von neumann è anche detta ISA (Instruction Set Architecture) ed ha le tre compopnet di cui sopra.



Bus: i dati sono trasmessi da una paprte all'altra del computer mediante dei bus, connettendo tutti i componenti interni principali alla CPU ed alla memoria, per mezzo dei bus. Ve ne sono di diverso tipo:
- data buys: porta i dati tra l'unità di memoria, i dispositivi di I/O, ed il processore.
- address bus: porta l'indirizzo dei dati (non i dati veri e propri) tra la memorai ed il porocessore
- control bus: porta i comandi di controllo dalla CPU (ed i segnali di stato da altri dispositiv) per conrtrollare e coordinare tutte le attività all'interno del computer


dispsotiviti Input/Outpu:  i progrmami o i dati sono letti nlla mmeoria principale dal dispppositivo di input, o da memoria secondaria sotto il controllo delle istruzioni di input della CPU. I dispositivi di output sono suati per mandare in output informazioni da un computer. Se alcuni risultati sono valutati dal computer e memorizzati nel computer, allora, con l'aiuto dei dispositiiv di output, possono essere mostrati all'utente.


## Oltre i limiti dell'architettura di Von Neumann

L'architettura di Von Neumann presenta un importante collo di bottiglia, legato alla *sequenzialità* nell'esecuzione delle istruzioni. In altre parole, non possiamo svincolarci dal fatto che le istruzioni possono soltanto essere eseguiti in maniera sequenziale. In pratica, possiamo dare ad una CPU di Von Neumann con un quantiatitvo semprpe maggiore di cache, RAM, e componenti più veloci, ma il collo di bottiglia di Von Neumann limiterà sempre le prestazioni della CPU.

Inoltre, in un normale computer che segue l'architettura di von Neumann, le istruzioni ed i dati sono già memorizzate nella stessa area di memoria. Quindi gli stessi bus sono usati per spostare le istruzioni ed i dati. Questo implica che la CPU non può fare le due cose insieme, ovvero leggere le isturzioni e leggere o scrivere i dati. L'architettura di Harvard cerca di andare oltre, separando la memoria ed i bus per le istruzioni ed i dati. In pratica, è stata sviluppata per andare oltre il collo di bottiglia dell'architettura di Von Neumann. Il vantaggio principale di avere bus separati per le isturzioni ed i dati è che la CPU può accedere alle istruzioni e leggere o scrivere datin allo stesso tempo.

##### Struttura dell'architettura harvard

Bus: i bus sono usati come percorsi per i segnali. Nelle architettture Harvard, ci sono diversi bus per le istruzioni ed i dati. 

I *data bus* portano i dati tra la memoria di sistema, il processore, e i dispositivi di I/O.

Il data address bus porta l'indirizzo dei dati dal processore alla memoria di sistema principale di sistema.

L'instruction bus porta le isturzioni tra la memoria principale di sistema, il processore, ed i dispositivi I/O.

L'instruction address bus porta gli indirizzi delle istruzioni dal processore alla memoria principale.

##### Registri operazionali

CI sono diversi tipi di registri coinvolti che sono usati per memorizzare indirizzi di diversi tipi di istruzioni. Per esempio, il Memory Address Register ed il Memory Data Register sono registri operazionali.

Il pprogram counter memorizza la posizione dell'istruzione successiva da eseguire. Il program counter passa questo nbuovo indirizzo al memory address register.

L'Arithmetic and Logic Unit: la ALU è pparte della CPU che fa tutte i calcoli richiesti. Effettua addizioni, sottrazioni, comparazione, operazioni logiche, operazioni di bit shifting, e varie operazioni di natura aritmetica.

Control Unit: la control unit è la parte della CPPU che oppera tutti i segnali di controllo del processore. Controlla i dispositivi di input ed output fisici e controlla anche il movimento di istruzioni e dei dati nelm sistema.

Sistema di I/O: i dispositivi di input sono usati per leggere i dati nella memoria principale con l'aiuto delle istruzioni di input CPU. L'informazione da un computer come output è data attraverso i dispositivi di output. Il computer dà i risultati di calcolo con l'aiuto dei dispositivi di output.

Nell'harvard architecture ci sono spazi di memoria separata per le istruzioni ed i dati. Questa separazione assicura che il processore ppossa accedere contemporantamente alle memorie per istruzioni ed id ati, permettendo un recupero dei dati più rapido ed efficiente.

inoltre, c'è la questione della fixed instruction length. Nell'architettura harvard, le istruzioni sono tipicamente di lunghezza fissa, il che semplifica il processo di estrazione delle istruzioni e permette un'elabroazione delle istruzioni più rapida.

istruzioni parallelo ed accesso ai dati: dal momento che l'arhcitettura harvard separa gli spazi di memoria per le istruzioni ed i dati, il processore può accedere entrambi gli spazi di memoria simultaneaemnte, permettendo la parallelizzazione delle istruzioni e del processing dei dati.

Uso della memmoria più efficiente: l'architettura Harvard permette un uso della memoria più efficientein quanto le memorie per i dati e le istruzioni possono essere ottimizzate in maneira indiependetne, ottenendo performance migliori,

Adatta a sistemi integrati: l'architettura Harvard viene spesso usata in sistemi integrati perché fornisce un accesso veloce ed efficiente sia alle istruzioni, sia ai dati, che è critico in applicazion real-time.

Flessibilità limitata: gli spazi di memoria separati nell'architettura Harvard limitano la flessibilità del processore nell'effettuare alcuen task, come la modifica delle istruzioni a runtime. Questo è lefato al fatto che modificare le istruzioni richiede l'accesso alla relativa memoria, che è seaparata dalla data memory.

Sicurezza: la separazione degli spazi di istruzione e memoria può fornire un (teorico) grado di sicurezza contro alcuni tipi di attacchi informatici come il buffer overflow.

SVANTAGGI

* complessità: l'uso di spazi di memoria separati per le istruzioni ed i dati nelle architetture harvard aggiunge alla complessità del design del processore, e può quindi tradursi in un aumento nel costo di produzione.
* flessibilità limitata: l'architettura Harvard ha flessibilità limitata in termini di modifica di istruzioni a runtime, perché le istruzioni ed i dati sono memorizzati in spazi di memoria separati. questo può rendere ceerti tipi di programmazione più difficili, o anche impossibili, da implementare.
* maggiori requisiti di memoria: l'architettura harvard richied epiù memoria di quella di Von Neumann, con maggiori costi e consumi energetici.
* limitazione della code size: la fixed instruction length nell'architettura harvard può limitare la dimensioen del codice che può essere eseguito, rendendo il tutto non adatto ad alcune applicazioni con delle code base più larghe.
