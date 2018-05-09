#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1000
int count[27];
char str[N];
int main(){
    int n=0,i=0,j=0,k=0,max=0;
    scanf("%d ", &n);
    while (n--){
        gets(str);
        int i=0,j=0,k=0;
        for (i=65; i<91; i++){
            for(j=0; str[j]!='\0'; j++){
                str[j]=toupper(str[j]);
                if (str[j]<65||str[j]>90)   continue;
                if (str[j]==i)              count[i-65]++;
            }
        }
    }
    while(1){
        max=0;
        for (j=0; j<27; j++){
            if (count[j]>max){
                max=count[j];
                k=j;
            }
            else if (count[j]==max && k>j)
                k=j;
        }
        if (max==0) break;
        else{
            printf("%c %d\n", k+65, max);
            count[k]=0;
        }
    }
    return 0;
}
