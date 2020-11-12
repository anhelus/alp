Immaginiamo di scrivere il nostro main come segue.

```c
#include <stdio.h>
#include <math.h>

int calcola_ipotenusa(int c_1, int c_2) {
	int i = c_1*c_1 + c_2 * c_2;
	return sqrt(i);
}

int main() {
	int i = calcola_ipotenusa(3, 4);
	printf("Ipotenusa: %d", i);
	return 0;
}
```