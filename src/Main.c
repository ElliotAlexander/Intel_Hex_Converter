#include "Main.h"

char* G_OUTPUT_FILE_NAME = "output.txt";

int main(int argc, char** argv){
	
	printf("Arguments loaded: %d\n", argc-1);

	char* file_name;

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
						file_name = argv[x+1];
						printf("Loaded file: %s\n", file_name);
						x++;
					} else {
						// will print as ((null)) if not set.
						printf("Failed to parse input file name (%s)\n", argv[x+1]);
						return 1;
					}
					break;
				}
			}
		} else {
			printf("Unknown argument!\n");
		}
	}
	FILE* fp = load_File(file_name);
	parse_to_IHEX(fp);


}
