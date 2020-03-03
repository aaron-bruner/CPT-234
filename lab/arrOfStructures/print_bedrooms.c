#include <stdio.h>
#include "houses.h"

void print_bedrooms(struct house a[], int n, int beds) {

    int i;

    print_header();
    for (i = 0; i < n; ++i)
        if (a[i].beds >= beds)
            print_one_house(a[i]);

}
