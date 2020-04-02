#include <stdio.h>
#include <math.h>

int processLED (int bulbNum);
int processLumens(int bulbNum, int numReadings);

int main () {

    int month, day, year, c, avg, j[5] = {0}, count = 0;
    scanf("%d%d%d", &month,&day,&year);
    printf("\nTest date: %d/%d/%d\nLED Lumens\n", month, day, year);


while (1) {
    avg = processLED(count);
    if (avg == -1)
    break;
    else {
    j[count] = avg;
    ++count;
    }
}

int highest_bulb, highest_bulb_reading;

highest_bulb_reading = j[0];
for (int k = 1; k < 5; k++) { 
    if (j[k] > highest_bulb_reading) {
        highest_bulb_reading = j[k];
        highest_bulb = k+1;
    }
}

    printf("\nLED bulb %d has the highest average reading of %d lumens", highest_bulb, highest_bulb_reading);
    printf("\n");

return 0;

}

int processLED (int bulbNum) {
int i, avg;

    scanf("%d", &i);

    if (feof(stdin))
    return -1;

    avg = processLumens(bulbNum, i);

    return avg;
}

int processLumens( int bulbNum, int numReadings) {

    printf("%3d", bulbNum+1);
    int n = numReadings;    
    int b[5];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%4d", b[i]);
    }
    int avg = 0;
    for (int i = 0; i < n; ++i) {
        avg = avg + b[i];
    }
    avg = rint(avg/n);
    
    printf(" Avg =%4d\n", avg);

    return avg;
}






