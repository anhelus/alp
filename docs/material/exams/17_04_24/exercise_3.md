# Soluzione all'esercizio 3

Di seguito riportiamo le risposte ai quesiti posti dall'esercizio 3.

!!! question "Domande"
    1. In un sistema di numerazione posizionale...
    2. In un sistema di numerazione addizionale il valore di ogni simbolo è...
    3. Detto + il simbolo di OR logico, quale delle seguenti identità rappresenta la legge dell'idempotenza?
    4. Un diagramma a blocchi...
    5. Un diagramma a blocchi strutturato...
    6. Un blocco di codice inserito tra "dowhile" ed "end", in MATLAB:
    7. Indicare quale delle seguenti righe può essere usata per definire una procedura in MATLAB.
    8. Il clock di sistema...
    9. Un processo...
    10. Un algoritmo iterativo...

??? tip annotate "Risposta"
    1. ...il valore di ogni cifra dipende dalla sua posizione nel numero. (1)
    2. ...fisso. (2)
    3. `z + z = z` (3)
    4. ...è una rappresentazione grafica di un algoritmo. (4)
    5. ...è sempre preferibile al suo equivalente non strutturato. (5)
    6. Nessuna delle altre risposte è vera. (6)
    7. `function testProc(a, b)`. (7)
    8. ...ha il compito di sincronizzare lo operazioni. (8)
    9. ...è un'entità dinamica che contiene il codice, i dati, e lo stato di esecuzione. (9)
    10. ...si basa sullo schema di flusso del ciclo.

1.  :man_raising_hand: Nei sistemi di numerazione posizionali, come ad esempio il sistema numerico, il valore di ciascun simbolo è dipendente dalla posizione, a differenza dei sistemi addizionali.
2.  :man_raising_hand: Nei sistemi di numerazione addizionali, come ad esempio quello romano, il valore di ciascun simbolo è fisso, a differenza dei sistemi posizionali.
3.  :man_raising_hand: La legge dell'idempotenza indica che `z + z = z x z = z`, e discende direttamente dalla definizione algebrica generale.
4.  :man_raising_hand: Ricordiamo che i diagrammi a blocchi rappresentano la struttura dell'algoritmo, e non sono in alcun modo vincolati al linguaggio di programmazione usato.
5.  :man_raising_hand: La programmazione strutturata ha permesso di andare oltre il paradigma dello *spaghetti coding*, rimuovendo "salti" di difficile interpretabilità e manutenibilità, e facilitando di molto la vita del programmatore, che può usare le tre strutture base offerte da questo tipo di programmazione per descrivere un algoritmo.
6.  :man_raising_hand: MATLAB non permette l'uso di strutture `dowhile`.
7.  :man_raising_hand: MATLAB non ha una parola chiave specifica per le procedure. Invece, è necessario usare una funzione senza alcun valore di ritorno.
8.  :man_raising_hand: Il clock di sistema è una sorta di "metronomo" che coordina l'accesso ai registri della memoria, sia in scrittura, sia in lettura, allo scopo di mantenere la coerenza delle operazioni.
9.  :man_raising_hand: La definizione di "processo" discende direttamente dalla rappresentazione del nostro programma, correlato di dati e stato attuale, all'interno della struttura "a cipolla" del sistema operativo.
10.  :man_raising_hand: Ricordiamo che l'algoritmo iterativo è rappresentato mediante un flusso di verifica di una condizione *e* di incremento di un contatore/aggiornamento di condizione.
