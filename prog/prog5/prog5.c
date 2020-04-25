/*
Program:     prog5
Description: Process and gather statistics on bulb readings
Author:      ?
Date:        ?
*/

#include <stdio.h>
#include <stdlib.h>

   // prototypes
   void loadBulbs(int *lum, const int max, char *filename, double *pct, int *n);
   void printBulbs(int *lum, int *n);
   int minReading(int *lum, int *n);
   int maxReading(int *lum, int *n);
   int averageReading(int *lum, int *n);
   int suspectCount(int *lum, int *n, int average, double *pct);
   void printEquals();

int main(int argc, char *argv[]) {

   if( argc != 2)
      printf("Usage: %s filename\n", argv[0]);

   // constants
   const int MAX_READINGS = 200;

   // variables
   //int readings[MAX_READINGS];
   
   int *readings = (int*)malloc(MAX_READINGS * sizeof(int));
   
   int *n = malloc(sizeof(int));
   int min, max, avg, suspect;
   double *pct = malloc(sizeof(int));

   // read percentage and readings and print readings
   loadBulbs(readings, MAX_READINGS, argv[1], pct, n);
   printBulbs(readings, n);

   // gather statistics
   min = minReading(readings, n);
   max = maxReading(readings, n);
   avg = averageReading(readings, n);
   suspect = suspectCount(readings, n, avg, pct);

   // print statistics
   printEquals();
   printf("Statistics\n");
   printEquals();
   printf("Minimum: %d\n", min);
   printf("Maximum: %d\n", max);
   printf("Range: %d\n", max-min);
   printf("Average: %d\n", avg);
   printf("Outside %.1f%%: %d = %.1f%%\n", pct, suspect, (suspect * 100.0) / (double)*n);
   printEquals();
   return 0;
}

void loadBulbs(int *lum, const int max, char *filename, double *pct, int *n) {
/*    Read bulb readings and place in array
      Exit if too many readings for array
      Parameters: lum - readings arrray
                  max - maximum elements in array
      Return:     Number of readings placed in array
*/
   FILE *fp;
   fp = fopen(filename, "r");
   if ( fp == NULL ) {
       printf("Could not open file\n");
       exit(1);
   }

   int i = 0, reading;


   fscanf(fp, "%lf", pct);

   // While able to read a reading
   while (!feof(fp)) {
      if (i >= max) {         // see if it will fit
         printf("\nMore than %d readings!\n\n", max);
         exit(1);
      }
      fscanf(fp, "%d", lum+i);
      i++;
      *n+=1;
   }               // return count
   fclose(fp);
   *n-=1;
}

void printBulbs(int *lum, int *n) {
/*    Print bulb readings 10 per line preceed by headings
      Parameters: lum - readings array
                  n - number of elements in arrray
*/

   // print headings
   printEquals();
   printf("%d Readings\n", *n);
   printEquals();

   // print readings
   for (int i = 0; i < *n; i++) {
      if (i % 10 == 0 && i != 0)
         printf("\n");
      printf("%3d ", lum[i]);
   }
   printf("\n");   
}

int minReading(int *lum, int *n) {
/*    Determine minimum reading
      Parameters: lum - readings array
                  n - number of elements in arrray
      Return:     Minimum reading
*/
   int min;

   min = lum[0];
   for (int i = 1; i < *n; i++, *lum++) {
      if (*lum < min)
         min = *lum;
   return min;
}

}

int maxReading(int *lum, int *n) {
/*    Determine maximum reading
      Parameters: lum - readings array
                  n - number of elements in arrray
      Return:     Maximum reading
*/
   int max;

   max = lum[0];
   for (int i = 1; i < *n; i++, *lum++)
      if (*lum > max)
         max = *lum;
   return max;
}

int averageReading(int *lum, int *n) {
/*    Determine average reading
      Parameters: lum - readings array
                  n - number of elements in arrray
      Return:     Average reading
*/
   int i, total = 0, avg = 0;

   for (i = 0; i < *n; i++)
      total += *lum++;
   avg = total / *n;
   return avg;
}

int suspectCount(int *lum, int *n, int average, double *pct) {
/*    Determine count of readings outside range
      Parameters: lum - readings array
                  n - number of elements in arrray
                  average - average reading
                  pct - percentage
      Return:     Minimum reading
*/
   int i, count = 0;
   float radius, lower, upper;

   // calculate limits of range
   //radius = average * (pct / 100.0);
   lower = average - radius;
   upper = average + radius;

   // count readings outside range
   for (i = 0; i < *n; i++) {
      if (*lum < lower || *lum > upper) {
         count++; }
   lum++;
   }

   return count;
}

void printEquals() {
/*    Print line of 40 ='s
*/
   int i;

   for (i = 0; i < 40; i++)
      printf("=");
   printf("\n");
}
