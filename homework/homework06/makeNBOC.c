#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>


int makeNBOC(int num){

    int check = 0x12345678;
    char *ptr = (char *)&check;
    if (ptr[0] == 0x78){
        u_int32_t nbo = htonl(num);
        return nbo;
    }
    return num;
}





