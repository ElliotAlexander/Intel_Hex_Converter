#include "FileManager.h"

FILE* load_File(char* input_file_name){
	FILE* fp;
	fp = fopen(input_file_name, "w+");

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



