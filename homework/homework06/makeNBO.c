#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>


int makeNBO(int num){

    int check = 0x12345678;
    char *ptr = (char *)&check;
    if (ptr[0] == 0x78){
        u_int32_t nbo = htonl(num);
        return nbo;
    }
    return num;
}

void print_bytes(int number){
    char* ptr = (char*)&number;
    for (int i=0; i < 4; ++i){
        printf("%02x ", ptr[i]);
    }
}

int main(){
    printf("        1  2  3  4    byte\n");

    int test1 = makeNBO(0x12345678);
    printf("\nBefore: ");
    print_bytes(0x12345678);
    printf("\nAfter:  ");
    print_bytes(test1);
    printf("\n");

    int test2 = makeNBO(0x11223344);
    printf("\nBefore: ");
    print_bytes(0x11223344);
    printf("\nAfter:  ");
    print_bytes(test2);
    printf("\n");

}



