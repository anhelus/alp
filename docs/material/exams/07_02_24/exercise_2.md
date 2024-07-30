# Soluzione all'esercizio 2

Per risolvere l'esercizio 2 ragioniamo esattamente come abbiamo fatto per il primo esercizio. Procediamo quindi a strutturare il nostro script principale, che chiameremo `main.m`, come abbiamo fatto per le istruzioni di Algobuild.

Al solito, partiamo con la classica coppia `clear` e `clc`, le quali, come ricordiamo, servono (rispettivamente) a rimuovere le variabili esistenti dal workspace, ed a "pulire" la command window.

```Matlab
clear
clc
```

Fatto questo, impostiamo il valore del numero di righe e di colonne, indicate rispettivamente con `r` e `c`.

```Matlab
r = 3;
c = 4;
```

Da notare che, in questo caso, la traccia ci esplicita questi due valori, per cui non è necessario effettuare ulteriori operazioni.

## Parte 1: `caricaMatrice()`

Possiamo adesso creare la funzione `caricaMatrice()`, delegata al caricamento dello stesso. Creiamo una nuova funzione, ed inseriamo il seguente codice:

```Matlab linenums="1"
function M = caricaMatrice(r, c)

M = zeros(r, c);
for i = 1:c
    M(1, i) = randi([3, 15]);
    M(2, c-i+1) = M(1, i);
end

for i = 1:c
    M(3, i) = M(1, i) + M(2, i);
end

end
```

Analizziamo la funzione istruzione per istruzione. Alla prima riga, dichiariamo la funzione, che accetterà due parametri formali `r` e `c`, rappresentativi, rispettivamente, del numero di righe e del numero di colonne.

```matlab linenums="1"
function M = caricaMatrice(r, c)
```

!!!tip "Range di normalizzazione"
    Opzionalmente, potremmo decidere di inserire i range di normalizzazione da passare alla funzione `randi`, modificando quindi la firma in `caricaMatrice(r, c, a, b)`, con `a` margine inferiore e `b` margine superiore.

Analizziamo adesso le righe 3-7:

```matlab linenums="3"
M = zeros(r, c);
for i = 1:c
    M(1, i) = randi([3, 15]);
    M(2, c-i+1) = M(1, i);
end
```

Queste righe ci permettono di preallocare una matrice di dimensione $r \times c$, popolandola con un valore casuale compreso tra `3` e `15` alla prima riga, e replicandolo nella seconda come richiesto dalla traccia. In tal senso, è facile verificare che:

* quando `i` è `1`, allora `c-i+1` è pari a `4-1+1`, ovvero `4`...
* ...quando `i` è `2`, allora `c-i+1` è pari a `4-2+1`, ovvero `3`...
* ...e così via fino a `i` pari a `4`.

Vediamoa adesso cosa accade alle righe 9-11.

```matlab linenums="9"
for i = 1:c
    M(3, i) = M(1, i) + M(2, i);
end
```

In questo snippet stiamo caricando la terza ed ultima riga della matrice che, banalmente, sarà data dalla somma elemento per elemento delle due precedenti.

!!!note "Somma matriciale"
    In realtà, è possibile non utilizzare il ciclo `for` effettuando una somma matriciale, la cui implementazione è lasciata al lettore.

DA QUI

```matlab
switch modCar
    case 0
        disp("Uscita dal programma")
        return
    case 1
        while i <= N
            fprintf("Inserire l'elemento in posizione %d\n", i);
            val = input("");
            if val > 0 && mod(val, 0) == 0
                i = i + 1;
            else
                disp("Valore non valido. Riprovare.")
            end
        end
    case 2
        disp("Generazione casuale del vettore...")
        for i = 1:N
            V(i) = randi(100);
        end
    otherwise
        error("Modalità non conosciuta. Uscita dal programma.")
end
```

Vediamo che:

* nel `case 0`, gestiamo il caso in cui `modCar` sia pari proprio a `0`. In questo caso, visualizziamo a schermo un messaggio all'utente, ed usciamo dalla funzione mediante l'istruzione `return`;
* nel `case 1`, gestiamo il caso in cui `modCar` sia pari proprio a `1`. In questo caso, usiamo un `while` per fare in modo che l'utente possa inserire manualmente i valori. Ovviamente, controlliamo che i valori siano maggiori di zero, e che il modulo 1 sia uguale a zero (e che quindi il numero sia intero). Se ciò non è vero, sarà richiesto all'utente di caricare nuovamente il valore;
* nel `case 2`, gestiamo l'inserimento casuale dei valori. Per farlo, sfruttiamo la funzione `randi()`, che genera valori casuali compresi di default tra `1` ed il parametro passato (in questo caso, `100`);
* nell'`otherwise`, chiamato in ogni altra situazione, gestiamo una situazione di errore, uscendo dal programma.

!!!note "Note"
    Da notare come il valore massimo casuale passato sia scelto in maniera arbitraria come proprio pari a `100`.

## Parte 2: `ordinaVettore()`

Vediamo ora come ordinare il vettore caricato nel punto precedente. Scriviamo la funzione `ordinaVettore()`, che implementa l'algoritmo di ordinamento *selection sort*.

