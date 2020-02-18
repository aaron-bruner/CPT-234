#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	srand((int)time(0));

	int array1[20], array2[20], max1, smax1, max2, smax2;
	int i, innerprod = 0;

	printf("Enter 20 integers: \n");
	printf("\n");
	printf("array1:\n");

	for (i = 0; i < 20; ++i) {
		scanf("%d", &(array1[i]));
	}

	printf("\n");
	printf("array2:\n");
	for (i = 0; i < 20; ++i) {
		array2[i] = rand() % 50 + 1;
	}
	for (i = 0; i < 20; i++) {
	printf("%d\n", array2[i]);
	}
	max1 = array1[0];
	smax1 = array1[0];
	max2 = array2[0];
	smax2 = array2[0];

	for (i = 0; i < 20; i++) {
		if (array1[i] > max1) {
			smax1 = max1;
			max1 = array1[i];
		}
		else if (array1[i] > smax1 && array1[i] < max1)
			smax1 = array1[i];

		if (array2[i] > max2) {
			smax2 = max2;
			max2 = array2[i];
		}

		else if (array2[i] > smax2 && array2[i] < max2)
			smax2 = array2[i];
	}
	for (i = 0; i <= 19; i++) {
		innerprod = innerprod + array1[i] * array2[i];
	}
	printf("second highest from array1 is: %d\n", smax1);
	printf("second highest from array1 is: %d\n", smax2);
	printf("\n");
	printf("inner product is: %d\n", innerprod);

	return 0;
}
