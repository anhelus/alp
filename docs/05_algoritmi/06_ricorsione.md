La ricorsione è una tecnica che permette di progettare un algoritmo per risolvere un problema risolvendo delle istanze più piccole dello stesso, fino a quando il problema non è così piccolo che possiamo risolverlo direttamente.

Per il primo esempio, vediamo come calcolare la funzione fatoriale. Indichiamo il fattoriale di $n$ con $n!$.

Il fattoriale è definito come il prodotto degli interi che vanno da $1$ ad $n$. Ad esempio, $5!$ è pari a $1 \cdot 2 \cdot 3 \cdot 4 \cdot 5$, ovvero $120$.

Ci si potrebbe chiedere perché ci dovrebbe interessare la funzione fattoriale. E' molto utile per quando stiamo provando a contare quanti diversi modi di combinare diverse cose ci sono. Immaginiamo ad esempio di dover combinare $n$ cose. Abbiamo $n$ modi di disporre la prima cosa. Per la seconda, ce ne rimangono $n-1$; combinandoli, abbiamo che i modi possibili per disporre le due cose sono $n \cdot (n - 1)$. Ovvaimente, il concetto può essere espanso, ed avremo che alla fine il modo di disporrre le $n$ cose sarà pari ad $n \cdot (n - 1) \cdot (n - 2) \cdot ... \cdot 2 \cdot 1$.

Il fattoriale è definito per tutti gli interi positivi, assieme allo 0, con $0! = 1$.

## Calcolare il fattoriale in maniera iterativa

Calcolare il fattoriale in maniera iterativa è molto semplice. Infatti:

```
STEP 1 -> RES = 1;
STEP 2 -> FOR I = 1; I <= N; I++
              RES = RES * I;
STEP 3 -> RETURN N_FATT;
```

L'implementazione è in realtà abbastanza semplice: si tratta, nella pratica, di fare una serie di moltiplicazioni:

$$
n! = n \cdot (n - 1) \ldot 2 \cdot 1
$$

Notiamo però che $(n - 1) ! = (n - 1) \ldot 2 \cdot 1$, per cui possiamo scrivere che:

$$
n! = n \cdot (n - 1)!
$$

In questa situazione, $(n - 1)!$ diventa un *sottoproblema* che dobbiamo risolvere per calcolare $n!$.

Ad esempio:

$$
5! = 5 * 4!
$$

Estendendo il concetto, e minimizzando le dimensioni del sottoproblema, abbiamo che:

$$
5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
$$

Usando la proprietà commutativa:

$$
\begin{eqnarray}
0! * 1 &= 1 &= 1! &\Rightarrow \\
1! * 2 &= 2 &= 2! &!Rightarrow \\
2! * 3 &= 2 &= 3! &!Rightarrow \\
3! * 4 &= 2 &= 4! &!Rightarrow \\
4! * 5 &= 2 &= 5!
\end{eqnarray}
$$

Risulta che:

* nel caso n = 0, allora n! = 1 (caso base);
* nel caso n > 0, allora possiamo moltiplicare $n$ per il valore restituito dalla funzione $(n-1)!$ 

Possiamo quindi rivedere la nostra funzione utilizzando un approccio *ricorsivo*.

```
STEP 1 -> IF N = 0
		      return 1
		  ELSE
		      return n * factorial(n - 1)
```

## Note

Affinché un algoritmo ricorsivo funzioni, deve essere ricorsivamente condotto al caso base. Ad esempio, quando si calcola $n!$ in maniera ricorsiva, il sottoproblema diventa sempre più piccolo fino a che no si arriva al caso base. Usare algoritmi ricorsivi nel *senso opposto* potrebbe non portare mai a convergenza.