```matlab
function V = ordinaVettore(V)

for i = 1:length(V)
    k = i;
    for j = i+1:length(V)
        if V(k) > V(j)
            k = j;
        end
    end
    tmp = V(k);
    V(k) = V(i);
    V(i) = tmp;
end
end
```

La funzione `ordinaVettore(V)` accetta quindi il vettore `V` in ingresso, e restituisce lo stesso vettore ordinato. Per farlo, utilizzeremo un ciclo esterno (con indice `i`) ed un ciclo interno (con indice `j`).

Ad ogni iterazione del ciclo esterno, andremo ad utilizzare una variabile di appoggio `k`, che inizialmente sarà pari ad `i`. Fatto questo, useremo un ciclo interno, che partirà dall'elemento immediatamente successivo a `j`. 

Verifichiamo, ad ogni iterazione del ciclo interno, se l'elemento in posizione `k` sia maggiore di quello in posizione `j`; se ciò è vero, provvediamo allo scambio, altrimenti questo non avviene. In altre parole, stiamo cercando il valore *minimo* della restante parte del vettore e, al termine del ciclo interno, lo andremo a sostituire al valore analizzato dal ciclo esterno sfruttando la variabile temporanea `tmp`.

!!!tip "Lunghezza del vettore"
    Potremmo pensare di inserire come parametri formali in ingresso alla funzione `ordinaVettore()` non solo `V`, ma anche `N`. Tuttavia, questo parametro è superfluo, visto e considerato che MATLAB ci offre la funzione `length(V)` che restituisce la lunghezza del vettore passato come parametro. In alternativa, potremmo decidere di usare la funzione `size(V, 1)`, che ci restituisce il numero di righe del vettore (che, nel caso di un vettore colonna, coincide anche con la lunghezza dello stesso). 

## Parte 3: `calcolaStatistiche()`

Nella terza parte provvederemo a calcolare le tre statistiche richieste, ovvero *minimo*, *massimo* e *media*. Da notare che effettueremo questa operazione *sul vettore ordinato*, per cui potremo sfruttare questa caratteristica per giungere rapidamente all'individuazione dei primi due valori. Infatti, potremo scrivere la funzione come segue:

```matlab
function calcolaStatistiche(V)

minimo = V(1);
massimo = V(length(V));

media = 0;

for i = 1:length(V)
    media = media + V(i);
end

media = media / length(V);

end
```

Vediamo come il `minimo` sia dato dal primo valore del vettore ordinato, mentre il massimo sia quello in posizione `length(V)` che, grazie all'indicizzazione offerta dal MATLAB, è proprio quello in ultima posizione. Per ciò che riguarda invece la media, procediamo al calcolo della stessa usando un semplice ciclo for.

!!!note "Nota per il calcolo delle statistiche"
    Ovviamente, questo modo di procedere vale soltanto nel caso il vettore sia ordinato. In caso di vettore non ordinato, il massimo ed il minimo dovranno essere calcolati mediante due semplici cicli enumerativi. Tuttavia, nel contesto della traccia, possiamo tranquillamente procedere come indicato nella funzione `calcolaStatistiche()`.

## Parte 4: `stampa()`

L'ultima parte prevede la stampa a schermo del vettore. Per farlo, potremo scegliere diverse opzioni, tra cui:

* costruire una stringa e visualizzarla al termine del ciclo;
* usare la funzione `fprintf` all'interno di un ciclo;
* utilizzare la funzione `disp`.

Vediamo brevemente tutte le possibili modalità:

```matlab
function stampa(V)

str = "Il vettore ordinato è:\n";
for i = 1:length(V)
    str = str + num2str(V(i)) + "\n";
end

fprintf(str);

end
```

In pratica, creeremo una stringa `str` a cui concateneremo, ad ogni iterazione, il valore `i`-mo di `V` seguito dall'escape character `\n`. Al termine, visualizzeremo la stringa creata mediante la funzione `fprintf`.

Se volessimo usare la funzione `fprintf` all'interno di un ciclo, dovremmo procedere come segue:

```matlab
function stampa(V)

fprintf("Il vettore ordinato è: \n");
for i = 1:length(V)
    fprintf("%d\n", V(i));
end
```

Infine, usando la funzione `disp`:

```matlab
function stampa(V)

disp("Il vettore ordinato è: ")
for i = 1:length(V)
    disp(V(i))
end
```

## Script complessivo

Combiniamo tutte le funzioni in quello che è lo script complessivo risultante.

```matlab
clear
clc

N = input("Inserire la lunghezza del vettore\n");
[V, modCar] = caricaVettore(N);
if modCar == 0
    return
end

V = ordinaVettore(V);

stampa(V);
```

Da notare che il valore `modCar` viene utilizzato immediatamente dopo la chiamata a `caricaVettore()`: infatti, se questo è pari a `0`, entreremo nell'istruzione condizionale mostrata alla riga 6, che terminerà immediatamente il programma grazie all'istruzione `return`.

!!!note "Gestione della modalità sconosciuta"
    In questa versione del programma, abbiamo scelto di gestire sia una modalità di inserimento non conosciuta, lanciando un errore, sia di dare all'utente la possibilità di terminare il programma. Altre modalità di gestione di tale scelta (ad esempio, forzando la scelta a soli due valori mediante un'istruzione condizionale) sono altrettanto valide nel contesto della traccia.
