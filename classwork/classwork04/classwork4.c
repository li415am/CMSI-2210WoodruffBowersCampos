
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 25


int main( int argc, char * argv[] ) {

   char input[10];
   char storage[MAX_ENTRY][10];
   int values[MAX_ENTRY];
   int length = 0;

   for (int i = 0; i < MAX_ENTRY; i++){
        printf( "\n  enter an integer: " );
        fgets( input, 10, stdin);
        int integer = atoi(input);
    if ( integer == -9999){
        break;
    }
    values[i] = integer;
    length++;
   } 

    float sum = 0;

    for(int i = 0; i < length; i++){
        sum += values[i];
    }

    printf("The sum of the entered numbers is: %f\n", sum);
    printf("The average of the sum (%f) of the %d numbers entered is %f\n", sum, length, sum/length);

    char conc[MAX_ENTRY];
    for (int i = 0; i < length; i++){
        sprintf(conc + strlen(conc), "%d", values[i]);
    }

    printf("The concatatenated strings are %s\n", conc);

    int sevens = 0;
    for (int i = 0; i < length; i++){
        if (conc[i] == 55) //7 in ascii is 55
            sevens++;
    }

    printf("The number of sevens entered: %d", sevens);

}