#include "Parser.h"

void parse_file_IHEX(FILE* input){
	char* next_line = malloc(sizeof(char) * 4096);
	int line_index = 0;
	int byte_count = 0;
	
	while((fgets (next_line, 60, input) != NULL)){

		char* address = strtok(next_line, "\t");
		char* ASCII_val = strtok(NULL, "\t");
		char* ASCII_val_hex = convert_To_Hex(ASCII_val);
	


		byte_count += (strlen(ASCII_val) * 2);
		if(strlen(ASCII_val_hex) > (255*2)){
			printf("Error - exceeded maximum byte length (255)");
			printf("Line : \n	%s", ASCII_val_hex);
		}

		fprintf(input, ":%02X%s00%s", byte_count, address, ASCII_val_hex);


		line_index++;

		printf("1\n");
	}
}	
