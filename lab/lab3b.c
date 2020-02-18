#include <stdio.h>
#include <math.h>

int main (void)
{
	int nsides, radius;

	printf("How many sides are there: ");
	scanf("%i", &nsides);
	printf("What is the radius: ");
	scanf("%i", &radius);

	printf("Number of sides: %i\n", nsides);
	printf("Radius (in): %i\n", radius);

	float angleR = 2*M_PI/ nsides, angleD = 360/nsides;
	printf("\nAngle is %.2f radians (%.1f degrees)\n", angleR, angleD);

	float osides = sqrt(2*radius*radius-2*radius*radius*cos(angleR));
	printf("Side is %.2f inches\n", osides);

	float perimeter = nsides*osides, feet = perimeter/12;
	printf("Perimeter is %.2f inches or %.2f feet.\n", perimeter, feet);

	return 0;
}
