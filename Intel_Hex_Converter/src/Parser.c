#include "Parser.h"

void parse_file_IHEX(FILE* input){
	char line[256];
	int byte_count = 0;
	FILE* output = open_output();

	while(fgets(line, sizeof(line), input)){
		if(line[0] == ';'){
			continue;
		}

		// Parse values from columns of each line.
		char* address = strtok(line, "\t");
		char* ASCII_val = strtok(NULL, "\t");
		char* ASCII_val_hex = convert_To_Hex(ASCII_val);

		byte_count = strlen(ASCII_val_hex) / 2;		
		int x = 2+strlen(ASCII_val_hex)+strlen(address)+1;
		char print_str[x];
		sprintf(print_str, ":%02X%s00%s", byte_count, address, ASCII_val_hex);



		// DEBUG		- Example given on the IntelHex wiki page :)
		// Useful for checking my maths 
		//int x = 14;
		//char print_str[] = ":0300300002337A";


		unsigned int sum = 0;

		// Ignore the colon, iterate from index 1 -> x+1
		for(int i = 1; i < (x+1);){
			char* next_hex = malloc(sizeof(char) * 2);
			strncpy(next_hex, (print_str + i), 2);
			sum += strtol(next_hex, NULL, 16);
			i += 2;
		}

		// Twos complement + bitmask.
		unsigned int checksum = ((~sum)+1) & 0x000000FF;

		// Print final string.
		fprintf(output, ":%02X%s00%s%02X\n", byte_count, address, ASCII_val_hex, checksum);
	}

	if(G_terminate_file_bool==1){
		fprintf(output, ":00000001FF");	
	}
}	


