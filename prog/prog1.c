/*Aaron Bruner
CPT-234-101
Assignment 1
*/

#include <stdio.h>

int main (void){

	int gfat, gprot, gcarb, galc, cfat, cprot, ccarb, calc, ctotal;
	float fatp, protp, carbp, alcp, totalp;

	// Asking the user for grams of each ingredient
	printf("Enter fat grams: ");
	scanf("%i",&gfat);

	printf("Enter protein grams: ");
	scanf("%i",&gprot);

	printf("Enter carbohydrate grams: ");
	scanf("%i",&gcarb);

	printf("Enter alcohol grams: ");
	scanf("%i",&galc);

	// Calculating the numbers for the chart
	cfat = gfat * 9; cprot = gprot * 4; ccarb = gcarb * 4; calc = galc * 7;
	ctotal = cfat + cprot + ccarb + calc;

	fatp =(float) cfat / ctotal * 100;
	protp =(float) cprot / ctotal * 100;
	carbp =(float) ccarb / ctotal * 100;
	alcp =(float) calc / ctotal * 100;
	totalp = fatp + protp + carbp + alcp;

	// Creating the chart using printf
	printf("\n              Grams Calories Percent\n");
	printf("Fat              %2i      %3i    %.1f\n", gfat, cfat, fatp);
	printf("Protein          %2i      %3i     %.1f\n", gprot, cprot, protp);
	printf("Carbohydrates    %2i      %3i    %.1f\n", gcarb, ccarb, carbp);
	printf("Alcohol          %2i      %3i     %.1f\n\n", galc, calc, alcp);	
	printf("TOTAL                    %3i   %.1f\n", ctotal, totalp);

	return 0;
}
