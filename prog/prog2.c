/*Aaron Bruner
CPT-234-101
Assignment 2
*/

#include <stdio.h>

int main (void){

	//CONVERSION RATES
	double GBP = 1.6329, CAD = 0.9190, CLP = 0.0017, DKK = 0.1739, EUR = 1.2953, RUB = 0.0271;
	double GBP_input,CAD_input,CLP_input,DKK_input,EUR_input,RUB_input, output;
	int input = 1, counter = 0;

	// Initial input prompt
	while (input != 0) {
	
	printf("Enter country code, zero to end: ");
	scanf("%i",&input);

	if (input == 0) {
		fprintf(stdout, "\n%i conversions done.\n", counter);
		return 0;
	}
	else {		// Ensures that the user's input is between 1 and 6
		while (input != 1 && input != 2 && input != 3 && input != 4 && input !=5 && input != 6) {
			printf("%i is an invalid country code!\n", input);
			printf("Enter country code, zero to end: ");
			scanf("%i", &input);
				if (input == 0) {
					fprintf(stdout, "\n%i conversions done.\n", counter);
					return 0;
				}
		}	
	}
		//		Switch function to determine currency amount then equivalence in USD
	switch (input) {
		case 1:
			printf("Enter GBP: ");
			scanf("%lf", &GBP_input);
			output = GBP_input * GBP;
			printf("%.2lf GBP = %.2lf USD\n\n", GBP_input, output);
			counter++;
			break;
		case 2:
			printf("Enter CAD: ");
			scanf("%lf", &CAD_input);
			output = CAD_input * CAD;
			printf("%.2lf CAD = %.2lf USD\n\n", CAD_input, output);
			counter++;
			break;
		case 3:
			printf("Enter CLP: ");
			scanf("%lf", &CLP_input);
			output = CLP_input * CLP;
			printf("%.2lf CLP = %.2lf USD\n\n", CLP_input, output);
			counter++;
			break;
		case 4:
			printf("Enter DKK: ");
			scanf("%lf", &DKK_input);
			output = DKK_input * DKK;
			printf("%.2lf DKK = %.2lf USD\n\n", DKK_input, output);
			counter++;
			break;
		case 5:
			printf("Enter EUR: ");
			scanf("%lf", &EUR_input);
			output = EUR_input * EUR;
			printf("%.2lf EUR = %.2lf USD\n\n", EUR_input, output);
			counter++;
			break;
		case 6:
			printf("Enter RUB: ");
			scanf("%lf", &RUB_input);
			output = RUB_input * RUB;
			printf("%.2lf RUB = %.2lf USD\n\n", RUB_input, output);
			counter++;
			break;
		default:
			break;
		}

	}
 

	return 0;
}
