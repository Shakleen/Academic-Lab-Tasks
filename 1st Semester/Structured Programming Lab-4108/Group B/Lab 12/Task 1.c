#include <stdio.h>
#include <string.h>
int main(){
    char str[80]={};
    printf("Input string:\n");
    gets(str);
    FILE *fp=fopen("file1.txt","w");
    int i=0,check=0;
    while(str[i]){
        check=fputc(str[i],fp);
        if(check==EOF){
            printf("Error!\n");
            return 0;
        }
        i++;
    }
    check=fclose(fp);
    if (check==EOF)
        printf("Error!\n");
    return 0;
}
