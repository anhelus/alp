#ifndef PARSING_H
#define PARSING_H

// Remove strp character from a str_in string
void strstrp(char* str_in, char* str_out, char strp, int length);
// Convert a string into an integer array
int string_to_int_array(char* string, int* buffer);

#endif // !PARSING_H
