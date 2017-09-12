#include "Utils.h"


void print_help(void){
	printf("----------------------------------\n");
	printf("\n \t\t\tIntel_Hex_Converter.exe\n\n"
		"\n\n Flags:\n"
		"\t -F <input.file> \t An input file, formatted in rows of <address> [tab] <ascii text>\n"
		"\t -O <output.file> \t An output file. Saved as the format given in the file name.\n"
		"\t -T \t\t\t Terminate file. If added, an end file record will be added to the output file.\n"
		"\t -A \t\t\t Append file. If added, the output file will be opened in a+ (Append/Create) mode, rather than w+ (overwrite/create)\n"
		"\t -H \t\t\t Print help text. I'm sure you've figure that out by now.\n");


	printf("\n\n\nExample Usage: \n"
			"\t Intel_Hex_Converter.exe -F input.txt -O output.hex -A \n\n"
			"----------------------------------\n\n");
}
