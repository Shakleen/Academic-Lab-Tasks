#include <stdio.h>

int main(){
    int input[1000]={}, i=0, val=0, j=0, k=0;
    printf("Input space separated values:\n");
    while (scanf("%d", &input[i])){
        if (input[i]<=0)
            break;
        else
            i++;
    }
    for (j=0; j<i; j++){
        int cnt=1;
        if (input[j]==0)
            continue;
        val=input[j];
        for (k=j+1; k<i; k++)
            if (val==input[k]){
                cnt++;
                input[k]=0;
            }
        printf("%d occurs %d times\n", val, cnt);
    }
    return 0;
}
