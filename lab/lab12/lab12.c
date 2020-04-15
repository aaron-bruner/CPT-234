#include "defs.h"
#include <stdlib.h>

int main (int argc, char **argv) {

    FILE *fileIn = fopen(argv[1], "r");
    if (fileIn == NULL) {
        fprintf(stderr, "File open error. Exiting program\n");
        exit(1);
    }
    int n, i;
    
	fscanf(fileIn, "%d", &n);
	
	struct food *a;
	a=(struct food *)malloc(sizeof(struct food));
	if (a == NULL) {
	    fprintf(stderr, "Malloc failed to allocate memory . . . exiting program");
	    exit(1);
	}

	for (i=0; i<n; ++i) {
		fscanf(fileIn, "%s", &a[i].item);
		fscanf(fileIn, "%s", &a[i].quantity);
		fscanf(fileIn, "%d", &a[i].calories);
		fscanf(fileIn, "%f", &a[i].proteins);
		fscanf(fileIn, "%f", &a[i].carbs);
		fscanf(fileIn, "%f", &a[i].fats);
	}
    fclose(fileIn);
    printArray(n,a);

    return 0;
}
    
