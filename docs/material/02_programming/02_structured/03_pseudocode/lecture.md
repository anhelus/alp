# 2.2.3 Pseudocodifica

La pseudocodifica è un linguaggio informale per descrivere algoritmi in modo strutturato, senza legarsi alla sintassi di un linguaggio di programmazione specifico. È utile per ragionare sulla logica di un algoritmo prima di implementarlo.

## Caratteristiche

Un buon pseudocodice dovrebbe:

* essere **leggibile** da un essere umano senza conoscere un linguaggio specifico;
* essere **strutturato** con blocchi ben delimitati (inizio/fine, if/else, cicli);
* usare **costrutti standard** (sequenza, selezione, iterazione) senza dettagli sintattici.

## Dichiarazione delle variabili

Le variabili si dichiarano specificandone il nome e il tipo:

```
var
    eta: integer;
    prezzo: real;
    valido: boolean;
    nome: string;
```

## I costrutti fondamentali

### Sequenza

Le istruzioni vengono eseguite una dopo l'altra, dall'alto verso il basso:

```
begin
    read(x)
    read(y)
    somma = x + y
    write(somma)
end
```

`read` legge un valore dall'esterno (input), `write` stampa un risultato (output).

### Selezione (`if-then-else`)

```
if condizione then
    istruzioni_se_vera
else
    istruzioni_se_falsa
endif
```

Esempio:

```
if eta >= 18 then
    write("Maggiorenne")
else
    write("Minorenne")
endif
```

### Iterazione con controllo in testa (`while`)

```
while condizione do
    istruzioni
endwhile
```

Esempio: sommare i primi 10 numeri

```
var
    somma: integer;
    i: integer;

begin
    somma = 0
    i = 1
    while i <= 10 do
        somma = somma + i
        i = i + 1
    endwhile
    write(somma)
end
```

### Iterazione con controllo in coda (`repeat-until`)

```
repeat
    istruzioni
until condizione
```

Il corpo viene eseguito **almeno una volta**, perché la condizione è controllata alla fine.

### Ciclo enumerativo (`for`)

```
for i = valore_iniziale to valore_finale step incremento do
    istruzioni
endfor
```

## Esempio completo: massimo di tre numeri

```
var
    a, b, c, max: integer;

begin
    read(a)
    read(b)
    read(c)

    if a >= b and a >= c then
        max = a
    else if b >= a and b >= c then
        max = b
    else
        max = c
    endif

    write(max)
end
```

## Vantaggi della pseudocodifica

* **Indipendenza dal linguaggio**: lo stesso algoritmo può essere tradotto in C, Java, Python, ecc.
* **Chiarezza**: ci si concentra sulla logica, non sulla sintassi (punto e virgola, parentesi, ecc.).
* **Comunicazione**: è più facile discutere un algoritmo con altri programmatori usando uno pseudocodice comune.
* **Progettazione**: permette di progettare la soluzione prima di sporcarsi le mani con il codice.

!!! tip "Dallo pseudocodice al C"
    Una volta scritto l'algoritmo in pseudocodice, tradurlo in C è quasi meccanico: ogni costrutto ha un equivalente diretto (`if` → `if`, `while` → `while`, `for` → `for`, `write` → `printf`, `read` → `scanf`).

