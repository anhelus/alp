# 2.5.1 - Le funzioni

Immaginiamo di dover calcolare il nostro voto di accesso all'esame laurea. Supponendo che nel nostro corso di studi ci siano esattamente venti esami, le istruzioni necessarie a calcolarlo sono molto semplici:

```linenums="1"
numero_esami = 20;
somma_voti = 0;
for i che va da 1 a numero_esami:
	somma_voti = somma_voti + voto_esame_i;
endfor
voto_medio = somma_voti/numero_esami;
voto_accesso = voto_medio / 3 * 11;
```

Queste istruzioni accettano un solo "insieme" di esami, relativo quindi a noi; come potremmo fare quindi per calcolare la media di un nostro collega? La tentazione potrebbe essere quella di "sdoppiare" le istruzioni, cambiando leggermente il nome delle variabili e passando un insieme di esami diverso:

```linenums="1"
numero_esami = 20;
somma_voti_a = 0;
for i che va da 1 a numero_esami:
	somma_voti_a = somma_voti_a + voto_esame_i_a;
endfor
voto_medio_a = somma_voti_a / numero_esami;
voto_accesso_a = voto_medio_a / 3 * 11;

somma_voti_b = 0;
for i che va da 1 a numero_esami:
	somma_voti_b = somma_voti_b + voto_esame_i;
endfor
voto_medio_b = somma_voti_b / numero_esami;
voto_accesso_b = voto_medio / 3 * 11;
```

Cosa accadrebbe se volessimo aggiungere un altro studente? Ovviamente, dovremmo aggiungere altre righe di codice; è facile quindi intuire che, in breve tempo, la situazione diventerebbe ingestibile.

In nostro aiuto, quindi, giungono le *funzioni*, ovvero dei costrutti che ci permettono di raggruppare istruzioni eseguite un numero arbitrario di volte all'interno del nostro codice. Le funzioni (chiamate anche *metodi*) assumono quindi il ruolo di *contenitore logico*, utilizzabile per effettuare una serie ben definita di operazioni su un certo input, conseguendo un determinato output.

Vediamo quindi come sono strutturate.

## Struttura di una funzione

Una funzione consta di due parti: una *firma* ed un *corpo*.

Nella firma, sono definiti:

