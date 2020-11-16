// quadrato
#include <stdio.h>

int quadrato(int n) {
	return n * n;
}

int main() {
	int a = 3;
	printf("Il quadrato di %d è %d\n", a, quadrato(a));
}