#include <stdio.h>

#define N 100
int main(){
    int n, i, j, a[N][N]={0}, flag=0;
    printf("Enter matrix size: (nxn)\n");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            if (i==j){
                if (a[i][j]==0)
                    flag=1;
            }
            else{
                if (a[i][j]!=0)
                    flag=1;
            }
        }
    }

    if (flag==0)
        printf("DIAGONAL METRIX\n");
    else
        printf("NOT DIAGONAL\n");
    return 0;
}
