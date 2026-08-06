# 1.2 Rappresentazione dei dati

Nella [scorsa lezione](01_intro_inf.md) abbiamo introdotto i concetti legati alla rappresentazione dell'informazione all'interno di sistemi automatici. Tuttavia, è importante approfondire ulteriormente il modo in cui questa informazione viene gestita.

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

!!! warning "Pericolo"
    Attenzione: un ingegnere civile potrebbe avere malori nel prosieguo della lettura. Perdonatemi per le eccessive ed atroci semplificazioni.

### Di che categoria è la nostra casa?

Partiamo dal metodo di costruzione della casa. In questo caso, come abbiamo potuto vedere, sono stati utilizzati dei mattoni; tuttavia, sappiamo benissimo che esistono diverse tecniche di costruzione, alcune che prevedono l'utilizzo del cemento armato, altre che prevedono l'uso del legno, altre ancora ibride. Avremo, quindi, diverse *categorie* di case; il dato associato a questa informazione, quindi, risulterà essere di tipo *categorico*. 

!!! question "Altri dati categorici"
    Il lettore più attento noterà che vi è un altro dato categorico all'interno della rappresentazione precedente. Stiamo, ovviamente, parlando del colore dei mattoni utilizzati.

### Quante mura abbiamo?

Altra importantissima informazione estrapolabile dalla frase precedente è quella relativa al numero di mura presenti all'interno della casa, ovvero cinque (probabilmente, uno sarà un divisorio, a meno di eventuali licenze poetiche del costruttore). Ciò suggerisce l'esistenza di un altro tipo di dato, ovvero quello *numerico*.

Da notare che, in questo caso, il numero di mura è *intero*. Nella realtà, tuttavia, esistono anche numeri *non interi*, globalmente noti come *reali*. Di conseguenza, esisteranno due tipi di dato numerico: il dato di tipo intero, o *numerico discreto*, ed il dato di tipo reale, o *numerico continuo*.

### Che bella questa casa!

L'ultima informazione che siamo in grado di estrapolare è quella fornita dal nostro gusto estetico, che ci suggerisce come la casa sia in qualche modo gradevole (o, più propriamente, *bella*). Questa informazione può essere associata ad una serie di valori che possono essere *ordinati* in maniera semanticamente crescente o decrescente. Per capirci, una casa *bella* è più gradevole di una *brutta*, ma meno gradevole di una *fantastica*. Il quarto tipo di dato è, quindi, *ordinale*.

## Riassumendo...

Riassumendo, abbiamo quattro tipologie di dati, come mostrati nella seguente tabella.

| Tipo di dato | Descrizione | Esempio |
| ------------ | ----------- | ------- |
| Categorico | Dato che descrive informazione il cui valore è all'interno di un insieme limitato di categorie | Mattoni, cemento, legno |
| Ordinale | Dato che descrive informazione il cui valore è semanticamente ordinabile | Orrendo, brutto, bello, fantastico |
| numerico discreto | Dato che descrive informazione associata a numeri interi | 1, 2, 100 |
| numerico continuo | Dato che descrive informazione associata a numeri continui | $\pi$, 2.45, $\sqrt{2}$ |

!!! info "Una precisazione sui tipi categorici"
    Il tipo ordinale è in realtà un *sottotipo* del tipo categorico: un dato ordinale è sempre categorico (appartiene a categorie), ma con l'aggiunta di una relazione d'ordine. Per esempio, "bello" e "orrendo" sono categorie, e in più sono ordinabili. Non tutti i dati categorici, però, sono ordinabili: il colore o il materiale non hanno un ordine intrinseco.

## Come rappresentare i dati in un sistema informativo

Alcuni dei tipi precedentemente descritti possono essere abbastanza complessi da rappresentare in un sistema informativo; ciò vale in particolare per i dati categorici e per quelli ordinali.

Il motivo di questa difficoltà è presto spiegato: potenzialmente, infatti, è necessario rappresentare un numero *molto elevato* di possibilità, in entrambi i casi. E, come ben sappiamo, le risorse di un calcolatore sono finite: di conseguenza, bisogna trovare una maniera per usare una rappresentazione *comune* e *condivisa* di tutti i tipi di dato.

