#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//*************************************************************************************************************************
//                                        Variables and Structures
//*************************************************************************************************************************

int stdNo=0, fctNo=0;

struct student{
    char    studentName[100];
    char    studentID[20];
    char    dateOfBirth[15];
    char    cgpa[5];
    char    department[4];
    char    departmentLocation[50];
    char    departmentEstablishment[15];
    char    departmentBudget[20];
}std[10];

struct faculty{
    char    facultyName[100];
    char    facultyID[20];
    char    designation[50];
    char    department[4];
    char    departmentLocation[50];
    char    departmentEstablishment[15];
    char    departmentBudget[20];
}fct[10];

//*************************************************************************************************************************
//                                          User Defined Functions
//*************************************************************************************************************************

void readFromFile();
void menu();
void store(char department[], char departmentLocation[], char departmentEstablishment[], char departmentBudget[]);
void storeStudentInfo();
void storeFacultyInfo();
void addStudentInfo();
void addFacultyInfo();
void editStudentInfo();
void editFacultyInfo();

//*************************************************************************************************************************
//                                            Main Function
//*************************************************************************************************************************

int main(){
    readFromFile();
    menu();
    return 0;
}

void readFromFile(){
    FILE *stdfp, *fctfp;

    if((stdfp=fopen("Students.txt", "r+"))==NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while(1){    // reading from student file
        if( fscanf(stdfp, "%s %s %s %s %s %s %s %s", std[stdNo].studentID, std[stdNo].studentName, std[stdNo].dateOfBirth,
               std[stdNo].cgpa, std[stdNo].department, std[stdNo].departmentLocation, std[stdNo].departmentEstablishment,
               std[stdNo].departmentBudget) != 8)  break;
//        printf("%s %s %s %s %s %s %s %s\n", std[stdNo].studentID, std[stdNo].studentName, std[stdNo].dateOfBirth,
//               std[stdNo].cgpa, std[stdNo].department, std[stdNo].departmentLocation, std[stdNo].departmentEstablishment,
//               std[stdNo].departmentBudget);
        stdNo++;
    }

    if ( fclose(stdfp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }

    if((fctfp=fopen("faculty.txt", "r+"))==NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fctNo=0;

    while(1){    // reading from faculty file
        if( fscanf(fctfp, "%s %s %s %s %s %s %s", fct[fctNo].facultyID, fct[fctNo].facultyName, fct[fctNo].designation,
               fct[fctNo].department, fct[fctNo].departmentLocation, fct[fctNo].departmentEstablishment,
               fct[fctNo].departmentBudget) != 7)  break;
//        printf("%s %s %s %s %s %s %s", fct[fctNo].facultyID, fct[fctNo].facultyName, fct[fctNo].designation,
//               fct[fctNo].department, fct[fctNo].departmentLocation, fct[fctNo].departmentEstablishment,
//               fct[fctNo].departmentBudget);
        fctNo++;
    }

    if ( fclose(fctfp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }

    return;
}

void menu(){
    int choice1=0, choice2=0;
    while(1){
        printf("\n\t\tMENU\n\n\t\t1. Student\n\n\t\t2. Faculty\n\n\t\t3. Exit\n\n\t\tInput Choice\n\n\t\t");

        scanf("%d", &choice1);
        getchar();

        switch(choice1){
        case 1:
            printf("\n\t\tStudent MENU\n\n\t\t1. Add\n\n\t\t2. Edit\n\n\t\t3. Go Back\n\n\t\tInput Choice\n\n\t\t");
            scanf("%d", &choice2);
            getchar();
            if(choice2==1)              addStudentInfo();
            else if (choice2==2)        editStudentInfo();
            break;
        case 2:
            printf("\n\t\tFaculty MENU\n\n\t\t1. Add\n\n\t\t2. Edit\n\n\t\t3. Go Back\n\n\t\tInput Choice\n\n\t\t");
            scanf("%d", &choice2);
            getchar();
            if(choice2==1)              addFacultyInfo();
            else if (choice2==2)        editFacultyInfo();
            break;
        case 3:
            return 0;
        }
    }

    return;
}

void storeStudentInfo(){
    int i=0;
    FILE *stdfp;

    if((stdfp=fopen("Students.txt", "w"))==NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while(i<stdNo){/* Writing info into file*/
        fputs(std[i].studentID, stdfp);                 fputc(' ', stdfp);
        fputs(std[i].studentName, stdfp);               fputc(' ', stdfp);        fputs(std[i].dateOfBirth, stdfp);               fputc(' ', stdfp);
        fputs(std[i].cgpa, stdfp);                      fputc(' ', stdfp);
        fputs(std[i].department, stdfp);                fputc(' ', stdfp);
        fputs(std[i].departmentLocation, stdfp);        fputc(' ', stdfp);
        fputs(std[i].departmentEstablishment, stdfp);   fputc(' ', stdfp);
        fputs(std[i].departmentBudget, stdfp);          fputc('\n', stdfp);
        i++;
    }

    if ( fclose(stdfp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }

    return;
}

void storeFacultyInfo(){
    int i=0;
    FILE *fctfp;

    if((fctfp=fopen("Faculty.txt", "w"))==NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while(i<fctNo){/* Writing info into file*/
        fputs(fct[i].facultyID, fctfp);                 fputc(' ', fctfp);
        fputs(fct[i].facultyName, fctfp);               fputc(' ', fctfp);        fputs(fct[i].designation, fctfp);               fputc(' ', fctfp);
        fputs(fct[i].department, fctfp);                fputc(' ', fctfp);
        fputs(fct[i].departmentLocation, fctfp);        fputc(' ', fctfp);
        fputs(fct[i].departmentEstablishment, fctfp);   fputc(' ', fctfp);
        fputs(fct[i].departmentBudget, fctfp);          fputc('\n', fctfp);
        i++;
    }

    if ( fclose(fctfp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }

    return;
}

void store(char department[], char departmentLocation[], char departmentEstablishment[], char departmentBudget[]){
    /*Replacing old department info with the inputted new one*/
    //Student portion
    int j=0;
    while(j<stdNo){
        if(strcmp(department,std[j].department)==0){
            strcpy(std[j].department, department);
            strcpy(std[j].departmentLocation, departmentLocation);
            strcpy(std[j].departmentEstablishment, departmentEstablishment);
            strcpy(std[j].departmentBudget, departmentBudget);
        }
        j++;
    }
    storeStudentInfo();

    //Faculty portion
    j=0;
    while(j<fctNo){
        if(strcmp(department,fct[j].department)==0){
            strcpy(fct[j].department, department);
            strcpy(fct[j].departmentLocation, departmentLocation);
            strcpy(fct[j].departmentEstablishment, departmentEstablishment);
            strcpy(fct[j].departmentBudget, departmentBudget);
        }
        j++;
    }
    storeFacultyInfo();

    return;
}

void addStudentInfo(){
    printf("\n\n\t\tEnter Student ID, Name, Date Of Birth, CGPA, Department name, Location, Est, Budget\n\n\t\t");
    scanf("%s %s %s %s %s %s %s %s", std[stdNo].studentID, std[stdNo].studentName, std[stdNo].dateOfBirth,
       std[stdNo].cgpa, std[stdNo].department, std[stdNo].departmentLocation, std[stdNo].departmentEstablishment,
       std[stdNo].departmentBudget);

    stdNo++;
//    printf("%d %s %s %lf %s %s %s %d\n", std[stdNo].studentID, std[stdNo].studentName, std[stdNo].dateOfBirth,
//       std[stdNo].cgpa, std[stdNo].department, std[stdNo].departmentLocation, std[stdNo].departmentEstablishment,
//       std[stdNo].departmentBudget);

    storeStudentInfo();

    return;
}

void addFacultyInfo(){
    printf("\n\n\t\tEnter Faculty ID, Name, Designation, Department name, Location, Est, Budget\n\n\t\t");

    scanf("%s %s %s %s %s %s %s", fct[fctNo].facultyID, fct[fctNo].facultyName, fct[fctNo].designation,
       fct[fctNo].department, fct[fctNo].departmentLocation, fct[fctNo].departmentEstablishment,
       fct[fctNo].departmentBudget);
//    getchar();
    fctNo++;

    storeFacultyInfo();

    return;
}

void editStudentInfo(){
    int  i=0, j=0;
    char SID[20]={}, studentName[100], dateOfBirth[15], cgpa[5], department[4],
         departmentLocation[50], departmentEstablishment[15], departmentBudget[20];

    printf("\n\n\t\tEnter Student ID to search record you want to edit\n\n\t\t");
    scanf("%s", SID);

    // Searching for the student info to edit
    while(i<stdNo)
        if(strcmp(SID, std[i].studentID)==0)      break;
        else                                      i++;

    if(i>=stdNo){//No matches found
        printf("%s Student ID NOT FOUND!\n", SID);
    }
    else{//Match found
        printf("\n\n\t\tEnter New Student Name, Date Of Birth, CGPA, Department name, Location, Est, Budget\n\n\t\t");
        scanf("%s %s %s %s %s %s %s", studentName, dateOfBirth, cgpa, department,
              departmentLocation, departmentEstablishment, departmentBudget);

        /* Replacing old student info with new one*/{
        strcpy(std[i].studentName, studentName);
        strcpy(std[i].dateOfBirth, dateOfBirth);
        strcpy(std[i].cgpa, cgpa);
        strcpy(std[i].department, department);
        strcpy(std[i].departmentLocation, departmentLocation);
        strcpy(std[i].departmentEstablishment, departmentEstablishment);
        strcpy(std[i].departmentBudget, departmentBudget);
        }

        store(department, departmentLocation, departmentEstablishment, departmentBudget);

        printf("\n\n\t\tSUCCESSFULLY CHANGED!\n");
    }

    return;
}

void editFacultyInfo(){
    int  i=0, j=0;
    char facultyName[100], facultyID[20], designation[50], department[4],
         departmentLocation[50], departmentEstablishment[15], departmentBudget[20];

    printf("\n\n\t\tEnter Faculty ID to search the record you want to edit\n\n\t\t");
    scanf("%s", facultyID);

    // Searching for the student info to edit
    while(i<fctNo)
        if(strcmp(facultyID, fct[i].facultyID)==0)      break;
        else                                            i++;

    if(i>=fctNo){//No matches found
        printf("%s Faculty ID NOT FOUND!\n", facultyID);
    }
    else{//Match found
        printf("\n\n\t\tEnter New Faculty Name, Designation, Department name, Location, Est, Budget\n\n\t\t");
        scanf("%s %s %s %s %s %s", facultyName, designation, department,
              departmentLocation, departmentEstablishment, departmentBudget);

        /* Replacing old student info with new one*/{
        strcpy(fct[i].facultyName, facultyName);
        strcpy(fct[i].designation, designation);
        strcpy(fct[i].department, department);
        strcpy(fct[i].departmentLocation, departmentLocation);
        strcpy(fct[i].departmentEstablishment, departmentEstablishment);
        strcpy(fct[i].departmentBudget, departmentBudget);
        }

        store(department, departmentLocation, departmentEstablishment, departmentBudget);

        printf("\n\n\t\tSUCCESSFULLY CHANGED!\n");
    }

    return;
}

//123456 Karim Professor CSE FirstAcademicBuilding 1997 100000
//12345678 Taher Assisstant CSE IUT 1997 100000

/*
160041029 Shakleen 30/04/1997 3.92 CSE FirstAcademicBuilding 1997 1000000
160041030 Azmaeen 20/04/1998 3.9 CSE FirstAcademicBuilding 1997 10000000
160041031 Lami 31/03/1997 3.76 CSE FirstAcademicBuilding 1997 10000000
*/
