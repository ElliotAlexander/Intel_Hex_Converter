#include "FileManager.h"

FILE* open_input(char* input_file_name){
	FILE* fp;
	fp = fopen(input_file_name, "r");

	if(fp){
		printf("File loaded successfully\n");
		return fp;
	} else {
		printf("Error loading file! Exiting. \n");
		exit(1);
	}
}


FILE* open_output(void){

	FILE* fp;

	// Toggleable file mode.
	if(G_APPEND_FILE == 1){
		fp = fopen(G_OUTPUT_FILE_NAME, "a+");
	} else {
		fp = fopen(G_OUTPUT_FILE_NAME, "w+");
	}


	if(fp){
		return fp;
	} else {
		printf("Error opening output file!\n");
		return NULL;
	}
}





