//function to test paritygen.nasm
//assemble paritygen.nasm, if not done already: nasm -felf64 paritygen.nasm
//to compile and link: gcc -static paritygen.o paritygen.c -o paritygen
//to run: ./paritygen
#include <stdio.h>
#include <inttypes.h>

int8_t paritygen(int8_t);

int main(){
    printf("Should print: 1010101");
    paritygen(0x00);
    paritygen(0x01);
    paritygen(0x3F);
    paritygen(0x02);
    paritygen(0x09);
    paritygen(0x7F);
    paritygen(0xFF);
    
    //1010101
    return 0;
}