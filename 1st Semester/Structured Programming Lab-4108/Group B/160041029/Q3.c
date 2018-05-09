#include <stdio.h>

int main(){
    int n,m,flag=0;
    scanf("%d %d", &n, &m);
    int a[m+2],i=0;
    for(i=0; i<m; i++){
        scanf("%d", &a[i]);
        if (n%a[i]){
            flag=1;
        }
    }
    if (flag){
        printf("NO");
    }
    else{
        printf("YES");
    }
    return 0;
}
