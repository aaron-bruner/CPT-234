#include <stdio.h>
#include <stdlib.h>

int testing(int *test, const int max);

int main (void) {


const int max = 5;
int *test;
int howmany;

test = (int*)malloc(sizeof(int)*max);

howmany = testing(test, max);

printf("%d\n", test[0]);
printf("%d\n", test[1]);
printf("%d\n", test[2]);
printf("%d\n", test[3]);
printf("%d\n", test[4]);

return 0;

}


int testing(int *test, const int max)  {

test[0] = 2;
test[1] = 4;
test[2] = 6;
test[3] = 8;
test[4] = 10;

int howmany = 30;


return howmany;

}
