#include <stdio.h>
#include <string.h>

struct phonebook{
    char name [51];
    char phnno [5] [51];
    char add [51];
    char email [5] [51];
    char grp [5] [51];
    struct phonebook *next;
};

struct phonebook *create (struct phonebook *h);
void view (struct phonebook *h);

int main(){
    struct phonebook *head = NULL;

    while (1){
        int choice = 0;

        printf("Menu:\n");
        printf("1->Create New Contact\n");
        printf("2->View All Contacts\n");
        printf("Enter choice:\n");

        scanf("%d", &choice);
        fflush(stdin);

        switch (choice){
        case 1:
            system("cls");
            head = create(head);
            break;
        case 2:
            system("cls");
            view(head);
            break;
        }
    }

    return 0;
}

struct phonebook *create (struct phonebook *h){
    struct phonebook *cur = (struct phonebook*) malloc (sizeof(struct phonebook));
    int i = 0, j = 0;
    char c = 0;
    char str [51] = {};

    /*LINKING*/{
    cur -> next = h;
    h = cur;
    }

    /*NAME*/{
    printf("Enter Contact Name:\n");
    gets(str);
    fflush(stdin);

    strcpy(cur -> name, str);
    }

    /*PHONENO*/{
    for (i = 0; i < 5; i++){
        printf("Do you want to enter a phone no?\n");
        scanf("%c", &c);
        fflush(stdin);

        if (c != 'Y'){
            while (i < 5){
                cur -> phnno[i][0] = '\0';
                i++;
            }
            break;
        }

        printf("Enter phone number:\n");
        scanf("%s", str);
        fflush(stdin);

        strcpy(cur -> phnno[i], str);
    }
    }

    /*ADDRESS*/{
    printf("Enter address:\n");
    scanf("%s", str);
    fflush(stdin);

    strcpy(cur -> add, str);
    }

    /*EMAIL ADDRESS*/{
    for (i = 0; i < 5; i++){
        printf("Do you want to enter an email?\n");
        scanf("%c", &c);
        fflush(stdin);

        if (c != 'Y'){
            while (i < 5){
                    cur -> email[i][0] = '\0';
                    i++;
            }
            break;
        }

        printf("Enter email address:\n");
        scanf("%s", str);
        fflush(stdin);

        strcpy(cur -> email[i], str);
    }
    }

    /*GROUP*/{
    for (i = 0; i < 5; i++){
        printf("Do you want to add a group?\n");
        scanf("%c", &c);
        fflush(stdin);

        if (c != 'Y'){
            while (i < 5){
                cur -> grp[i][0] = '\0';
                i++;
            }
            break;
        }

        printf("Enter group:\n");
        scanf("%s", str);
        fflush(stdin);

        strcpy(cur->grp, str);
    }
    }

    return h;
}

void view(struct phonebook *h){
    struct phonebook *cur = h;
    char str [51] = {};
    int i = 0, contact = 0;

    while (cur != NULL){
        contact++;
        printf("Contact no %d\n", contact);

        /*NAME*/
        printf("Name = %s\n", cur -> name);
        printf("\n");

        /*PHONE NUMBERS*/
        for (i = 0; i < 5; i++){
            strcpy(str, cur -> phnno[i]);

            if (strlen(str) == 0){
                break;
            }

            printf("Number %d = %s\n", i+1, str);
        }
        printf("\n");

        /*ADDRESS*/
        printf("Address = %s\n", cur -> add);
        printf("\n");

        /*EMAIL ADDRESS*/
        for (i = 0; i < 5; i++){
            strcpy(str, cur->email[i]);

            if (strlen(str) == 0){
                break;
            }

            printf("Email %d = %s\n", i+1, str);
        }
        printf("\n");

        /*GROUP*/
        for (i = 0; i < 5; i++){
            strcpy(str, cur -> grp[i]);

            if (strlen(str) == 0){
                break;
            }

            printf("Group %d = %s\n", i+1, str);
        }
        printf("\n");

        cur = cur -> next;
    }

    return;
}
