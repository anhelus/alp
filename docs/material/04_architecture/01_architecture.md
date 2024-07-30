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



L'architettura di Von Neumann venne inizialmente proposta nel 1945 da John Von Neumann.

Storicamente, esistono due tipi di architetture:

1. **fixed program computers**, il cui funzionamento è speicfico e non possono essere riprogrammati, come ad esempio le calcolatrici
2. **stored program computers**, il cui funzionamento può essere riprogrammato per effettuare diversi task differnti

I moderni computer sono ovviamente basati sul concetto di stored-program introdotto da John VOn Neumann. IN questo concetto, i programmi ed i dati sono memorizzati in uno spazio riservato chiamato *memoria*é Questa idea, all'ìepoca innovativa, implicava cheun comptuer costruito con l'archiettura di Von Neumann sarebbe stato molto più semplice da riprogrammare.

La struttura base 

The basic structure is like this, 



It is also known as ISA (Instruction set architecture) computer and is having three basic units:  

The Central Processing Unit (CPU) 
The Main Memory Unit 
The Input/Output Device Let’s consider them in detail.
         1. Central Processing Unit-

          The central processing unit is defined as the it is an electric circuit used for the executing the instruction of computer program.

          It has following major components:

          1.Control Unit(CU)

          2.Arithmetic and Logic Unit(ALU)

          3.variety of Registers

Control Unit – 
A control unit (CU) handles all processor control signals. It directs all input and output flow, fetches code for instructions, and controls how data moves around the system. 
Arithmetic and Logic Unit (ALU) – 
The arithmetic logic unit is that part of the CPU that handles all the calculations the CPU may need, e.g. Addition, Subtraction, Comparisons. It performs Logical Operations, Bit Shifting Operations, and Arithmetic operations. 


Figure – Basic CPU structure, illustrating ALU 

Registers – Registers refer to high-speed storage areas in the CPU. The data processed by the CPU are fetched from the registers. There are different types of registers used in architecture :-
Accumulator: Stores the results of calculations made by ALU. It holds the intermediate of arithmetic and logical operatoins.it act as  a temporary storage location or device.
Program Counter (PC): Keeps track of the memory location of the next instructions to be dealt with. The PC then passes this next address to the Memory Address Register (MAR). 
Memory Address Register (MAR): It stores the memory locations of instructions that need to be fetched from memory or stored in memory. 
Memory Data Register (MDR): It stores instructions fetched from memory or any data that is to be transferred to, and stored in, memory. 
Current Instruction Register (CIR): It stores the most recently fetched instructions while it is waiting to be coded and executed. 
Instruction Buffer Register (IBR): The instruction that is not to be executed immediately is placed in the instruction buffer register IBR. 
 
Buses – Data is transmitted from one part of a computer to another, connecting all major internal components to the CPU and memory, by the means of Buses. Types: 
Data Bus: It carries data among the memory unit, the I/O devices, and the processor. 
Address Bus: It carries the address of data (not the actual data) between memory and processor. 
Control Bus: It carries control commands from the CPU (and status signals from other devices) in order to control and coordinate all the activities within the computer.
Input/Output Devices – Program or data is read into main memory from the input device or secondary storage under the control of CPU input instruction. Output devices are used to output information from a computer. If some results are evaluated by the computer and it is stored in the computer, then with the help of output devices, we can present them to the user.
Von Neumann bottleneck – 
Whatever we do to enhance performance, we cannot get away from the fact that instructions can only be done one at a time and can only be carried out sequentially. Both of these factors hold back the competence of the CPU. This is commonly referred to as the ‘Von Neumann bottleneck’. We can provide a Von Neumann processor with more cache, more RAM, or faster components but if original gains are to be made in CPU performance then an influential inspection needs to take place of CPU configuration. 

This architecture is very important and is used in our PCs and even in Super Computers.




In a normal computer that follows von Neumann architecture, instructions, and data both are stored in the same memory. So same buses are used to fetch instructions and data. This means the CPU cannot do both things together (read the instruction and read/write data). Harvard Architecture is the computer architecture that contains separate storage and separate buses (signal path) for instruction and data. It was basically developed to overcome the bottleneck of Von Neumann’s Architecture. The main advantage of having separate buses for instruction and data is that the CPU can access instructions and read/write data at the same time. 

