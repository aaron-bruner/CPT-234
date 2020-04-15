#include <stdio.h>

void my_strcpy(char dest[], const char src[]);

int main () {

char str1[31]; char str2[31];

printf("Enter a string of length at most 30: ");
scanf("%s", str1);

my_strcpy(str2, str1);
const char youEntered[31] = {"You entered:"};
my_strcpy(str1, youEntered);
printf("%s %s\n", str1, str2);
return 0;

}

void my_strcpy(char dest[],const char src[]) {

    int i;
    for (i = 0; src[i] != '\0'; ++i) { 
        dest[i] = src[i]; 
    } 
  
    dest[i] = '\0'; 
}
