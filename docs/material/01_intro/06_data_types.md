# 1.6 - Dimensione dei dati

Nella [lezione precedente](05_sis_bin.md) abbiamo accennato al fatto che i calcolatori hanno a disposizione una word la cui dimensione dipende dall'architettura del processore; ciò implica che ogni tipo di dato (cui abbiamo [già accennato](02_data_repr.md)) avrà una dimensione prefissata. Scendiamo più nel dettaglio.

## Dati numerici

### Numeri interi

Partiamo dai dati di tipo numerico intero. In questo caso, il limite legato alla dimensione della word impone che il massimo valore numerico trattabile da un calcolatore sia pari a $2^N$, con $N$ dimensione della parola. Nella pratica, se abbiamo una parola a $32$ bit, il valore massimo gestibile dal processore sarà pari a $2^{32}$ (o, considerando lo $0$, $2^{32}-1$). Nella maggior parte dei processori odierni, la parola è a $64$ bit, per cui il valore massimo gestibile dal processore sarà di $2^{64}$.

!!!note "Nota"
    Ricordiamo che $2^{64} = 18.446.743.073.709.551.616$. Il limite appare quindi abbastanza permissivo. Tuttavia, se sommassimo $1$ a $2^{64}$, il valore restituito sarebbe pari a zero o, più probabilmente, il programma andrebbe in errore.

##### Interi e segno

Ricordiamo come i numeri interi siano dotati di segno: avremo quindi sia numeri negativi, sia numeri positivi. Ciò non andrà a modificare il numero di valori rappresentabili, che saranno sempre $2^{64}$, quanto piuttosto il *range* dei valori rappresentati, che sarà egualmente suddiviso tra valori negativi e positivi, e quindi centrato sullo $0$. Avremo quindi $\frac{2^{64}}{2}$ valori positivi, e $\frac{2^{64}}{2}$ valori negativi; in altre parole, potremo rappresentare i numeri tra $-2^{63}$ a $2^{63}$.

Facciamo un esempio più facilmente digeribile, considerando come word una parola ad otto bit. In questo caso:

- considerando solo lo zero ed i valori strettamente positivi, sarà possibile rappresentare tutti i numeri interi compresi tra $0$ e $255 = 2^{8}-1$;
- considerando anche i valori negativi, sarà possibile rappresentare tutti i numeri interi compresi tra $-128 = -2^{8-1}$ e $127 = -2^{8-1}-1$. Ovviamente, anche in questo caso consideriamo lo zero.

Nella seguente tabella, sono riassunti alcuni tra i tipi di valore intero più comune, differenziati a seconda della loro lunghezza.

| Tipo di dato | Lunghezza | Valore minimo assumibile | Valore massimo assumibile |
| ------------ | --------- | ------------------------ | ------------------------- |
| `bit`        | 1 bit     | 0                        | 1                         |
| `ubyte`      | 8 bit     | 0                        | 255                       |
| `byte`       | 8 bit     | -128                     | 127                       |
| `ushort`     | 16 bit    | 0                        | $2^{16} - 1$ = 65535      |
| `short`      | 16 bit    | -32768                   | 32767                     |
| `uint`       | 32 bit    | 0                        | $2^{32} - 1$ = 4294967295 |
| `int`        | 32 bit    | $-2^{31}$ = 2147483648   | $2^{31} - 1$ = 2147483647 |
| `ulong`      | 64 bit    | 0                        | $2^{64} - 1$              |
| `long`       | 64 bit    | $-2^{63}$                | $2^{63} - 1$              |

!!!note "Il simbolo `u`"
    I più attenti avranno notato la presenza del simbolo `u` nelle notazioni che includono solo i valori positivi. Intuitivamente, la `u` sta per *unsigned*, ovvero "senza segno".

### Numeri reali

Così come i numeri interi, anche i numeri reali devono essere rappresentati mediante un'approssimazione finita che tenga conto della dimensione della word. Dato che i numeri reali sono composti da una parte intera e da una frazionaria, dovremo trovare una maniera per rappresentare entrambe utilizzando i bit messi a disposizione dalla word. Per farlo, avremo due possibili rappresentazioni, che vediamo di seguito.

##### Rappresentazione a virgola fissa

