# Assembly e linguaggio macchina

I computer odierni sono delle macchine di Von Neumann (concetto che riprenderemo più in avanti) in grado di eseguire i programmi memorizzati nella memoria di massa, ovvero un insieme di istruzioni che indicano al processore il da farsi. 

Le istruzioni sono sostanzialmente dei *numeri* definiti sotto forma di un insieme di bit, la cui lunghezza dipende dalla specifica architettura utilizzata; ad esempio, le istruzioni per un processore di tipo ARM, come quelli presenti nella maggior parte degli smartphone, possono essere a 32 o 64 bit, ma sono incompatibili con quelle scritte per processori con architettura x64 (ovvero, quella comunemente usata su desktop e notebook).

Un esempio di istruzione è il numero `0x0120`, che potrebbe istruire il processore ad *inserire `1` nel registro `0`*; tale numero rappresenta una (piccola) porzione di *codice macchina*. Ovviamente, scrivere programmi moderni in questo modo è estremamente complesso ed inefficiente, per cui nessun programmatore utilizza direttamente il codice macchina; tuttavia, esiste un linguaggio che si colloca ad un livello di astrazione leggermente più alto, chiamato *assembly*, che ne fornisce una sorta di "rappresentazione testuale". In altre parole, *l'assembly è un linguaggio di programmazione a basso livello le cui istruzioni sono facilmente riconducibili al codice macchina*.

Approfondiamo brevemente i due linguaggi.

## Il linguaggio macchina

##### Un po' di storia

L'utilizzo della rappresentazione binaria per le istruzioni di un calcolatore deriva dai primi lavori compiuti da pionieri dell'informatica come John Mauchly e John Atanasoff nella prima metà dello scorso secolo, e che portò alla sua implementazione sui primi computer a partire dagli anni '50. Prima di quel momento, infatti, macchine come l'UNIVAC o l'ENIAC richiedevano agli (sfortunati) programmatori l'utilizzo di relé, collegamenti analogici ed interruttori di vario tipo, che rendevano l'utilizzo di queste macchine complesso e dispendioso in termini di tempo.

Con l'evoluzione dei calcolatori vennero anche nuove versioni del linguaggio macchina: una volta inventato il transistor, nel 1947, non passò molto tempo prima della commercializzazione del primo calcolatore digitale, l'UNIVAC I, programmabile inizialmente esclusivamente utilizzando il linguaggio macchina. Successivamente, negli anni '50, venne introdotto anche il corrispondente linguaggio assembly, chiamato PAL-11R; nonostante questo richiedesse comunque una dettagliata conoscenza del linguaggio macchina sottostante, era in grado di facilitare notevolmente il compito ai programmatori.

Fu con l'arrivo di linguaggi ad alto livello come il COBOL, il BASIC ed il FORTRAN che si diffusero istruzioni più simili al linguaggio naturale (in questo caso, l'inglese), e la platea di programmatori si ampliò a dismisura. Tuttavia, il linguaggio macchina continuò ad essere utilizzato per sviluppare software ad elevate prestazioni, come ad esempio i sistemi operativi. Avvicinandosi al nuovo millennio, tuttavia, vennero introdotti linguaggi più complessi come il C ed il C++, che resero possibile ai programmatori scrivere del codice portabile tra diverse macchina. Anche allora, tuttavia, il linguaggio macchina rimase un *must* nello sviluppo di software a basso livello, come firmware e driver. Con l'avvento dei linguaggi più moderni, come Java o Python, la pratica di sviluppare in codice macchina è definitivamente andata in disuso.

##### Programmare in linguaggio macchina

Il linguaggio macchina, come abbiamo già detto, permette di controllare direttamente la CPU. Ogni istruzione fa in modo che la CPU esegua un task specifico, come memorizzare o caricare un valore, o eseguire un'operazione aritmetico/logica, modificando di conseguenza una o più unità di dati all'interno della memoria o dei registri del processore. Normalmente, il codice macchina è considerato come l'interfaccia maggiormente "a basso livello" verso la CPU, tuttavia, esistono alcuni processori che includono un'interfaccia ancora più a basso livello chiamata *microcode*.

