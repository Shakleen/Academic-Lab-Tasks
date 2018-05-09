#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char str[10000] = {}, temp[10] = {};
    int i = 0, j = 0, k = 0, l = 0, len = 0, num [100] = {};

    gets(str);
    len = strlen(str);

    for (i = 0; i <= len; i++){
        if (str[i] >= 48 && str[i] <= 57){
            temp[j++] = str[i];
        }
        else{
            temp[j] = '\0';
            j = 0;

            num[k++] = atoi(temp);
        }
    }

    for (i = 0; i < k-2; i++){
        int side1 = num[i], side2 = 0, side3 = 0;

        for (j = i+1; j < k-1; j++){
            side2 = num[j];

            for (l = j+1; l < k; l++){
                side3 = num[l];

                if (side1+side2 > side3 && side2+side3 > side1 && side3+side1 > side2){
                    printf("%d %d %d\n", side1, side2, side3);
                }
            }
        }
    }

    return 0;
}
