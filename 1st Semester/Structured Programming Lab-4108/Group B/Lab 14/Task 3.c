#include <stdio.h>
#include <string.h>

int main(){
    int i=1, l=0;
    char ch[2]="\n";
    FILE *fp;
    if( (fp=fopen("Task 3 File.txt", "wb")) == NULL ){
        printf("Error Opening File For Writing!\n");
        exit(1);
    }
    while(i<4){
        char str[1000]={};
        printf("Input %d-th string:\n", i);
        gets(str);
        l+=strlen(str);
        fputs(str,fp);
        fputs(ch,fp);
        i++;
    }
    fclose(fp);
    if( (fp=fopen("Task 3 File.txt", "rb")) == NULL ){
        printf("Error Opening File For Reading!\n");
        exit(1);
    }
    i=1;
    l+=4;
    while(i<=l){
        fseek(fp,-i,SEEK_END);
        char cha=fgetc(fp);
        printf("%c",cha);
        i++;
    }
//    fseek(fp,0,SEEK_END);
//    int j=ftell(fp);
//    printf("%d",j);
//        char cha=fgetc(fp);
//       printf("%c",cha);
    return 0;
}