* il *nome* della funzione, ovvero un identificativo utile a richiamarla in altre parti del programma (un po' come quello della variabile);
* il *tipo di ritorno*, ovvero il tipo del valore restituito (ovvero, mandato in output) dalla funzione;
* i *parametri di ingresso*, ovvero il tipo ed i nomi dei valori in ingresso (input) alla funzione.

Nel corpo, invece, saranno indicate le istruzioni vere e proprie, oltre che l'eventuale valore restituito dalla funzione. Schematizzando:

```linenums="1"
tipo_ritorno nome_funzione(tipo_par_1 par_1, tipo_par_2 par_2):			// Questa è la firma...
	istr_1;																// ...questo è il corpo...
	istr_2;
	tipo_ritorno valore_ritorno = istr_3;
	return valore_ritorno;												// ...e questo è il valore restituito!
```

Da notare la presenza della parola chiave `return`, che serve ad indicare il valore (o, per meglio dire, la variabile) che sarà "restituita" dalla funzione. 

!!!note "Nota"
	Quando la funzione trova la parola chiave `return`, si "ferma" immediatamente, e l'esecuzione del programma continua.

Facciamo un esempio creando una pseudo-funzione per il calcolo del voto di accesso all'esame di laurea; chiamiamola, in maniera originale, `calcolo_voto_accesso_laurea`, e supponiamo restituisca un `float` (il voto di accesso non approssimato) a partire da un insieme di valori `interi` (i voti dei singoli esami). Allora:

```linenums="1"
numero_esami = 20;

float calcolo_voto_accesso_laurea(int[] voti_esami):
	somma_voti = 0;
	for i che va da 1 a numero_esami:
		somma_voti = somma_voti + voto_esame_i;
	endfor
	voto_medio = somma_voti / numero_esami;
	voto_accesso = voto_medio / 3 * 11;
	return voto_accesso;
```

Immaginiamo di voler chiamare la funzione per calcolare i nostri voti, oltre a quelli di un collega. Per farlo, useremo istruzioni simili a queste:

```linenums="1"
mio_voto_accesso = calcolo_voto_accesso_laurea(miei_voti);
voto_accesso_collega = calcolo_voto_accesso_laurea(voti_collega);
```

Come si può notare, il numero di righe di codice scritte diminuisce in maniera tanto più rilevante quanto più si usa la funzione!

!!!note "Nota sulle parentesi quadre"
	Abbiamo usato in precedenza le parentesi quadre (`[]`) per indicare un "insieme" di valori. In realtà, questa notazione indica spesso un *array*, o una *lista*, a seconda del linguaggio; ne parleremo più diffusamente nel seguito.

## Il concetto di modularità

Abbiamo visto come una funzione serva ad evitare di dover ripetere numerose volte lo stesso insieme di istruzioni. Tuttavia, abbiamo accennato in precedenza anche al fatto che ogni funzione è un contenitore logico di una sequena di istruzioni da utilizzare per risolvere un problema: ciò ci conduce direttamente al concetto di *modularità*, per il quale una funzione deve contenere *esclusivamente* le istruzioni necessarie ad eseguire lo scopo per cui è stata concepita.

Per fare un esempio, immaginiamo adesso di dover calcolare, oltre al voto medio di accesso all'esame di laurea, anche quello finale, tenendo conto della votazione della commissione e dell'eventuale lode. Sottolineamo comunque come sia sempre importante per noi (e, nello specifico, per la segreteria e la commissione) tenere traccia del voto medio, per cui le due cose andranno, in qualche modo, separate.

L'approccio da utilizzare è quindi quello di creare un'altra funzione che asserva allo scopo di calcolare il voto finale:

```linenums=1"
int calcolo_voto_finale_laurea(float voto_accesso, int voto_esame, float soglia_lode):
	voto_cumulativo = voto_accesso + voto_esame;
	if (voto_cumulativo > (110 + soglia_lode)):
		return 110L
	else:
		return voto_cumulativo
```

Da notare la presenza di due `return`: questo è corretto perché, essendo specificati nei due rami di un'istruzione condizionale, saranno mutualmente esclusivi, e quindi la funzione potrà "arrivare" soltanto ad uno di essi.

## Funzioni, variabili ed ambito

Introduciamo brevemente il concetto di *ambito* di una variabile. All'interno del nostro programma, infatti, ogni variabile ha una sorta di "ciclo di vita", nel quale viene creata, utilizzata, ed infine distrutta.

L'intero programma ha un ambito chiamato *globale*: ciò significa che tutte le variabili specificate nel corpo principale del programma, che vedremo in avanti essere chiamato spesso *main*, avranno validità in tutto il nostro codice. Le singole funzioni, invece, definiscono un ambito *locale*, che viene creato alla chiamata della funzione, e distrutto al termine della stessa.

Ad esempio:

```linenums="1"
numero_esami = 20;
miei_voti = lista_miei_voti;

float calcolo_voto_accesso_laurea(int[] voti_esami):
	somma_voti = 0;
	for i che va da 1 a numero_esami:
		somma_voti = somma_voti + voto_esame_i;
	endfor
	voto_medio = somma_voti / numero_esami;
	voto_accesso = voto_medio / 3 * 11;
	return voto_accesso;

voto_accesso_mio = calcolo_voto_accesso_laurea(miei_voti);
```

Nel codice precedente, dichiariamo le variabili `numero_esami` e `miei_voti` nel corpo principale del programma: ciò significa che questa variabili hanno validità nell'intero codice, e sono quindi richiamabili (e potenzialmente *modificabili*) anche all'interno della funzione `calcolo_voto_accesso_laurea`. Dal canto suo, quest'ultima crea un ambito locale: ciò comporta che le variabili create al suo interno, come `somma_voti`, `voto_medio` e `voto_accesso`, *non potranno essere accedute all'esterno della funzione*.

Da ciò seguono alcune considerazioni:

1. parlando in maniera "logica", la parola chiave `return` serve a "trasferire" il valore di una variabile da un ambito locale ad uno globale;
2. la variabile restituita *cambia identificatore*, ma il valore è quello calcolato all'interno della funzione;
3. occorre fare estrema attenzione alla modifica delle variabili globali in ambito locale, ovvero all'interno delle singole funzioni.

Imparare ad utilizzare l'ambito delle variabili è propedeutico al corretto utilizzo delle tecniche di programmazione, e tenere a mente queste tre semplici regole ci aiuterà enormemente nella scrittura dle nsotro codice.
