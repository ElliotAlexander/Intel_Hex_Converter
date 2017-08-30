#include "Parser.h"


void parse_to_IHEX(FILE* input){
	char* next_line;
	next_line = fgets(next_line, 4096, input);
	int line_index = 0;
	int byte_count = 0;
	

	while(next_line != NULL){
		char* address = strtok(next_line, ",");
		char* ASCII_val = strtok(NULL, ",");
		char* ASCII_val_hex = convert_To_Hex(ASCII_val);
		byte_count += (strlen(ASCII_val) * 2);
	
		
		if(strlen(ASCII_val_hex) > (255*2)){
			printf("Error - exceeded maximum byte length (255)");
			printf("Line : \n	%s", ASCII_val_hex);
		}

		if(strlen(address) > 

		fprintf(input, ":%02X%s00%s", byte_count, address, ASCII_val_hex);
		line_index++;
		fgets(next_line, 4096, input);
	}

	fprintf(input, ":00000001FF");

}	
