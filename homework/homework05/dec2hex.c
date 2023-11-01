#include <stdio.h>
#include <stdlib.h>

//Chose to do the option where the user is prompted. Error checking for negative numbers as well
//as handles incorrect number of args.
//Accepts letter and words because they are just represented as numbers.

int main(int argc, char* argv[]){

    unsigned long num = 0;
    int boolean = 1;
    int size = 8;
    
    if (argc < 2){
        printf("You entered less than two numbers: treating as 32 bit\n");
    }
    else if (atoi(argv[1]) == 64){
        printf("Treating as 64 bit\n");
        size = 16;
    }
    else{
        printf("Treating as 32 bit\n");
    }
    do {
    printf("Please enter an unsigned base-10 number\n");
    scanf("%lu", &num);
    } while (num < 0);

    int index = size-1;
    char hex[size+1];

    for (int i = 0; i < size+1; i++) {
        hex[i] = '0';
    }

    hex[size] = '\0';

    while (boolean){
          if (num < 16){
            boolean = 0;
        }

        int rem = num%16;

        if (rem < 10){  
            hex[index] = rem + '0';
        }
        else if (rem == 10){
            hex[index] = 'A';
        }
        else if (rem == 11){
            hex[index] = 'B';
        }
        else if (rem == 12){
            hex[index] = 'C';
        }
          else if (rem == 13){
            hex[index] = 'D';
        }
          else if (rem == 14){
            hex[index] = 'E';
        }
          else if (rem == 15){
            hex[index] = 'F';
        }
              
        index -= 1;
        num /= 16;
    }

    printf("0x%s\n", hex);
    return 0;
} 