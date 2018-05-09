#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char str[1000] = {}, temp [100] = {}, str2 [1000] = {};

    gets(str);

    int i = 0, j = 0, k = 0, l = 0, len = strlen(str);

    for (i = 0; i <= len; i++){
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) && i != len){
            temp [l++] = str [i];
        }
        else{
            int lenTemp = strlen(temp);

            l = 0;

            if (lenTemp == 0){
                str2[k++] = str[i];
            }
            else{
                for (j = 0; j < lenTemp; j++, k++){
                    str2[k] = temp[lenTemp-1-j];
                    temp[lenTemp-1-j] = 0;
                }

                str2[k++] = str[i];
            }
        }
    }

    printf("%s\n", str2);

    return 0;
}
