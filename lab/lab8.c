#define arrSize 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initWithInput(int array1[]);
void initWithRandom(int array1[]);
int findSecondHighest(int array1[]);
int findHighest(int array1[]);
int findInnerProduct(int array1[], int array2[]);

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

/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the highest number in the array specified                              */
/* inputs:  the name of the array wanting to be sorted                                             */
/* outputs:  the max of the array specified                                                        */
/* ----------------------------------------------------------------------------------------------- */
int findHighest(int array[]) {

    int i, max, smax;
	max = array[0];
	smax = array[0];

	for (i = 0; i < arrSize; i++) {
		if (array[i] > max) {
			smax = max;
			max = array[i];
		}
	}
	return max;
}

/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the second highest number in the array specified                       */
/* inputs:  the name of the array wanting to be sorted                                             */
/* outputs:  the second max of the array specified                                                 */
/* ----------------------------------------------------------------------------------------------- */
int findSecondHighest(int array[]) {

    int i, max, smax;
	max = findHighest(array);
	smax = array[0];

	for (i = 0; i < arrSize; i++) {
        if (array[i] > smax && array[i] < max)
			smax = array[i];
	}
	return smax;
}

/* ----------------------------------------------------------------------------------------------- */
/* description:  calculates the inner product of the two arrays specified                          */
/* inputs:  two arrays                                                                             */
/* outputs:  the result of the inner product calculation                                           */
/* ----------------------------------------------------------------------------------------------- */
int findInnerProduct(int array1[], int array2[]) {

    int i, product = 0;
	for (i = 0; i < arrSize; i++) {
		product = product + array1[i] * array2[i];
	}
	return product;
}

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
