## Esercizi svolti

Questi esercizi sono svolti e disponibili a [questo link](https://github.com/anhelus/informatica-dm-uniba-ex.git).

!!! warning "Nota!"
Il fatto che gli esercizi siano svolti non vuol essere un incoraggiamento a copiarne la soluzione. L'idea è invece quella di usarla come _riferimento_, per confrontare il proprio approccio ad una tra le tante possibili risoluzioni.

### Modularità

#### 1. Matematicamente

Creare il programma `Matematicamente` che contiene al suo interno due moduli:

- il modulo `aritmetica`, contenente le funzioni `aggiungi` e `moltiplica`;
- il modulo `trigonometria`, contenente le funzioni `seno` e `coseno`.

La descrizione delle funzioni è la seguente:

- `aggiungi` restituisce la somma di due interi `a` e `b`;
- `moltiplica` restituisce il prodotto di due interi `a` e `b`;
- `seno` restituisce il seno di un angolo a partire dal suo coseno usando l'identità trigonometrica;
- `coseno` restituisce il coseno di un angolo a partire dal suo seno usando l'identità trigonometrica.

Provare l'utilizzo dei due moduli.

### Visibilità delle variabili

#### 2. AreaPerimetro

Creare il programma `AreaPerimetro`, che include due funzioni:

- la funzione `calcola_area_quadrato` restituisce l'area di un quadrato dato il lato;
- la funzione `calcola_perimetro_quadrato` restituisce il perimetro di un quadrato dato il lato.

1. Si verifichi cosa accade se si prova ad accedere al valore del perimetro all'interno della funzione `calcola_area_quadrato`, e viceversa.
2. Si utilizzi una variabile globale per impostare il valore del lato.
3. Si utilizzi una variabile locale, il cui nome è lo stesso di quello associato alla variabile globale, per impostare il valore del lato.

!!! tip "Suggerimento"
Per verificare il valore di area e perimetro, si utilizzi la funzione `printf`.

#### 3. ContatoreStatico

Creare il programma `ContatoreStatico` che include una funzione `conta()` che, ogni volta che viene chiamata, incrementa il valore numerico intero associato ad un contatore.

Fare in modo che:

1. la funzione `conta()` non accetti in ingresso alcun parametro;
2. il contatore sia una variabile locale alla funzione `conta()`.

!!! tip "Suggerimento"
Si utilizzi in maniera appropriata la parola chiave `static`.

#### 4. Operatori

##### Parte 1: Quadratico

Scriviamo il programma `Quadratico`, che include una funzione che, dato un valore intero in ingresso, ne calcola il quadrato e lo restituisce. Il valore restituito dovrà essere stampato a schermo all'interno della funzione `main`.

##### Parte 2: Pari e Dispari

Scriviamo il programma `PariDispari` che, dato un valore intero in ingresso, valuta se questo è pari mediante un'apposita funzione. Detta funzione restituirà un valore booleano in uscita; se questo è _vero_ (_true_), avviserà l'utente che il numero è pari, altrimenti avviserà l'utente che il numero è dispari.

!!! tip "Suggerimento"
Utilizzare l'header `stdbool.h` per gestire i valori booleani. In alternativa, ricordare che ogni intero diverso da 0 è considerato come un _true_.

##### Parte 3: Confrontiamoci

Scriviamo il programma `Confrontiamoci`, che confronta due intervalli di valori di tipo $[a,b]$ e $[c,d]$ con $(a,b,c,d)$ numeri interi. Scriviamo in primis una funzione `confronto_relazionale` che dovrà:

- stampare a schermo il _maggiore_ tra gli estremi inferiori $a$ e $c$;
- stampare a schermo il _minore_ tra gli estremi superiori $b$ e $d$;
- stabilire se il numero di elementi all'interno dei due insiemi è lo stesso.

Successivamente, scriviamo una funzione `confronto_logico` che dovrà verificare, usando solo operatori di logica booleana, se gli intervalli sopraccitati hanno lo stesso numero di elementi e gli estremi degli stessi coincidono, oppure se una sola di queste condizioni è verificata.

#### 5. Array

Un tensore è un array ad $n$ dimensioni contenente valori arbitrari. Creare due tensori di dimensioni $3 \times 3 \times 3$, uno contenente valori interi, e l'altro contenente valori in formato `double`. Usare l'operatore `sizeof` per confrontare lo spazio occupato in memoria, visualizzando a schermo tutti i valori dell'array più "pesante".

## Esercizi da svolgere

Lo svolgimento di questi esercizi è delegato allo studente.

### Modularità

#### 1. SimulAuto

Creare il programma `SimulAuto` che contiene al suo interno due moduli:

- il modulo `gestisci_velocita`, contenente le funzioni `accelera` e `decelera`;
- il modulo `gestisci direzione`, contenente la funzione `sterza`.

Le funzioni sono descritte come segue:

- `accelera` restituisce la velocità raggiunta dopo `t` secondi a partire dalla velocità `v_i` applicando l'accelerazione `a`;
- `decelera` restituisce la velocità raggiunta dopo `t` secondi a partire dalla velocità `v_i` applicando la decelerazione `d`;
- `sterza` restituisce il nuovo angolo di sterzata a partire da quello attuale `a` e da quello applicato `s`.

!!! note "Nota"
Tutti i valori sono da considerarsi interi.

!!! tip "Suggerimento"
Si consideri l'accelerazione pari ad: $a = \frac{v_f - v_i}{t_f - t_i}$.
