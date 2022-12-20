


void time_passed(start_time)
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
