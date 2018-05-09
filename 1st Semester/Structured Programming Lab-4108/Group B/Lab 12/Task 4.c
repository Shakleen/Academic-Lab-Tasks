#include <stdio.h>
#include <string.h>
int main(){
    char str[80]={};
    gets(str);
    int i=0,j=0,count=0,flag=0,length=strlen(str)-1;
//Checking unique letters
    for(i=97;i<=122;i++){
        for(j=0;j<=length;j++){
            if(str[j]==i){
                count++;
                break;
            }
        }
    }
//Checking sub-string palindrome
    if(count!=length+1){
        for(i=0;i<length;i++){
            flag=0;
            int mid=(length+i+1)/2,k=0;
            for(j=i;j<=mid;j++,k++){
                if(str[j]==str[length-k])   flag=1;
                else                        flag=0;
            }
            if(flag)    count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
