#include <stdio.h>

#define N 100
int main(){
    int i,j,x,y,m,n, a[N][N], b[N][N], c[N][N];
    printf("Enter the dimensions of Mat A (i X j):\n");
    scanf("%d %d", &i, &j);

    printf("Enter the dimensions of Mat B (x X y):\n");
    scanf("%d %d", &x, &y);

    if (i!=x || j!=y)
        printf("Matrix addition not possible!\n");
    else{
        printf("Enter Mat A elements:\n");
        for (m=0; m<i; m++)
            for (n=0; n<j; n++)
                scanf("%d", &a[m][n]);
        printf("Enter Mat B elements:\n");
        for (m=0; m<x; m++)
            for (n=0; n<y; n++)
                scanf("%d", &b[m][n]);
        printf("The Result of addition:\n");
        for (m=0; m<x; m++){
            for (n=0; n<y; n++){
                c[m][n]=a[m][n]+b[m][n];
                printf("%5d", c[m][n]);
            }
            printf("\n");
        }
        printf("The Result of subtraction:\n");
        for (m=0; m<x; m++){
            for (n=0; n<y; n++){
                c[m][n]=a[m][n]-b[m][n];
                printf("%5d", c[m][n]);
            }
            printf("\n");
        }
    }
    return 0;
}
