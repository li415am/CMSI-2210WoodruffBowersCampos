#include <stdio.h>

int makeNBOC(int);

void print_bytes(int number){
    char* ptr = (char*)&number;
    for (int i=0; i < 4; ++i){
        printf("%02x ", ptr[i]);
    }
}

int main(){
    printf("        1  2  3  4    byte\n");

    int test1 = makeNBOC(0x12345678);
    printf("\nBefore: ");
    print_bytes(0x12345678);
    printf("\nAfter:  ");
    print_bytes(test1);
    printf("\n");

    int test2 = makeNBOC(0x11223344);
    printf("\nBefore: ");
    print_bytes(0x11223344);
    printf("\nAfter:  ");
    print_bytes(test2);
    printf("\n");

}