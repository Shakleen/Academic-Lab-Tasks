#include <stdio.h>

int main(){
    int n,i=0,j=0,cnt=0;
    scanf("%d", &n);
    int x[n+2], y[n+2];
    for(i=0; i<n; i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    for (i=0; i<n; i++){
        int l=0,r=0,u=0,b=0;
        for(j=0; j<n; j++){
            if (i==j)   continue;
            if (x[j]==x[i]){
                if (y[j]<y[i]){
                    b++;
                }
                else if (y[j]>y[i]){
                    u++;
                }
            }
            else if (y[j]==y[i]){
                if (x[j]<x[i]){
                    l++;
                }
                else if (x[j]>x[i]){
                    r++;
                }
            }
            if (b && u && l && r){
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
