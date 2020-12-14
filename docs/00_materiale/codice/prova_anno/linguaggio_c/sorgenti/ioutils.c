#include "ioutils.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void read_file(char* string) {
	char file_name[128] = { '\0' };
	printf("Please enter file name:\t\t\t\t\t-> ");
	if (scanf("%s", file_name) <= 0) {
		printf("Error while scanning file name. Returning...");
		exit(EXIT_FAILURE);
	}
	if (file_name != NULL)
	{
		FILE* fp;
		if ((fp = fopen(file_name, "r")) == NULL) {
			printf("Unable to read file. Returning...");
			exit(EXIT_FAILURE);
		}
		if (fscanf(fp, "%s", string) <= 0)
			exit(EXIT_FAILURE);
	}
}


void print_array(int array[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

char text_or_shell() {
	char input_mode = '\0';
	while (1) {
		printf("Enter 'f' to use a text file, or 'r' to use shell.\t-> ");
		if (scanf(" %c", &input_mode) <= 0) {
			printf("Parsing error. Returning...");
			exit(EXIT_FAILURE);
		}
		if (input_mode == 'f' || input_mode == 'r') {
			return input_mode;
		}
	}
}

void save_to_file(int array[], int length) {
	printf("Enter a valid file name:\t\t\t\t -> ");
	char file_name[128] = { '\0' };
	if (scanf("%s", file_name) <= 0)
		exit(1);
	FILE* fp;
	if ((fp = fopen(file_name, "w")) == NULL) {
		printf("Error while creating the new file...");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "[%d", array[0]);
	for (int i = 1; i < length; i++) {
		fprintf(fp, ", %d", array[i]);
	}
	fprintf(fp, "]");
}
