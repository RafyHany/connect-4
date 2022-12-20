#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void time_passed(time_t start_time);
int computer_turn(int width);


int main()
{
    time_t start_time=time(NULL);
         srand(time(NULL));


    return 0;
}
int computer_turn(int width)
{
 int computer_choice=rand()%width+1;
 return computer_choice;
}
void time_passed(time_t start_time)
{
    time_t current_time;
    int seconds,minutes,hours;
    current_time=time(NULL);
    seconds=(current_time-start_time);
    hours=(seconds/3600);
    minutes=(seconds%3600)/60;
    seconds=(seconds%3600)%60;
    printf("Time passed:%02d:%02d:%02d\n",hours,minutes,seconds);
}

