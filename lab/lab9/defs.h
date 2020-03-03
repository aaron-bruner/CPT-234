/* Aaron Bruner
   CPT-234-101
   Lab 9
*/
#ifndef defs_h
#define defs_h

#define arrSize 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initWithInput(int array[]);
void initWithRandom(int array[]);
int findSecondHighest(int array[]);
int findHighest(int array[]);
int findInnerProduct(int array1[], int array2[]);

#endif
