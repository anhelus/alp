# 2.8 I paradigmi di programmazione

Nella [lezione 6](../02_structured/01_intro/lecture.md) abbiamo parlato del paradigma della programmazione strutturata riferendoci a tutte quelle tecniche volte ad imprimere una certa struttura nel nostro codice. Abbiamo però anche sottolineato come quello della programmazione strutturata *non* sia l'unico paradigma di programmazione presente al giorno d'oggi; esistono infatti diversi altri approcci, tutti però riconducibili a due macro-aree, ovvero quelle della *programmazione imperativa* da un lato, e della *programmazione dichiarativa* dall'altro.

## La programmazione imperativa

Come suggerito dal termine stesso, il paradigma della programmazione imperativa prevede che il nostro programma espliciti una sequenza ben definita di istruzioni da seguire, integrate secondo le strutture che abbiamo visto quando abbiamo parlato della [programmazione strutturata](../02_structured/01_intro/lecture.md).

In generale, questo approccio risulta essere decisamente comprensibile dal programmatore, che si limita ad indicare una sequenza più o meno articolata di "ordini"; tuttavia, è importante sottolineare come la maggior chiarezza del paradigma imperativo rispetto a quello dichiarativo comporti contestualmente una maggior verbosità del primo rispetto al secondo.

Esempi di linguaggi di programmazione che adottano il paradigma imperativo sono C, C++, Java e Python.

Tra i linguaggi di programmazione imperativa si annoverano tre distinti "stili" di programmazione, ovvero quello strutturato (che abbiamo già trattato), quello procedurale e quello modulare.

In particolare, nell'approccio procedurale il programma viene suddiviso in piccole task, ciascuna delle quali è descritta nel codice mediante una *procedura*, concetto assimilabile al moderno "metodo" o "funzione". Il paradigma modulare fa un ulteriore passo in avanti in tal senso, e struttura il programma in una serie di moduli indipendenti combinati tra loro a formare il software definitivo.

## La programmazione dichiarativa

Il paradigma di programmazione dichiarativa prevede che il risultato richiesto sia *descritto*, e che non siano invece specificate le singole istruzioni da parte dello sviluppatore.

In pratica, a differenza del paradigma imperativo, che definisce *come* arrivare ad un risultato, il paradigma dichiarativo si limita a descrivere cià che si vuole ottenere, posizionandosi di conseguenza più vicino all'essere umano che al calcolatore (ovvero ad un *livello di astrazione* più elevato). Esempi di linguaggi di programmazione che seguono il paradigma imperativo sono Prolog, Lisp o SQL.

In analogia al paradigma imperativo, anche quello dichiarativo vede due possibili stili di programmazione, ovvero quello *funzionale* e quello *logico*. In ogni caso, i paradigmi dichiarativi sono generalmente più complessi da utilizzare rispetto a quelli imperativi, in quanto richiedono un elevato apporto logico da parte del programmatore, che invece nel paradigma imperativo deve "limitarsi" ad implementare correttamente una sequenza di istruzioni.
