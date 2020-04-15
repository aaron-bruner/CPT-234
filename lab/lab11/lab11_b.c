#include <stdio.h>
#include <stdlib.h>

void my_strcpy(char dest[], const char src[]);

int main () {

char *str1; char *str2;
int charPointer;

printf("What is the longest length of a string that you will enter? ");
scanf("%d", &charPointer);

str1 = malloc(charPointer * sizeof(char));

if (str1 == NULL) {
    printf("malloc failed to allocate enough memory!\n");
    return 1;
    }


printf("Enter a string: ");
scanf("%s", str1);

my_strcpy(str2, str1);
const char *youEntered = {"You entered:"};
my_strcpy(str1, youEntered);

printf("%s %s\n", str1, str2);
return 0;

}

void my_strcpy(char *dest,const char *src) {

    int i;
    for (i = 0; src[i] != '\0'; ++i) { 
        dest[i] = src[i]; 
    } 
  
    dest[i] = '\0'; 
}
