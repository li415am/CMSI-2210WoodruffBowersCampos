#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[]){

    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char* natoAlp[26] = {"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "xray", "yankee", "zulu"};
    char userIn[100];


    printf("Enter a word: \n");
    scanf("%s", &userIn);

    for (int i = 0; userIn[i]; i++){
        userIn[i] = tolower(userIn[i]);
    }

    for (int i = 0; i < strlen(userIn); i++){

        char temp = userIn[i];
        for (int z = 0; z < 26; z++){
            if(alphabet[z] == temp){
                printf("\n%s", natoAlp[z]);
                break;
            }
        }
    }

//------------------------------------------------------------------------------
    char* morse[26] = {"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"};
    char userInp[100];

    printf("\nEnter another word: \n");
    scanf("%s", &userInp);

    for (int i = 0; userIn[i]; i++){
        userInp[i] = tolower(userInp[i]); 
    }

    for (int i=0; i < strlen(userInp); i++){
        char temp = userInp[i];
        for (int z = 0; z < 26; z++){
            if(alphabet[z] == temp){
                printf("\n%s", morse[z]);
                break;
            }
        }
    }
    printf("\n");


//--------------------------------------------------------------------------------
    float initialDeposit;
    float interestRate;

    printf("Enter your initial deposit: ");
    scanf("%f", &initialDeposit);
    printf("\nEnter the interest rate (in percent):");
    scanf("%f", &interestRate);
    printf("\n");

    for (int i = 0; i < 3; i++){
        initialDeposit = initialDeposit * (1 + interestRate/1000);
        printf("Your balance after %i months (compunded monthly) is: %.2f \n", i, initialDeposit);
    }
}