Ragioniamo un attimo su quale potrebbe essere un formato ottimale per ottenere questa rappresentazione.

Partiamo chiedendoci quale tra i quattro tipi sia il più "semplice" da utilizzare. La risposta, ovviamente, è il tipo *numerico discreto*: maneggiare numeri interi è intrinsecamente meno complesso del maneggiare numeri continui o insiemi potenzialmente infiniti di parole.

Fatto questo, dobbiamo chiederci se sia possibile, in qualche modo, rappresentare le altre categorie sotto forma di numero intero. Partiamo dai dati categorici.

### Categorici come interi

Per rappresentare un dato categorico come intero, dovremo usare il cosiddetto *metodo del dizionario*. Nella pratica, ad ogni possibile categoria sarà associato un numero intero, e questo sarà usato per rappresentare detta categoria. Un esempio è ciò che avviene nella seguente tabella.

| Categoria | Intero associato |
| --------- | ---------------- |
| Mattoni | 1 |
| Cemento armato | 2 |
| Legno | 3 |

Grazie al dizionario definito nella tabella precedente, potremo rappresentare la categoria "mattoni" mediante il numero 1, il "cemento armato" mediante il 2, e via discorrendo. L'aggiornamento del dizionario a seguito di una nuova categoria è volutamente lasciato al lettore.

!!! note "Operazioni definite sul tipo categorico"
    Da sottolineare come l'unica operazione definibile su un tipo di dato categorico sia quella di uguaglianza, che risponde alla domanda *la categoria di X è uguale alla categoria di Y*? Per metterla in italiano, *il colore del primo mattone è uguale a quello del secondo*? Ovviamente, questa operazione è *preservata* dal dizionario: se due mattoni sono rossi, la loro rappresentazione in numero intero sarà sempre pari ad $1$.

### Ordinali come interi

La rappresentazione di un dato ordinale come intero usiamo invece il *metodo dell'enumerazione*. Innanzitutto, ordiniamo i valori secondo il loro significato semantico. Ad esempio:

1. *orrendo*
2. *brutto*
3. *bello*
4. *fantastico*

Fatto questo, potremo associare un numero intero ad ogni valore, in maniera crescente. Sì, lo avevamo già fatto, ma è comunque opportuno consultare la seguente tabella.

| Ordinale | Intero associato |
| --------- | ---------------- |
| Orrendo | 1 |
| Brutto | 2 |
| Bello | 3 |
| Fantastico | 4 |

!!! note "Operazioni definite sul tipo ordinale"
    In caso di tipo ordinale, possiamo definire la *relazione di ordine*, che l'enumerazione preserva. In altre parole, se "bello" è meglio di "orrendo", il valore associato a "bello" (3) sarà maggiore di quello associato a "orrendo" (1).

Siamo quindi adesso in grado di individuare le diverse tipologie di dato che è possibile avere all'interno di un contenitore informativo.

!!! tip "Anteprima: i tipi nella programmazione"
    I quattro tipi che abbiamo visto trovano un corrispettivo diretto nei linguaggi di programmazione: gli interi (`int`), i numeri con virgola (`float`, `double`), i caratteri (`char`) e i valori vero/falso (`bool`). Il **booleano** è un caso speciale di tipo categorico con esattamente due valori: *vero* e *falso*. Sarà fondamentale quando parleremo di algebra booleana.

In definitiva, abbiamo introdotto il concetto di *codifica*, inteso come processo di associare un valore categorico o ordinale ad un numero intero. La scelta di detta codifica è *arbitraria* (ovvero, posso scegliere 1 per rosso, 5 per blu e 23 per verde), purché sia condivisa tra chi scrive e chi legge il dato (ovvero, ci sia un *protocollo* standard e condiviso).

Nella [prossima lezione](03_dig_an.md) andremo a vedere come vengono codificate, dal punto di vista "fisico", le informazioni all'interno di un calcolatore.

!!! warning "Numeri reali e numeri interi"
    Abbiamo volutamente tralasciato la questione relativa ai numeri reali, che tratteremo più estesamente quando parleremo della rappresentazione a virgola mobile nel sistema binario. Per adesso, ciò che ci interessa sapere è che i numeri discreti possono *approssimare* i numeri continui, ma con un inevitabile margine di errore dovuto alla precisione limitata.