In teoria, quindi, è possibile scrivere programmi direttamente in linguaggio macchina. Tuttavia, farlo è estremamente complesso e dispendioso, in quanto il programmatore dovrebbe gestire manualmente i singoli bit del processore. Ciò limita l'applicazione pratica di questo paradigma nei moderni processori a situazioni limite, nelle quali l'interazione a bassissimo livello è inaggirabile; di conseguenza, i linguaggi moderni vengono *tradotti* in codice macchina mediante appositi programmi chiamati *assembler*, *linker* e *compilatori*.

!!!tip "Interpreti e linguaggio macchina"
    Un'eccezione notevole al paradigma precedente è data dagli interpreti, che *non* traducono il codice sorgente in linguaggio macchina. Ciò è legato al fatto che questi traduttori sono delle vere e proprie "macchine virtuali" che eseguono le istruzioni indicate nel cordice sorgente.

## Il linguaggio assembly

Abbiamo visto come il linguaggio macchina sia estremamente ostico da utilizzare ma, al contempo, offra possibilità semplicemente inarrivabili dai linguaggi di programmazione ad alto livello. Per rendere in qualche modo disponibili dette potenzialità ai programmatori ne è stata quindi creata una versione *human-readable* che si occupa di "mappare" il codice macchina in stringhe ed istruzioni che, per quanto complesse, risultino essere leggibili da parte di un essere umano; questo linguaggio è chiamato *assembly*.

##### Un po' di storia

Il linguaggio assembly non esisteva quando i comptuer




Assembly languages did not exist when stored-program computers were first introduced. The credit for inventing assembly language goes to Kathleen Booth, who began theoretical work on the concept in 1947.
It was late 1948 when the Electronic Delay Storage Automatic Calculator (EDSAC) had an assembler integrated into its bootstrap program. It leveraged one-letter mnemonics developed by David Wheeler, credited as the creator of the first “assembler.”

A few years later, in 1955, an assembly language known as the Symbolic Optimal Assembly Program (SOAP) was written by Stan Poley for the IBM 650 computer.

Assembly languages went one step ahead of machine language. They eliminated much of the tedious, time-consuming, and error-prone operations seen in the first-generation programming of the earliest computers. They freed programmers from tasks such as calculating addresses and remembering numeric codes, thereby becoming the standard for many types of programming.

Several programs were written using only assembly language. It was only in 1961 that the Burroughs MCP was introduced — this was the first computer whose operating system was not developed using only assembly language. Instead, its OS was written in Executive Systems Problem Oriented Language (ESPOL).

Assembly language had (and, to a certain extent, still has) commercial applications. For instance, a considerable portion of the IBM mainframe software by corporations was written using assembly language.

In commercial applications, the biggest advantages of assembly language included minimal bloat and overhead, as well as greater reliability and speed.

However, assembly language was not only used commercially. As computers became more commonplace, assembly language also entered people’s homes.





Il linguaggio assembly dà all’utente la capacità di influenzare il funzionamento dell’hardware e del software dlela macchina. Possiamo vederlo come un mezzo per collegare l’hardware del computer al sistema operativo, e fare in modo che questi lavorino insieme. Il linguaggio fornisce inoltre un ponte per fare in modo che il sistema operativo comunichi con i programmi applicativi (e viceversa).

A differenza dei linguaggi di alto livello, l’assembly varia a seconda della macchina, in quanto ogni microprocessore si affida al suo insieme di istruzioni supportate. Ad esempio, il linguaggio assemvbly per un PC IBM consiste dell’instruction set Intel 8086/8088.

Imparare il linguaggio assembly comportra diversi benefici. Ad esempio, il programmatore può comprendre al meglio l’architettura del sistema. Inoltre, alcuni programmi che richiedono una stretta interazione a livello hardware (pensiamo ad un programma di telecomunicazion) e queste sono spesso difficili (e alle vlote impossibili) da scrivere in linguaggi ad alto livello.

