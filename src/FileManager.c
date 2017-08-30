#include "FileManager.h"

FILE* load_File(char* input_file_name){
	FILE* fp;

	fp = fopen(input_file_name, "a+");
	if(fp != NULL){
		printf("File loaded successfully\n");
		return fp;
	} else {
		printf("Error loading file! Exiting. \n");
		exit(1);
	}
	return NULL;
}



