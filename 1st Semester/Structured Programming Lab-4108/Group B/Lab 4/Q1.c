#include <stdio.h>

int main(){
    int n=0, i=0, mul=0;
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        if (i%4 == 0){
            printf("%d ", i*i);
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}
