#include <stdio.h>

int main(){
    int a,b,i=0;
    scanf("%d %d", &a, &b);
    long long ans=1;
    for(i=1; i<=b; i++){
        ans*=a;
    }
    printf("%lld", ans);
    return 0;
}