PEr rendere più semplice la programmazione, la mggior parte dei linguaggi ad alto livello impongono delle regole che restgringono quello che può fare il programmatore. Ad esempio, il Pascal non permette che i programmatori asseegnino caatteri a valori di tipo intero. Di converso l’assembly ha un numero molto basso di regole e restrizuioni, in quanto praticamente gutti gli aspetti si affidano alla discrezionalità del program,ma. Anche se questo dà ai programmatori esperti la libertà di cui hanno bisogno per spingere i limiti del linguaggio assembly, richiede anche di gestire molte situazioni che la programmazione ad alto livello invece gestisce automaticamente.

Per esempio, se un programma ad alto livello è usato per comparare due stringhe, il codice sarà traslato usando delle istruzioni semplici. Tuttavia, il programma sarà molto più denso usando istruzioni complesse che effettuano lo stessa operazione.

Un altro vantaggio dell’assembly rispetto ai linguaggi ad alto livello è l’efficienza sia in termini di memoria sia in termini di tempo: il coldice scritto in linguaggio assembly è generalemnte pi denso dello stesso codice generato da un linguaggio ad alto livello. Questo è legato al fatto che molti compilatori utilizzano in maniera subottimale le istruzioni complesse.

Prima abbiamo detto che 0x0120 significa “metti 1 nel registro 0”. Un registro è una piccola partizione di memoria che può contenere un numero. Dato che normalmente ve ne sono pochi, non possono rimpiazzare la memoria principale della macchian; ttuavia, sono estremamente più veloci di quest’ultima, quindi maneggiarli diventa fondamentale.

NEl linguaggio assembly, l’inserimento del numero 1 nel registro 0 è scritto come moves r0, #1. Di conseguenza, quando l’asesembler vede un’operazione MOVS può generare il corretto codice macchina, a seconda del registro usatgo.

Ecco un esempio di linguaggio assembly:

```assembly
// i = 15;
mov r3, #15
str r3, [r11, #-8]

//j = 25;
mov r3, #25
str r3, [r11, #-12]

// i = i + j;
ldr r2, [r11, #-8]
ldr r3, [r11, #-12]
add r3, r2, r3
str r3, [r11, #-8]
```


Le righe che iniziano con // sono dei commenti che contengono l’equivalente in linguaggio C di quello che si fa in linguaggio assembly. Come possiamo vedere, questo codice crea una variabile i, che è memorizzata nella memoria stack, e la imposta a 15. Infine, aggiunge i a j, caricando o i in r2 e j in r3, e quindi memorizza i risultati in i.

In altre parole, impsotare due variabili e sommarle richiede otto righe di codice. Questo ci fa capire quanto sforzo richiederebbe lo sviluppo di linguaggi più complessi: il programma equivalente in 3 è lungo solo tre righe, e diventa ancora più compatto in linguaggi ancora a più alto livello.

### Machine language vs Assembly language

ASSEMBLY

Assembly languages did not exist when stored-program computers were first introduced. The credit for inventing assembly language goes to Kathleen Booth, who began theoretical work on the concept in 1947.
It was late 1948 when the Electronic Delay Storage Automatic Calculator (EDSAC) had an assembler integrated into its bootstrap program. It leveraged one-letter mnemonics developed by David Wheeler, credited as the creator of the first “assembler.”

A few years later, in 1955, an assembly language known as the Symbolic Optimal Assembly Program (SOAP) was written by Stan Poley for the IBM 650 computer.

Assembly languages went one step ahead of machine language. They eliminated much of the tedious, time-consuming, and error-prone operations seen in the first-generation programming of the earliest computers. They freed programmers from tasks such as calculating addresses and remembering numeric codes, thereby becoming the standard for many types of programming.

Several programs were written using only assembly language. It was only in 1961 that the Burroughs MCP was introduced — this was the first computer whose operating system was not developed using only assembly language. Instead, its OS was written in Executive Systems Problem Oriented Language (ESPOL).

Assembly language had (and, to a certain extent, still has) commercial applications. For instance, a considerable portion of the IBM mainframe software by corporations was written using assembly language.

In commercial applications, the biggest advantages of assembly language included minimal bloat and overhead, as well as greater reliability and speed.

However, assembly language was not only used commercially. As computers became more commonplace, assembly language also entered people’s homes.

SVILUPPO

LINGUAGGIO MACCHINA



ASSEMBLY

