# Criteri di valutazione del tema d'anno

Le quattro differenti parti in cui è strutturato il tema d'anno saranno valutate come segue.

## Parte Prima - Analisi del problema

| Topic                              | Valutazione della capacità di...                                         | Punteggio    |
| ---------------------------------- | ------------------------------------------------------------------------ | ------------ |
| Descrizione del problema           | ...analisi e spiegazione dell'approccio usato                            | 0 - 10 punti |
| Individuazione di input ed output  | ...interpretazione degli input e comunicazione dei risultati i risultati | 0 - 4 punti  |
| Diagramma di flusso e pseudocodice | ...strutturazione della risoluzione del problema                         | 0 - 10 punti |
| Analisi computazionale a priori    | ...stima del costo di esecuzione dell'algoritmo                          | 0 - 6 punti  |

## Parte Seconda - Implementazione in linguaggio C

| Topic                                  | Valutazione della capacità di...                                       | Punteggio    |
| -------------------------------------- | ---------------------------------------------------------------------- | ------------ |
| Correttezza del programma              | ...utilizzo delle tecniche di programmazione                           | 0 - 18 punti |
| Documentazione del programma           | ...esposizione delle funzioni e dell'uso del programma ad utenti terzi | 0 - 4 punti  |
| Stile (commenti, modularità, etc.)     | ...adesione alle best practices considerate per il linguaggio C        | 0 - 4 punti  |
| Coerenza con flow chart e pseudocodice | ...implementazione a partire da un dato documento di design            | 0 - 4 punti  |

## Parte Terza - Implementazione in linguaggio C++

| Topic                                  | Valutazione della capacità di...                                       | Punteggio    |
| -------------------------------------- | ---------------------------------------------------------------------- | ------------ |
| Correttezza del programma              | ...utilizzo delle tecniche di programmazione                           | 0 - 18 punti |
| Documentazione del programma           | ...esposizione delle funzioni e dell'uso del programma ad utenti terzi | 0 - 4 punti  |
| Stile (commenti, modularità, etc.)     | ...adesione alle best practices considerate per il linguaggio C++      | 0 - 4 punti  |
| Coerenza con flow chart e pseudocodice | ...implementazione a partire da un dato documento di design            | 0 - 4 punti  |

## Parte Quarta - Implementazione in linguaggio Python

| Topic                                  | Valutazione della capacità di...                                       | Punteggio    |
| -------------------------------------- | ---------------------------------------------------------------------- | ------------ |
| Correttezza del programma              | ...utilizzo delle tecniche di programmazione                           | 0 - 18 punti |
| Documentazione del programma           | ...esposizione delle funzioni e dell'uso del programma ad utenti terzi | 0 - 4 punti  |
| Stile (commenti, modularità, etc.)     | ...adesione alle best practices considerate per il linguaggio Python   | 0 - 4 punti  |
| Coerenza con flow chart e pseudocodice | ...implementazione a partire da un dato documento di design            | 0 - 4 punti  |

Il risultato finale sarà dato dalla media delle valutazioni ottenute nelle quattro parti.

## Quantificazione punteggio parametri di valutazione

### Malus

I seguenti malus possono essere applicati ai topic in parte _oggettivamente_ valutabili.

| Parametro                 | Topic di riferimento         | Descrizione                                                                                                            | Punteggio                                                          |
| ------------------------- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| Programma non funzionante | Correttezza del programma    | Problema legato al funzionamento del programma, riprodotto secondo le modalità descritte nella documentazione annessa. | Da -5 a -18 punti a seconda dell'entità dei problemi rilevati.     |
| Bug                       | Correttezza del programma    | Bug che compromette, più o meno seriamente, il funzionamento del programma (che resta comunque fruibile).              | Da -1 a -4 per bug, a seconda della gravità dello stesso.          |
| Feature subottima         | Correttezza del programma    | Feature implementata in maniera incompleta, subottima o ridondante, ma senza bug apparenti.                            | Da -1 a -2, a seconda dell'entità dei problemi rilevati.           |
| Feature mancante          | Correttezza del programma    | Feature richiesta ma non implementatata.                                                                               | Da -1 a -2, a seconda dell'entità dei problemi rilevati.           |
| Documentazione incompleta | Documentazione del programma | Documentazione totalmente o parzialmente assente.                                                                      | Da -1 a -4 punti a seconda della parte di documentazione mancante. |

Tutti i topic di riferimento non riportati si intendono valutati in maniera discrezionale in base a fattori maggiormente astratti quali presentazione, adesione ai canoni illustrati durante il corso, coerenza, capacità di risoluzione del problema, etc.

!!!note "Impatto del malus"
	Si noti che questi malus vanno ad incidere _esclusivamente per le parti di loro pertinenza_: ciò significa che, ad esempio, consegnando un codice perfettamente funzionante, ma nessuna documentazione, il malus legato alla documentazione non andrà ad intaccare la valutazione ricevuta sul codice.

### Bonus

I seguenti bonus sono applicati nella valutazione complessiva degli esoneri.

| Parametro                   | Punteggio                                   |
| --------------------------- | ------------------------------------------- |
| Numero di membri del gruppo | +1 per gruppi con un singolo membro.        |
| Difficoltà traccia          | 0/+2 in base alla difficoltà della traccia. |

!!!note "Nota"
	I precedenti bonus **non concorrono** all'acquisizione della sufficienza o della lode.

!!!note "Nota sulla correzione del codice"
	Le verifiche della seconda, terza e quarta parte del tema d'anno prevedono prevalentemente il test di funzionamento del programma, con conseguente evidenziazione di eventuali bug o feature mancanti, che vanno a concorrere alla valutazione secondo le modalità esplicitate sul sito del corso. Una verifica stretta del codice non sarà effettuata, se non in situazioni eccezionali ed individuate discrezionalmente.

## Voto finale e verbalizzazione

Al termine delle quattro prove, sarà assegnato a ciascun gruppo un voto parziale, assieme ad una scheda di valutazione (questa in forma strettamente privata, consultabile su richiesta dai membri del gruppo in fase di comunicazione del voto). Tale voto sarà dato dalla media dei voti ottenuti nelle quattro prove. Gli studenti che intendessero verbalizzarlo, dovranno iscriversi ad una tra le date d'appello successive mediante le modalità standard riportate da Esse3.

!!!note "Nota"
	Si sottolinea come il voto comunicato al termine degli esoneri **non sarà in formato numerico**, ma piuttosto associato ad una valutazione di tipo **descrittivo**: il primo sarà comunicato soltanto a seguito dell'iscrizione all'appello, e secondo modalità stabilite di volta in volta.

Il giorno dell'appello, gli studenti potranno:

- accettare il voto finale degli esoneri;
- rifiutare il voto finale degli esoneri, sostenendo l'esame integrale;
- richiedere una valutazione orale integrativa, vertente sull'intero programma del corso.

La valutazione orale integrativa è **strettamente personale**: ciò significa i membri di un gruppo dovranno necessariamente richiederla (e sottoporvisi) separatamente. Le modalità e le date per l'orale saranno stabilite di volta in volta in base a richieste pervenute e disponibilità del docente.

Si noti che la valutazione orale integrativa per il tema d'anno potrà far oscillare il voto di un massimo di **tre punti**, **sia in positivo, sia in negativo**.

### Conseguimento della lode

In casi eccezionali, è possibile assegnare la lode agli studenti meritevoli. Per ottenerla, sarà necessario sottoporsi alla valutazione orale integrativa secondo le modalità prima indicate.
