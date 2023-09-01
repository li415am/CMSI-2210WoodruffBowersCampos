#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {

    char name[25];
    printf("Enter a name: ");
    gets(name);
    
    printf( "\n\n\t Hello, %s!\n\n\n", name);
    return 0;

}
