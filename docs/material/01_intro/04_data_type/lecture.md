# 4 - I tipi di dato

Nel capitolo precedente abbiamo accennato al fatto che i calcolatori hanno a disposizione una determinata *parola*, la cui dimensione dipende dall'architettura, che determina il numero massimo di bit che possono essere rappresentati nei dati gestiti in fase di elaborazione. Questo, ovviamente, comporta un limite: vediamone in breve le implicazioni, approfittando per introdurre i diversi *tipi* di dato.

## 4.1 - Dati numerici

Il primo tipo di dati che vediamo è quello *numerico*, che comprende, in linea generale, i numeri interi e reali.

!!!note "I numeri complessi"
    I più attenti potrebbero chiedersi perché i numeri complessi non sono stati menzionati in precedenza. Infatti, i numeri complessi non sono contemplati come dati *primitivi* in numerosi linguaggi di programmazione, anche se, come vedremo, Python prevede un'apposita struttura dedicata allo scopo.

### 4.1.1 - Numeri interi

Il limite imposto alla lunghezza della parola comporta che il valore numerico massimo trattabile da un calcolatore sia finito: ad esempio, nel caso di un'architettura con parola a 64 bit (come la maggior parte dei processori odierni), sarà possibile rappresentare "soltanto" $2^{64}$ possibili valori.

!!!note "Nota"
    Ricordiamo che $2^{64} = 18.446.744.073.709.551.616$. Il limite appare quindi abbastanza permissivo.

Cosa accade, quindi, se dovessimo raggiungere $2^{64}$? Molto semplice: il conteggio ricomincia da zero (o il programma va in errore).

Altrettanto importante è il notare come i numeri possano essere dotati di segno. Questo, ovviamente, va ad influenzare gli *estremi* dell'intervallo dei valori rappresentabili, ma non la *cardinalità* dello stesso. Infatti, se si considera il segno anteposto al numero, potremo trattare valori che vanno nell'intervallo da $-2^{63}$ a $2^{63}$.

Facciamo un breve esempio pratico, con una lunghezza della parola di otto bit. In questo caso:

- considerando solo lo zero ed i valori strettamente positivi, sarà possibile rappresentare tutti i numeri interi compresi tra $0$ e $255 = 2^{8-1}$;
- considerando anche i valori negativi, sarà possibile rappresentare tutti i numeri interi compresi tra $-128 = -2^{8-1}$ e $127 = -2^{8-1}-1$.

Nella seguente tabella, sono riassunti alcuni tra i tipi di valore intero più comune, differenziati a seconda della loro lunghezza.

| Tipo di dato | Lunghezza | Valore minimo assumibile | Valore massimo assumibile |
| ------------ | --------- | ------------------------ | ------------------------- |
| `bit`        | 1 bit     | 0                        | 1                         |
| `ubyte`      | 8 bit     | 0                        | 255                       |
| `byte`       | 8 bit     | -128                     | 127                       |
| `ushort`     | 16 bit    | 0                        | $2^{16} - 1$ = 65535      |
| `short`      | 16 bit    | -32768                   | 32767                     |
| `uint`       | 32 bit    | 0                        | $2^{32} - 1$ = 4294967295   |
| `int`        | 32 bit    | $-2^{31}$ = 2147483648     | $2^{31} - 1$ = 2147483647   |
| `ulong`      | 64 bit    | 0                        | $2^{64} - 1$                |
| `long`       | 64 bit    | $-2^{63}$                  | $2^{63} - 1$                |

!!!note "Il `bit`"
    Il bit è il tipo di dato numerico più "limitato" rappresentabile, e viene spesso utilizzato come valore booleano.

!!!note "Il simbolo `u`"
    I più attenti avranno notato la presenza del simbolo `u` nelle notazioni che includono solo i valori positivi. Intuitivamente, la `u` sta per *unsigned*, ovvero "senza segno".

