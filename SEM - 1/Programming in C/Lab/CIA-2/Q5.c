#include <stdio.h>

struct time{

    int hour;
    int minute;
    int sec;
};

int to_seconds(struct time *time){

    int secs = 0;

    secs += time -> hour * 3600;
    secs += time -> minute * 60;
    secs += time -> sec;

    return secs;
}

int difference(int num1, int num2){

    if (num1 > num2) return (num1 - num2);
    else return (num2 - num1);
}

void main(){

    struct time time1 = {11, 34, 0}, time2 = {8, 54, 12};
    int secs1, secs2, time;

    secs1 = to_seconds(&time1);
    secs2 = to_seconds(&time2);

    time = difference(secs1, secs2);
    
    printf("Remaining Time: %d:%d:%d", (time / 3600), ((time - ((time / 3600) * 3600)) / 60), (time - ((time / 3600) * 3600) - (((time - ((time / 3600) * 3600)) / 60) * 60)));
}