# Traccia del 17/01/2024

## Esercizio 1

Utilizzando i flowchart e formalizzandoli in Algobuild, definire gli algoritmi per soddisfare le seguenti richieste.
1. Definire una funzione che permetta il caricamento di una matrice $M$ di dimensione $3 \times 4$ in modo tale che:
    a. gli elementi della prima riga di $M$ siamo numeri interi strettamente positivi generati in maniera casuale ed inclusi nell'intervallo $[3, 15]$;
    b. gli elementi della seconda riga di $M$ siano disposti in maniera inversa rispetto a quelli della prima riga;
    c. gli elementi della terza riga di $M$ isano 


Caricare un vettore colonna $V$ di dimensione $N$. Gli elementi di $V$ devono essere numeri interi positivi i quali possono essere caricati in maniera autonoma dall’utente o generati in maniera casuale. Si noti che la modalità di caricamento deve essere specificata a monte mediante un opportuno menu di scelta.
2. Ordinare il vettore $V$ secondo un ordinamento crescente.
3. Calcolare il massimo, il minimo e la media dei valori del vettore $V$ (ordinato).
4. Stampare a schermo il vettore $V$ in maniera che venga rappresentato come un vettore colonna. Ad esempio:

\begin{align}
V_1 \\
V_2 \\
\ldots \\
V_n \\
\end{align}


È richiesto che il programma sia suddiviso in procedure e/o funzioni opportunamente generalizzabili.

!!! tip "Soluzione"
    La soluzione è disponibile a [questo indirizzo](./exercise_1.md).

## Esercizio 2

Utilizzando l’ambiente di programmazione Matlab, implementare un programma che esegua le funzioni dell’esercizio 1, utilizzando un’opportuna combinazione di script, funzioni e procedure.

!!! tip "Soluzione"
    La soluzione è disponibile a [questo indirizzo](./exercise_2.md)

## Risposte ai quesiti

Di seguito riportiamo le risposte ai quesiti posti dall'esercizio 3.

!!! question "Domande"
    1. Qual è il numero di simboli distinti utilizzati nel sistema binario?
    2. In un sistema di numerazione addizionale il valore di ogni simbolo è...
    3. Detto `+` il simbolo di OR logico, quale delle seguenti identità rappresenta la legge dell'idempotenza?
    4. Un diagramma a blocchi...
    5. La programmazione strutturata...
    6. Un blocco di codice inserito fra `dowhile` ed `end` in MATLAB...
    7. Indicare quale delle seguenti righe può essere utilizzata per definire una procedura in MATLAB.
    8. Un driver...
    9. L'unità MMU...
    10. Un algoritmo iterativo...

??? tip annotate "Risposta"
    1. Due (1)
    2. ...fisso (2)
    3. `k + k = k` (3)
    4. ...è una rappresentazione grafica di un algoritmo (4)
    5. ...rispetta il teorema di Bohm-Jacopini (5)
    6. Nessuna delle altre risposte è vera (6)
    7. `function testProc(a, b)` (7)
    8. ...deve essere installato su una macchina affinché questa possa controllare una certa periferica (8)
    9. ...si serve di una tabella delle pagine allo scopo di mettere in relazione pagine logiche e pagine fisiche in memoria. (9)
    10. ...si basa sullo schema di flusso del ciclo.

1.  :man_raising_hand: I simboli sono due, ovvero lo `0` e l'`1`.
2.  :man_raising_hand: Nei sistemi di numerazione addizionali, come ad esempio l'alfabeto romano, il valore di ciascun simbolo è fisso, a differenza dei sistemi posizionali.
3.  :man_raising_hand: La legge dell'idempotenza indica che `k + k = k x k = k`, e discende direttamente dalla definizione algebrica generale.
4.  :man_raising_hand: Ricordiamo che i diagrammi a blocchi rappresentano la struttura dell'algoritmo, e non sono in alcun modo vincolati al linguaggio di programmazione usato.
5.  :man_raising_hand: La programmazione strutturata si basa sui tre tipi di struttura identificati dal teorema di Bohm-Jacopini, e permette ovviamente l'uso di diagrammi strutturati.
6.  :man_raising_hand: MATLAB non permette l'uso di strutture `dowhile`.
7.  :man_raising_hand: MATLAB non ha una parola chiave specifica per le procedure. Invece, è necessario usare una funzione senza alcun valore di ritorno.
8.  :man_raising_hand: Pensiamo, ad esempio, ai driver della scheda video.
9.  :man_raising_hand: Ricordiamo che è utilizzata nelle tecniche di paging.
10.  :man_raising_hand: Ricordiamo che l'algoritmo iterativo è rappresentato mediante un flusso di verifica di una condizione *e* di incremento di un contatore/aggiornamento di condizione.
