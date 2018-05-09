#include <stdio.h>

int main(){
    int grp=0;
    char str[101]={};
    while(1){
        scanf("%d", &grp);
        if(!grp)  break;
        scanf("%s", str);
        int len=strlen(str), wrd=len/grp, k=0;
        while(k<grp){
            int start=k*wrd, mid=start+(wrd+1)/2, last=start+wrd-1, i=0;
            for(i=start; i < mid; i++){
                char temp=str[i];
                str[i]=str[last-i+start];
                str[last-i+start]=temp;
            }
            k++;
        }
        printf("%s\n", str);
    }


    return 0;
}
