#include <stdio.h>
#include <string.h>
#define LENGTH 20
#define ARRAY_LENGTH 10

int main(void){
    //if statement or do while to stop entering after a four letter word
    // create pointer array for words
    // assign word to small_word until larger word 
    //keep comparing is length smaller then replace with new word 
    // assign the word to string_largest then if it is smaller reassign
    char ch, *word[ARRAY_LENGTH][LENGTH],smallest_word[LENGTH],largest_word[LENGTH];
    int length,j=0;

    while(1){
        printf("Enter words:");
        scanf("%s",word[j]);
        length = strlen(word[j]);
        
        if(length==4){
            break;
        }

        if(j==0){
            strcpy(smallest_word,word[j]);
            strcpy(largest_word,word[j]);
        }
        else{
             if(strlen(word[j])>strlen(largest_word)){
            strcpy(largest_word,word[j]);
        }
            if(strlen(word[j])<strlen(smallest_word)){
                strcpy(smallest_word,word[j]);
            }

        }

        j++;

    }
    printf("The smallest word is %s",smallest_word);
    printf("The largest word is %s",largest_word);

    return 0;
}