Assembly language was the primary development language for several well-known home computers in the 1980s and 1990s, including the Sinclair ZX Spectrum, MSX, Atari ST, Commodore 64, and Commodore Amiga.
One reason for this was the interpreted BASIC dialects on these systems leading to insufficient execution speed and unsatisfactory facilities for taking complete advantage of available system hardware.

Popular examples of assembly language programs included the Turbo Pascal compiler, the IBM PC DOS operating systems, and even early programs such as the spreadsheet processor Lotus 1-2-3 and the 1993 arcade game NBA Jam. Interestingly, assembly language was chosen to enhance the performance of the Sega Saturn, a gaming console well-known for its development challenges.

The use of hand-coded assembly language was even seen in early microcomputers, including in operating systems and large applications. Assembly language allowed developers to address system challenges such as severe resource constraints, imposed idiosyncratic display and memory architectures, limited and buggy services, and the lack of first-class high-level language compilers for microcomputers.

FORTRAN, COBOL, and PL/I eventually went on to displace assembly language; however, numerous large organizations still relied on assembly language application infrastructures until the turn of the millennium.

While it did not take long for the use of assembly languages to be supplanted by higher-level languages, they still see usage even today for direct hardware manipulation, addressing critical performance issues, and accessing specialized processor instructions. The typical applications of modern-day assembly languages include low-level embedded systems, real-time systems, and device drivers.

APPLICAZIONI

LINGUAGGIO MACHCINA



ASSEMBLY

Assembly language is used for several applications. For instance, it is useful for standalone, compact executables that must run without recourse to the libraries or runtime components found in high-level languages. Examples include