!!!note "Tipi e lunghezza"
    I tipi riportati nella tabella precedente, assieme alla loro lunghezza, sono quelli "standard", cui aderiscono la maggior parte dei linguaggi di programmazione (ma *non tutti*).

### 4.1.2 Rappresentazione di numeri reali

Così come per l'insieme dei numeri naturali, anche quello dei numeri reali $\mathbb{R}$ deve essere rappresentato mediante un'approssimazione finita. Ricordiamo che ogni numero reale è composto da una parte intera ed una *razionale*; di conseguenza, considerato che il numero di bit per la rappresentazione è sempre lo stesso, occorre trovare un modo per conciliare la presenza di queste due parti.

In tal senso, esistono due possibili rappresentazioni che è possibile utilizzare.

Nella rappresentazione **a virgola fissa**, o **fixed point**, si usa un numero fisso di bit per la parte intera del numero da rappresentare, con i rimanenti usati per la parte decimale. Più interessante è invece la rappresentazione **a virgola mobile**, o **floating point**, basata sui concetti di *mantissa* (ovvero, parte decimale) ed *esponente*.

Formalmente, definiamo la mantissa di un numero reale $n$ è pari al valore del numero diminuito della sua parte intera $n_{int}$:

$$
M = n - n_{int}
$$

E' facile verificare che la mantissa $M$ è sempre compresa tra $-1$ ed $1$.

La rappresentazione in virgola mobile di $n$ è definita quindi come:

$$
n = M * b^e
$$

con $b$ base scelta, ed $e$ esponente.

Ad esempio, per rappresentare il numero $5.2$ in virgola mobile, potremo scrivere:

$$
n = 0.52 * 10^1
$$

da cui $M = 0.52$ ed $e = 1$. Questa notazione, detta *normalizzata*, prevede che la parte razionale sia sempre minore di uno, mentre quella intera sia pari a zero. Equivalentemente, potremmo scrivere:

$$
n = 0.052 * 10^2
$$

così come:

$$
n = 52 * 10^{-1}
$$

Tuttavia, è la notazione normalizzata ad essere usata per convenzione.

Il vantaggio legato all'utilizzo della rappresentazione in virgola mobile sta nel fatto che è possibile rappresentare un range di numeri molto più ampio rispetto a quello a virgola fissa. Ad esempio, immaginiamo di voler utilizzare quattro simboli (*notate che non stiamo utilizzando la rappresentazione binaria, quindi non parliamo di bit*) per rappresentare il numero $63500$. Se usassimo una rappresentazione a virgola fissa, così come una intera, *non potremmo in alcun modo rappresentarlo*; invece, con la rappresentazione a virgola mobile, avremmo:

$$
M = 635 \\
e = 5 \\
n = 0.635 * 10^5
$$

e, dovendo memorizzare esclusivamente la mantissa (che richiede tre simboli) e l'esponente (che ne richiede uno), riusciremmo nel nostro intento.

## 4.2 - Caratteri

Anche i caratteri che troviamo normalmente sulle nostre tastiere devono essere rappresentati in binario. In generale, il concetto di *carattere* deve essere assimilato a quello di *simbolo*, in quanto i calcolatori devono poter rappresentare simboli "speciali" (ad esempio, la chiocciola @ o l'underscore _), così come caratteri in altri tipi di alfabeti (ad esempio, il cirillico o il mandarino).

L'enorme varietà di caratteri ha portato alla necessità di uniformarne la rappresentazione, creando una corrispondenza biunivoca tra simboli e numeri interi. Questa corrispondenza è stata codificata in standard ben precisi, tra i quali vale la pena citare l'ASCII e l'UNICODE. Quello che però questo comporta dal punto di vista pratico è che, così come i dati di tipo numerico, anche il numero totale di caratteri rappresentabili sarà limitato dalla lunghezza della parola utilizzata dall'architettura del calcolatore.

!!! note "Curiosità"
    Complessivamente, lo standard UNICODE è in grado di rappresentare più di diecimila caratteri; essendo però codificato a sedici bit, vi è spazio ancora per un bel po' di lingue morte.
