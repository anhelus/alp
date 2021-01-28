# Esercizi per di programmazione

Per questi esercizi, è disponibile il codice, da usare come base per lo studio.

## Linguaggio C

### Esercizio 1: Matematicamente

Creare il programma `Matematicamente` che contiene al suo interno due moduli:

- il modulo `aritmetica`, contenente le funzioni `aggiungi` e `moltiplica`;
- il modulo `trigonometria`, contenente le funzioni `seno` e `coseno`.

La descrizione delle funzioni è la seguente:

- `aggiungi` restituisce la somma di due interi `a` e `b`;
- `moltiplica` restituisce il prodotto di due interi `a` e `b`;
- `seno` restituisce il seno di un angolo a partire dal suo coseno usando l'identità trigonometrica;
- `coseno` restituisce il coseno di un angolo a partire dal suo seno usando l'identità trigonometrica.

Provare l'utilizzo dei due moduli.

#### Codice fornito

| Modulo            | Link                                                                                                                                   |
| ----------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| `aritmetica.h`    | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Matematicamente/aritmetica.h)    |
| `aritmetica.c`    | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Matematicamente/aritmetica.c)    |
| `trigonometria.h` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Matematicamente/trigonometria.h) |
| `trigonometria.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Matematicamente/trigonometria.c) |
| `main.c`          | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Matematicamente/main.c)          |

### Esercizio 2. AreaPerimetro

Creare il programma `AreaPerimetro`, che include due funzioni:

- la funzione `calcola_area_quadrato` restituisce l'area di un quadrato dato il lato;
- la funzione `calcola_perimetro_quadrato` restituisce il perimetro di un quadrato dato il lato.

1. Si verifichi cosa accade se si prova ad accedere al valore del perimetro all'interno della funzione `calcola_area_quadrato`, e viceversa.
2. Si utilizzi una variabile globale per impostare il valore del lato.
3. Si utilizzi una variabile locale, il cui nome è lo stesso di quello associato alla variabile globale, per impostare il valore del lato.

!!! tip "Suggerimento"
	Per verificare il valore di area e perimetro, si utilizzi la funzione `printf`.

#### Codice fornito

| Modulo   | Link                                                                                                                        |
| -------- | --------------------------------------------------------------------------------------------------------------------------- |
| `main.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/AreaPerimetro/main.c) |

### Esercizio 3. ContatoreStatico

Creare il programma `ContatoreStatico` che include una funzione `conta()` che, ogni volta che viene chiamata, incrementa il valore numerico intero associato ad un contatore.

Fare in modo che:

1. la funzione `conta()` non accetti in ingresso alcun parametro;
2. il contatore sia una variabile locale alla funzione `conta()`.

!!! tip "Suggerimento"
	Si utilizzi in maniera appropriata la parola chiave `static`.

#### Codice fornito

| Modulo   | Link                                                                                                                              |
| -------- | --------------------------------------------------------------------------------------------------------------------------------- |
| `main.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Contatore%20Statico/main.c) |

### Esercizio 4. Operandi

#### Parte 1: Quadratico

Scriviamo il programma `Quadratico`, che include una funzione che, dato un valore intero in ingresso, ne calcola il quadrato e lo restituisce. Il valore restituito dovrà essere stampato a schermo all'interno della funzione `main`.

#### Parte 2: Pari e Dispari

Scriviamo il programma `PariDispari` che, dato un valore intero in ingresso, valuta se questo è pari mediante un'apposita funzione. Detta funzione restituirà un valore booleano in uscita; se questo è _vero_ (_true_), avviserà l'utente che il numero è pari, altrimenti avviserà l'utente che il numero è dispari.

!!! tip "Suggerimento"
	Utilizzare l'header `stdbool.h` per gestire i valori booleani. In alternativa, ricordare che ogni intero diverso da 0 è considerato come un _true_.

#### Parte 3: Confrontiamoci

Scriviamo il programma `Confrontiamoci`, che confronta due intervalli di valori di tipo $[a,b]$ e $[c,d]$ con $(a,b,c,d)$ numeri interi. Scriviamo in primis una funzione `confronto_relazionale` che dovrà:

- stampare a schermo il _maggiore_ tra gli estremi inferiori $a$ e $c$;
- stampare a schermo il _minore_ tra gli estremi superiori $b$ e $d$;
- stabilire se il numero di elementi all'interno dei due insiemi è lo stesso.

Successivamente, scriviamo una funzione `confronto_logico` che dovrà verificare, usando solo operatori di logica booleana, se gli intervalli sopraccitati hanno lo stesso numero di elementi e gli estremi degli stessi coincidono, oppure se una sola di queste condizioni è verificata.

#### Codice fornito

| Modulo   | Link                                                                                                                   |
| -------- | ---------------------------------------------------------------------------------------------------------------------- |
| `main.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Operandi/main.c) |

