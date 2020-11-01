La *funzione*, o *metodo*, è un costrutto che permette di raggruppare una serie di istruzioni che sono eseguite più volte all'interno del nostro programma.

Una funzione è articolata in due parti: una *firma* ed un *corpo*. La firma della funzione è dove sono definiti:

* *nome della funzione* (ovvero un identificativo utile a richiamarla in altre parti del programma);
* *tipo di ritorno*, ovvero il tipo del valore in output alla funzione;
* *parametri di ingresso*, ovvero il tipo ed i nomi dei valori che saranno mandati in input alla funzione.

Nel corpo sono invece definite le istruzioni vere e proprie, oltre che il valore restituito dalla funzione (che, ovviamente, deve essere del tipo specificato in firma.)

Ad esempio:

```c
// Questa è la firma!
tipo_ritorno nome_funzione(tipo_par_1 par_1, tipo_par_2 par_2)
{
	// Questo è il corpo
	istr_1;
	istr_2;
	tipo_ritorno valore_ritorno = istr_3;
	return valore_ritorno;
}
```

E' importante sottolineare come il tipo di ritorno ed i tipi dei parametri in ingresso possono essere omessi in caso di linguaggio non fortemente tipizzato.

Molti linguaggi specificano inoltre dei *modificatori di accesso* alla funzione; ne parleremo in seguito, quando introdurremo la programmazione orientata agli oggetti.

## Riutilizzo del codice

Il principio alla base dello sviluppo delle funzioni è quello secondo il quale vogliamo *minimizzare* il quantitativo di codice scritto. Meno codice, infatti, significa meno possibilità di refusi, che in linguaggi dalla grammatica "rigida" come quello per i computer possono anche significare l'impossibilità di eseguire il programma.

Inoltre, una funzione può essere intesa, *molto* alla lontana, come un teorema matematico: ad esempio, le relazioni definite dal teorema di Pitagora valgono *indipendentemente* dai valori dei cateti e dell'ipotenusa. Ciò ci permette quindi di avere un insieme di istruzioni *fisse* e *controllabili*, che possiamo manipolare e verificare a piacimento, conservando la *coerenza* del nostro programma: saremo infatti sicuri che il comportamento di una funzione sarà replicato alla stessa maniera *ogni volta che la chiameremo*, indipendentemente dal programma considerato.

Facciamo un esempio.

```python
def ipotenusa(c_1, c_2):
	c_1_quad = c_1**2
	c_2_quad = c_2**2
	i = (c_1_quad + c_2_quad)**1/2
	return i

# Questo è il nostro programma
if __name__ == "__main__":
	a = 3
	b = 4
	i_1 = ipotenusa(a, b)
	c = 6
	d = 8
	i_2 = ipotenusa(c, d)
```

Se non avessimo utilizzato la funzione ipotenusa, avremmo dovuto scrivere due volte la formula per il calcolo dell'ipotenusa, con il rischio di sbagliare una volta, o comunque scrivere due metodi di calcolo differenti.

!!! note "La stessa funzione in C"
	L'esempio precedente è scritto in Python, linguaggio non fortemente tipizzato. In C la funzione sarebbe
	```c
	int ipotenusa(int c_1, int c_2) {
		int c_1_quad = c_1*c_1;
		int c_2_quad = c_2*c_2;
		int c_quad_sum = c_1_quad + c_2_quad;
		int i = sqrt(c_quad_sum);
		return i;
	}
	```

## Modularità

Le funzioni permettono anche di scrivere del codice *modulare*. Ciò significa che ogni funzione asserve ad un determinato scopo, ed il nostro programma può "comporsi" a partire da diversi metodi, cambiando i quali se ne cambiano anche scopi e finalità. 

Ad esempio, se si dovesse in futuro scoprire una nuova formulazione per il teorema di Pitagora, non dovremmo cambiare tutto il nostro programma, ma basterebbe modificare esclusivamente la funzione che implementa il teorema di Pitagora:

```python
def ipotenusa(c_1, c_2):
	i = (c_1 + c_2)
	return i

# Il programma non cambia!
if __name__ == "__main__":
	a = 3
	b = 4
	i_1 = ipotenusa(a, b)
	c = 6
	d = 8
	i_2 = ipotenusa(c, d)
```
