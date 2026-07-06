# 3.2.2 - Ricerca binaria

## Introduzione

La *ricerca dicotomica* o, più comunemente, *binary search*, permette di ridurre in maniera drastica il numero di operazioni necessarie per trovare un elemento all'interno di una lista *ordinata*.

!!! note "Definizione del problema"
    La ricerca dicotomica serve a trovare un oggetto in una lista ordinata.

## Descrizione dell'algoritmo

L'idea alla base della binary search è *tenere traccia di un intervallo di ipotesi ragionevoli*. Facciamo un rapido esempio per capire al meglio di cosa si tratta.

Immaginiamo che noi, Alice, chiediamo al nostro collega, Bob, di pensare ad un numero compreso tra *uno* e *cento*. Il nostro obiettivo è quello di indovinare il numero in meno di otto mosse: facendolo, costringeremo Bob a pagare il caffè (anche al Docente). Le regole dicono che, ad ogni mossa, diremo a Bob un numero, e lui ci dirà soltanto se quello che ha pensato è *inferiore* o *superiore*.

Bob già gongola, pensando al caffè che gusterà a nostre spese: in realtà, però, non sa che noi abbiamo seguito l'insegnamento del Docente, e quindi siamo pronti a fargli sparire il sorriso dalle labbra.

La nostra strategia è semplice: scartare, ad ogni mossa, il maggior numero possibile di *ipotesi false*, ovvero di numeri che *non* coincidono con quello pensato da Bob. Per farlo, partiamo con una mossa standard: diciamo a Bob che, a nostro avviso, il numero cui ha pensato è 50. Bob, ovviamente, sogghigna: non è quello, e si limita a dirci che è *superiore*. Quello che lui non afferra al volo è che ha appena ridotto di metà il nostro spazio delle ipotesi, che da cento possibilità è passato a cinquanta.

La seconda mossa è altrettanto semplice: infatti, gli proponiamo la metà del nuovo intervallo, ovvero 75. Bob continua a godersela, dicendoci che è *inferiore*. Ma noi abbiamo ulteriormente delimitato il nostro range di possibilità.

Il gioco prosegue come segue.

```
ROUND 3
--------------------------------
ALICE -> 62 --- BOB -> INFERIORE
--------------------------------
ROUND 4
--------------------------------
ALICE -> 56 --- BOB -> SUPERIORE
--------------------------------
ROUND 5
--------------------------------
ALICE -> 59 --- BOB -> SUPERIORE
--------------------------------
ROUND 6 (BOB IMPALLIDISCE)
--------------------------------
ALICE -> 61 --- BOB -> INFERIORE
--------------------------------
ROUND 7 (BOB TREMANTE...)
--------------------------------
ALICE -> 60 --- BOB -> PAGARE
```

In sole sette mosse, abbiamo trovato il valore immaginato da Bob e, mentre sorseggiamo il meritato caffè, ringraziamo il Docente di Informatica per averci illuminato.

## Fase di progettazione

Potremmo voler implementare questo algoritmo in un linguaggio di programmazione, di modo da serializzare la vittoria di caffè con gli altri nostri amici Charlie, Dave, etc.

Per farlo, possiamo usare poche variabili: *min* per indicare l'ipotesi minima più ragionevole, e *max* per l'ipotesi massima ragionevole.

Ecco un'implementazione step-by-step:

1. sia min = 1 e max = n
2. troviamo il valore medio tra min e max, arrotondato ad un intero
3. se abbiamo trovato il numero, fermiamoci; altrimenti
4. se l'ipotesi era troppo bassa, impostiamo min a n/2 + 1
5. se l'ipotesi era troppo alta, impostiamo max a n/2 - 1
6. torniamo al passo 2

## Complessità computazionale

L'idea chiave è che quando la ricerca dicotomica fa un'ipotesi incorretta, la porzione dell'array che contiene le ipotesi ragionevoli è ridotta di metà. Se la porzione ragionevole ha 32 elementi, un'ipotesi non corretta la riduce di 16. Quindi, la ricerca dicotomica dimezza la dimensione della porzione ragionevole ad ogni ipotesi non corretta.

Quindi, se iniziamo con un array lungo 8, la prima ipotesi non corretta riduce la dimensione del problema a 4, quindi a 2, e quindi a 1. Per cui con un array di otto elementi sono necessari al più quattro valutazioni.

Cosa accade con 16? Serve un passaggio in più, e quindi sono necessarie cinque valutazioni.

Ogni volta che raddoppiamo la dimensione dell'array, abbiamo bisogno di soltanto una nuova ipotesi. Possiamo quindi esprimere il numero di ipotesi, nel caso peggiore, come "il numero di volte che dobbiamo ripetutamente dimezzare, partendo da $n$, fino ad arrivare ad 1, più 1". Questo significa che dobbiamo usare $\log_2 (n)$. Quindi, se $n = 64$, il numero di ricerche è pari a 6. Per i 2.600.000 stelle, il numero di ipotesi è pari a 22.

!!! note "Nota"
    I numeri che abbiamo indicato non sono potenze di 2. In questo caso, valuteremo la potenza di due immediatamente inferiore, e vi aggiungeremo 1. Ecco perché per gli studenti abbiamo 7, mentre per le stelle abbiamo 22.

Il vantaggio di una complessità logaritmica è che cresce molto lentamente, essendo l'inverso della funzione esponenziale, che invece cresce molto rapidamente.

## Pseudocodice

```linenums="1"
function binarySearch(array, target):
    min = 1
    max = length(array)
    while min <= max:
        mid = floor((min + max) / 2)
        if array[mid] == target:
            return mid
        else if array[mid] < target:
            min = mid + 1
        else:
            max = mid - 1
        endif
    endwhile
    return -1  // non trovato
```

## Proprietà

- Richiede che l'array sia *ordinato*
- Complessità temporale: $O(\log n)$
- Complessità spaziale: $O(1)$ (versione iterativa)
