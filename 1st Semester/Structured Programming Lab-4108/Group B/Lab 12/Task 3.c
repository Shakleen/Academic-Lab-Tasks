#include <stdio.h>
#include <string.h>
int main(){
    FILE *fp=fopen("Q3.txt", "r");
    char str[1000]={};
    int i=0;
    while(1){
        str[i]=fgetc(fp);
        if(str[i]=='\n')
            str[i]=' ';
        if (str[i]==EOF){
            break;
        }
        i++;
    }
    str[i]='\0';
    fclose(fp);
    fp=fopen("file2.txt", "w");
    int check=0;
    i=0;
    while(str[i]){
        check=fputc(str[i],fp);
        if(check==EOF)
            break;
        i++;
    }
    fclose(fp);
    return 0;
}
