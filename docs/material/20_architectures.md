# XX - L'architettura dei calcolatori

## La macchina di Von Neumann

La macchina di Von Neumann venne per la prima volta teorizzata e progettata dal matematico ungherese John Von Neumann attorno alla metà del secolo scorso.

Una macchina di Von Neumann si basa su quattro componenti fondamentali, come quelli mostrati in figura 1.

TODO FIGURA

In particolare, abbiamo la **central processing unit** (CPU), la **memoria centrale**, l'interfaccia di I/O, ed il bus di sistema.

Vediamo queste componenti nel dettaglio.

### CPU

La CPU è la parte centrale di elaborazione della macchina di Von Neumann, e possiamo pensarla come una sorta di "cervello" dell'elaboratore. Il suo compito principale è quello di eseguire le istruzioni di calcolo e 

### La memoria

Dal punto di vista delle macchine moderne, sono stati inseriti uno o più livelli di *memoria cache*

Lo schema si basa su 4 componenti fondamentali:

CPU
RAM
Interfaccia di I/O (Input/Output)
Bus di sistema
CPU
La CPU (Central Processing Unit) è l'unità centrale di elaborazione e si può definire come il “cervello” del computer. La CPU esegue le istruzioni di calcolo e di controllo, coordinando le altre componenti nell’esecuzione delle istruzioni stesse. La CPU, detta anche processore, si suddivide in:

ALU (Arithmetic Logic Unit), che effettua i calcoli aritmetici e logici;
CU (Control Unit), è l'unità di controllo, che sovrintende al funzionamento delle altre componenti.
La CPU coordina le altre componenti del sistema utilizzando un circuito temporizzatore, detto clock di sistema o semplicemente clock. Utilizzando una metafora, si può dire che il clock detta il tempo nell'esecuzione delle istruzioni così come il beat detta il tempo all'interno di una canzone.

Memoria
Per quanto riguarda la memoria del computer, una prima distinzione si può fare tra memoria principale e memoria secondaria. La RAM (Random Access Memory) è la memoria centrale, può essere considerata una delle memorie principali assieme ai registri ed alla cache. La RAM riveste un ruolo fondamentale nell’architettura di Von Neumann: tutte le istruzioni ed i dati devono risiedere in RAM per poter essere utilizzati dalla CPU. La RAM è però volatile, dunque le informazioni in essa contenute si perderanno allo spegnimento del computer. Memorie volatili sono anche i registri, fra cui citiamo i registri MAR, MDR, PC, IR e PSW, che assumono un ruolo fondamentale nel ciclo delle istruzioni macchina, affrontato in questo post. 

Può essere classificata come memoria principale anche la ROM (Read Only Memory), che è una memoria persistente a sola lettura. La ROM contiene il programma di bootstrap, ovvero il programma che consente al sistema di avviarsi e caricare il software principale, che tipicamente è il sistema operativo.

Per quanto riguarda la memoria secondaria, citiamo il disco rigido (hard disk) ed i dischi a stato solido (SSD), sui quali vengono conservati dati e programmi in maniera persistente. Essendo persistenti, in tali dischi i dati si mantengono anche dopo lo spegnimento del computer.

Input/Output
Gli hard disk, assieme ai lettori CD/DVD, alle tastiere, ai mouse, alle webcam, possono inoltre essere considerati dispositivi di input dell’architettura. Dispositivi di output sono invece stampanti e schermi. Dunque, i dispositivi di input servono ad inserire dati e/o a dare comandi al sistema, mentre i dispositivi di output servono a comunicare all’utente i dati elaborati dalla macchina. I vari dispositivi (detti anche periferiche) sono diversi tra loro e dunque necessitano di un’interfaccia comune per poter comunicare con gli altri componenti dell’architettura. Tale interfaccia è appunto l’interfaccia di I/O.

Bus
Infine, il bus è il canale di comunicazione che permette di collegare tra loro i componenti dell’architettura, consentendo il transito delle informazioni. In particolare, nell’architettura di Von Neumann possiamo distinguere diverse linee nel bus di sistema:

bus di controllo, per abilitare la memoria in lettura o scrittura
bus di indirizzi, per individuare gli indirizzi di memoria
bus dati, per contenere i dati da leggere o scrivere
Una particolarità dell’architettura di Von Neumann è che istruzioni e dati viaggiano senza distinzione all’interno dell’unico bus di sistema presente. Questo non avviene invece nell'architettura Harvard, su cui sono basati i più famosi microcontrollori moderni, come ad esempio Arduino. Arduino è sicuramente uno dei microcontrollori più utilizzati in ambito didattico.




Analizziamo singolarmente ciascuna delle componenti.

Processore
Il processore (CPU, Central Processing Unit) è un interprete di istruzioni, costituito da tre componenti:

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

Dispositivi di I/O
I Dispositivi di Input/Output (o periferiche), sotto il controllo e coordinamento del processore, consentono l’interazione tra il computer e l’utente (più in generale, l’interazione tra il computer e l’ambiente), in particolare consentono l’immissione dei dati all’interno del computer e la comunicazione all’esterno dei risultati ottenuti con l’elaborazione.

Per unità di Input si intende un dispositivo che consente di immettere dei dati nel computer. Per unità di Output si intende un dispositivo che riceve dal sistema i risultati dell’elaborazione dei dati e li trasmette all’utente.

Esistono infine unità periferiche che svolgono entrambe le funzioni di input e output, per esempio:

Modem: è un dispositivo di ricetrasmissione, cioè che consente la comunicazione di più computer utilizzando la linea telefonica;
Monitor touch screen: è un dispositivo costituito da uno schermo ed un digitalizzatore, che consente all’utente di interagire con l’interfaccia grafica mediante apposita penna/stilo o con le dita.