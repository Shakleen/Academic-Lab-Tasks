#include <stdio.h>

int main(){
    int n = 0, num [10000] = {}, i = 0, pos [10000] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    rec(num, 0, n, pos);

    if (pos[n-1] == 1){
        printf("YES!");
    }
    else{
        printf("NO!");
    }

    return 0;
}

void rec(int *num, int i, int n, int *pos){
    if (i == n)   return;

    int j = 0, lim = i + num[i];

    for (j = i+1; j <= lim; j++){
        pos [i] = 1;
        pos [j] = 1;
    }

    rec(num, ++i, n, pos);

    return;
}
