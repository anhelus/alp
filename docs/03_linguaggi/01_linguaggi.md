## Il Linguaggio Naturale

Il *Linguaggio Naturale* è usato per la comunicazione (scritta ed orale) tra gli esseri umani. Ovviamente, il linguaggio naturale presenta diverse fonti di ambiguità, tra cui:

* *evoluzione del linguaggio*: molto spesso, termini arcaici o neologismi potrebbero non essere ben compresi, come *atavico* o *skippare*;
* *polisemia*: esistono termini che hanno un significato diverso a seconda del contesto (ad esempio, *i principi non hanno principi*);
* *ambiguità intrinseca*: frasi e termini che per essere interpretati hanno necessariamente bisogno del contesto (*una vecchia porta la sbarra*).

Questi motivi, oltre all'enorme variabilità, fanno sì che il linguaggio naturale non sia adatto a permettere la comunicazione tra uomo e macchina. E' quindi l'umano a doversi giocoforza adattare.

### Definizione formale di Linguaggio

Iniziamo dando una definizione (più o meno) formale di linguaggio.

!!! quote "Linguaggio"
	*Un linguaggio è l'insieme di parole ottenute applicando le regole di una data grammatica.*

La grammatica, a sua volta, è definita come segue:

!!! quote "Grammatica"
	*Una grammatica è un formalismo atto a definire un linguaggio mediante l'imposizione di un metodo per la costruzione delle parole.*

E' chiaro come le due definizioni siano strettamente correlate tra loro, in quanto l'una discende direttamente dall'altra.

### Sintassi e semantica (nel linguaggio naturale)

Le parole di un linguaggio possono essere analizzate da due diversi punti di vista:

* *sintattico*: comporta la verifica della correttezza della forma linguistica in cui è codificato;
* *semantico*: comporta la verifica del significato associato alla forma linguistica.

In realtà, esiste anche l'analisi *pragmatica* del testo, che ne prevede l'analisi nel contesto dell'utilizzo comune; quest'ultima, tuttavia, esula dai nostri obiettivi, e l'eventuale approfondimento è demandato al lettore.

Una frase scorretta dal punto di vista sintattico è la seguente:

> Io ho andato a scuola.

Una frase corretta dal punto di vista sintattico, ma semanticamente inconsistente è la seguente:

> Tu hai suonato il cellulare al contrario.

## I Linguaggi di Programmazione

I *Linguaggi di Programmazione* definiscono una notazione specificamente pensata per definire degli *algoritmi*. 

La principale differenza che intercorre con il linguaggio naturale è che mentre quest'ultimo è orientato alla comunicazione con altri esseri umani, i linguaggi di programmazione permettono agli umani di comunicare una serie di istruzioni ad una macchina, la quale potrebbe controllare dei dispositivi esterni di I/O (quali stampanti ed hard disk, ma anche bracci robotici, ad esempio). Ciò è possibile usando appositi *traduttori* (ci ritorneremo più avanti).

### Livelli di astrazione

In generale, comunque, i linguaggi di programmazione sfruttano appieno il concetto di *astrazione* delle risorse della macchina su cui viene eseguito un programma. Questo è un concetto ricorrente in informatica; ne abbiamo infatti avuto un "assaggio" quando abbiamo parlato del modello ISO/OSI, nel quale ogni layer rappresenta una ulteriore "astrazione" rispetto a quello sottostante, in modo da rendere il messaggio più facilmente comprensibile da parte di un utente umano.

Nell'ambito dei linguaggi di programmazione, astrarre significa mettere a disposizione i canali fisici di elaborazione dei dati (ovvero, i circuiti) ad un'entità (lo sviluppatore) che parla un linguaggio naturale. Diversi linguaggi di programmazione offrono diversi livelli di astrazione.

#### Linguaggi ad alto livello

