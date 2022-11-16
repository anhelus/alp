# E24 - Programmare in Python

## Esercizio E24.1

Scriviamo una funzione che iteri fino a che il valore associato ad un contatore intero è minore di 10. Usiamo un ciclo `while`.

### Soluzione S11.1

```py
def itera_while():
    i=0
    while i < 10:
            i=i+1
            print("{}-ma iterazione".format(i))
```

Il risultato ottenuto sarà:

```py
>>> itera_while()
1-ma iterazione
2-ma iterazione
3-ma iterazione
4-ma iterazione
5-ma iterazione
6-ma iterazione
7-ma iterazione
8-ma iterazione
9-ma iterazione
10-ma iterazione
```

## Esercizio E24.2

Scriviamo una funzione che iteri fino a che una condizione booleana non è `False`. Usiamo un ciclo `for`, ponendo come numero massimo di iterazioni 100 e se necessario, usando il metodo [`random.randint(a, b)`](https://docs.python.org/3/library/random.html#random.randint).

### Soluzione S11.2

```py
def itera_for():
    cond=True
    for i in range(100):
            eval = random.randint(-10, 10)
            print('Valuto numero {}'.format(eval))
            if eval < 0:
                    print('Esco')
                    cond=False
                    return cond
            else:
                    print('Continuo')
    return cond
```

Il risultato ottenuto sarà:

```py
>>> itera_for()
Valuto numero 6
Continuo
Valuto numero 7
Continuo
Valuto numero 8
Continuo
Valuto numero -4
Esco
False
```

## Esercizio E24.3

Estraiamo tutti gli indici pari di una lista arbitraria di dieci elementi in ordine inverso. Per farlo, usiamo sia la funzione `range` sia lo slicing.

### Soluzione S11.3

```py
def estrai_con_slice(lista):
    if len(lista) != 10:
            print('Errore!')
            return []
    else:
            return lista[-2::-2]

def estrai_con_range(lista):
    if len(lista) != 10:
        print('Errore!')
        return []
    else:
        l_out = []
        for i in range(8, -1, -2):
            l_out.append(lista[i])
        return l_out
```

Il risultato ottenuto sarà:

```py
>>> l = [1,2,3,4,5,6,7,8,9,10]
>>> estrai_con_slice(l)
[10, 8, 6, 4, 2]
>>> estrai_con_range(l)
[10, 8, 6, 4, 2]
```

## Esercizio E24.4

Utilizzare il pattern matching per stampare a schermo la parola "Vero" se il valore di una variabile è `True`, e "Falso" altrimenti.

### Soluzione S11.4

```py
def match_case(true_or_false):
    match true_or_false:
        case True:
            return "Vero"
        case False:
            return "Falso"
```

Il risultato ottenuto sarà:

```py
>>> a = True
>>> match_case(a)
'Vero'
>>> b = False
>>> match_case(b)
'Falso'
```

## Esercizio E24.5

Creare un metodo che raddoppi una lista passata come argomento in ingresso. Provare ad utilizzare un ciclo `for` e ricordare la differenza tra shallow e deep copy.

### Soluzione S11.5

Potremmo essere tentati di scrivere una funzione come la seguente:

```py
def raddoppia_lista(lista):
    for elemento in lista:
        lista.append(elemento)
        print(f"Lista all'iterazione attuale: {lista}")
```

Proviamo a chiamare questa funzione; avremo subito un output ingestibile. Ciò è legato al fatto che Python è fermo in un loop infinito: il metodo agisce sulla lista originaria, che ad ogni iterazione del ciclo "ingloba" un altro elemento, provocando di conseguenza un aumento delle dimensioni della lista e, quindi, un'ulteriore iterazione, e così via all'infinito.

Possiamo però ottenere il risultato che ci serve usando il metodo `deepcopy`:

```py
from copy import deepcopy

def raddoppia_lista_deep(lista):
    lista_appoggio = deepcopy(lista)
    for elemento in lista_appoggio:
        lista.append(elemento)
        print(f"Lista di appoggio: {lista_appoggio}")
        print(f"Lista attuale: {lista}")
```

In questo caso, stiamo creando un'altra variabile, chiamata `lista_appoggio`, che sarà utilizzata come "buffer" per aggiungere alla lista originaria gli elementi relativi a sé stessa. Provando a chiamare questo codice otterremo il risultato desiderato:

```py
>>> raddoppia_lista_deep([1, 2])
Lista di appoggio: [1, 2]
Lista attuale: [1, 2, 1]
Lista di appoggio: [1, 2]
Lista attuale: [1, 2, 1, 2]
```
