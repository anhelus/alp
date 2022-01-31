# Cenni ai test

I test vanno effettuati a livello di ogni singola funzione, per verificarne il funzionamento (*unit test*), oppure a livello dell'intero programma, per verificare le funzionalità complessivi (*integration test*).

I test inoltre non devono essere *invasivi*: se, ad esempio, creiamo un file durante i nostri test, dobbiamo assicurarci di cancellarlo al termine.

## Istruzione `assert`

L'istruzione `assert` restituisce `True` se la condizione passata è verificata, `False` altrimenti. Se `assert` è `True`, inoltre, l'esecuzione prosegue:

```python
>>> assert True			# nothing happens...
```

mentre se è `False`, viene lanciata un'eccezione di tipo `AssertionError`:

```python
>>> assert False
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AssertionError
>>>
```
