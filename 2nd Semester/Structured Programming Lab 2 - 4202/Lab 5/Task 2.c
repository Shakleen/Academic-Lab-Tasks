#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char str [10000] = {}, temp [100] = {};

    gets(str);

    int len = strlen(str), num [1000] = {}, l = 0, j = 0, i = 0, no = 0,
        max = -10000, maxt = 0, numin = 0;

    for (i = 0; i <= len; i++){
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-' && i != len){
            temp [l++] = str [i];
        }
        else{
            temp [l] = '\0';

            int lentemp = strlen(temp);

            no = atoi(temp);

            for (l = 0; l < lentemp; l++){
                temp[l] = 0;
            }

            l = 0;

            num[numin++] = no;
        }
    }

    for (i = 0; i < numin - 2; i++){
        for (j = i + 1; j < numin - 1; j++){
            for (l = j + 1; l < numin; l++){
                maxt = num[i] * num[j] * num[l];

                if (maxt > max){
                    max = maxt;
                }
            }
        }
    }

    printf("%d\n", max);

    return 0;
}
