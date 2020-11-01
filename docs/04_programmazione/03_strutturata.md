I *diagrammi di flusso* sono delle rappresentazioni grafiche del flusso di esecuzione di un algoritmo imperativo.

## Flussi

Analizziamo adesso tre diversi tipi di flusso dati, ovvero la *sequenza*, la *selezione* ed il *ciclo*.

### Sequenza

Il concetto di *sequenza* prevede una serie di istruzioni che siano realizzate l'una in cascata all'altra. Ad esempio, nel montaggio di un mobile IKEA, abbiamo normalmente una sequenza di istruzioni che portano al collegamento in maniera (sperabilmente) univoca dei vari pezzi tra loro.

Per comprendere al meglio il concetto di sequenza, immaginiamo la seguente funzione (in Python).

```python
def distanza_euclidea(punto_a_x, punto_a_y, punto_b_x, punto_b_y):
	distanza_x = (punto_a_x - punto_b_x)**2
	distanza_y = (punto_a_y - punto_b_y)**2
	distanza = (distanza_x + distanza_y)**1/2
	return distanza
```

Le operazioni che vengono eseguite possono essere schematizzate come segue:

```
1 > Analisi degli ingressi
2 > Valutazione della differenza tra punto_a_x e punto_b_x
3 > Valutazione del quadrato della differenza calcolata al punto 2
4 > Valutazione della differenza tra punto_a_y e punto_b_y
5 > Valutazione del quadrato della differenza calcolata al punto 4
6 > Estrazione della radice quadrata del valore calcolato al punto 5
```

Graficamente:

TODO: rappresentare 

### Selezione

La *selezione* prevede invece la scelta tra due istruzioni che possono essere realizzate in maniera mutualmente esclusiva. Questo si traduce nella struttura IF - THEN - ELSE, che può essere riassunta in linguaggio naturale come:

!!! cite
	*IF* una data condizione è verificata *THEN* esegui queste istruzioni *ELSE* esegui queste altre istruzioni.

Immaginiamo ad esempio di inserire dei controlli alla precedente istruzione per verificare che i punti di cui vogliamo calcolare la distanza non coincidano.

```python
def distanza_euclidea(punto_a_x, punto_a_y, punto_b_x, punto_b_y):
	if (punto_a_x == punto_b_x and punto_a_y == punto_b_y):
		distanza_x = (punto_a_x - punto_b_x)**2
		distanza_y = (punto_a_y - punto_b_y)**2
		distanza = (distanza_x + distanza_y)**1/2
	else:
		distanza = 0.0
	return distanza
```

Le operazioni che vengono eseguite possono essere schematizzate come segue:

```
1 > Analisi degli ingressi
2 > Se le coordinate di a e di b coincidono...
	3a > ...valutazione della differenza tra punto_a_x e punto_b_x
	4a > Valutazione del quadrato della differenza calcolata al punto 2
	5a > Valutazione della differenza tra punto_a_y e punto_b_y
	6a > Valutazione del quadrato della differenza calcolata al punto 4
	7a > Estrazione della radice quadrata del valore calcolato al punto 5
	...altrimenti...
	3b > Assegna a distanza il valore 0.0
8 > Restituisci il valore di distanza
```

Graficamente:

TODO: rappresentare 

#### Istruzione switch

TODO: ricordare che lo switch non è sempre presente in tutti i linguaggi
TODO: perché switch e non struttura gerarchica di IF

### Ciclo

L'ultimo tipo di struttura di controllo che esiste è il *ciclo*, o *iterazione*. Anche comprendere come si strutturi l'iterazione è intuitivo: in particolare, il ciclo prevede che siano reiterate più volte una o più istruzioni, fino a che non sia verificata una condizione.

#### Istruzione For

#### Istruzione While

## Il teorema di Bohm-Jacopini

TODO: RIVEDERE

Il teorema di Bohm-Jacopini dice che:
orema di Böhm-Jacopini, enunciato nel 1966[1] dagli informatici Corrado Böhm e Giuseppe Jacopini, è un teorema di informatica teorica il quale afferma che qualunque algoritmo può essere implementato in fase di programmazione (in diagramma di flusso, pseudocodice o codice sorgente) utilizzando tre sole strutture dette strutture di controllo: la sequenza, la selezione ed il ciclo (iterazione), da applicare ricorsivamente alla composizione di istruzioni elementari (ad esempio, istruzioni eseguibili con il modello di base della macchina di Turing).

Le implicazioni sono ovviamente importanti.

Questo teorema ha un interesse anche teorico, in quanto i linguaggi di programmazione tendono a dotarsi di più tipi di istruzioni di larga portata per evitare che i programmatori debbano occuparsi di istruzioni di portata molto minuta e quindi dispersive per quanto attiene alla padronanza delle finalità dell'algoritmo (esistono però linguaggi minimalisti, come Brainfuck, che si attengono alla lettera al teorema). Il suo valore va visto nella sua capacità di fornire indicazioni generali per le attività di progettazione di nuovi linguaggi e di strategie di programmazione. In effetti, esso ha contribuito alla critica dell'uso sconsiderato delle istruzioni go to e alla definizione delle linee guida della programmazione strutturata che si sono avuti intorno al 1970.
