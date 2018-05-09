#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n=0, m=0, i=0, j=0, sum=0, k=0;

    scanf("%d %d", &n, &m);
    for (k=n; k<=m; k++){
        sum=0;
        for (i=k; i>0; i/=10){
            j=i%10;
            sum+=j*j*j;
        }
    //    printf("%d", sum);
        if (sum==(k/2))
            printf("%d is Funny\n", k);
    }
    return 0;
}
