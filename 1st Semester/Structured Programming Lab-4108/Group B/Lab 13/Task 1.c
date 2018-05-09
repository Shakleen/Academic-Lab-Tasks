#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("Q1.txt", "r");
    int count=0,i=0;
    char word[20]={},ch=0;
    while(!feof(fp)){
        ch=fgetc(fp);
        ch=toupper(ch);
        if(ch>=65 && ch<=90){
            word[i++]=ch;
        }
        else if(i>0){
            i=0;
            count++;
        }
    }
    fclose(fp);
    printf("%d", count);
    return 0;
}
