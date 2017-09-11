#include "IHEX.h"

void end_IHEX_file(FILE* input){
	fprintf(input, ":00000001FF");
}
