## Traduttori

Parlando dei linguaggi di programmazione, abbiamo detto che:

!!! cite "Il Docente, o, alternativamente, Queste Dispense."
	*La principale differenza che intercorre con il linguaggio naturale è che mentre quest'ultimo è orientato alla comunicazione con altri esseri umani, i linguaggi di programmazione permettono agli umani di comunicare una serie di istruzioni ad una macchina, la quale potrebbe controllare dei dispositivi esterni di I/O (quali stampanti ed hard disk, ma anche bracci robotici, ad esempio).*

L'esecuzione di questo task è delegato ad un apposito programma chiamato *traduttore*, che si occupa di tradurre il codice scritto in un linguaggio (chiamato *linguaggio sorgente*) in codice scritto in un altro linguaggio (chiamato *linguaggio obiettivo*).

Normalmente, il linguaggio sorgente è ad un livello di astrazione più alto rispetto al linguaggio obiettivo: ad esempio, il linguaggio sorgente potrebbe essere il C, mentre il linguaggio obiettivo potrebbe essere Assembly.

Il traduttore ha diversi compiti: per prima cosa, si occupa di verificare la *correttezza sintattica* del codice scritto in linguaggio sorgente. Per fare un esempio, il traduttore validerà questa istruzione:

```python
a = 1 + 2
```

ma non questa:

```python
a = = 2 + 'pippo'
```

Una volta validata la correttezza sintattica delle istruzioni analizzate, attribuirà a ciascuna di esse un opportuno *significato*, associando le corrispondenti istruzioni nel linguaggio obiettivo. E' importante sottolinare come l'interpretazione debba essere *univoca*, onde garantire la proprietà di non ambiguità degli algoritmi.

Esistono principalmente due categorie di traduttori: i *compilatori* e gli *interpreti*.

## Compilatori

Il termine *compilatore* viene usato per indicare i traduttori che si occupano di tradurre *direttamente* il codice da un linguaggio sorgente ad alto livello ad un linguaggio obiettivo a basso livello, come assembly, codice oggetto o codice macchina.

!!! note "Nota"
	Il fatto che un compilatore traduca direttamente il codice da linguaggio ad alto livello a codice oggetto/macchina implica che quest'ultimo sia *specifico* per un certo tipo di hardware e software. Ciò comporta che, in molte situazioni, non saremo in grado di eseguire il codice compilato per i nostri PC su dispositivi come Arduino o i nostri smartphone!

### Tipologie di compilatore (alcuni esempi)

Esistono diversi tipi di compilatore. Ad esempio, se il programma compilato può essere eseguito su un computer le cui caratteristiche hardware o software sono diverse da quelle del computer sul quale il programma è stato compilato, siamo di fronte ad un *cross-compilatore*.

!!! note "Nota"
	Per "caratteristiche hardware o software" si intendono prevalentemente CPU (ed il suo instruction set) e sistema operativo (ed i driver che comandano i diversi dispositivi).

Il programma *duale* di un compilatore è chiamato *decompilatore*, ed è, prevedibilmente, un programma che traduce il codice da un linguaggio sorgente a basso livello ad un linguaggio obiettivo a più alto livello.

Un altro esempio di compilatore è il *transcompilatore*, che traduce un programma scritto in un sorgente ad alto livello in codice scritto in un obiettivo sempre ad alto livello.

### Operazioni di un compilatore

La maggior parte dei compilatori odierni segue un percorso articolato in tre diverse fasi (*three-stage compilers*), chiamate rispettivamente *front end*, *middle end* e *back end*.

#### Front end

Lo scopo del *front end* è quello di analizzare il codice scritto in liguaggio sorgente, creando una *rappresentazione intermedia* del programma.

Il processo supportato dalla fase di front end si articola in quattro diverse fasi.

##### Preprocessing

La fase di *preprocessing* (in italiano *pre-elaborazione*) si occupa di sostituire alcune direttive specifiche per il linguaggio (ad esempio, le direttive `#define` in C) con il corrispondente codice sorgente.

##### Analisi lessicale

La fase di *analisi lessicale* prevede la lettura del sorgente come un'unica stringa, e la successiva suddivisione della stessa in "parti" dette *token*, i quali sono delimitati da caratteri come segni di interpunzione (ad esempio, virgole, punti, etc.), operatori matematici (ad esempio, i segni `+`, `-`, etc.), parentesi, o anche nomi di variabile e parole riservate.

Un esempio di tokenizzazione è il seguente. il codice sorgente:

```c
if (x > 0.0) 
{
	y = 1.0;
}
```

diventa:

```c
if(x>0.0)y=1.0;
```

che produce i token `if`, `(`, `x`, `>`, `0.0`, `)`, `y`, `=`, `1.0`.

##### Analisi sintattica