### Esercizio 5. Array

Un tensore è un array ad $n$ dimensioni contenente valori arbitrari. Creare due tensori di dimensioni $3 \times 3 \times 3$, uno contenente valori interi, e l'altro contenente valori in formato `double`. Usare l'operatore `sizeof` per confrontare lo spazio occupato in memoria, visualizzando a schermo tutti i valori dell'array più "pesante".

#### Codice fornito

| Modulo   | Link                                                                                                                |
| -------- | ------------------------------------------------------------------------------------------------------------------- |
| `main.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Array/main.c) |

### Esercizio 6. Puntatori

#### Codice fornito

| Modulo                 | Link                                                                                                                                  |
| ---------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| `puntatori.h`          | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Puntatori/puntatori.h)          |
| `puntatori.c`          | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Puntatori/puntatori.c)          |
| `puntatori_funzione.h` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Puntatori/puntatori_funzione.h) |
| `puntatori_funzione.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Puntatori/puntatori_funzione.c) |
| `main.c`               | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Puntatori/main.c)               |

### Esercizio 7. Typedef

#### Codice fornito

| Modulo   | Link                                                                                                                  |
| -------- | --------------------------------------------------------------------------------------------------------------------- |
| `main.c` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C/Linguaggio%20C/Typedef/main.c) |

## Esercizi in C++

### Esercizio 1. Namespaces

#### Codice fornito

| Modulo     | Link                                                                                                               |
| ---------- | ------------------------------------------------------------------------------------------------------------------ |
| `main.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Namespace/source.cpp) |

### Esercizio 2. Variabili reference

#### Codice fornito

| Modulo     | Link                                                                                                               |
| ---------- | ------------------------------------------------------------------------------------------------------------------ |
| `main.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Reference/source.cpp) |

### Esercizio 3. I/O in C++

#### Codice fornito

| Modulo     | Link                                                                                                              |
| ---------- | ----------------------------------------------------------------------------------------------------------------- |
| `main.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/IOSample/source.cpp) |

### Esercizio 4. Classi

#### Codice fornito

| Modulo          | Link                                                                                                               |
| --------------- | ------------------------------------------------------------------------------------------------------------------ |
| `contratti.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Classi/contratti.cpp) |
| `contratti.h`   | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Classi/contratti.h)   |
| `persona.cpp`   | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Classi/persona.cpp)   |
| `persona.h`     | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Classi/persona.h)     |
| `main.cpp`      | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/Classi/main.cpp)      |

### Esercizio 5. Funzioni avanzate

#### Codice fornito

| Modulo     | Link                                                                                                                      |
| ---------- | ------------------------------------------------------------------------------------------------------------------------- |
| `main.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/FunzioniAvanzate/source.cpp) |

### Esercizio 6. I/O su file

#### Codice fornito

| Modulo     | Link                                                                                                            |
| ---------- | --------------------------------------------------------------------------------------------------------------- |
| `main.cpp` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20C%2B%2B/FileIO/source.cpp) |

## Esercizi in Python

### Esercizio 1. Liste come stack e code

#### Codice fornito

| Modulo   | Link                                                                                                                                    |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| `run.py` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20Python/03%20-%20Strutture%20Dati/a_stack_queue.py) |

### Esercizio 2. List comprehension

#### Codice fornito

| Modulo   | Link                                                                                                                                           |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| `run.py` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Linguaggio%20Python/03%20-%20Strutture%20Dati/b_list_comprehension.py) |

### Esercizio 3. Esercizi sui moduli

#### Codice fornito

| Modulo   | Link                                                                                                         |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| `run.py` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/tree/master/Linguaggio%20Python/04%20-%20Modulo) |

### Esercizio 3. Esercizi sulle classi

#### Codice fornito

| Modulo   | Link                                                                                                         |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| `run.py` | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/tree/master/Linguaggio%20Python/05%20-%20Classi) |
