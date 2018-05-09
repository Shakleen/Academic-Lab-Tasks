#include <stdio.h>

int main(){
    FILE *fp=fopen("Q2.txt","r");
    char ch=0;
    while(1){
        ch=fgetc(fp);
        if (ch==EOF)
            break;
        printf("%c",ch);
    }
    int check=fclose(fp);
    if (check==EOF)
        printf("Error!\n");
    return 0;
}
