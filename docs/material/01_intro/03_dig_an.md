# 2 - Rappresentazione dei dati

Nella [scorsa lezione](../01_intro/lecture.md) abbiamo introdotto i concetti legati alla rappresentazione dell'informazione all'interno di sistemi automatici. Tuttavia, è importante approfondire ulteriormente il modo in cui questa informazione viene gestita.

## I tipi di dato

Partiamo da una domanda: quali sono i *tipi* di dato che possiamo voler rappresentare? Per dare una risposta, possiamo pensare a quello che caratterizza il mondo attorno a noi.

Pensiamo alla seguente frase:

> *La casa di mattoni di colore rosso, con le sue cinque mura, è bella.*

Ora, al di là dell'informazione (evidentemente importantissima) contenuta nella frase precedente, notiamo che abbiamo informazioni relative a:

1. il *colore* della casa;
2. il *metodo di costruzione* della casa;
3. il *numero di mura* della casa;
4. la *bellezza* della casa.

Ragioniamoci su un attimo: scopriremo che abbiamo diverse *tipologie* di dato che possiamo rappresentare. Vediamole insieme.

!!!warning "Pericolo"
    Attenzione: un ingegnere civile potrebbe avere malori nel prosieguo della lettura. Perdonatemi per le eccessive ed atroci semplificazioni.

##### Di che categoria è la nostra casa?

Partiamo dal metodo di costruzione della casa. In questo caso, come abbiamo potuto vedere, sono stati utilizzati dei mattoni; tuttavia, sappiamo benissimo che esistono diverse tecniche di costruzione, alcune che prevedono l'utilizzo del cemento armato, altre che prevedono l'uso del legno, altre ancora ibride. Avremo, quindi, diverse *categorie* di case; il dato associato a questa informazione, quindi, risulterà essere di tipo *categorico*. 

!!! question "Altri dati categorici"
    Il lettore più attento noterà che vi è un altro dato categorico all'interno della rappresentazione precedente. Stiamo, ovviamente, parlando del colore dei mattoni utilizzati.

##### Quante mura abbiamo?

Altra importantissima informazione estrapolabile dalla frase precedente è quella relativa al numero di mura presenti all'interno della casa, ovvero cinque (probabilmente, uno sarà un divisorio, a meno di eventuali licenze poetiche del costruttore). Ciò suggerisce l'esistenza di un altro tipo di dato, ovvero quello *numerico*.

Da notare che, in questo caso, il numero di mura è *intero*. Nella realtà, tuttavia, esistono anche numeri *non interi*, globalmente noti come *reali*. Di conseguenza, esisteranno due tipi di dato numerico: il dato di tipo intero, o *numerale discreto*, ed il dato di tipo reale, o *numerale continuo*.

##### Che bella questa casa!

L'ultima informazione che siamo in grado di estrapolare è quella fornita dal nostro gusto estetico, che ci suggerisce come la casa sia in qualche modo gradevole (o, più propriamente, *bella*). Questa informazione può essere associata ad una serie di valori che possono essere *ordinati* in maniera semanticamente crescente o decrescente. Per capirci, una casa *bella* è più gradevole di una *brutta*, ma meno gradevole di una *fantastica*. Il quarto tipo di dato è, quindi, *ordinale*.

### Riassumendo...

Riassumendo, abbiamo quattro tipologie di dati, come mostrati nella seguente tabella.

| Tipo di dato | Descrizione | Esempio |
| ------------ | ----------- | ------- |
| Categorico | Dato che descrive informazione il cui valore è all'interno di un insieme limitato di categorie | Rosso, verde, blu |
| Ordinale | Dato che descrive informazione il cui valore è semanticamente ordinabile | Orrendo, brutto, bello, fantastico |
| Numerale discreto | Dato che descrive informazione associata a numeri interi | 1, 2, 100 |
| Numerale continuo | Dato che descrive informazione associata a numeri continui | $\pi$, 2.45, $\sqrt{2}$ |

## Come rappresentare i dati in un sistema informativo

Alcuni dei tipi precedentemente descritti possono essere abbastanza complessi da rappresentare in un sistema informativo; ciò vale in particolare per i dati categorici e per quelli ordinali.

Il motivo di questa difficoltà è presto spiegato: potenzialmente, infatti, è necessario rappresentare un numero *molto elevato* di possibilità, in entrambi i casi. E, come ben sappiamo, le risorse di un calcolatore sono finite: di conseguenza, bisogna trovare una maniera per usare una rappresentazione *comune* e *condivisa* di tutti i tipi di dato.

Ragioniamo un attimo su quale potrebbe essere un formato ottimale per ottenere questa rappresentazione.

Partiamo chiedendoci quale tra i quattro tipi sia il più "semplice" da utilizzare. La risposta, ovviamente, è il tipo *numerale discreto*: maneggiare numeri interi è intrinsecamente meno complesso del maneggiare numeri continui o insiemi potenzialmente infiniti di parole.

