#include "HexConverter.h"
#include <String.h>


char* convert_To_Hex(char* input_string){

	if(input_string == NULL){
		printf("ERROR - Null String (HexConverter.c)\n");
		return NULL;
	}

	int input_len = strlen(input_string);

	char* output_char;
	output_char = (char*) malloc(input_len * 2 * sizeof(char));

	for(int i = 0; i < input_len ; i++){
		sprintf(output_char + (i*2), "%02X", input_string[i]);
	}	

	return output_char;
}
