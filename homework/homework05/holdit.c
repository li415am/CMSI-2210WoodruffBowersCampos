#include <stdio.h>
#include <time.h>

int main(){

    printf("This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter'key. When you absolutely have to exhale, press the enter key again. The duration will be displayed in minutes and seconds.\n");
    clock_t initial_time, timer;
   
    getchar();
    initial_time = clock();
    printf("initial time- %lu", initial_time);
    getchar();
    timer = clock();
    printf("time- %lu", timer);
    printf("You held your breath for: %d minutes and %d seconds", (timer-initial_time), ((timer-initial_time)));
}