Fatto questo, dobbiamo chiederci se sia possibile, in qualche modo, rappresentare le altre categorie sotto forma di numero intero. Partiamo dai dati categorici.

##### Categorici come interi

Per rappresentare un dato categorico come intero, dovremo usare il cosiddetto *metodo del dizionario*. Nella pratica, ad ogni possibile categoria sarà associato un numero intero, e questo sarà usato per rappresentare detta categoria. Un esempio è ciò che avviene nella seguente tabella.

| Categoria | Intero associato |
| --------- | ---------------- |
| Rosso | 1 |
| Blu | 2 |
| Verde | 3 |

Grazie al dizionario definito nella tabella precedente, potremo rappresentare la categoria "rosso" mediante il numero 1, la "verde" mediante il 3, e via discorrendo. L'aggiornamento del dizionario a seguito di una nuova categoria è volutamente lasciato al lettore.

!!!warning "Numeri reali e numeri interi"
    Tralasciamo per un attimo la questione relativa ai numeri reali, che tratteremo più estesamente quando parleremo della rappresentazione a virgola mobile nel sistema binario; per adesso, ciò che ci interessa è che la risposta è *sì, possiamo usare i numerali discreti per rappresentare numerali continui*.

##### Ordinali come interi






Ognuno di questi tipi può essere rappresentato (anche in maniera approssimata) mediante un numero intero con unità frazionaria).

**Categorici come interi**

Per farlo, usiamo un metodo chiamato del dizionario. In pratica, ad ogni possibile valore è associato un numero intero, con il quale questo sarà rappresentato.

Ad esempio:

```
{
    rosso = 1
    verde = 2
    blu = 3
}
```

L'unica operazione definita su un dato di questo tipo è l'uguaglianza, e la codifica preserva questa operazione. In pratica, se rosso = rosso, allora 0 = 0.

**Ordinali come interi**

Per rpapresentare gli ordinali come interi si usa il metodo dell'enumerazione.

I valori sono ordinati, e ad ognuno è associato un valore intero cresscente.

orrendo = 0
brutto = 1
bello = 2
Fantastico  = 3

La codifica in questo caso rappresenta la relazione di ordine:

orrendo < bello  => 0 < 2

#### Codifica analogica e digitali

Una codifica si dice *analogica* se mantiene un'analogia tra la struttura dell'entità di informazione e la struttura della configurazione (possiamo parlare di codifica continua).

Una codifica si dice *digitale* se impone un numero di configuraizone distinti ammissibili e converte un'entità di infomrazioe in una di queste configuraizoni mediante una regola di codifica (codifica discreta).

Come è meglio codificare l'informazione per la sua elaborazione automatica mediante un calcolatore?

#### Vantaggi della codifica digitale

Qualsiasi sistema fisico (incluso il calcolatore) è sottoposto
all’influenza dell’ambiente circostante che ne perturba la
configurazione introducendo rumore
•
E’ necessario rendere il sistema fisico che elabora l’informazione il più
immune possibile al rumore
•
La codifica analogica è fortemente sensibile al rumore, poiché tutte le
configurazioni sono lecite e non si può distinguere la componente di
informazione dal contributo dovuto al rumore
•
Minore è il numero di configurazioni possibili maggiore è la possibilità di
isolare l’informazione dal rumore
•
E’ questa la ragione principale del successo della codifica binaria nei
calcolatori elettronici (la più estrema codifica discreta due soli valori per
ogni simbolo)

# Campionamento

