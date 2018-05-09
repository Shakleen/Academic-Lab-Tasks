#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    int rollno;
    char name[200];
    char department[4];
    char course[150];
    int year;
}std[21];

/*Functions*/
void year (int y);
void dept (char *d);
void cour (char *c);

int main(){

    FILE *fp;

    if ( (fp = fopen("students.txt","r")) == NULL){
        printf("Error opening file for reading!\n");
        exit(1);
    }

    //Taking input form file
    int i = 0;
    for (i = 0; i < 21; i++){
        int j = 0;
        char ch [200] = {};
        //Name
        for (j = 0; ; j++){
            char cha = fgetc(fp);

            if (cha == '\n'){
                ch[j] = '\0';
                break;
            }

            ch[j] = cha;
        }

        strcpy(std[i].name, ch);

        //Roll
        char r[12] = {};

        for (j = 0; ; j++){
            char cha = fgetc(fp);

            if (cha == '\n'){
                r[j] = '\0';
                break;
            }

            r[j] = cha;
        }

        int rl = atoi(r);

        std[i].rollno = rl;

        //Department
        for (j = 0; ; j++){
            char cha = fgetc(fp);

            if (cha == '\n'){
                ch[j] = '\0';
                break;
            }

            ch[j] = cha;
        }

        strcpy(std[i].department, ch);

        //Course
        for (j = 0; ; j++){
            char cha = fgetc(fp);

            if (cha == '\n'){
                ch[j] = '\0';
                break;
            }

            ch[j] = cha;
        }

        strcpy(std[i].course, ch);

        //Year
        for (j = 0; ; j++){
            char cha = fgetc(fp);

            if (cha == '\n'){
                ch[j] = '\0';
                break;
            }

            ch[j] = cha;
        }

        int yr = atoi(ch);

        std[i].year = yr;
    }

    fclose(fp);

    /*Menu*/{
    printf("Enter choice:\n");
    printf("1 -> Print names of students joining in a particular year\n");
    printf("2 -> Print names of students in a particular department\n");
    printf("3 -> Print names of students taking a particular course\n");
    printf("4 -> Print data of a student\n");
    }

    int choice = 0, yr = 0, r = 0;
    char d[4] = {}, c[150] = {};

    scanf("%d", &choice);
    fflush(stdin);

    switch(choice){
        case 1:{
            printf("\n\nEnter the year of joining:\n");
            scanf("%d", &yr);

            printf("\nThe names of the students joining this year are:\n");
            year(yr);

            break;
        }
        case 2:{
            printf("\n\nEnter department name:\n");
            scanf("%s", d);

            printf("\nThe names of the students of this department are:\n");
            dept(d);

            break;
        }
        case 3:{
            printf("\n\nEnter course name:\n");
            gets(c);

            printf("\nThe names of students taking this course are:\n");
            cour(c);

            break;
        }
        case 4:{
            printf("\n\nEnter roll number\n");
            scanf("%d", &r);

            printf("\nThe student with this roll has the following info:\n");
            info(r);

            break;
        }
    }

    return 0;
}

void year (int y){
    int i = 0;

    for (i = 0; i < 21; i++){
        if (std[i].year == y){
            printf("%s\n", std[i].name);
        }
    }

    return;
}

void dept (char *d){
    int i = 0;

    for (i = 0; i < 21; i++){
        if ( !strcmp(std[i].department,d) ){
            printf("%s\n", std[i].name);
        }
    }

    return;
}

void cour(char *c){
    int i = 0;

    for (i = 0; i < 21; i++){
        if ( !strcmp(std[i].course,c) ){
            printf("%s\n", std[i].name);
        }
    }

    return;
}

void info (int r){
    int i = 0;

    for (i = 0; i < 21; i++){
        if ( std[i].rollno == r ){
            printf("Name = %s\n", std[i].name);
            printf("Roll = %d\n", std[i].rollno);
            printf("Department = %s\n", std[i].department);
            printf("Course = %s\n", std[i].course);
            printf("Year of joining = %d\n", std[i].year);
            break;
        }
    }

    return;
}
