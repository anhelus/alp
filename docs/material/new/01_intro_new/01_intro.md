# Introduzione all'informatica

Come per molti degli argomenti cui ci si approccia nel corso della vita, trovare una definizione per il concetto di _informatica_ può aiutare a comprenderne al meglio la natura.

Partiamo quindi da una (breve) analisi etimologica del termine _informatica_. Questo, infatti, è la traduzione italiana del francese _informatique_, crasi delle parole _informa(tion)_ ed _(automa)tique_. Intuitivamente, possiamo dedurre che la disciplina tratti quindi di "informazioni automatiche" o, per meglio dire, _automatizzazione delle informazioni_.

E, se ci pensiamo, è proprio di quello che si occupa l'informatica, ovvero di gestire in maniera automatica una serie più o meno rilevante di informazioni, correlate ad un qualsiasi aspetto della nostra vita, siano esse le nostre foto su Facebook, il nostro libretto universitario oppure i dati dei nostri conti corrente bancari: tutte queste informazioni vengono elaborate in maniera (più o meno) automatica.

Proviamo ad arricchire questa prima, un po' generica, definizione. Per farlo, sfruttiamo un'altra denominazione straniera, ovvero quella inglese, lingua nella quale l'informatica è chiamata _computer science_. Quello che notiamo di questa definizione è il termine _science_, che ci suggerisce come l'informatica, in realtà, sia basata su solide fondamenta scientifiche: per capirci, infatti, i "padri fondatori" della materia erano prevalentemente dei matematici, uno fra tutti il celebre Alan Turing.

L'ultimo fattore da tenere in conto è che l'informatica rappresenta uno vero e proprio _pilastro_ della società moderna. Tutto ciò che utilizziamo al giorno d'oggi, dallo smartphone che stiamo usando per leggere questo documento, al computer mediante il quale è stato scritto, fino ad arrivare alle nostre auto, o anche ai termostati nelle nostre caldaie, sono basati su tutte le evoluzioni informatiche (ed elettroniche) succedutesi a partire dal Secondo Dopoguerra.

Ecco, quindi, che possiamo dare una definizione "finale" di informatica, presa direttamente dall'Oxford Languages:

!!!quote "L'informatica"
    L'informatica è la scienza che si occupa dell'_ordinamento_, del _trattamento_ e della _trasmissione_ delle _informazioni_ per mezzo dell'_elaborazione elettronica_, la quale rende possibile gestire e organizzare le ingenti masse di dati prodotte dal moderno sviluppo sociale, scientifico e tecnologico.

Ora, non è tanto importante memorizzare questa definizione, quanto piuttosto comprenderne la portata: l'informatica è ovunque, e conoscerla ci dà l'accesso alle porte di quello che è il mondo odierno.

## Informatica ed informazione

Vediamo altre definizioni.

!!!quote "Definizione"
    Studio degli algoritmi che descrivono e trasformano l'informazione: la loro teoria, analisi, progetto, efficienza, realizzazione ed applicazione.

!!!quote "Definizione 2"
    Scienza della rappresentazione e della elaborazione dell'informazione

L'informazione è costituota dal connubio di dati (rappresnetazioni di entità di interesse) ed interpretazione (regole per comprendere e manipolare i dati).

## Componenti dell'informazione

L'informazione deve essere scritta su un qualche supporto fisico che funga da veicolo (ad esempio carta o disco magnetico).

Il linguaggio è un insieme di regole che permette di scrivere e leggere infomrazione, oltre che interpretarla.

Un linguaggio è tipicamente costituito da alfabeto (insieme di simboli appartenenti al linguaggio) e regole (insieme di regole che permettono di combinare tali simboli in costrutti del linguaggio ed interpretarli).

Affinché ogni simbolo contribuisca con un minimo di infomrazione, un alfabeto deve avere almeno due simboli distinti.

#### Sistemi automatici

L'elaborazione automatica dell'infomraizone avviene grazie ad una rappresentazione gestibile. Esistono fonti di informazioni diverse, e il loro trattamento automatico richiede uniformità nella modalità con cui venogno rappresentate.

L'infomrazione gestita da un calcolatore viene quindi mantenuta in forma numerica, con il più semplice sistema di numerazione possibile, quello binario (due soli simboli).

I dati vengono memorizzati mediante numeri interi finiti.

#### Rappresentazione dei dati

Un dato può essere di vari tipo:

* categorico (ross, verede, blu)
* ordinale (orrendo, brutto, bello, fantastico)
* numerale discreto: 10, 159, -10
* numerale continuo: 10^13, \sqrt(2)

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


