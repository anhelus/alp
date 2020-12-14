#include "parsing.h"
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void strstrp(char* str_in, char* str_out, char strp, int length) {
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (str_in[i] != strp) {
			str_out[j] = str_in[i];
			j++;
		}
	}
}

int string_to_int_array(char* string, int* buffer) {
	char* number = strtok(string, ",");
	int numbers = 0;
	while (number != NULL) {
		buffer[numbers] = atoi(number);
		numbers++;
		number = strtok(NULL, ",");
	}
	return numbers;
}
