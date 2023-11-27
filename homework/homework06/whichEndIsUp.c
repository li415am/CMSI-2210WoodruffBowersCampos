#include <stdio.h>

int main(){
    int num = 0x12345679;
    char* ptr = (char*)&num;

    if (ptr[0] == 0x12){
                printf("This system is big endian");
    } 
    else if (ptr[0] == 0x79){
        printf("This system is little endian");
    }

    return 0;
}
