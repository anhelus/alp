# Architettura dei Calcolatori

La conoscenza dell'architettura del calcolatore può


L'architettura di un calcolatore è basata su 

## Il modello di von Neumann

L'architettura di un computer è basata sul modlelo porposto da John von Neumann alla metà degli anni '40 del secolo scorso.

Questa architettura prevede tre entità logiche:

- memoria
- Centra Processing Unit, che comprende
		- control unit
		- ALU (Arithmetic Logic Unit)
- dispositivi di input/utput


Le informazioni (dati) viaggiano tra le componenti mediante un *bus*

# cpu

è la componente che acquisisce, interpreta ed esegue le istruzioni dei programmi

Si componea sua volta di:
- control unit, responsabile del prelievo e della decodifica delle istruzioni, oltre che dell'invio dei segnali di controllo
- arithmetic logic unit, per l'esecuzione delle operazioni aritmetiche e logiche
- alcune varianti dle modello prevedono anche un clock

Dal punto di vista operativo, la CPU fa uso di alcuni registri:

 - elementi di memoria i cui valori possono essere aceduti in lettura e scrittura molto velocemente
 - CIR: Current Instruction Register / contiene l'istruzione in corsodi esecuzione
 - PC (Program Counter) - contiene l'indirizzo della prossima istruzioen del programma in esecuzione

# Memoria

E' la memoria cenrale, di lavoro, da non confondersi con la memoria di massa in cui vengono immagazzinati dati e programmi quando non in uso.
Contiene gli elementi che il computer sta usando nella corrente elaborazione, e precisamente 

-  le istruzioni del programma in corso di esecuzione
- i dati necessari all'esecuzione di quel programma

si può immaginare la memoria come costituita da tante celle, ognuna identificata univocamente dal proprio indirizzo

I/O

Sono i dispositivi con cui rispettivamente

-  vengono forniti dati e programmi al computer
- vengono prododotti dal computer i risultati dell'elaborazione

# SUpporto

La machcina di Von Neuman è una macchina astratta, un modello per realizzare macchine reali.
Per questo non vengono enfatizzati ulteriori elementi logici che pure osno necessari, come ad esempio 
-

- bus e clock di sistema
- memorie di massa
- interfacce di rete...

Nel modello di von Neumann è implicita la separazione della memoria dalla unità di elaborazione, definendo quello che viene chiamato stored-program computer. Inizialmente, infatti questi due blocchi erano unici ed avevano una memoria programma  fissa. Ad esempio, un  calcolatore desktop (in principio) si presentava come una macchina in grado di eseguire operazioni matematiche, ma sarebbe stato impossibile usare un word processor oppure eseguire dei video games. Tale macchina rappresentò una grande innovazione; la possibilità di trattare le istruzioni come fossero dati permise lo sviluppo di assembler e compilatori.  Era così possibile “scrivere programmi che scrivono programmi”. Chiaramente, la possibilità di modificare programmi è anche uno  svantaggio: se si sbaglia indirizzo di memoria si rischia di sovrascrivere il firmware e ciò può comportare anche il danneggiamento irreversibile della macchina. Un altro problema tipico di queste macchine è rappresentato dal buffer overflow. Per risolvere il problema si può pensare di implementare alcune forme di protezione della memoria. Il termine deriva dall’articolo scritto dal matematico John von Neumann nel giugno del 1945, che trattava per primo una macchina stored-program gereral purpouse (denominata EDVAC). La separazione della CPU dalla memoria ha però portato a quello che è oggi conosciuto come collo di bottiglia di von Neumann. Il throughput  (cioè la velocità di trasferimento dei dati) tra unità di elaborazione e memoria è molto minore rispetto alla quantità di dati trasferiti. Inoltre, il throughput è molto minore rispetto alla frequenza operativa della CPU. Queste considerazioni determinano  una seria limitazione nella velocità effettiva di esecuzione delle istruzioni. In presenza di operazioni di accesso alla memoria la CPU deve continuamente attendere che tali dati arrivino. Attualmente le frequenze operative e la dimensione della memoria aumenta ad un tasso esponenziale, mentre  il  throughput  avanza molto lentamente,  rendendo sempre più  marcato questo collo di bottiglia.

# L'architettura Harvard

Per superare i limiti imposti dal modello di von Neuman,, venne introdotta l'architettura Harvard, che presuppne la separazione della memoria programma da quella dati. Il termine deriva dalla macchina Harvard Mark I.

PoicHé nell'architettura di von Neumann il blocco di memoria ed il relativo percorso sono unici, non è possibile leggere allo stesso tempo una istruzione ed un dato. In un computer con architettura Harvard questoo è invece possibile.

Questo rappresentò uan rivoluzione, perché permise di superare i limiti imposti dall'archietttura di von Neumann. INfatti, la CPU è in grado di effettuare il fetch dell'istruzione successiva contemporaneamente al completamento di quella corrente. Da qui allo sviluppo di sistemi basati su pipeline il passo è breve.

Ovviamente, rispetto ad una macchina di von Neumann, quella Harvard risulta più complessa dal punto di vista implementativo e circuitale. Questo si traduce in un costo superiore.

# LE MODERNE CPU

Non si deve pensare che l'architettura di von Neumann sia completamente scomparsa a favore di quella Harvard. le moderne CPU fanno spesso uso di memorie più velici (cache) ma con dimensioni ridotte, allo scopo di bufferizzare i dati dalla memoria principale (off-chip). L'architettura implementata in questi casi è una soluzione mista: per l'accesso della CPU alla cache è usata l'architettura Harvard, mentre si usa la von Neumann per gli eventuali accessi alla memoria off-chip.



