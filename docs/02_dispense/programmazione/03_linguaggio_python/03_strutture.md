# Ancora sulle strutture dati in Python

## Liste come stack e code

Python mette a disposione un'estesa serie di metodi di accesso, inserimento e gestione delle liste, disponibili a [questo indirizzo](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists).

E' interessante quindi notare come sia possibile costruire uno stack o una coda in maniera estremamente semplice; vediamo come.

### Stack

Ricordiamo che uno stack adotta una strategia di accesso del tipo LIFO; ciò significa quindi che il primo elemento ad essere servito sarà quello in cima allo stack. Potremo quindi usare il metodo `append()` per inserire l'elemento in cima alla lista, ed il metodo `pop()` per recuperarlo.

```python
>>> s = [1,2,3]
>>> s.append(4)
>>> s
[1, 2, 3, 4]
>>> e = s.pop()
>>> e
4
>>> s
[1, 2, 3]
```

### Coda

Per le code, che ricordiamo adottare una strategia del tipo FIFO, abbiamo due possibilità. La prima è quella di usare i metodi `insert()` e `pop()` come segue:

```python
from time import time

def queue_classica(queue, pushed=1):
	t1 = time()
	queue.insert(0, pushed)
	queue.pop(0)
	t2 = time()
	print(t2-t1)
```

Notiamo che stiamo usando `insert(0, pushed)` per inserire l'elemento `pushed` in cima alla coda, ed il metodo `pop(0)` per estrarre detto elemento.

Lo svantaggio principale di questo approccio sta nel fatto che le operazioni di `insert()` e di `pop()` possono essere rallentate dalla necessità di riallocare lo spazio occupato dagli elementi della lista.

Un altro modo è quello di usare una `deque`, definita nella libreria `collections`, ovvero una struttura Python progettata specificamente per "velocizzare" le operazioni di `append()` e `pop()` *da entrambi i capi* della struttura dati:

```python
from collections import deque

def queue_con_deque(queue, pushed=1):
	t1 = time()
	queue.append(pushed)
	queue.popleft()
	t2 = time()
	print(t2-t1)
```

Proviamo a chiamare le due funzioni (abbiamo già integrato nel corpo ciò che serve a cronometrarle):

```python
queue = list(range(1000000000))
queue_d = deque(queue)

queue_classica(queue)
queue_con_deque(queue_d)

>>> Tempo necessario con queue classica: 0.016004323959350586
>>> Tempo necessario con deque: 0.0
```

Notiamo quindi che l'uso di una lista classica richiede un tempo maggiore rispetto all'uso di una deque.

!!!note "Nota"
	E' importante notare che stiamo considerando soltanto le operazioni su coda. Qualora considerassimo anche il cast di tipo, potremmo avere risultati differenti; è per questo consigliabile usare una struttura di tipo deque soltanto qualora ci siano *numerose* operazioni di `push()` e `pop()` dalla coda.

## List comprehension

5.1.3. List Comprehensions
List comprehensions provide a concise way to create lists. Common applications are to make new lists where each element is the result of some operations applied to each member of another sequence or iterable, or to create a subsequence of those elements that satisfy a certain condition.

For example, assume we want to create a list of squares, like:

>>>
>>> squares = []
>>> for x in range(10):
...     squares.append(x**2)
...
>>> squares
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
Note that this creates (or overwrites) a variable named x that still exists after the loop completes. We can calculate the list of squares without any side effects using:

squares = list(map(lambda x: x**2, range(10)))
or, equivalently:

squares = [x**2 for x in range(10)]
which is more concise and readable.

A list comprehension consists of brackets containing an expression followed by a for clause, then zero or more for or if clauses. The result will be a new list resulting from evaluating the expression in the context of the for and if clauses which follow it. For example, this listcomp combines the elements of two lists if they are not equal:

