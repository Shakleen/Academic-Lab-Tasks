#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n=0,cnt=0;
    scanf("%d", &n);
    while(n--){
        int a,b,c;
        char d,ans[3];
        scanf("%d%c%d=%s",&a,&d,&b,&ans);
        if (ans[0]=='?')    continue;
        else                c=atoi(ans);
        if (d=='+' && a+b==c)
            cnt++;
        else if (d=='-' && a-b==c)
            cnt++;
    }
    printf("%d",cnt);

    return 0;
}
