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

## Parte 1: `caricaVoti()`

Possiamo adesso creare la funzione `caricaVoti()`, delegata al caricamento dei voti sul libretto. Creiamo una nuova funzione, ed inseriamo il seguente codice:

```Matlab linenums="1"
function L = caricaVoti(N)
%CARICAVOTI Funzione per caricare N voti sul libretto L, rappresentato
%sotto forma di vettore.

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

La funzione avrà quindi il nome `caricaVoti`, accetterà come parametro formale `N`, rappresentativo della lunghezza del vettore da considerare, e restituirà l'argomento `V`, ovvero il vettore desiderato e rappresentativo del libretto dei voti.

Alla riga 3 preallochiamo un vettore di $N$ elementi, mentre alle righe 5-16 abbiamo il cuore della nostra funzione.

```matlab linenums="5"
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

## Parte 2: `ordinaVoti()`

Vediamo ora come ordinare il vettore caricato nel punto precedente. Scriviamo la funzione `ordinaVoti()`, che implementa l'algoritmo di ordinamento *bubble sort*.

```matlab
function L = ordinaVoti(L)
%ORDINAVOTI Ordina i voti utilizzando l'algoritmo bubble sort.

% L'algoritmo bubble sort confronta i due valori immediatamente successivi,
% scambiandoli di posto se necessario.
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

## Parte 3: `calcolaMedia()`

```matlab
function M = calcolaMedia(L_ord)
%CALCOLAMEDIA Funzione per il calcolo della media a partire dal vettore
%ordinato.

% Scarto i due voti più bassi.
L_ord_utile = L_ord(3:length(L_ord));
% Calcolo la media.
media = 0;
for i = 1:length(L_ord_utile)
    media = media + L_ord_utile(i);
end

% Restituisco la media.
M = media / length(L_ord_utile);

end
```

## Parte 4: `calcolaVotoLaurea()`

```matlab
function V = calcolaVotoLaurea(M)
%CALCOLAVOTOLAUREA Funzione per il calcolo del voto di ingresso alla
%seduta.

V = floor(M * 11/3);

end
```

## Parte 5: `stampaRisultati()`

```matlab
function stampaRisultati(V, M)
%STAMPARISULTATI Procedura per la stampa a schermo di voto di ingresso alla
%seduta e media voti.

fprintf("Il voto di ingresso alla seduta è %.2f\n", V);
fprintf("La media voti è %.2f\n", M);

end
```

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
