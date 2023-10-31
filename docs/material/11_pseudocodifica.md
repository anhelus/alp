# Pseudocodifica

La pseudocodifica è un linguaggio per descrivere gli algoritmi strutturati. Per farlo, dobbiamo codificare l'algoritmo in due parti:

* la prima è quella della *dichiarazione* delle variabili;
* la seconda è la *descrizione* delle azioni dell'algoritmo.

## Tipo delle variabili

Sappiamo che il tipo di una variabile rappresenta l'insieme dei valori che possono essere ad essa assegnati.

SOno permessi quattro tipi, ovvero **integer**, **real**, boolean e string-q. In particoalre:

* gli integer rappresentano i numeri interi;
* i real rappresentano i numeri decimali, rappresentabili sia in notazione decmiale che in notazione scientifica;
* i boolean rappresetano un valore booleano che può assumere valore pari a vero o falso;
* le string-q sono parole (o stringhe) costituite da *q* caratteri.

## La dichiaraizone delle variabili

La dichiarazione elel varaibili è un elenco preceduto dalla parola chiave **var**.

La dichiarazione prevede che queste siano suddivise per tipo. La forma è del tipo:

var nome_variabile_1: tipo_1;
    nome_variabile_2: tipo_2;
    nome_variabile_3: tipo_3.

## La descrizione delle azioni

Regole fondamentali:
1. prima della prima azione vi è un begin
2. dopo l'ultima vi è un  end
3. la lettura è read
4. la scrittura è write

### Schema sequenziale

Le istruzioni in una sequenza sono rappresentate secondo uno schema sequenziale. In altre parole, supponendo una sequenza del tipo...

le istruzioni sono fatte in modo sequenziale

### Schema di selezione

Gli schemi di selezione sono rappresentati mediante la struttura if then else, con un endif finale.

### Schemi di iterazione

Gli schemi di iterazione sono rappresentati mediante la struttura while Cond Do S, con S sequenza nel caso di controllo in coda, mentre con contro0llo in testa abbiamo un repeat S until C.

##### Schema enumerativo

Esistonod elle situaizoni particolari nei quali ci sono detrerminate schemi linguistici. Ad esempio, nel caso di un for 


```
for idx from val_in to val_fin step incr do
    S
endfor
```
Esistono anche delle rappresentazioni