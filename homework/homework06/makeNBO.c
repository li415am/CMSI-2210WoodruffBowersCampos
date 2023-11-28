#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int makeNBO(int num){

    int check = 0x12345678;
    char *ptr = (char *)&check;
    if (ptr[0] == 0x78){
        u_int32_t nbo = htonl(num);
        return nbo;
    }
    return num;
    // printf("%d\n", num);
    // int bytes = sizeof(num);
    // printf("%d\n", bytes);
    // int count = (bytes + 5) / 4;
    // printf("%d\n", count);
    // for (int i = 0; i < 1; i++){
    //      printf("%02x", ptr[i]);
    // }
}

int main(){
    int test1 = makeNBO(0x12345678);
    printf("Before: %d\n", 0x12345678);
    printf("After:  %d", test1);
}