In generale, i linguaggi ad *alto livello*, come ad esempio Python, sono molto "vicini" al linguaggio parlato da un essere umano, ed astraggono l'accesso alle risorse del calcolatore. Ad esempio, Python non richiede che sia lo sviluppatore a gestire la (tediosa e complessa) operazione di gestione della memoria, ma la gestisce in automatico mediante tecniche di *garbage collection*.

Ciò comporta vantaggi e svantaggi: da un lato, è più semplice scrivere programmi in un linguaggio ad alto livello; dall'altro, però, vi è una certa "mancanza di controllo" sulle operazioni compiute dalla macchina che, nonostante non risulti essere un problema nella maggior parte dei casi, può essere necessaria in caso di applicazioni che richiedono delle procedure di ottimizzazione specifiche.

#### Linguaggi a basso livello

A differenza dei linguaggi ad alto livello, quelli a *basso livello* sono più vicini al linguaggio parlato dalla macchina. In tal senso, i linguaggi di questo tipo delegano allo sviluppatore operazioni di gestione diretta delle risorse del calcolatore, ed i programmi scritti in questi linguaggi sono contestualmente più complessi, richiedendo un grado di attenzione ed ottimizzazione più elevato rispetto a quelli scritti in linguaggi ad alto livello. Ciò lascia però spazio al programmatore esperto, che potrà ottimizzare in maniera più granulare le proprie applicazioni, senza dover sottostare ai meccanismi di astrazione delle risorse usati dai linguaggi ad alto livello.

!!! nota "Nota sulla gestione delle risorse"
	I meccanismi di gestione delle risorse dei linguaggi ad alto livello non sono "poco efficienti". Tutt'altro: essendo scritti da ottimi programmatori, sono molto spesso estremamente più performanti rispetto a quelli che scriverebbe lo sviluppatore quadratico medio. Tuttavia, questi meccanismi sono, giocoforza, **generici**, dato che devono adattarsi all'intero ventaglio dei possibili algoritmi implementabili dal linguaggio di programmazione. La genericità determina, in specifiche e limitate circostanze, uno svantaggio, che potrebbe rendere preferibile un maggior controllo sulle risorse della macchina. E' importante sottolineare comunque come la maggior parte dei linguaggi di programmazione ad alto livello offra metodi specifici per gestire questo tipo di situazioni.

### Strutture dati

I linguaggi di programmazione sfruttano il concetto di *struttura dati* ci permettono di organizzare, gestire e memorizzare dati in maniera efficiente. Entrando nel dettaglio, le strutture dati sono delle *collezioni* di diversi valori, che caratterizzano anche le *relazioni* tra di essi e le *operazioni* che vi possono essere applicate.

Esistono diverse tipologie di strutture dati, ognuna delle quali adatta ad un certo utilizzo. Vediamone alcune.

* *Array*: questa struttura dati è concettualmente assimibilabile ad un *vettore* di elementi, tipicamente (ma non necessariamente, a seconda del linguaggio) dello stesso tipo, organizzati secondo un ordine specifico, e ridimensionabili a seconda delle esigenze. E' possibile accedere ad ogni elemento dell'array mediate un apposito *indice* intero.
* *Linked List* (o più semplicemente *liste*): sono delle collezioni di elementi, tipicamente dello stesso tipo. Ogni elemento della lista è chiamato *nodo*, e contiene al suo interno le informazioni riguardanti sia il valore associato a quell'elemento, sia un riferimento al nodo successivo nella lista. Concettualmente, lista ed array sono molto simili; tuttavia, la lista offre un vantaggio fondamentale, legato al fatto che è possibile inserire o rimuovere un elemento dalla lista in maniera più efficiente rispetto all'effettuare la stessa operazione su di un array.
* *Struct* (o anche *tupla*): sono delle strutture dati in cui ogni record è un valore che contiene altri valori (chiamati *membri* o *campi*), tipicamente in numero e sequenza fissi, indicizzati usando esclusivamente i nomi.
* *Union*: sono delle strutture dati che specificano quale, tra un certo numero di tipi primitivi, può essere memorizzato in una sua istanza. Si contrappongono alle struct, in quanto ammettono un unico valore per volta.
* *Oggetto*: struttura dati che contiene un certo numero di campi (come una struct) e vari metodi che operano direttamente sui contenuti dei dati.

