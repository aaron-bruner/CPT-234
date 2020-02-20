// Aaron Bruner
// CPT-234
// Lab 6 - broken.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0;
    int table[10];
    int count = 0;
    int search = 1;
	int number = 5;   

	table[0] = 5;

	count = 1;
    while (count < 10) {
		 table[count] = number++ * 2;
       count++;
    }

    while (search == 1) {
        if ((table[i++] == 11) || (count < i)) {
           search = 0;
        } 
    }

    if (i > count) {
       printf("The number 11 is not in the table.\n");
    }
    else {
       printf("The number 11 is in the table at location: %d\n", i-1);
    }

    return 0;
}
