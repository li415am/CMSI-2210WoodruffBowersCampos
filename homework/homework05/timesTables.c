#include <stdio.h>

int main(int argc, char* argv[]){
    
    if (argc == 1){
        printf("You did not provide a number in the command line. Exiting program.");
        return 0;
    }

    int n = atoi(argv[1]);
    int width_spec = 0;

    //sqrt of max int
    if (n > 46340 || n < 2){
        printf("You entered a number too big. Exiting program.");
        return 0;
    } else{
        int num = n*n;
        int count = 0;

        while(num > 0){
            count++;
            num /= 10;
        }

        width_spec = count;
    }
    printf("    ");
    for (int z = 0; z < width_spec; z++){
        printf(" ");
    }
    for (int i=2; i <= n; i++){
        printf("  %*d  ",width_spec, i);
    }
    printf("\n");
    printf("    ");
    for (int z = 0; z < width_spec; z++){
        printf(" ");
    }
    for (int i=2; i <= n; i++){
        printf("____");
        for (int z = 0; z < width_spec; z++){
            printf("_");
        }    
    }
    printf("\n");
    
    
    for (int i=2; i <= n; i++){

        printf("  %*d |",width_spec, i);

        for(int z = 2; z <= n; z++){
            printf("  %*d  ", width_spec, i*z);
        }
        printf("\n");
    }


}