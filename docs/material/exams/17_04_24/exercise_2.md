# Soluzione all'esercizio 2

Per l'esecizio 2 è opportuno ragionare allo stesso modo in cui si è ragionato per l'esercizio 1. In particolare, procediamo a strutturare il nostro script principale (`main.m`) ricalcando l'andamento delle istruzioni usate in Algobuild.

Partiamo con la classica coppia `clear` e `clc`, le quali, come ricordiamo, servono (rispettivamente) a rimuovere le variabili esistenti dal workspace, ed a "pulire" la command window.

```Matlab
clear
clc
```

Fatto questo, possiamo fissare i valore di $N$, ovvero la lunghezza da assegnare al nostro vettore, scegliendo $N=10$.

```Matlab
N = 10;
```

Possiamo a questo punto passare alla prima funzione, ovvero la `caricaVoti()`.

## Parte 1: `caricaVoti()`

La funzione `caricaVoti()` è delegata al caricamento dei voti sul libretto. Creiamo una nuova funzione, ed inseriamo il seguente codice:

```Matlab linenums="1"
function L = caricaVoti(N)

L = zeros(1, N);
i = 1;
while i <= N
    voto = input("Inserire il voto:\n");
    if mod(voto, 1) == 0
        if voto >= 18 && voto <= 30
            L(i) = voto;
            i = i + 1;
        else
            disp("Il voto deve essere compreso tra 18 e 30!");
        end
    else
        disp("Il voto deve essere intero!");
    end
end

end
```

Analizziamo la funzione istruzione per istruzione.

Alla prima riga, abbiamo la dichiarazione della funzione:

```matlab linenums="1"
function L = caricaVoti(N)
```

La funzione avrà quindi il nome `caricaVoti`, accetterà come parametro formale `N`, rappresentativo del numero di esami che conterrà il nostro libretto, e restituirà l'argomento `L`, il libretto dei voti che, come vedremo, sarà un vettore riga.

Il vettore `L` è preallocato alla riga 3, mentre nelle righe successive avremo il cuore della funzione di inserimento. Questa è strutturata secondo un ciclo while; ciò avviene per permettere, se necessario, il re-inserimento di un valore. Ciò avviene, ad esempio, quando il valore inserito non è intero, o quando non è compreso tra 18 e 30. In particolare, per verificare che il voto sia intero, possiamo usare la funzione `mod` come segue:

```matlab
if mod(voto, 1) == 0
    # controllo il valore del voto
else
    disp("Il voto deve essere intero!");
end
```

Nel precedente snippet, controlliamo che il modulo 1 dell'input inserito (associato, come evidente, alla variabile `voto`) sia pari a `0`. Intuitivamente, se il resto della divisione tra `voto` ed `1` è nullo, il numero è pari; in alternativa, non lo è, per cui dovremo chiedere nuovamente l'immissione del valore all'utente.

La restante parte della funzione verifica che il voto sia compreso tra 18 e 30 e, se ciò è vero, incrementa il valore di `i` di 1, passando all'iterazione successiva del ciclo. 

## Parte 2: `ordinaVoti()`

Vediamo ora come ordinare il vettore caricato nel punto precedente. Scriviamo la funzione `ordinaVoti()`, che implementa l'algoritmo di ordinamento *bubble sort*. Un esempio di codice è il seguente:

```matlab
function L = ordinaVoti(L)

for i = 1:length(L)
    for j = 1:length(L) - i
        if L(j) > L(j + 1)
            temp = L(j + 1);
            L(j + 1) = L(j);
            L(j) = temp;
        end
    end
end

end
```

La funzione è molto semplice, e prevede il confronto tra i due elementi adiacenti del vettore, scambiandoli di posto se necessario. Ciò avviene usando due variabili di appoggio, ovvero `i` e `j`; la funzione restituisce quindi il vettore ordinato.

## Parte 3: `calcolaMedia()`

La funzione `calcolaMedia()` permette il calcolo del voto medio di ingresso di laurea.

```matlab
function M = calcolaMedia(L_ord)

L_ord_utile = L_ord(3:length(L_ord));
media = 0;
for i = 1:length(L_ord_utile)
    media = media + L_ord_utile(i);
end

M = media / length(L_ord_utile);

end
```

Ricordando che il calcolo della media prevede lo *scarto* dei due voti più bassi, e presupponendo di utilizzare la funzione sul vettore *già ordinato*, la funzione parte selezionando la parte utile del vettore dei voti ordinato (`L_ord`):

```matlab
L_ord_utile = L_ord(3:length(L_ord));
```

In altre parole, usiamo l'indicizzazione per selezionare gli elementi di `L_ord` che vanno dal terzo in poi.

Una volta estratto il vettore di riferimento, procederemo a calcolare la media usando un ciclo `for` e, successivamente, dividendo il risultato della sommatoria per la lunghezza complessiva del vettore di interesse. 

## Parte 4: `calcolaVotoLaurea()`

La funzioen `calcolaVotoLaurea()` è molto semplice e può essere riassunta in una riga.

```matlab
function V = calcolaVotoLaurea(M)

V = floor(M * 11/3);

end
```

Da notare la funzione `floor` che ci assicura che il voto di uscita `V` sia approssimato all'intero più vicino.

!!!tip "Perché usare una funzione?"
    In questo caso, l'utilizzo di una funzione per il calcolo del voto di laurea potrebbe apparire quantomeno ridondante. Tuttavia, utilizzare un approccio di questo tipo favorisce la *modularità* del codice. Ciò potrebbe essere utile in situazioni nelle quali un Ateneo modificasse la procedura di calcolo del voto finale di laurea: a quel punto, ci basterebbe agire sul contenuto della funzione `calcolaVotoLaurea()`, invece che sullo script complessivo.

## Parte 5: `stampaRisultati()`

Anche la procedura per la stampa dei risultati è molto semplice, e può essere implementata usando due istruzioni `fprintf` opportunamente scritte.

```matlab
function stampaRisultati(V, M)

fprintf("Il voto di ingresso alla seduta è %.2f\n", V);
fprintf("La media voti è %.2f\n", M);

end
```

Anche in questo caso, è preferibile usare una procedura in modo da rendere il programma maggiormente modulare ed adattabile a future esigenze.

## Script complessivo

Combiniamo tutte le funzioni in quello che è lo script complessivo risultante.

```matlab
clear
clc

N = 10;
L = caricaVoti(N);
L_ord = ordinaVoti(L);
M = calcolaMedia(L_ord);
V = calcolaVotoLaurea(M);
stampaRisultati(V, M);
```
