#include <stdio.h>
#include "houses.h"

void print_lot(struct house a[], int n, float lot) {

    int i;

    print_header();
    for (i = 0; i < n; ++i)
        if (a[i].acres >= lot)
            print_one_house(a[i]);

}
