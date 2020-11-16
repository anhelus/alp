// pari
#include <stdbool.h>
#include <stdio.h>

bool numero_pari(int n) {
	if (n % 2 == 0) {
		return true;
	}
	return false;
}

int main() {
	int pari = 4;
	int dispari = 5;
	printf("Il valore di %d è pari? %d\n", pari, numero_pari(pari));
	printf("Il valore di %d è pari? %d\n", dispari, numero_pari(dispari));
}