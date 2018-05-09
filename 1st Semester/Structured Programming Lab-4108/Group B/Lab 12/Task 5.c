#include <stdio.h>
#include <string.h>

int main(){
    char str1[80],str2[80];
    gets(str1);
    gets(str2);
    int l1=strlen(str1), l2=strlen(str2);
    if(l1!=l2){
        printf("Not Anagram\n");
        return 0;
    }
    else{
        int i=0,j=0,flag=1;
        for(i=0; i<l1; i++){
            str1[i]=tolower(str1[i]);
            for(j=0; j<l2; j++){
                str2[j]=tolower(str2[j]);
                if(str1[i]==str2[j]){
                    str2[j]=1;
                    break;
                }
            }
        }
        for(j=0; j<l2; j++){
            if(str2[2]!=1){
                flag=0;
                break;
            }
        }
        if(flag)    printf("Anagram\n");
        else        printf("Not Anagram\n");
    }
    return 0;
}
