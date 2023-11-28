//when compiling use gcc -static or gcc -no-pie
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int64_t findGCDfunc(int64_t, int64_t);

int main(){
    assert(462837 == findGCDfunc(3113041662, 11570925));
    assert(462837 == findGCDfunc(11570925, 3113041662));
    assert(3113041662 == findGCDfunc(0, 3113041662));
    assert(3113041662 == findGCDfunc(3113041662, 0));
    assert(1 == findGCDfunc(3113041662, 1));
    assert(1 == findGCDfunc(1, 3113041662));
    assert(711304166224512345 == findGCDfunc(711304166224512345, 711304166224512345));

    printf( "Yay, all tests passed");
}