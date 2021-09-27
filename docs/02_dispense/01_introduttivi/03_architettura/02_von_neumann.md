# L'architettura di von Neumann

!!!quote "Andrew Tanenbaum"
    *John von Neumann era un genio del calibro di Leonardo da Vinci.*

L'architettura proposta da John von Neumann è unanimanente riconosciuta come quella alla base delle moderne architetture dei calcolatori, ed ha avuto un ruolo fondamentale nella definizione del paradigma delle macchine *riprogrammabili*.

![von_neumann](../../assets/images/02_dispense/01_teoria/03_architettura/von_neumann.png)

L'architettura di von Neumann consta di quattro parti fondamentali, ovvero:

* una *Central Processing Unit*, nota ai più come *CPU*;
* un'unità di memoria;
* uno o più dispositivi di *input* ed *output*;
* un *bus di comunicazione*.

Vediamo adesso più nel dettaglio ciascuna di queste componenti.

## Central Processing Unit

La CPU è il "cuore" della macchina di von Neumann, e consta a sua volta di due componenti fondamentali.

### Control Unit

La prima componente della CPU è la **Control Unit** (*CU*), responsabile per il recupero (*fetch*) e la decodifica (*decode*) delle istruzioni.

Al suo interno, troviamo due *registri*, ovvero sezioni di memoria dalle dimensioni limitate ma rapidamente accessibili. In particolare:

* il **Current Instruction Register** (*CIR*), all'interno del quale è memorizzata l'istruzione attualmente in esecuzione;
* il **Program Counter** (*PC*), all'inerno del quale è memorizzato l'indirizzo dell'istruzione da eseguire successivamente a quella attualmente memorizzata nel CIR.

### Processing Unit

La seconda componente della CPU è la **Processing Unit**, delegata all'esecuzione delle operazioni aritmetiche e logiche fondamentali.

All'interno della Processing Unit troviamo:

* una **Arithmetic Logic Unit** (*ALU*), delegata alla gestione delle operazioni aritmetico-logiche;
* una serie di registri che memorizzano le operazioni più utilizzate.

### Memoria

L'unità di memoria contiene i dati e le istruzioni attualmente necessarie alla corretta esecuzione di un programma. La memoria dialoga principalmente con la CPU, ed il suo compito consiste nell'agire da "magazzino", 
