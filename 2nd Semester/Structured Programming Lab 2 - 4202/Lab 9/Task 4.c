#include <stdio.h>

int main(){
    int num[1000] = {};
    int n = 0, a = 0, i = 0, same = 0, none = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &a);

        num[a]++;

        if (num[a] > 1){
            same = a;
        }
    }

    for (i = 1; i <= n; i++){
        if (!num[i]){
            none = i;
            break;
        }
    }

    printf("%d %d\n", none, same);

    return 0;
}
