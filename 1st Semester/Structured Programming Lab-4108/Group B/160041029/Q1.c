#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double x=0;
    scanf("%d", &n);

    while(n--){
        scanf("%lf", &x);
        int i=1,j=1;
        double ex=1;
        for(i=1; i<=100; i++){
            double d=1;
            for(j=1; j<=i; j++){
                d*=x/j;
            }
            ex+=d;
        }
        printf("%.4lf\n",ex);
    }


    return 0;
}