### Linguaggi imperativi vs. linguaggi dichiarativi

In generale, è possibile operare un'ulteriore distinzione tra linguaggi di programmazione, in base alle modalità con cui viene definita la serie di operazioni che il programma dovrà eseguire.

Nella programmazione *imperativa* (o *procedurale*), è possibile controllare lo stato del programma, specificando il *flusso di esecuzione* delle istruzioni. Tipici esempi di linguaggi procedurali sono Python, C e C++.

Nella programmazione *dichiarativa* (o *non procedurale*), invece, viene semplicemente indicato al programma il risultato che vogliamo ottenere. Esempi di linguaggi di questo tipo sono SQL e Prolog.

Facciamo un esempio. In un linguaggio imperativo, "imponiamo" al programma le istruzioni da compiere; specifichiamo quindi *come* ottenere un risultato. Ad esempio:

```python
x = 12
y = x * 2
print("Il valore di x è: {}".format(x))
```

Nell'esempio precedente, scritto in Python, indichiamo al programma che deve valutare il valore di `x`, moltiplicarlo per 2, assegnarlo ad `y` e mostrarlo a schermo.

Un esempio di programmazione dichiarativa è invece quello che usiamo quando interroghiamo un database mediante istruzioni SQL. Ad esempio:

```sql
SELECT * FROM TABLE STUDENTI;
```

In questo caso, è chiaro come non si stia specificando come interrogare il database, ma soltanto quello che ci si aspetta da esso (il *cosa*).

### Espressitivà

In generale, un linguaggio è una *rappresentazione* scritta o verbale di una serie di *concetti*; la quantità e qualità di questa rappresentazione è determinata dalla *potenza espressiva* di un linguaggio.

Per quello che riguarda i linguaggi di programmazione, l'espressività è associata ai problemi che sono in grado di risolvere e, di conseguenza, agli *algoritmi che sono in grado di rappresentare*. In particolare, i linguaggi di programmazione più comuni sono spesso definiti come *Turing-completi*, in quanto possono implementare tutti gli algoritmi risolvibili da una macchina di Turing universale (torneremo più avanti su questo concetto).

I linguaggi di markup, come ad esempio HTML ed XML, non sono normalmente considerati linguaggi di programmazione.

### Sintassi e semantica (nei linguaggi di programmazione)

Come nei linguaggi naturali, anche per i linguaggi di programmazione sono essenziali i concetti di *sintassi* e *semantica*.

In particolare, la sintassi specifica le regole con le quali un'istruzione viene ritenuta valida. In generale, queste variano da linguaggio a linguaggio (rimanendo pur sempre abbastanza "affini"), e sono estremamente *rigide*: un programma non conforme alle regole sintattiche indicate per il linguaggio non potrà in alcun modo essere eseguito.

Per fortuna, queste regole sono *poche*, *semplici* e *ben definite* per ogni linguaggio. Neanche lontanamente complesse come l'uso dei congiuntivi, quindi.

Anche la semantica ha un rapporto estremamente "stretto" con l'analogo concetto usato nei linguaggi naturali, dato che ci permette di valutare il contenuto informativo di un programma. In particolare, ci sono tre metodi per trattare formalmente la semantica di un programma, allo scopo di caratterizzarne il comportamento:

* nella *semantica operazionale* si specifica come i costrutti del linguaggio vengano eseguiti su di una macchina astratta;
* nella *semantica denotazionale* si specifica come interpretare il significato dei costrutti scritti in un linguaggio;
* nella *semantica assiomatica* si specifica come determinare il significato dei costrutti scritti in un linguaggio usando degli *assiomi* (ovvero regole di "correttezza" data una certa logica).
