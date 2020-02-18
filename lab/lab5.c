/* Aaron Bruner
   Lab 5
   CPT-234-101 */

#include<stdio.h>

int main(void){

	char character, upper, lower, again = '1';

	// Checking the user's input and determining what the best result is.
	while ( again == '1' ) {

		fprintf(stdout, "Enter a letter or number from the keyboard. ");
		scanf(" %c", &character);

		// Calculations
		upper = character - 32;
		lower = character + 32;

		// If a lowercase character is provided the uppercase is returned.
		if ( character >= 'a' && character <= 'z'  )
			fprintf(stdout,"The uppercase of that letter is: %c.\n", upper);

		// If an uppercase character is provided the lowercase is returned.
		else if ( character >= 'A' && character <= 'Z' )
			fprintf(stdout, "The lowercase of that letter is: %c.\n", lower);

		// If a number between 0 and 9 is entered then odd or even is displayed.
		else if ( character >= '0' && character <= '9' ) {
			if ( character % 2 == 0 )
			fprintf(stdout, "You entered an even number.\n");
			else
			fprintf(stdout, "You entered an odd number.\n");
		}
		else
		fprintf(stdout, "You've entered an invalid character.\n");

		// Asking user if they'd like to check another character
		fprintf(stdout, "Would you like to go again? Enter 1 for yes, 0 for no. ");
		scanf(" %c", &again);

		while ( again != '0' && again != '1' ){
			fprintf(stdout, "Invalid input. Enter a 1 to go again, or a 0 to quit: ");
			scanf(" %c", &again);

		}
	}

	return 0;

}
