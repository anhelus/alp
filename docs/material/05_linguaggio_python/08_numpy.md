# NumPy e manipolazione di array

## Cosa è NumPy?

NumPy è una libreria per la manipolazione di array in Python.

### Installazione di NumPy

Iniziamo installandola mediante il *package manager* integrato di Python da riga di comando, chiamato `pip`:

```bash
pip install numpy
```

!!!note "Nota"
	In questa maniera, Numpy sarà installato globalmente.

Una volta completata l'installazione, potremo accedere alle variabili, classi e funzioni definite dalla libreria.

### Uso di NumPy

#### Importazione di NumPy

Iniziamo importando `numpy`:

```python
>>> import numpy as np
```

!!!note "Nota"
	Notiamo l'utilizzo del modulo sotto forma di alias.

#### Creazione di un array

Esistono diversi modi per creare un array.

##### Creazione diretta

Il primo è crearlo direttamente come oggetto di tipo `array`:

```python
>>> a = np.array([1,2,3])
>>> a
array([1, 2, 3])
```

!!!note "Nota"
	Si utilizza la notazione `np` a causa del fatto che `numpy` è stato importato con suddetto alias. Se questo non fosse avvenuto, sarebbe stato necessario usare `numpy.array`.

##### Uso di `ndarray`

Gli array NumPy sono un'istanza della classe `ndarray`. Possiamo quindi crearne uno richiamandola direttamente:

```python
>>> f = np.ndarray(shape=(2,2), dtype=float)
>>> f
array([[5.e-324, 5.e-324],
       [0.e+000, 0.e+000]])
```

##### Funzione `arange`

La funzione `arange` è analoga alla funzione `range` di Python, ma restituisce un array NumPy invece di una lista.

```python
>>> a = np.arange(1, 4)
>>> a
array([1, 2, 3])
```

##### Dimensioni dell'array

Un array in NumPy può essere ad $n$ dimensioni:

```python
>>> one_d = np.arange(5)
>>> one_d
array([0, 1, 2, 3, 4])
>>> two_d = np.arange(9).reshape(3,3)
>>> two_d
array([[0, 1, 2],
       [3, 4, 5],
       [6, 7, 8]])
>>> three_d = np.arange(27).reshape(3,3,3)
>>> three_d
array([[[ 0,  1,  2],
        [ 3,  4,  5],
        [ 6,  7,  8]],

       [[ 9, 10, 11],
        [12, 13, 14],
        [15, 16, 17]],

       [[18, 19, 20],
        [21, 22, 23],
        [24, 25, 26]]])
```

Nell'esempio precedente, `one_d` è un esempio di array monodimensionale, `two_d` bidimensionale (matrice) e `three_d` tridimensionale (tensore). Notiamo l'uso della funzione `reshape` che accetta come parametri una serie di interi, dove l'i-mo intero rappresenta il numero di elementi della i-ma dimensione dell'array. Quest'ultima è facilmente verificabile mediante l'attributo `shape`, ovvero una tupla che restituisce il numero di dimensioni dell'array:

```python
>>> three_d.shape
(3, 3, 3)
```

#### Operazioni elementari

##### Somma di array

```python
>>> a = np.arange(6,15).reshape(3,3)
>>> b = np.arange(30,21,-1).reshape(3,3)
>>> a + b
array([[36, 36, 36],
       [36, 36, 36],
       [36, 36, 36]])
```

##### Prodotto di array

Prodotto elemento per elemento:

```python
>>> a * b
array([[180, 203, 224],
       [243, 260, 275],
       [288, 299, 308]])
```

Prodotto matriciale:

```python
>>> a @ b
array([[ 561,  540,  519],
       [ 804,  774,  744],
       [1047, 1008,  969]])
```

#### Indexing e slicing

Le operazioni di indexing e slicing sono analoghe a quelle viste per le liste:

```python
>>> b[0:2,:]
array([[30,  29,  28],
       [ 27,  26,  25]])
>>> b[0,0]
30
>>> b[0,0] = 60
```

Notiamo che gli array NumPy sono mutabili.

#### Tipo di un array

A differenza delle liste, gli array NumPy sono tipizzati:

```python
>>> b[0,0] = 'stringa'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: invalid literal for int() with base 10: 'stringa'
>>> b[0,0] = 1.1
>>> b
array([[ 1, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
>>> type(b[0,0])
<class 'numpy.int32'>
```

Viene però effettuato un cast automatico nel tipo assegnato agli elementi dell'array:

```python
>>> b[0,0] = '1'
>>> b
array([[ 1, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
```

#### Copia di array

La copia di un array con l'operatore di assegnazione la creazione di un alias:

```python
>>> c = b
>>> c
array([[30, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
>>> b[0,0] = 60
>>> b
array([[60, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
>>> c
array([[60, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
```

Notiamo quindi come b e c siano due alias per gli stessi dati.

##### Shallow copy

La shallow copy (ovvero la copia per reference) produce effetti analoghi ed avviene mediante il metodo `view()`:

```python
>>> d = b.view()
>>> d
array([[60, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
>>> b[0,0] = 30
>>> d
array([[30, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
```

##### Deep copy

La deep copy (ovvero la copia per valore) avviene mediante il metodo `copy()`:

```python
>>> e = b.copy()
>>> b[0,0] = 120
>>> e
array([[30, 29, 28],
       [27, 26, 25],
       [24, 23, 22]])
```

#### Algebra matriciale

NumPy offre diverse operazioni di algebra matriciale. Ad esempio, è possibile invertire una matrice:

```python
>>> from numpy.linalg import inv
>>> inv(b)
array([[-0.03448276,  0.06896552, -0.03448276],
       [ 0.06896552, -7.47126437,  8.40229885],
       [-0.03448276,  7.73563218, -8.70114943]])
```

oppure calcolarne la norma di Frobenius:

```python
>>> from numpy.linalg import norm
>>> norm(b)
72.42237223399962
```

Per un elenco completo delle funzioni, si rimanda alla [reference di NumPy](https://numpy.org/doc/).
