#include <stdio.h>

int main(){
    int birthday, birthmonth, birthyear, year, month, day, hour;
    long int sec;
    printf("Enter your birth day, month, year: ");
    scanf("%d %d %d", &birthday, &birthmonth, &birthyear);

    day=30-birthday+18;
    month=12-birthmonth-1;
    year=2017-birthyear-1;

    hour=((day+month*30+year*365)+15)*24;
    sec=hour*3600;

    printf("You've spent %ld seconds.", sec);

    return 0;
}