Nella rappresentazione a virgola fissa (in inglese *fixed point*) viene usato un numero prefissato di bit per la parte intera, mentre i rimanenti sono usati per la parte decimale. Quindi, supponendo di usare $32$ bit per la parte intera, ed altrettanti per la parte decimale, il numero più grande che sarà possibile rappresentare avrà $2^{32}-1$, ed altrettanto come parte frazionaria.

Questa rappresentazione, seppur semplice da utilizzare, ha un grosso problema legato all'ottimizzazione delle risorse. Immaginiamo ad esempio di avere una word ad $8$ bit, equalmente ripartiti tra parte intera e frazionaria, e voler rappresentare il numero $1.62515$: per rappresentare la parte intera avremo bisogno soltanto di un bit, mentre per la parte frazionaria dovremmo usare più dei quattro bit riservati, per cui avremo necessità di troncare il risultato, con una rappresentazione quindi incompleta.

##### Rappresentazione a virgola mobile

La rappresentazione a virgola mobile (in inglese *floating point*) si basa sui concetti di *mantissa*, o *significando*, *base*, ed *esponente*. Formalmente, un numero $n$ può essere espresso come:

$$
n = M \cdot b^e
$$

In particolare, la mantissa $M$ sarà compresa tra $0$ ed $1$, e sarà quel numero che, moltiplicato per la base $b$ elevata all'esponente $e$, darà di nuovo $n$. Ad esempio, volendo rappresentare il valore $n = 5.2$ in virgola mobile, scriveremo:

$$
n = 0.52 \cdot 10^1
$$

Questa notazione, in cui la parte frazionaria è compresa tra $0$ ed $1$, mentre quella intera è pari a $0$, è detta *normalizzata*. 

!!!note "Notazioni equivalenti
    Equivalentemente, potremmo scrivere $n = 0.052 * 10^2$, oppure $n = 52 * 10^{-1}$. Tuttavia, è la notazione normalizzata quella ad essere usata per convenzione.

La rappresentazione in virgola mobile ha il vantaggio di popter rappresentare un insieme di valori molto più ampio rispetto a quello rappresentabile in virgola fissa. Immaginiamo, ad esempio, di voler rappresentare il numero $100000$, avendo però a disposizione soltanto $5$ simboli. Con una rappresentazione a virgola fissa non potremmo farlo; con una rappresentazione a virgola mobile, invece, potremo usare l'equivalenza:

$$
n = 0.1 \cdot 10^5
$$

Dato che dovremo memorizzare esclusivamente la mantissa e l'esponente, avremo bisogno soltanto di due simboli, rispettando i vincoli imposti.

!!!warning "Mantissa e base decimale"
    In questo esempio, abbiamo utilizzato la base decimale per semplicità. Tuttavia, gli stessi concetti si estendono all'utilizzo della base binaria.

## Caratteri

Anche la rappresentazione dei caratteri che troviamo sulle nostre tastiere deve avvenire in binario e, di conseguenza, è soggetta alle stesse limitazioni che abbiamo visto sussistere nel caso dei numeri.

Alcuni potrebbero pensare, di primo acchitto, che questo non sia un problema: nell'alfabeto latino, ad esempio, abbiamo al più 26 caratteri, per cui basterebbero $5$ bit per rappresentarli tutti. Giusto? Beh, non proprio.

Quando si parla di carattere, si parla di *qualsiasi simbolo che è possibile rappresentare sul nostro calcolatore*, inclusi anche, ad esempio, la chiocciola, o l'underscore, così come caratteri dell'alfabeto greco o cirillico.

Ciò implica la presenza di un'*enorme* varietà di caratteri, che ha portato alla necessità di una rappresentazione comprensiva ed uniforme, richiedendo quindi molti più bit dei $5$ inizialmente preventivati. Inoltre, è necessario usare una corrispondenza biunivoca tra simbolo e numero intero, definita mediante opportune tabelle, e che segue standard come l'ASCII e l'UNICODE.

## Conclusioni

Abbiamo visto come siano rappresentati in memoria alcuni tipi di dati, e come la dimensione occupata da questi cambi con le caratteristiche della parola usata pepr rappresentarli.

A questo punto, ci manca un ultimo tassello per la nostra panoramica sui concetti alla base dell'informatica: infatti, dovremo vedere come le variabili binarie si combinano tra loro sfruttando i concetti dell'[algebra booleana](./07_boole/01_intro.md).
