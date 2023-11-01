#include <stdio.h>
#include <stdlib.h>

//Chose to do the option where the user is prompted. Error checking for negative numbers.
//Accepts letter and words because they are just represented as numbers.
int main(){

    unsigned int num;
    do{
    printf("Please enter an unsigned base-10 number less than or equal to 4,294,967,295:\n");
    scanf("%u", &num);
    } while (num < 0);
    
    int index = 31;
    char binary[32];

    for (int i = 0; i < 32; i++) {
        binary[i] = '0';
    }

    while (num > 0){
        if (num == 1){
            binary[index] = '1';
            num = 0;
        }
        if (num%2 == 1){
            binary[index] = '1';
        }
        index -= 1;
        num /= 2;
    }

    printf("%s", binary);
    return 0;
} 