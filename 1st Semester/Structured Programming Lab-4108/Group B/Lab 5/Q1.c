#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int m=0, n=0, a=0, x=0, y=0;

    scanf("%d %d %d", &n, &m, &a);

    if (m%a==0)
        x=m/a;
    else
        x=m/a+1;

    if (n%a==0)
        y=n/a;
    else
        y=n/a+1;

    printf("%d", x*y);
    return 0;
}
