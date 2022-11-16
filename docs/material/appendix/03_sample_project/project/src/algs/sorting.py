
from abc import ABC, abstractmethod
from typing import Any, List


class BaseSort(ABC):
    """ Classe base per l'ordinamento.

    Argomenti:
        ar: Una lista che contiene i valori da ordinare. 
    """

    @staticmethod
    def check_numeric(val: Any) -> bool:
        """ Controlla se un valore è numerico.

        Argomenti:
            val: il valore da analizzare.

        Restituisce:
            True se val è numerico, False altrimenti.
        """
        return False or (type(val) == int or type(val) == float)

    def __init__(self, ar: List) -> None:
        self.ar = ar	

    @property
    def ar(self):
        """ L'array da ordinare.

        Lancia:
            ValueError se l'array passato è vuoto.
            ValueError se l'array contiene valori non numerici.
        """
        return self.__ar
    
    @ar.setter
    def ar(self, value) -> List:
        if not len(value) > 0:
            raise ValueError("Error: array cannot be empty.")
        if not all([BaseSort.check_numeric(v) for v in value]):
            raise ValueError("Error: array cannot contain non-numeric elements.")
        self.__ar = value

    @abstractmethod
    def sort(self, inplace: bool=True) -> List:
        """ Ordina un array di valori numerici.

        Argomenti:
            inplace: booleano che indica se l'ordinamento
                deve essere effettuato sulla variabile stessa.
        
        Restituisce:
            Una lista di elementi ordinati se `inplace` è False,
            altrimenti niente, in quanto l'ordinamento è effettuato
            su ar.
        """
        pass


class SelectionSort(BaseSort):
    """ Classe derivata che implementa il selection sort.
    """

    @staticmethod
    def _compare_sort(l_ar: List, r_ar: List) -> None:
        """ Metodo per la comparazione e l'ordinamento.

        Ad ogni iterazione, confronta l'i-mo valore di
        r_ar con l'ultimo di l_ar, e li cambia di posto
        se il primo è inferiore al secondo.
        """
        while len(r_ar) > 0:
            l_ar += [r_ar.pop(0)]
            for i in range(len(r_ar)):
                if r_ar[i] < l_ar[-1]:
                    l_ar[-1], r_ar[i] = r_ar[i], l_ar[-1]

    def sort(self, inplace=True):
        l_ar = []
        if not inplace:
            aux_ar = self.ar[:]
        SelectionSort._compare_sort(l_ar, self.ar)
        if not inplace:
            self.ar = aux_ar
            return l_ar
        self.ar = l_ar
        return