La fase di *analisi sintattica*, comunemente nota anche come *parsing*, prevede l'analisi dei singoli token allo scopo di valutarne la correttezza *sintattica*, ovvero l'adesione alle regole grammaticali stabilite per quel linguaggio.

L'analisi sintattica crea una struttura ad albero costruita a partire dalle regole formali del linguaggio, chiamata *albero di parsing* (*parse tree*).

##### Analisi semantica

La fase di *analisi semantica* integra le informazioni immagazzinate nel parse tree con informazioni di tipo semantico, come ad esempio il *type checking*, che controlla la coerenza tra i diversi tipi assunti dalle variabili.

#### Middle End

Lo scopo del *middle end* è quello di ottimizzare la rappresentazione intermedia ottenuta dal front end.

Per far questo, sono implementate delle tecniche di *analisi* del programma (ad esempio, mediante l'analisi del flusso di esecuzione, allo scopo di valutare e la presenza di eventuali ridondanze) ed *ottimizzazione* (ad esempio, rimuovendo le ridondanze individuate nella fase precedente).

Un esempio di ridondanza è il seguente:

```csharp
int main (void) {
	int a = 0;
	// Codice ridondante!
	if (1 == 0) {
		a = 1;
	}
	return a;
}
```

Il codice all'interno dell'istruzione condizionale *non è raggiungibile*, in quanto la condizione di uguaglianza tra uno e zero non è, per le conoscenze attuali, mai verificata.

#### Back End

Lo scopo del *back end* è quello di inserire (opzionalmente) delle ottimizzazioni specifiche per l'architettura corrente (ovvero per il processore per il quale il codice sta venendo compilato), e generare il codice *oggetto*.

!!! note "Nota"
	Il codice oggetto **non** è il programma eseguibile. Generare l'eseguibile è compito di un altro programma, spesso integrato in quelli che generalmente sono indicati come compilatori, chiamato *linker*.

## Interpreti

L'altro tipo di traduttore comunemente utilizzato al giorno d'oggi è chiamato *interprete*.

L'approccio usato dall'interprete si differenzia da quello usato dal compilatore principalmente per un dettaglio: laddove il compilatore fa in modo che l'intero processo di traduzione da codice sorgente a programma eseguibile avvenga *prima* dell'esecuzione del programma, in un lasso di tempo chiamato *compile time*, l'interprete esegue un'istruzione *immediatamente*; in teoria, ogni istruzione in un linguaggio interpretata potrebbe essere eseguita immediatamente dopo la sua scrittura. Non vi è quindi una netta separazione, almeno dal punto di vista dell'utente, tra *compile time* e *run time* (con quest'ultimo il lasso di tempo in cui il programma è in esecuzione).

Gli step di interpetazione sono quindi essenzialmente tre:

* controllo dell'istruzione sul codice sorgente;
* traduzione in linguaggio macchina;
* esecuzione dell'istruzione tradotta.

Ne consegue che un programma interpretato potrebbe interrompersi "al volo" (ovvero a run time), proprio perché l'interprete non è in grado di anticipare eventuali errori sul sorgente.

## Compilatore vs. Interprete

Di seguito una tabella comparativa di vantaggi e svantaggi legati all'adozione di un compilatore o di un interprete.

|   | Compilatore | Interpete |
| - | ----------- | --------- |
| Vantaggi | <ul><li>Ottimizzazione del codice</li><li>Maggiore velocità di esecuzione</li><li>Controllo sintattico e semantico</li></ul> | <ul><li>*Compile time* nullo o ridotto</li><li>Maggiore portabilità tra architettura</li><li>Possibilità di debug con granularità a livello di singola istruzione</li></ul> |
| Svantaggi | <ul><li>Minore portabilità tra architetture</li><li>Debug complesso da effettuare</li></ul> | <ul><li>Minore velocità di esecuzione</li><li>Performance non ottimizzate</li><li>Possibili errori imprevisti a *run time*</li></ul> |

## Linguaggi compilati e linguaggi interpretati

Per *linguaggio compilato* si intende un linguaggio di programmazione le cui implementazioni sono tipicamente *compilate*; di converso, un linguaggio *interpretato* prevede l'uso estensivo di interpeti.

La distinzione è però alquanto vaga. Infatti, almeno in linea di principio, qualunque linguaggio può essere implementato indifferentemente mediante un compilatore od un itnerprete. E' anche possibile *combinare* entrambe le soluzioni: un compilatore può ad esempio occuparsi della traduzione del codice sorgente nella rappresentazione intermedia, chiamata in questi casi *bytecode*, che viene passata ad un interprete che la esegue. E' questo ad esempio il caso di Java, che utilizza questo tipo di soluzione per passare il bytecode alla *Java Virtual Machine*, di cui esiste un'implementazione per la maggior parte delle architetture esistenti.
