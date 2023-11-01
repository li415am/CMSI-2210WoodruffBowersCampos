#include <stdio.h>
#include <time.h>

int main(){

    printf("This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter'key. When you absolutely have to exhale, press the enter key again. The duration will be displayed in minutes and seconds.\n");
    time_t initial_time, timer;
    getchar();
    initial_time = time(NULL);
    getchar();
    timer = time(NULL);
    printf("You held your breath for: %lu minutes and %lu seconds\n", (timer-initial_time)/60, (timer-initial_time)%60);
    return 0;
}