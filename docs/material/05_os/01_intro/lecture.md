# 5.1 - Introduzione ai sistemi operativi

## Cos'è un sistema operativo?

Un **sistema operativo** (in inglese *Operating System*, o **OS**) è un software di base che gestisce le risorse hardware e software del calcolatore, fornendo un'interfaccia tra l'utente e la macchina. Senza un sistema operativo, un computer sarebbe solo un insieme di componenti elettronici incapaci di interagire con l'utente o di eseguire programmi in modo coordinato.

Il sistema operativo svolge diverse funzioni fondamentali:

- **gestione della CPU**: decide quali programmi possono utilizzare la CPU e per quanto tempo (*scheduling*);
- **gestione della memoria**: alloca e dealloca la memoria per i vari processi in esecuzione;
- **gestione dei dispositivi di I/O**: fornisce un'interfaccia standard per comunicare con tastiera, mouse, disco, stampanti, etc.;
- **gestione del file system**: organizza i dati su disco in file e directory;
- **gestione della sicurezza**: protegge le risorse da accessi non autorizzati;
- **interfaccia utente**: fornisce una shell (testuale) o un ambiente grafico (GUI) per interagire con il sistema.

!!!note "Sistemi operativi noti"
    Esempi di sistemi operativi includono Microsoft Windows, macOS, Linux, Android e iOS. Ciascuno è progettato per specifici tipi di dispositivi (PC, server, smartphone, embedded).

## Evoluzione storica

### Prima generazione (1940-1950)

I primi calcolatori non avevano un sistema operativo. Il programmatore interagiva direttamente con l'hardware, inserendo istruzioni tramite interruttori o schede perforate. Ogni programma aveva il controllo completo della macchina.

### Seconda generazione (1950-1960)

Con l'introduzione dei transistor e dei *mainframe*, nacquero i primi sistemi operativi primitivi, come i *monitor batch*. I programmi venivano raggruppati in lotti (*batch*) ed eseguiti uno dopo l'altro senza interazione con l'utente.

### Terza generazione (1960-1970)

Con i circuiti integrati nacquero sistemi operativi più complessi come **OS/360** (IBM). Fu introdotto il concetto di *multiprogrammazione*: più programmi risiedono contemporaneamente in memoria e la CPU passa dall'uno all'altro per massimizzare l'utilizzo.

### Quarta generazione (1970-oggi)

L'avvento dei microprocessori portò alla nascita di sistemi operativi personali come **MS-DOS**, **Unix** e successivamente **Windows**, **macOS** e **Linux**. Caratteristiche chiave: interfaccia grafica, multitasking, memoria virtuale, networking.

## Componenti di un sistema operativo

Un sistema operativo moderno è composto da diversi moduli, il più importante dei quali è il **kernel**, che approfondiremo nella [prossima lezione](../02_kernel/lecture.md). Gli altri componenti includono:

- **shell**: l'interfaccia tramite cui l'utente impartisce comandi (testuale come Bash o grafica come Windows Explorer);
- **file system**: organizza i dati in file e directory su supporti di memorizzazione;
- **driver**: software che permette al sistema operativo di comunicare con i dispositivi hardware;
- **librerie di sistema**: insiemi di funzioni predefinite che i programmi possono utilizzare (ad esempio, per leggere un file o aprire una connessione di rete).
