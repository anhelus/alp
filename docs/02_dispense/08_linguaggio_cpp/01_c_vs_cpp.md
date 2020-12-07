Partiamo con quello che, probabilmente, rappresenta il concetto più importante da sottolineare, ovvero:

!!! cite "Affermazione importantissima"
	Il C++ è un _superset_ del C.

Ciò significa, banalmente, che le istruzioni che abbiamo visto ed usato finora in C definiscono un sottoinsieme del C++. Di conseguenza, i due linguaggi condividono una sintassi ed una semantica comune; ciò tuttavia non deve trarre in inganno, perché il C++ utilizza diversi concetti avanzati che il C non ha a sua disposizione. Vediamoli insieme.

## Concetti generali

In primis, vediamo riassunte nella seguente tabella alcune differenze fondamentali che intercorrono tra i due linguaggi.

| Argomento                   | C                               | C++                               |
| --------------------------- | ------------------------------- | --------------------------------- |
| Keyword                     | 32                              | 52                                |
| Paradigma di programmazione | Imperativo                      | Imperativo/OOP                    |
| Focus principale            | Metodi e processi               | Dati                              |
| Tipi definiti dall'utente   | Supporto limitato con `typedef` | Pieno supporto mediante le classi |
| Gestione delle eccezioni    | Non presente                    | Presente                          |

Nella precedente tabella, vediamo un semplice dato "numerico", dato dal maggior numero di keyword a disposizione per il C++; ciò indica la presenza di una sintassi comunque più ricca ed articolata, necessaria a supportare alcuni concetti avanzati non a disposizione del C.

La prima differenza di peso sta nel paradigma di programmazione utilizzato: laddove il C infatti utilizza esclusivamente il concetto di programmazione imperativa, il C++ permette di sfruttare la potenza della **programmazione orientata agli oggetti** (in inglese, **object oriented programming**, **OOP**). Conseguenza naturale è il **focus** del programma: laddove in C l'obiettivo è modellare il _processo_ alla base del nostro algoritmo, nel C++ è necessario focalizzarsi sui _dati_ che viaggiano da un'istruzione all'altra.

Altra cosa importante da considerare è il supporto ai tipi definiti dall'utente. Anche C lo offriva: abbiamo infatti visto che, grazie alla parola chiave `typedef`, è possibile definire tipi personalizzati anche abbastanza complessi usando adeguatamente struct ed union. Tuttavia, C++ riesce a potenziare gli strumenti in mano al programmatore grazie al concetto di **classe**.

In ultimo, a differenza del C, il C++ è in grado di gestire situazioni inattese grazie al meccanismo delle **eccezioni**, che ci permettono di "verificare" il risultato di una serie di istruzioni, gestendo direttamente nel codice sorgente eventuali errori insorti.

## Concetti legati alla OOP

Ed è qui che arriviamo al "succo" delle differenze tra C e C++, ovvero quelle che nascono dall'adesione di quest'ultimo al paradigma OOP. Vediamole brevemente riassunte nella seguente tabella.

| Argomento                          | C                       | C++                       |
| ---------------------------------- | ----------------------- | ------------------------- |
| Namespace                          | Non definito            | Definito                  |
| Allocazione dinamica della memoria | `malloc()` e `calloc()` | `new()` e `delete()`      |
| Rapporto tra variabili e funzioni  | Separate                | Incapsulate negli oggetti |
| Modificatori di accesso            | No                      | Sì                        |

La prima importante differenza è quella legata all'adozione, da parte del C++, del concetto di _namespace_, utile ad evitare delle "collisioni" di dominio. In parole povere, usare i namespace permette di diminuire drasticamente le ambiguità presenti nel codice.

La seconda importante differenza è quella legata ai meccanismi di allocazione dinamica della memoria: in C, questi vengono gestiti mediante l'utilizzo di funzioni come `malloc()`, `calloc()` e `free()`, mentre nel C++ ci si concentra sugli operatori di creazione e distruzione degli oggetti.

Altre importanti differenze stanno nel rapporto tra variabili e funzioni, che in C++ fanno largo uso del concetto di _incapsulamento_ per evitare l'accesso da parte di codice esterno e, potenzialmente, dannoso, e nell'utilizzo dei _modificatori di accesso_ per regolare la visibilità di un attributo o di una funzione di una classe.

In generale, però, i concetti maggiormente importanti sono tre, ovvero **incapsulamento**, **polimorfismo** ed **ereditarietà**; li vedremo più avanti, quando parleremo più estesamente della programmazione orientata agli oggetti.
