#include <stdio.h>
#define N 100
int main(){
    int n, a[N][N]={0}, i=0, j=0;
    printf("Enter array size: (nxn)\n");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (i==0 || j==0 || i==n-1 || j==n-1)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j+1];
        }
    }
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            printf("%5d  ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
