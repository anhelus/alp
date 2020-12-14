#include "ioutils.h"
#include <stdio.h>
#include <stdbool.h>

void swap(int vector[], int swap_l_idx, int swap_r_idx, int swap_val) {
	vector[swap_l_idx] = vector[swap_r_idx];
	vector[swap_r_idx] = swap_val;
}

void selection_sort(int vector[], int length) {
	for (int i = 0; i < length; i++) {
		int current = vector[i];
		int swap_index = i + 1;
		bool swapped = false;
		for (int j = i + 1; j < length; j++) {
			if (vector[j] < current) {
				current = vector[j];
				swap_index = j;
				swapped = true;
			}
		}
		if (swapped) {
			swap(vector, swap_index, i, current);
		}
		// Print just to be sure!
		printf("%d-th iteration: \n", i);
		print_array(vector, length);
	}
}