>>>
>>> [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
and it’s equivalent to:

>>>
>>> combs = []
>>> for x in [1,2,3]:
...     for y in [3,1,4]:
...         if x != y:
...             combs.append((x, y))
...
>>> combs
[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
Note how the order of the for and if statements is the same in both these snippets.

If the expression is a tuple (e.g. the (x, y) in the previous example), it must be parenthesized.

>>>
>>> vec = [-4, -2, 0, 2, 4]

>>> # create a new list with the values doubled

>>> [x*2 for x in vec]
[-8, -4, 0, 4, 8]

>>> # filter the list to exclude negative numbers

>>> [x for x in vec if x >= 0]
[0, 2, 4]

>>> # apply a function to all the elements

>>> [abs(x) for x in vec]
[4, 2, 0, 2, 4]

>>> # call a method on each element

>>> freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
>>> [weapon.strip() for weapon in freshfruit]
['banana', 'loganberry', 'passion fruit']

>>> # create a list of 2-tuples like (number, square)

>>> [(x, x**2) for x in range(6)]
[(0, 0), (1, 1), (2, 4), (3, 9), (4, 16), (5, 25)]

>>> # the tuple must be parenthesized, otherwise an error is raised

>>> [x, x**2 for x in range(6)]
  File "<stdin>", line 1, in <module>
    [x, x**2 for x in range(6)]
               ^
SyntaxError: invalid syntax

>>> # flatten a list using a listcomp with two 'for'

>>> vec = [[1,2,3], [4,5,6], [7,8,9]]
>>> [num for elem in vec for num in elem]
[1, 2, 3, 4, 5, 6, 7, 8, 9]
List comprehensions can contain complex expressions and nested functions:

>>>
>>> from math import pi
>>> [str(round(pi, i)) for i in range(1, 6)]
['3.1', '3.14', '3.142', '3.1416', '3.14159']
5.1.4. Nested List Comprehensions
The initial expression in a list comprehension can be any arbitrary expression, including another list comprehension.

Consider the following example of a 3x4 matrix implemented as a list of 3 lists of length 4:

>>>
>>> matrix = [
...     [1, 2, 3, 4],
...     [5, 6, 7, 8],
...     [9, 10, 11, 12],
... ]
The following list comprehension will transpose rows and columns:

>>>
>>> [[row[i] for row in matrix] for i in range(4)]
[[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
As we saw in the previous section, the nested listcomp is evaluated in the context of the for that follows it, so this example is equivalent to:

>>>
>>> transposed = []
>>> for i in range(4):
...     transposed.append([row[i] for row in matrix])
...
>>> transposed
[[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
which, in turn, is the same as:

>>>
>>> transposed = []
>>> for i in range(4):
...     # the following 3 lines implement the nested listcomp
...     transposed_row = []
...     for row in matrix:
...         transposed_row.append(row[i])
...     transposed.append(transposed_row)
...
>>> transposed
[[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
In the real world, you should prefer built-in functions to complex flow statements. The zip() function would do a great job for this use case:

>>>
>>> list(zip(*matrix))
[(1, 5, 9), (2, 6, 10), (3, 7, 11), (4, 8, 12)]
See Unpacking Argument Lists for details on the asterisk in this line.

## Tuple

5.3. Tuples and Sequences
We saw that lists and strings have many common properties, such as indexing and slicing operations. They are two examples of sequence data types (see Sequence Types — list, tuple, range). Since Python is an evolving language, other sequence data types may be added. There is also another standard sequence data type: the tuple.

A tuple consists of a number of values separated by commas, for instance:

>>>
>>> t = 12345, 54321, 'hello!'
>>> t[0]
12345
>>> t
(12345, 54321, 'hello!')

>>> # Tuples may be nested

... u = t, (1, 2, 3, 4, 5)
>>> u
((12345, 54321, 'hello!'), (1, 2, 3, 4, 5))

>>> # Tuples are immutable

... t[0] = 88888
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment

>>> # but they can contain mutable objects

... v = ([1, 2, 3], [3, 2, 1])
>>> v
([1, 2, 3], [3, 2, 1])
As you see, on output tuples are always enclosed in parentheses, so that nested tuples are interpreted correctly; they may be input with or without surrounding parentheses, although often parentheses are necessary anyway (if the tuple is part of a larger expression). It is not possible to assign to the individual items of a tuple, however it is possible to create tuples which contain mutable objects, such as lists.

Though tuples may seem similar to lists, they are often used in different situations and for different purposes. Tuples are immutable, and usually contain a heterogeneous sequence of elements that are accessed via unpacking (see later in this section) or indexing (or even by attribute in the case of namedtuples). Lists are mutable, and their elements are usually homogeneous and are accessed by iterating over the list.

A special problem is the construction of tuples containing 0 or 1 items: the syntax has some extra quirks to accommodate these. Empty tuples are constructed by an empty pair of parentheses; a tuple with one item is constructed by following a value with a comma (it is not sufficient to enclose a single value in parentheses). Ugly, but effective. For example:

>>>
>>> empty = ()
>>> singleton = 'hello',    # <-- note trailing comma
>>> len(empty)
0
>>> len(singleton)
1
>>> singleton
('hello',)
The statement t = 12345, 54321, 'hello!' is an example of tuple packing: the values 12345, 54321 and 'hello!' are packed together in a tuple. The reverse operation is also possible:

>>>
>>> x, y, z = t
This is called, appropriately enough, sequence unpacking and works for any sequence on the right-hand side. Sequence unpacking requires that there are as many variables on the left side of the equals sign as there are elements in the sequence. Note that multiple assignment is really just a combination of tuple packing and sequence unpacking.

## Dizionari

5.5. Dictionaries
Another useful data type built into Python is the dictionary (see Mapping Types — dict). Dictionaries are sometimes found in other languages as “associative memories” or “associative arrays”. Unlike sequences, which are indexed by a range of numbers, dictionaries are indexed by keys, which can be any immutable type; strings and numbers can always be keys. Tuples can be used as keys if they contain only strings, numbers, or tuples; if a tuple contains any mutable object either directly or indirectly, it cannot be used as a key. You can’t use lists as keys, since lists can be modified in place using index assignments, slice assignments, or methods like append() and extend().

It is best to think of a dictionary as a set of key: value pairs, with the requirement that the keys are unique (within one dictionary). A pair of braces creates an empty dictionary: {}. Placing a comma-separated list of key:value pairs within the braces adds initial key:value pairs to the dictionary; this is also the way dictionaries are written on output.

The main operations on a dictionary are storing a value with some key and extracting the value given the key. It is also possible to delete a key:value pair with del. If you store using a key that is already in use, the old value associated with that key is forgotten. It is an error to extract a value using a non-existent key.

Performing list(d) on a dictionary returns a list of all the keys used in the dictionary, in insertion order (if you want it sorted, just use sorted(d) instead). To check whether a single key is in the dictionary, use the in keyword.

Here is a small example using a dictionary:

>>>
>>> tel = {'jack': 4098, 'sape': 4139}
>>> tel['guido'] = 4127
>>> tel
{'jack': 4098, 'sape': 4139, 'guido': 4127}
>>> tel['jack']
4098
>>> del tel['sape']
>>> tel['irv'] = 4127
>>> tel
{'jack': 4098, 'guido': 4127, 'irv': 4127}
>>> list(tel)
['jack', 'guido', 'irv']
>>> sorted(tel)
['guido', 'irv', 'jack']
>>> 'guido' in tel
True
>>> 'jack' not in tel
False
The dict() constructor builds dictionaries directly from sequences of key-value pairs:

>>>
>>> dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
{'sape': 4139, 'guido': 4127, 'jack': 4098}
In addition, dict comprehensions can be used to create dictionaries from arbitrary key and value expressions:

>>>
>>> {x: x**2 for x in (2, 4, 6)}
{2: 4, 4: 16, 6: 36}
When the keys are simple strings, it is sometimes easier to specify pairs using keyword arguments:

>>>
>>> dict(sape=4139, guido=4127, jack=4098)
{'sape': 4139, 'guido': 4127, 'jack': 4098}
