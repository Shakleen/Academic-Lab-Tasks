#include <stdio.h>

int main(){
    FILE *fp1=fopen("TASK 2 File 1.txt", "w");
    while(1){
        char str[100]={},ch='\n';
        gets(str);
        if(str[0]=='\0'){
            fclose(fp1);
            break;
        }
        fputs(str,fp1);
        fputc(ch,fp1);
    }
    FILE *fp2=fopen("TASK 2 File 2.txt", "w");
    while(1){
        char str[100]={},ch='\n';
        gets(str);
        if(str[0]=='\0'){
            fclose(fp2);
            break;
        }
        fputs(str,fp2);
        fputc(ch,fp2);
    }
    fp1=fopen("TASK 2 File 1.txt", "r");
    fp2=fopen("TASK 2 File 2.txt", "r");
    while(1){
        char ch1=fgetc(fp1), ch2=fgetc(fp2);
        if(ch1==EOF || ch2==EOF){
            printf("IDENTICAL!\n");
            break;
        }
        else{
            if(ch1!=ch2){
                printf("NOT IDENTICAL!\n");
                break;
            }
        }
    }
    return 0;
}
