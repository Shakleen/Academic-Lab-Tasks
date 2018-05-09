#include <stdio.h>

int main(){
    char s [1000] = {}, t [1000] = {};
    int in [1000] = {}, i = 0, j = 0, k = 0, flag = 1, brk = 1;

    gets(s);
    gets(t);

    for (i = 0, flag = 1; i < lens; i++){
        for (j = 0; j < lens; j++){
            if (s[j] == t [k]){
                k++:
                continue;
            }
            else if (flag){
                l = j;
                flag = 0;
            }
            else{
                brk = 1;
            }
        }
    }


    return 0;
}
