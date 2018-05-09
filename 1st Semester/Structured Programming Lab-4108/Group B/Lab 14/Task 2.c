#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    struct std{
        int rollno;
        char name[100];
        char dept[4];
        char course[15];
        int year;
    }s[17];
    int i=0,j=0;
    FILE *fp;
    if ( (fp=fopen("students.txt", "r")) == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    while( i < 17){
        //reading name
        char ch=0;
        for(j=0; ; j++){
            ch=fgetc(fp);
            if (ch==EOF){
                printf("Error reading name!\n");
                exit(1);
            }
            if (ch == '\n') break;
            s[i].name[j]=ch;
        }
        //Reading roll no
        char roll[10];
        for(j=0; ; j++){
            ch=fgetc(fp);
            if (ch==EOF){
                printf("Error reading roll!\n");
                exit(1);
            }
            if (ch == '\n') break;
            roll[j]=ch;
        }
        s[i].rollno=atoi(roll);
        //Reading department
        for(j=0; ; j++){
            ch=fgetc(fp);
            if (ch==EOF){
                printf("Error reading department!\n");
                exit(1);
            }
            if (ch=='\n')   break;
            s[i].dept[j]=ch;
        }
        //Reading course
        for(j=0; ; j++){
            ch=fgetc(fp);
            if (ch==EOF){
                printf("Error reading department!\n");
                exit(1);
            }
            if (ch=='\n')   break;
            s[i].course[j]=ch;
        }
        //Reading year
        char year[5];
        if (fgets(year,4,fp) == EOF){
            printf("Error reading year!\n");
            exit(1);
        }
        s[i].year=atoi(year);
        i++;
    }
    for (i=0; i<17; i++){
        printf("%d %s %s %s %d\n",s[i].rollno, s[i].name, s[i].dept, s[i].course, s[i].year);
    }
    return 0;
}