[firmware](https://www.spiceworks.com/tech/devops/articles/what-is-firmware/)

for telephones, air-conditioning control systems, automobile ignition and fuel systems, sensors, and security systems.

Assembly language is also used in programs with performance-sensitive inner loops, where it provides opportunities for optimization that are otherwise difficult to achieve when using a high-level language (think linear algebra with BLAS or discrete cosine transformation).

Assembly language is useful for programs that build vectorized functions for programs in C and other higher-level languages.

It is also used in real-time programs such as flight navigation systems, medical equipment, and simulations. For instance, fly-by-wire systems require telemetry to be interpreted and executed within stringent time constraints. Thus, sources of unpredictable delays must be removed, making some interpreted languages incompatible with the application. Here, assembly language gives programmers greater transparency and management capabilities over processing details.

Similarly, assembly language can be useful for cryptographic algorithms that strictly require the same execution time every time to thwart [timing attacks](https://www.spiceworks.com/it-security/vulnerability-management/articles/what-is-cyber-threat/).

Assembly language is used in solutions that require end-to-end control over the environment. It can also be found in applications without high-level language and for new or specialized processors with no cross-compilers available.

Aside from this, it is used in instruction set simulators for tracing, debugging, and monitoring while keeping additional overhead to a minimum.

“ROM hacking” of video games can also occur by modifying program code at the assembly language level.

It can also be used for reverse-engineering and altering program files, such as existing binaries that could have been initially written in either assembly or higher-level languages.

Finally, fundamental topics like binary arithmetic, stack processing, memory allocation, character set encoding, compiler design, and interrupt processing would be difficult to study without learners first understanding how computers operate at the hardware level.

PROGRAMMAZIONE




Assembly language is the preferred language for programming on systems with older processors featuring limited high-level language options, such as the Commodore 64 and Atari 2600.

It is also used in the boot code for many newer systems. Here, it serves as the low-level code that initializes and runs tests on the [system hardware](https://www.spiceworks.com/it-security/vulnerability-management/articles/what-is-hardware-security/) before the operating system is booted. It is often stored in ROM.

It is also used for low-level code like operating system kernels, which cannot depend on the availability of pre-existing system calls.

Assembly language is also used for writing code that interacts directly with hardware, such as interrupt handlers and device drivers.

Finally, this language is used for programs requiring processor-specific instructions not implemented at the compiler level. This can include, for instance, the bitwise rotation instruction that is a key part of many encryption algorithms.

FeATURE DEL LINGUAGGIO

**Human comprehension:**

Unlike assembly language, machine language is so unreadable that even the US Copyright Office has stated its inability to identify whether specific encoded programs are original work. Comparisons have been made between machine language and genetic code. However, the machine code used for a program can be decompiled or disassembled in cases where its functioning needs to be made more easily understandable to humans, although this output will be without the relevant symbolic references and comments.

**Microcode:** Some computers implement machine language using a more fundamental layer called microcode. This underlying layer provides a common interface for machine language for various computer models with varying underlying dataflows. Using microcode facilitates the porting of machine language programs between computing models.

**Bytecode:** Bytecode, also called p-code, is different from machine language and is either compiled into machine language for direct execution or executed through an interpreter. However, some processors (like Java) are designed to execute specific bytecode directly as machine language.

**In-memory storage:** When a computer runs a program, it is stored in RAM as machine code. The CPU uses this code to perform its tasks. To improve program performance, the machine code is sometimes cached, and the CPU tracks the part of the machine code that needs to be executed by using a program counter, which is a value that guides the CPU to where in memory the next set of instructions can be found. It can be set to any memory address, but an error will be generated if the address is invalid. To help prevent this, some systems use special bits called “execute bits” to indicate if a section of memory contains code that is allowed to be executed.

**Code space:** When multiple programs run on the computer simultaneously, each program has its own memory section dedicated to machine language. These sections are called code spaces. In multithreading environments, different threads of a single program share the same code space, which can reduce the amount of time needed to switch between tasks. However, this can also be a [security concern](https://www.spiceworks.com/it-security/vulnerability-management/articles/what-is-cyber-threat/), as malicious actors can execute code stored in the code

**Fundamental elements:**

Assembly languages typically consist of three types of instruction statements: opcode mnemonics, assembly directives, and data definitions. These fundamental elements are leveraged to define program operations. Apart from these, assembler authors can categorize the statements and nomenclature they use in various ways. For instance, some authors may classify any element other than a machine mnemonic or extended mnemonic as a pseudo-operation, or pseudo-op for short.

**Mnemonics:** In assembly language, instructions are simple and represented by a symbolic name known as a mnemonic. The mnemonic refers to a machine language instruction, which typically consists of an operation (opcode) and one or more operands. Operands can be immediate values, registers, or data addresses stored elsewhere in memory. The assembler reflects the underlying processor architecture in how it handles the operands. Some assemblers include extended mnemonics for specialized uses and macro-instructions that generate multiple machine instructions.

**Data directives:** These directives allow users to define data elements to hold variables and data. They define a data type, length, alignment, and data availability for outside programs assembled separately. Data directives are classified as pseudo-ops by some assemblers.

**Assembly directives:** Assembly language has special commands called assembly directives or pseudo-opcodes. These directives instruct the assembler to perform operations other than assembling instructions. They can impact the object code, symbol table, and the values of internal assembler parameters. Assembly language allows programmers to associate names with memory locations and constants, making the code more self-documenting. Some assemblers also provide flexible symbol management and support for comments in the code. These comments are important as the raw assembly language can be challenging to understand without them.

**Macros:** These are sequences of text lines in assembly language that can include variables and constants. Macros are typically used to make assembly language programs appear shorter and to add structure to the code. Assembler macro instructions can be lengthy and include high-level language elements like variables, arithmetic operations, and string manipulation. Macros can take parameters and generate assembly language instructions based on the arguments. Despite their power, macro processing has fallen into disuse in many high-level languages but remains a staple in assembly language.

# **Takeaway**

Both machine and assembly languages are low-level programming languages used to write programs. Machine language is the binary code computers understand and execute directly, while assembly language is a human-readable machine language representation.

One of the key differences between the two languages is their level of abstraction. Machine language is much closer to the hardware, consisting of a series of binary instructions that the CPU can execute directly. On the other hand, assembly language uses mnemonics and symbols to represent machine language instructions, making it easier for humans to read and write.

Another difference is the level of control offered by the two languages. Assembly language provides a higher level of control over the system, allowing direct manipulation of memory locations, register values, and system calls. Machine language, on the other hand, only allows direct manipulation of the binary code.

Higher-level programming languages have largely replaced both languages; however, the two still serve specific functions.