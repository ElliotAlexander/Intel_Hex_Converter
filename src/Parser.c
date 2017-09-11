#include "Parser.h"

void parse_file_IHEX(FILE* input){
	char line[256];
	int byte_count = 0;

	while(fgets(line, sizeof(line), input)){
		char* address = strtok(line, "\t");
		char* ASCII_val = strtok(NULL, "\t");
		char* ASCII_val_hex = convert_To_Hex(ASCII_val);
		

		byte_count += 10;
		byte_count += (strlen(ASCII_val) * 2);
		if(strlen(ASCII_val_hex) > (255*2)){
			printf("Error - exceeded maximum byte length (255)");
			printf("Line : \n	%s", ASCII_val_hex);
		}

		fprintf(input, ":%02X%s00%s", byte_count, address, ASCII_val_hex);
	}
}	
