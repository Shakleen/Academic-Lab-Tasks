#include <stdio.h>
#include <string.h>

struct ph{
    char name [51];
    char phoneno [5][12];
    char ad [51];
    char email [5][51];
    char grp[20];
}contact [20];

void input (int no);
void print (int no);

int main(){
    int no;
    for (no = 0; no < 20; no++){
        printf("Menu\n");
        printf("1 -> Create New Contact\n");
        printf("2 -> View All existing contact\n");

        int c = 0;

        scanf("%d", &c);
        fflush(stdin);

        switch(c){
        case 1:
            input(no);
            break;
        case 2:
            print(no);
            break;
        }
    }
    return 0;
}

void input (int no){

    printf("Input name\n");

    char name[50];

    fflush(stdin);
    gets(name);

    strcpy(contact[no].name, name);

    int i = 0;

    for (i = 1; i <= 5; i++){
        printf("Enter number?\n");
        char c = 0;

        scanf("%c", &c);
        fflush(stdin);

        if (c != 'Y'){
            break;
        }

        printf("Enter phone number:\n");

        char n[13] = {};

        fflush(stdin);
        scanf("%s", n);
        fflush(stdin);

        strcpy(contact[no].phoneno[i-1], n);
    }

    printf("Enter address:\n");

    char ad[50] = {};

    fflush(stdin);
    gets(ad);

    strcpy(contact[no].ad, ad);

    for (i = 1; i <= 5; i++){
        printf("Enter email?\n");
        char c;

        fflush(stdin);
        scanf("%c", &c);
        fflush(stdin);

        if (c != 'Y'){
            break;
        }

        printf("Enter email address:\n");

        char n[50] = {};

        fflush(stdin);
        scanf("%s", n);
        fflush(stdin);

        strcpy(contact[no].email[i-1], n);
    }

    printf("Enter group:\n");

    char g[20] = {};

    fflush(stdin);
    gets(g);

    strcpy(contact[no].grp, g);

    return;
}

void print(int no){
    printf("\nExisting contacts\n");
    int i = 0, j = 0;
    for (i = 0; i <= no; i++){
        char n[51] = {};

        strcpy(n, contact[i].name);

        if (strlen(n) == 0){
            break;
        }

        printf("Name : %s\n", contact[i].name);

        for (j = 0; j < 5; j++){
            char number[12] = {};

            strcpy(number, contact[i].phoneno[j]);

            if ( strlen(number) ){
                printf("Phone number %d : %s\n", j+1, number);
            }
        }

        printf("Address : %s\n", contact[i].ad);

        printf("Group : %s\n", contact[i].grp);

        for (j = 0; j < 5; j++){
            char e[12] = {};

            strcpy(e, contact[i].email[j]);

            if ( strlen(e) ){
                printf("Email %d : %s\n", j+1, e);
            }
        }
    }
}
