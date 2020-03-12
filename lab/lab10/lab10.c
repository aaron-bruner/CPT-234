#include "defs.h"

int main (void) {

    int n, i;
    
	scanf("%d", &n);

	struct food a[n];

	for (i=0; i<n; ++i) {
		scanf("%s", &a[i].item);
		scanf("%s", &a[i].quantity);
		scanf("%d", &a[i].calories);
		scanf("%f", &a[i].proteins);
		scanf("%f", &a[i].carbs);
		scanf("%f", &a[i].fats);
	}

    printArray(n,a);

    return 0;
}
    
