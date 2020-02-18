#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){

	int counter;

	srand((int)time(0));

	int array1[21];

	for ( counter = 1; counter <= 20; counter++) {
		printf("Enter an integer: ");
		scanf("%d", &array1[counter]);
	}

	printf("%d ", array1);
	return 0;
}
