# E27 - Esercizi sulle strutture dati

## Esercizio E27.1

Proviamo a valutare il tempo necessario alle operazioni di `insert` e `pop` su una coda in Python usando la libreria `time`. Confrontiamo il risultato ottenuto con quello ottenibile implementando una coda come una struttura di tipo `deque` e usando gli opportuni metodi `appendleft` e `popleft`.

### Soluzione S27.1

```py
from time import time
from collections import deque

def queue(queue, pushed=1):
	tic = time()
	queue.insert(0, 4)
	queue.pop()
	toc = time()
	return tic, toc

def queue_con_deque(queue, pushed=1):
	tic = time()
	queue.appendleft(pushed)
	queue.popleft()
	toc = time()
	return tic, toc
```

Proviamo a chiamare le due funzioni:

```py
queue = list(range(10000000))
queue_d = deque(queue)

queue_classica(queue)
queue_con_deque(queue_d)
```

Avremo un output simile al seguente:

```sh
Tempo necessario con lista: 0.08756685126958008
Tempo necessario con deque: 0.0
```

## Esercizio E27.2

Selezioniamo tutti i nomi che iniziano con la lettera B dalla seguente lista:

```py
lista_nomi = [
    "Jax Teller",
    "Walter White",
    "Billy Butcher",
    "Luke Skywalker",
    "Bobby Singer",
    "Johnny Lawrence"]
```

Facciamolo usando un ciclo ed una list comprehension.

### Soluzione S27.2

Usando un ciclo:

```py
output_for = []
for nome in lista_nomi:
    if nomi[0] == "B":
        output_for.append(nome)
```

Usando una list comprehension:

```py
output = [nome for nome in lista_nomi if nome[0] == "B"]
```

## Esercizio E27.3

Ottenere una lista che abbia al suo interno tutti i quadrati dei numeri che vanno da 1 a 10

### Soluzione S27.3

Usando un ciclo:

```py
def quadrato(numero):
    return numero ** 2

output = []
for i in range(1, 11):
    output.append(quadrato(i))
```

Usando una list comprehension:

```py
output = [quadrato(i) for i in range(1, 11)]
```

## Esercizio E27.4

Ottenere una lista che abbia la stringa `pari` in corrispondenza dei numeri pari, mentre quella `dispari` in corrispondenza dei numeri dispari, per tutti i numeri che vanno da 1 a 10.

### Soluzione S27.4

Usando un ciclo:

```py
output = []
for i in range(1, 10):
    if i % 2 == 0:
        output.append("pari")
    else:
        output.append("dispari")
```

Usando una list comprehension:

```py
output = ["pari" if i % 2 == 0 else "dispari" for i in range(1, 10)]
```

!!!tip "Suggerimento"
    Possiamo usare la forma base della list comprehension definendo una funzione accessoria. Ad esempio:
    > ```py
      def pari_o_dispari(numero):
          if numero % 2 == 0:
              return 'pari'
          else:
              return 'dispari'
      ```

## Esercizio E27.5

Scrivere una dict comprehension che permetta di ottenere il dizionario `vecchio_o_giovane` dato il seguente dizionario:

```py
dizionario = {
    'Jax Teller': 27,
    'Walter White': 52,
    'Billy Butcher': 41,
    'Luke Skywalker': 79,
    'Bobby Singer': 68,
    'Johnny Lawrence': 49}
```

In particolare, il dizionario `vecchio_o_giovane` avrà le stesse chiavi del dizionario di partenza, a cui sarà associato il valore `giovane` soltanto se il valore della chiave del dizionario di partenza è inferiore a 65.

### Soluzione S27.5

```py
vecchio_o_giovane = { k: 'vecchio' if v > 65 else 'giovane' for (k, v) in dizionario.items() }
```

!!!note "Nota"
	Per iterare sul dizionario originale, usiamo il metodo `items()` che, come visto in precedenza, ci restituisce un oggetto di tipo `dict_items` il quale è, per l'appunto, iterabile.
