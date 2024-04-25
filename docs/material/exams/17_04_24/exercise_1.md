# Soluzione all'esercizio 1

## Parte 1: `caricaVettore()`

La funzione `caricaVettore()` è mostrata nella seguente figura. Da notare come la modalità di caricamento (`modCar`) debba essere specificata tra i parametri formali. Inoltre, dato che non viene specificato altrimenti, si utilizza per semplicità la funzione composta `round(random()*10)` per generare un numero casuale compreso tra `0` ed `1` (mediante `round()`), moltiplicarlo per `10`, ed arrotondarlo.

<figure markdown>
  ![carica](./images/caricaVettore.png)
  <figcaption>Figura 1 - La funzione caricaVettore()</figcaption>
</figure>

## Parte 2: `ordinaVettore()`

L'ordinamento del vettore avviene per selezione (*selection sort*). Il funzionamento dell'algoritmo è standard.

<figure markdown>
  ![ordina](./images/ordinaVettore.png)
  <figcaption>Figura 1 - La funzione ordinaVettore()</figcaption>
</figure>

## Parte 3: `calcolaStatistiche()`

La procedura `calcolaStatistiche()` sfrutta l'ordinamento crescente del vettore. Da notare che, dato che `N` è rimasto `double` (formato di default di Algobuild), utilizziamo la funzione `dtoi` per creare una variabile temporanea `len` di tipo intero, a cui sottraiamo il valore `1` (sempre intero), e che utilizziamo per recuperare il massimo del vettore.

<figure markdown>
  ![calcola](./images/calcolaStatistiche.png)
  <figcaption>Figura 1 - La procedura calcolaStatistiche()</figcaption>
</figure>

## Parte 4: `stampa()`

Nella procedura `stampa` creiamo una singola stringa che man mano popolata con i valori del vettore `V`, opportunamente convertiti in stringhe mediante la funzione `dtos()`, e stampati a schermo al termine dell'iterazione.

<figure markdown>
  ![stampa](./images/stampa.png)
  <figcaption>Figura 1 - La procedura stampa()</figcaption>
</figure>

## Script complessivo

Nello script complessivo usiamo due ulteriori sezioni, una per l'inserimento e la verifica della lunghezza del vettore (parametro `N`), ed una per l'inserimento e la verifica delle modalità di caricamento del vettore (parametro `modCar`). Da notare che in entrambe queste sezioni viene utilizzato un `do-while` per verificare la correttezza del valore inserito dall'utente.

Inoltre, vi è la verifica su quest'ultimo valore che, se pari a `0`, comporta l'uscita dal programma.

<figure markdown>
  ![main](./images/main.png)
  <figcaption>Figura 1 - Lo script principale</figcaption>
</figure>

!!!note "Nota"
    Le ulteriori sezioni possono essere inserite all'interno di apposite funzioni per la verifica dei valori.
