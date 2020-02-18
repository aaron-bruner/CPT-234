/* Aaron Bruner
CPT-234-101
Lab 4 */

#include <stdio.h>

	int main(void){

	int usrint, n=1, usrcnt, n2, sum;

	fprintf(stdout, "Enter an integer: ");
	scanf("%i", &usrint);

		while(usrint <= 0) {
			printf("You must enter a positive number above zero: ");
			scanf("%i", &usrint);
		}
	fprintf(stdout, "%9s%12s\n", "Value", "Sum");

	for (usrcnt = 0;usrcnt < usrint; ++usrcnt) {

		sum = n*2-1;
		fprintf(stdout,"%9i%12i\n", n, sum);

		n2=n*2;
		n=n2;
	}

	return 0;

}