Structure of Harvard Architecture: 

Structure of Harvard Architecture
Structure of Harvard Architecture

Buses

Buses are used as signal pathways. In Harvard architecture, there are separate buses for both instruction and data. Types of Buses: 


Data Bus: It carries data among the main memory system, processor, and I/O devices. 
Data Address Bus: It carries the address of data from the processor to the main memory system. 
Instruction Bus: It carries instructions among the main memory system, processor, and I/O devices. 
Instruction Address Bus: It carries the address of instructions from the processor to the main memory system. 
Operational Registers

There are different types of registers involved in it which are used for storing addresses of different types of instructions. For example, the Memory Address Register and Memory Data Register are operational registers. 

Program Counter: It has the location of the next instruction to be executed. The program counter then passes this next address to the memory address register. 
Arithmetic and Logic Unit: The arithmetic logic unit is part of the CPU that operates all the calculations needed. It performs addition, subtraction, comparison, logical Operations, bit Shifting Operations, and various arithmetic operations. 
Control Unit:  The Control Unit is the part of the CPU that operates all processor control signals. It controls the input and output devices and also controls the movement of instructions and data within the system. 
Input/Output System: Input devices are used to read data into main memory with the help of CPU input instruction. The information from a computer as output is given through Output devices. The computer gives the results of computation with the help of output devices. 
 Features:

Separate memory spaces: In Harvard architecture, there are separate memory spaces for instructions and data. This separation ensures that the processor can access both the instruction and data memories simultaneously, allowing for faster and more efficient data retrieval.
Fixed instruction length: In Harvard architecture, instructions are typically of fixed length, which simplifies the instruction fetch process and allows for faster instruction processing.
Parallel instruction and data access: Since Harvard architecture separates the memory spaces for instructions and data, the processor can access both memory spaces simultaneously, allowing for parallel instruction and data processing.
More efficient memory usage: Harvard architecture allows for more efficient use of memory as the data and instruction memories can be optimized independently, which can lead to better performance.
Suitable for embedded systems: Harvard architecture is commonly used in embedded systems because it provides fast and efficient access to both instructions and data, which is critical in real-time applications.
Limited flexibility: The separate memory spaces in Harvard architecture limit the flexibility of the processor to perform certain tasks, such as modifying instructions at runtime. This is because modifying instructions requires access to the instruction memory, which is separate from the data memory.
Advantage of Harvard Architecture: 

Harvard architecture has two separate buses for instruction and data. Hence, the CPU can access instructions and read/write data at the same time. This is the major advantage of Harvard architecture. 

In practice, Modified Harvard Architecture is used where we have two separate caches (data and instruction). This is common and used in X86 and ARM processors.

Fast and efficient data access: Since Harvard architecture has separate memory spaces for instructions and data, it allows for parallel and simultaneous access to both memory spaces, which leads to faster and more efficient data access.
Better performance: The use of fixed instruction length, parallel processing, and optimized memory usage in Harvard architecture can lead to improved performance and faster execution of instructions.
Suitable for real-time applications: Harvard architecture is commonly used in embedded systems and other real-time applications where speed and efficiency are critical.
Security: The separation of instruction and data memory spaces can also provide a degree of security against certain types of attacks, such as buffer overflow attacks.
Disadvantages of Harvard Architecture:

Complexity: The use of separate memory spaces for instructions and data in Harvard architecture adds to the complexity of the processor design and can increase the cost of manufacturing.
Limited flexibility: Harvard architecture has limited flexibility in terms of modifying instructions at runtime because instructions and data are stored in separate memory spaces. This can make certain types of programming more difficult or impossible to implement.
Higher memory requirements: Harvard architecture requires more memory than Von Neumann architecture, which can lead to higher costs and power consumption.
Code size limitations: Fixed instruction length in Harvard architecture can limit the size of code that can be executed, making it unsuitable for some applications with larger code bases.