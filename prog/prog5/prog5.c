/*
Program:     prog5
Description: Process and gather statistics on bulb readings
Author:      ?
Date:        ?
*/

#include <stdio.h>
#include <stdlib.h>

   // prototypes
   void loadBulbs(int *lum, int n, char *filename);
   void countBulbs(char *filename, double *pct, int *n);
   void printBulbs(int *lum, int n);
   int minReading(int *lum, int n);
   int maxReading(int *lum, int n);
   int averageReading(int *lum, int n);
   int suspectCount(int *lum, int n, int average, double pct);
   void printEquals();

int main(int argc, char *argv[]) {

   if( argc != 2) {
      printf("Usage: %s filename\n", argv[0]);
      exit(2);
   }

   // variables
   
   int n = 0;
   int min, max, avg, suspect;
   double pct;

   // read percentage and readings and print readings
   countBulbs(argv[1], &pct, &n);
   int *readings = (int*)malloc(n * sizeof(int));
   loadBulbs(readings, n, argv[1]);
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
   printf("Outside %.1f%%: %d = %.1f%%\n", pct, suspect, (suspect * 100.0) / n);
   printEquals();
   return 0;
}

void loadBulbs(int *lum, int n, char *filename) {

   FILE *fp;
   fp = fopen(filename, "r");
   if ( fp == NULL ) {
       printf("Could not open file\n");
       exit(2);
   }
    int test;
    double trash;
    fscanf(fp, "%lf", &trash);
    for (int i = 0; i < n; i++) {
      fscanf(fp, "%d", lum+i);
      }
   fclose(fp);
   
}

void countBulbs(char *filename, double *pct, int *n) {

   FILE *fp;
   fp = fopen(filename, "r");
   if ( fp == NULL ) {
       printf("Could not open file\n");
       exit(2);
   }
   
   fscanf(fp, "%lf", pct);
   
   *n = 0;
    int test;
   while ( fscanf(fp, "%d", &test) == 1) {
      *n+=1;
   }
   fclose(fp);
}

void printBulbs(int *lum, int n) {

   // print headings
   printEquals();
   printf("%d Readings\n", n);
   printEquals();

   // print readings
   for (int i = 0; i < n; i++) {
      if (i % 10 == 0 && i != 0)
         printf("\n");
      printf("%3d ", *lum++);
   }
   printf("\n");   
}

int minReading(int *lum, int n) {

   int min = *lum;
   
   for (int i = 1; i < n; i++) {
      if (*(lum+i) < min)
         min = *(lum+i);
   }
   return min;
}

int maxReading(int *lum, int n) {

   int max = *lum;

   for (int i = 1; i < n; i++)
      if (*(lum+i) > max)
         max = *(lum+i);
   return max;
}

int averageReading(int *lum, int n) {

   int i, total = 0, avg = 0;

   for (i = 0; i < n; i++)
      total += *(lum+i);
   avg = total / n;
   return avg;
}

int suspectCount(int *lum, int n, int average, double pct) {

   int i, count = 0;
   float radius, lower, upper;

   // calculate limits of range
   radius = average * (pct / 100.0);
   lower = average - radius;
   upper = average + radius;

   // count readings outside range
   for (i = 0; i < n; i++) {
      if (*(lum+i) < lower || *(lum+i) > upper) {
         count++; }
   *(lum+i);
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
