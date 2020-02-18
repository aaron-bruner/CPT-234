// mystery.c // Fall 2019// This program is the group assignment -we'll figure it out together!
#include <stdio.h>

int main(void) {

	int    points,         totalPoints         = 0;
	int    pointsPossible, totalPointsPossible = 0;
	double grade;

	printf("Enter the number of points possible on the first assignment\n");
	printf("or enter '-1' to quit: ");
	scanf("%d", &pointsPossible);

	while (pointsPossible != -1) {
		printf("Enter points correct of %d: ", pointsPossible);
		scanf("%d", &points);

			while (points < 0) {
				printf("You must enter a positive number:");
				scanf("%d", &points);
			}
				totalPoints         += points;
				totalPointsPossible += pointsPossible;
		printf("Enter points possible on next assignment or '-1': ");
		scanf("%d", &pointsPossible);}grade = 100.0 * totalPoints / totalPointsPossible;
		printf("The final grade is: %6.2f%%\n", grade);

	return 0;
}
