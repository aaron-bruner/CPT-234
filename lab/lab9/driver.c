#include "defs.h"

int main(void) {

	srand((int)time(0));

	int array1[arrSize], array2[arrSize];
	
	initWithInput(array1);
	printf("... initializing array2 ...\n");
	initWithRandom(array2);
	
	printf("second highest from array1 is: %d\n", findSecondHighest(array1));
	printf("second highest from array1 is: %d\n", findSecondHighest(array2));
    printf("\n");
	printf("inner product is: %d\n", findInnerProduct(array1, array2));

	return 0;
}
