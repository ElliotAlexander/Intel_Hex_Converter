#include "FileManager.h"

FILE* load_File(char* input_file_name){
	FILE* fp;
	fp = fopen(input_file_name, "r+");

	if(fp){
		printf("File loaded successfully\n");
		parse_file_IHEX(fp);
		return fp;
	} else {
		printf("Error loading file! Exiting. \n");
		exit(1);
	}
	return NULL;
}


FILE* open_output(void){
	FILE* fp;
	fp = fopen(G_OUTPUT_FILE_NAME, "a+");
	if(fp){
		return fp;
	} else {
		printf("Error opening output file!\n");
		return NULL;
	}
}


