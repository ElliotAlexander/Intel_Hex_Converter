#include "Main.h"

char* G_OUTPUT_FILE_NAME = "output.txt";
int G_APPEND_FILE = 0;
int G_terminate_file_bool = 0;

int file_input_bool = 0;
int file_output_bool = 0;
char* input_file;

int main(int argc, char** argv){
	
	printf("Arguments loaded: %d\n", argc-1);

	if(argc < 2 ){
		printf("Error loading arguments - No arguments found\n");
		return 1;
	} 

	for(int x = 1; x < argc; x++){
		if(argv[x][0] == '-'){
			char arg = argv[x][1];
			int argInt = arg;

			if(argInt > 97){
				argInt -= 32;
			}

			switch(argInt) {
				case 70: {			// -F argument.
					if(argv[x+1] != NULL && argv[x+1][0] != '-'){
						input_file = argv[x+1];
						file_input_bool = 1;
						printf("Loaded file: %s\n", input_file);
						x++;
					} else {
						// will print as ((null)) if not set.
						printf("Failed to parse input file name (%s)\n", argv[x+1]);
						return 1;
					}
					break;
				}

				case 79:
				{
					if(argv[x+1] != NULL){
						G_OUTPUT_FILE_NAME = argv[x+1];
						printf("Saving to file output with name %s.\n", G_OUTPUT_FILE_NAME);

					} else {
						file_output_bool = 1;
						printf("Saving to file output with default name %s.\n", G_OUTPUT_FILE_NAME);
					}
					break;
				}

				case 65:			// A - Append File
				{
					G_APPEND_FILE = 1;
					printf("Using output mode 'Append'\n");
					break;
				}

				case 84: 			// T - terminate file
				{	
					G_terminate_file_bool = 1;
					printf("Terminating file on completion.\n");
					break;
				}

				case 72: 
				{
					print_help();
				}
			}
		} else {
			printf("Unknown argument!\n");
		}
	}

	if(file_input_bool){
		FILE* fp = load_File(input_file);
		parse_file_IHEX(fp);
	}
}