•
Permette di approssimare in maniera arbitrariamente accurata
informazione continua (
•
Consiste nel
•
misurare il segnale ad intervalli regolari (di tempo se evolve nel tempo,
come un suono di spazio se immagine entrambi se video)
•
approssimare ogni misura continua con un valore discreto


Perché il sistema binario per gli elaboratori?
•
Oltre alla minore sensibilità al rumore
•
I calcolatori funzionano con l’energia elettrica
•
L’energia elettrica viene gestita da transistor (” che
hanno due posizioni acceso 1 e spento 0

•
Il termine informazione nel linguaggio comune è spesso usato
come sinonimo di messaggio
•
Def MESSAGGIO è una combinazione di simboli
•
Def INFORMAZIONE è la misura dell’ampiezza della classe dei
messaggi alla quale appartiene un dato messaggio
•
Prendiamo un messaggio XXXX dove X è uno dei simboli
dell’alfabeto standard (A, B,......,J, K,......, composto da 26 simboli
•
L’informazione è data dalla cardinalità dell’insieme di messaggi formati
da 4 simboli X
•
XXXX  26 4

•
L’informazione viene misurata in bit
•
Il numero di bit di informazione di ogni messaggio è dato per
convenzione dal log 2 della numerosità della classe di messaggi
disponibili
•
Un’ informazione di n bit può essere rappresentata da uno fra 2 n
simboli diversi o da un insieme ordinato di n simboli binari


Ricordare:

$$
log_a b = \frac{log_c b}{log_c a}
$$

$$
log_2 b = \frac{log_{10} b}{log_{10} 2}
$$


Esempio
•
Sia dato un messaggio XXYYY (X è uno dei simboli dell’alfabeto
standard (A, B,......, Y è uno dei simboli dell’alfabeto binario
0 1
•
L’informazione è 26 2 x( 2 3
•
L’informazione misurata in bit è log 2 26 2 x( 2 3

Numero di cifre necessario per rappresentare una quantità
• Con n bit il numero X più grande rappresentabile è 2n-1, il
numero più piccolo è 2n-1


•
Il concetto di numero è indipendente dalla sua rappresentazione
(
•
Un sistema di numerazione è uno schema per codificare numeri
•
è definito da
•
cifre
•
regole da applicare per costruire i numeri
•
Esistono due categorie di sistemi di numerazione
•
addizionali
•
posizionali


Sistemi
di Numerazione Addizionali
•
In un sistema di numerazione addizionale ogni simbolo ha un
valore fisso indipendente dalla posizione che occupa
•
Il sistema più semplice è quello in cui si usa come simbolo
un’unica barretta
||
 2
|||||
 5


Sistemi
di Numerazione Addizionali
Sistema di
Numerazione Romano
•
Il sistema addizionale più conosciuto è quello romano
•
Simboli I= 1 V= 5 X= 10 L= 50 C= 100 D= 500 M= 1000
•
Regola il valore di ciascun simbolo viene sommato se alla sua
destra compare un simbolo di valore inferiore o uguale (o se è
l’ultimo), altrimenti viene sottratto
DCXXII
 622
CMV
 905


Sistemi
di Numerazione Posizionali
•
In un sistema di numerazione posizionale il valore di ogni cifra
dipende dalla sua posizione all’interno del numero
•
ad ogni posizione è associato un peso pi
•
le posizioni si contano da destra a sinistra a partire da 0
•
Il valore della cifra viene moltiplicato per la base b elevata alla posizione
N
c n 1 c n 2 c 1 c 0
V(N)
N)==(c n 1 b n 1 ))++(c n 2 b n 2 ))++....++(c 1 b 1 ))++(c 0 b 0
notazione espansa)


Sistemi di Numerazione Posizionali
Forma polinomiale
• Possiamo definire la seguente relazione detta forma
polinomiale
• analogamente possiamo scrivere numeri frazionari:
• o numeri con parte intera e parte frazionaria:
Informatica per l’ingegneria 26
Nota
Il sistema di numerazione in base 10, o sistema decimale, è il sistema
comunemente usato, ed i numeri in base 10 sono rappresentati di norma senza
l’indicazione della base.


Sistema
Binario (base
•
E’ il sistema di numerazione con la base più piccola possibile
•
In questo caso le cifre sono 0 1
•
Si parla di cifra binaria binary digit o bit)
•
Il bit è l’unità minima di informazione


Sistema
Binario (base
Vantaggio
minor numero di simboli fondamentali 0 1 facilità
di stabilire una corrispondenza biunivoca con due possibili stati di
funzionamento dei circuiti elettronici
Svantaggio
maggior numero di cifre necessarie per rappresentare
un numero
(
2 cifre decimali 7 cifre binarie)


Conversioni
di base
•
I numeri sono concetti astratti rappresentabili in una qualsiasi
base di numerazione (a seconda di quanti simboli si possono
combinare tra loro)
•
È possibile che la stessa quantità sia descritta in modi diversi,
cioè usando simboli diversi di un sistema di numerazione basato
su una base diversa
•
Ciò comporta la necessità di passare da una base di
numerazione ad un’altra, attraverso dei meccanismi matematici
molto semplici
•
L’operazione con cui si passa da una base di numerazione ad
un’altra, si chiama conversione di base



Conversione
Base 10  Base B Interi
Numeri interi
•
Un numero intero in base 10 si può esprime in base B
dividendolo ripetutamente per B fino ad ottenere un quoziente
0 e recuperando i resti in ordine inverso alla loro determinazione
•
Quindi se la base è 2
•
dividere ripetutamente per 2 fermandosi solo quando si ottiene un
quoziente nullo i resti delle divisioni effettuate, presi in ordine inverso a
quello con cui sono stati calcolati, formano il numero convertito



Conversione
Base 10  Base B Frazionari
•
Un numero intero in base 10 si può esprime in base B
dividendolo ripetutamente per B fino ad ottenere un quoziente
0 e recuperando i resti in ordine inverso alla loro determinazione
•
Per la parte frazionaria moltiplicare ripetutamente per B
fino ad ottenere un valore 0 e recuperando la parte intera
nell’ordine di determinazione
Informatica per l’ingegneria 33
(11,25)
10 = ( 2
Oppure fino a raggiungere il numero
massimo di cifre binarie con cui si
intende rappresentare il numero
frazionario (si ottiene
un’approssimazione per difetto del
numero decimale).
Infatti, in alcuni casi il risultato della
moltiplicazione per 2 non arriverà
mai ad avere parte decimale nulla


