# I/O in Python

## Input ed output da riga di comando

### Input da riga di comando

```python
>>> a = input('Insert a value: ')
Insert a value: 12
>>> a
'12'
>>> l = input('Insert a value: ')
Insert a value: ['Fox', 'Mulder']
>>> l
"['Fox', 'Mulder']"
```

### Output su riga di comando

```python
>>> print(a)
12
>>> print('Jax Teller')
Jax Teller
>>> print('{} {}'.format('Hermione', 'Granger'))
Hermione Granger
```

## File

### Lettura

```python
with open(file_name, 'r') as f:
	f.read()
```

!!!note "Nota"
	Il metodo `read()` accetta come parametro il numero di caratteri da leggere. Di default, legge l'intero file; per leggere un carattere alla volta, specificare il valore `-1`.

!!!note "Lettura riga per riga"
	Per leggere riga per riga, usare il metodo `readlines()`.

### Scrittura

```python
with open(file_name, 'w') as f:
	f.write('some line')
```

!!!note "Nota"
	Il metodo `write()` può essere sostituito dal metodo `writelines()` per scrivere una riga alla volta.

Ricordiamoci sempre di chiudere il file:

```python
f.close()
```
