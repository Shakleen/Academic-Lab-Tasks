#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mystrtok (char *str, char *delim, char *token, int start);

int main(){
    char delim [3] = {}, str [100] = {}, token [100] = {};
    int i = 0;

    scanf("%s %s", str, delim);

    i = mystrtok(str, delim, token, i);

    printf("%s\n", token);

    i = mystrtok(str, delim, token, i);

    printf("%s\n", token);

    i = mystrtok(str, delim, token, i);

    printf("%s\n", token);

    return 0;
}

int mystrtok (char *str, char *delim, char *token, int start){

    memset(token, 0, sizeof(token));

    int length = strlen(str), length_del = strlen(delim), f = 0, j = 0, i = 0, flag = 0;
    char ch = 0;

        for (i = start, j = 0; i < length; i++){

            if (length_del == 1){   //For single delim character
                if (str[i] == delim [0]){
                    start = i + 1;
                    token [i] = '\0';
                    flag = 1;
                    return start;
                }

                token [j++] = str [i];
            }

            else if (length_del == 2)//For double delim character
            {
                if ((str[i] == delim [0] || str [i] == delim [1]) && !f){
                    if (str [i] == delim [0])          ch = delim [1];
                    else                               ch = delim [0];

                    flag = f = 1;

                    continue;
                }
                else if (str [i] == ch){
                    start = i;
                    return start;
                }

                if (f)            token [j++] = str [i];
            }
        }

        if ( !flag ){
            return length;
        }
}
