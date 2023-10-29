#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    
    if (argc == 1){
        printf("You did not provide a file. Exiting program.");
        return 0;
    }

    FILE *fptr;
    int c = 0;
    int word_count = 0;
    int is_word = 1;

    fptr = fopen(argv[1], "r");

    if (fptr == NULL){
        printf("Unable to open file. Exiting program.");
        return 0;
    }

    
    while ((c = fgetc(fptr)) != EOF)
    {
        if (!isspace((char)c) && is_word){
            word_count++;
            is_word = 0;
        }
        else if(isspace((char)c)){
            is_word = 1;
        }
    }
    
    printf("There are %d words in the file %s.", word_count, argv[1]);


    fclose(fptr);

}