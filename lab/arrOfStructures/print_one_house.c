#include <stdio.h>
#include "houses.h"

void print_one_house(struct house a) {

    printf(" %-6d%-10d%-7d%-15d%-10.4f%d\n", a.id, a.beds, a.baths, a.sqft, a.acres, a.price);

}
