#include "defs.h"
/* ----------------------------------------------------------------------------------------------- */
/* description:  asks the user to input twenty integers then stores them into the array specified. */
/* inputs:  the name of the array                                                                  */
/* outputs:  there is no output (void)                                                             */
/* ----------------------------------------------------------------------------------------------- */
void initWithInput(int array[]) {

    int i;
	printf("Enter 20 integers: \n");
	printf("\n");
	printf("array1:\n");

	for (i = 0; i < arrSize; ++i) {
		scanf("%d", &(array[i]));
	}
}

/* ----------------------------------------------------------------------------------------------- */
/* description:  creates twenty random integers between 1 and 50                                   */
/* inputs:  the name of the array                                                                  */
/* outputs:  there is no output (void)                                                             */
/* ----------------------------------------------------------------------------------------------- */
void initWithRandom(int array[]) {

    int i;
	printf("\n");
	printf("array2:\n");
	for (i = 0; i < arrSize; ++i) {
		array[i] = rand() % 50 + 1;
	}
	for (i = 0; i < arrSize; i++) {
	printf("%d\n", array[i]);
	}

}
