#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LENGTH 100

int main(void){
    char message[LENGTH],ch,reverse[LENGTH];
    int i=0,j,n=0;
    bool result;


    printf("Please enter the message:");
    scanf("%s",&message);

    strcpy(reverse,message);

    strrev(reverse);

    result = strcmp(reverse,message);

    if(result!=0)
      printf("Not a palindrome");
    else
      printf("Palindrome.");

    return 0;
}
