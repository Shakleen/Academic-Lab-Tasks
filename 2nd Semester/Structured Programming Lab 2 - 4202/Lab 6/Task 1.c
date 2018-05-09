#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int n = 0, i = 0, j = 0, k = 0, cnt = 0, len1 = 0, len2 = 0, mx = 0, mxi = 0;
    char str [10][1000] = {}, temp[1000] = {};

    scanf("%d", &n);

    for (i = 0; i <= n; i++){
        scanf(" %s", &str[i]);

        if (i == n){
            len2 = strlen(str[i]);
        }
    }

    for (i = 0; i < n; i++){
        len1 = strlen(str[i]);
        strcpy(temp, str[i]);
        cnt = 0;

        for (j = 0; j < len2; j++){
            for (k = 0; k < len1; k++){
                if (str[n][j] == temp[k] || str[n][j] == temp[k]-32){
                    cnt++;
                    temp[k] = 1;
                    break;
                }
            }
        }

        if (cnt > mx){
            mx = cnt;
            mxi = i;
        }
    }

    printf("%s", str[mxi]);
    return 0;
}
