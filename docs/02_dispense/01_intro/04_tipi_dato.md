# 4 - I tipi di dato

Abbiamo accennato in precedenza al fatto che ogni calcolatore ha a sua disposizione una determinata *parola*, dipendente dall'architettura, che rappresenta il numero massimo di bit rappresentabili all'interno dei dati dell'elaboratore. Vediamo in breve cosa comporta questo "limite".

## 4.1 - Dati numerici

### 4.1.1 - Numeri interi

Le limitazioni imposte dalle parole dei calcolatori fanno in modo che il valore numerico massimo trattabile dagli stessi sia *finito*. Ad esempio, nel caso di un'architettura a 64 bit, sarà possibile rappresentare "soltanto" $2^64$ possibili valori.

!!!note "Nota"
    Notiamo che per i numeri interi questo valore è $2^64 = 18.446.744.073.709.551.616$, per cui il limite è, in realtà, abbastanza "rilassato".

Cosa accade, quindi, se raggiungiamo $2^64$? Molto semplice: il conteggio ricomincia da zero, o il programma va in errore.

Altrettanto importante è il notare come i numeri (interi) possano essere dotati di segno. Questo, ovviamente, va ad influenzare *l'intervallo* dei valori rappresentabili (ma non il *numero* degli stessi). Infatti, se si considera il segno anteposto al numero, il dato potrà assumere valori da $-2^(63 - 1)$ a $2^(64)$.

Facciamo un breve esempio pratico. Supponiamo che la lunghezza della parola $W$ sia di otto bit; allora:

- considerando solo i valori positivi, sarà possibile rappresentare tutti i numeri interi compresi tra $0$ e $255 = 2^8-1$;
- considerando anche i valori negativi, sarà possibile rappresentare tutti i numeri interi compresi tra $-128 = -2^{W-1}$ e $127 = -2^{W-1}-1$.

### 4.1.2 Rappresentazione di numeri reali

TODO:

Così come per l'insieme dei numeri naturali, anche quello dei numeri reali $\mathbb{R}$ può essere rappresentato all'interno di un calcolatore esclusivamente mediante un'approssimazione finita. Per trovare quest'approssimazione, occorre considerare che ogni numero reale è composto da una parte _intera_ $r$ ed una parte _frazionaria_ $f$.

TODO: tabella

| Tipo di dato | Lunghezza | Valore minimo assumibile | Valore massimo assumibile |
| ------------ | --------- | ------------------------ | ------------------------- |
| byte         | 1 byte    | 0                        | 255                       |
| ubyte        | 1 byte    | -128                     | 127                       |

#### Rappresentazione a virgola fissa

Supponiamo di avere a disposizione parole composte da $W$ bit. Nella rappresentazione a virgola fissa (o _fixed point_) di un numero $N$, usiamo un numero fisso di bit (ovvero $W_r$) per la parte intera di $N$, ed i rimanenti bit ($W_f$) per la rappresentazione della parte frazionaria. Ovviamente, questa rappresentazione ha lo svantaggio di essere poco flessibile, e le viene spesso preferita quella a _virgola mobile_.

#### Rappresentazione a virgola mobile

La modalità di rappresentazione di un numero reale maggiormente diffusa è quella a _virgola mobile_ (_floating point_), che si basa sui concetti di _mantissa_, ovvero la _parte frazionaria_ di un numero, e _caratteristica_, o _esponente_.

In particolare, la mantissa di un numero reale $n$ è pari al valore del numero diminuito della sua parte intera $n_i$:

$$
M = n - n_i
$$

Ad esempio, la mantissa di $5.2$ è pari a $0.2$. E' facile verificare che la mantissa $M$ è sempre compresa tra $-1$ ed $1$.

Ne consegue che un numero $a$ è rappresentabile in una data base $b$ mediante la seguente relazione:

$$
a = M * b^e
$$

### Rappresentazione di caratteri

Anche i caratteri (ovvero quelli che troviamo normalmente sulle nostre tastiere) possono essere rappresentati in binario. Più in generale, il concetto di "carattere" è assimilabile a quello di _simbolo_, in quanto i calcolatori sono in grado di comprendere simboli che indicano, tra le altre cose, le cifre decimali, la punteggiatura, ed una vasta serie di caratteri speciali (ad esempio, l'underscore, la "chiocciola", e via dicendo).

L'enorme varietà di caratteri ha portato alla necessità di uniformarne la rappresentazione, creando una corrispondenza biunivoca tra ogni carattere ed un numero intero. Tale corrispondenza è stabilita da _standard_ ben precisi, tra i quali vale la pena di ricordare lo standard ASCII e quello UNICODE. Quest'ultimo è particolarmente potente (ed esteso), in quanto permette di codificare la maggior parte dei caratteri conosciuti, compresi quelli di alcune lingue ormai considerate morte (come ad esempio il greco antico).

!!! note "Curiosità"
Complessivamente, lo standard UNICODE è in grado di rappresentare più di diecimila caratteri. Essendo però codificato a sedici bit, vi è spazio ancora per un bel po' di lingue morte.
