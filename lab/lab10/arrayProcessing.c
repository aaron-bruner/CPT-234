#include "defs.h"

void printArray(int n, struct food a[]) {
    int i;

        printf("%-29s%-10s%-9s%-4s%-8s%s\n","FOOD ITEM","QUANTITY","CALS","PRO","CARBS","FAT");
    for (i=0; i<n; ++i)
        printf("%d. %-27s%8s%5d%8.2f%6.2f%6.2f\n",i+1, a[i].item, a[i].quantity, a[i].calories, a[i].proteins, a[i].carbs, a[i].fats);

    return;

}
