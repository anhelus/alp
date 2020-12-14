#include "ioutils.h"
#include "parsing.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))

int main() {
	// Select input type
	char input_mode = text_or_shell();
	char vector[128] = { '\0' };
	
	// Read array
	if (input_mode == 'f') {
		 read_file(vector);
	}
	else if (input_mode == 'r') {
		printf("Please enter array values:\t\t\t\t-> ");
		if (scanf("%s", vector) <= 0) {
			exit(EXIT_FAILURE);
		}
	}

	// Parse array
	char vector2[128];
	strstrp(vector, vector2, '[', ARRAY_SIZE(vector));
	strstrp(vector2, vector2, ']', ARRAY_SIZE(vector));
	strstrp(vector2, vector2, '{', ARRAY_SIZE(vector));
	strstrp(vector2, vector2, '}', ARRAY_SIZE(vector));
	int values[128];
	int idx = string_to_int_array(vector2, values);
	printf("Parsed array: \n");
	print_array(values, idx);
	
	// Selection sort
	selection_sort(values, idx);
	
	// Results
	printf("Sorted vector: \n");
	print_array(values, idx);

	printf("Do you want to save results on a text file?\n");
	save_to_file(values, idx);
}