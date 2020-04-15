#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int loadBulbs (int *bulbReadings, const int maxReadings);
void printBulbs (int *bulbReadings, int numReadings);
int minReading (int *bulbReadings, int numReadings);
int maxReading (int *bulbReadings, int numReadings);
int averageReading (int *bulbReadings, int numReadings);
int suspectCount (int *bulbReadings, int numReadings, int averageReading, double percentFactor);

int main (void) {

    const int maxReadings = 200;
    int *bulbReadings;
    double percentFactor;

    scanf("%lf", &percentFactor);
    
    bulbReadings = (int*)malloc(sizeof(int)*maxReadings);

    int numReadings;
    
    numReadings = loadBulbs(bulbReadings, maxReadings);
    if (numReadings == -1) {
        exit(1);
    }
    printBulbs(bulbReadings, numReadings);
    printf("\n========================================\n");
    printf("Statistics\n");    
    printf("========================================\n");
    printf("Minimum: %d\n", minReading(bulbReadings, numReadings));
    printf("Maximum: %d\n", maxReading(bulbReadings, numReadings));
    printf("Range: %d\n", maxReading(bulbReadings, numReadings)-minReading(bulbReadings, numReadings)); 
    printf("Average: %d\n", averageReading(bulbReadings, numReadings));
    int aver = averageReading(bulbReadings, numReadings);
    int suspectCounter = suspectCount(bulbReadings, numReadings, aver, percentFactor);
    double outsidePercentage = fabs(((float)numReadings - suspectCounter)/(float)numReadings-1)*100;
    printf("Outside: %.1lf%: %d = %.1lf%\n", percentFactor, suspectCounter, outsidePercentage);
    printf("========================================\n");

return 0;

}

int loadBulbs(int *bulbReadings, const int maxReadings) {


    int numReadings = 0;


    while (!feof(stdin) && numReadings < maxReadings) {
    
    scanf("%d", &bulbReadings[numReadings]);
    numReadings++;    
    }
    numReadings++;
    if (numReadings > maxReadings) {
        printf("Error there were more readings than expected...\n");
        return -1;
    }
    else
    numReadings--;

return numReadings-1;
}

void printBulbs (int *bulbReadings, int numReadings) {

    printf("========================================\n");
    printf("%d Readings\n", numReadings);
    printf("========================================\n");
    for (int i = 0; i < numReadings; ++i) {
        if (i==10||i==20||i==30||i==40||i==50||i==60||i==70||i==80||i==90||i==100){
        printf("\n");
        }
        printf("%d ", bulbReadings[i]);
    } 

}

int minReading( int *bulbReadings, int numReadings) {

    int min = bulbReadings[0];
    
    for (int i = 1; i < numReadings; i++) {
        if (bulbReadings[i] < min)
            min = bulbReadings[i];
    }
    return min;

}

int maxReading(int *bulbReadings, int numReadings) {

    int max;
    
    max = bulbReadings[0];
    for(int i = 1; i < numReadings; i++) {
        if ( bulbReadings[i] > max )
            max = bulbReadings[i];
    }
    
    return max;
}

int averageReading(int *bulbReadings, int numReadings) {

    int sum = 0, average;
    
    for (int i = 0; i < numReadings; ++i) {
        sum += bulbReadings[i];
    }

    average = sum / numReadings;
    
    return average;

}

int suspectCount (int *bulbReadings, int numReadings, int averageReading, double percentFactor) {

    double dMinLimit, dMaxLimit;
    int iMinLimit, iMaxLimit, outsideReadings = 0;
    
    dMinLimit = averageReading - (averageReading * percentFactor / 100);
    dMaxLimit = averageReading + (averageReading * percentFactor / 100);

    iMinLimit = (int)dMinLimit; iMaxLimit = (int)dMaxLimit;
    
    for (int i=0; i<numReadings; ++i) {
        if (bulbReadings[i] > iMaxLimit || bulbReadings[i] < iMinLimit)
            outsideReadings++;
    }

    return outsideReadings;

}

