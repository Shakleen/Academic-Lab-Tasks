#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct phonebook
{
    char name [51];
    char phnno [5] [51];
    char add [51];
    char email [5] [51];
    char grp [5] [51];
    struct phonebook *next;
};

struct phonebook *load (struct phonebook *h);
struct phonebook *create (struct phonebook *h);
void view (struct phonebook *h);
void store (struct phonebook *h);

int main()
{
    struct phonebook *head = NULL;
    char str [] = "      ", po [] = "===>> ", ch = 0;
    int i = 1;

    head = load (head);

    while (1)
    {
        system("cls");
        printf("Menu:\n\n");
        if (i == 1)            printf("%s1->CREATE NEW CONTACT\n\n", po);
        else                   printf("%s1->Create New Contact\n\n", str);
        if (i == 2)            printf("%s2->VIEW ALL CONTACTS\n\n", po);
        else                   printf("%s2->View All Contacts\n\n", str);
        if (i == 3)            printf("%s3->EXIT\n\n", po);
        else                   printf("%s3->Exit\n\n", str);
        printf("\n\nPress UP or DOWN arrow key to navigate\n\n");

        ch = getche();

        if (ch == 72)
        {
            if (i > 1)  i--;
            else        i = 3;
        }
        else if (ch == 80)
        {
            if (i < 3)  i++;
            else        i = 1;
        }
        else if (ch == 13)
        {
            if (i == 1)
            {
                system("cls");
                head = create (head);
            }
            else if (i == 2)
            {
                system("cls");
                view (head);
            }
            else if (i == 3)
            {
                system("cls");
                store(head);
            }
        }
    }

    return 0;
}

struct phonebook *create (struct phonebook *h)
{
    struct phonebook *cur = (struct phonebook*) malloc (sizeof(struct phonebook)), *itr = h, *prev = NULL;
    int i = 0, j = 0, flag = 1;
    char c = 0;
    char str [51] = {};

    /*NAME*/
    {
        printf("\n\n\t\tEnter Contact Name:\n\n\n\t\t");
        gets(str);
        fflush(stdin);

        strcpy(cur -> name, str);
    }

    /*LINKING*/
    {
        if (h == NULL)
        {
            h = cur;
            cur -> next = NULL;
        }
        else
        {
            while (itr != NULL)
            {
                if (stricmp(cur -> name, itr -> name) <= 0)
                {
                    if (prev == NULL)
                    {
                        h = cur;
                    }
                    else
                    {
                        prev -> next = cur;
                    }

                    cur -> next = itr;
                    flag = 0;
                    break;
                }

                prev = itr;
                itr = itr -> next;
            }

            if (flag)
            {
                itr -> next = cur;
                cur -> next = NULL;
            }
        }
    }

    /*PHONENO*/
    {
        for (i = 0; i < 5; )
        {
            printf("\n\n\t\tDo you want to enter a phone no? (Y/y for YES and N/n for NO)\n\n\n\t\t");
            c = getche();
            fflush(stdin);

            if (c == 'N' || c == 'n')
            {
                while (i < 5)
                {
                    cur -> phnno[i][0] = '\0';
                    i++;
                }
                break;
            }
            else if (c == 'Y' || c == 'y')
            {
                printf("\n\n\t\tEnter phone number:\n\n\t\t");
                scanf("%s", str);
                fflush(stdin);

                strcpy(cur -> phnno[i], str);
                i++;
            }
            else
            {
                printf("\n\n\t\tWrong input. Please try again!\n");
            }
        }
    }

    /*ADDRESS*/
    {
        printf("\n\n\t\tEnter address:\n\n\t\t");
        scanf("%s", str);
        fflush(stdin);

        strcpy(cur -> add, str);
    }

    /*EMAIL ADDRESS*/
    {
        for (i = 0; i < 5; )
        {
            printf("\n\n\t\tDo you want to enter an email address? (Y/y for YES and N/n for NO)\n\n\n\t\t");
            c = getche();
            fflush(stdin);

            if (c == 'N' || c == 'n')
            {
                while (i < 5)
                {
                    cur -> email[i][0] = '\0';
                    i++;
                }
                break;
            }
            else if (c == 'Y' || c == 'y')
            {
                printf("\n\n\t\tEnter email address:\n\n\t\t");
                scanf("%s", str);
                fflush(stdin);

                strcpy(cur -> email[i], str);
                i++;
            }
            else
            {
                printf("\n\n\t\tWrong input. Please try again!\n");
            }
        }
    }

    /*GROUP*/
    {
        for (i = 0; i < 5; )
        {
            printf("\n\n\t\tDo you want to enter a group for contact? (Y/y for YES and N/n for NO)\n\n\n\t\t");
            c = getche();
            fflush(stdin);

            if (c == 'N' || c == 'n')
            {
                while (i < 5)
                {
                    cur -> grp[i][0] = '\0';
                    i++;
                }
                break;
            }
            else if (c == 'Y' || c == 'y')
            {
                printf("\n\n\t\tEnter group name:\n\n\t\t");
                scanf("%s", str);
                fflush(stdin);

                strcpy(cur -> grp[i], str);
                i++;
            }
            else
            {
                printf("\n\n\t\tWrong input. Please try again!\n");
            }
        }
    }

    return h;
}

void view(struct phonebook *h)
{
    struct phonebook *cur = h;
    char str [51] = {};
    int i = 0, contact = 0;

    printf("\n\n\t\tCONTACT INFO\n\n\t\t");

    while (cur != NULL)
    {
        contact++;
        printf("\n\t\tContact no %d\n\t\t", contact);

        /*NAME*/
        printf("Name = %s\n\t\t", cur -> name);
        printf("\n\t\t");

        /*PHONE NUMBERS*/
        for (i = 0; i < 5; i++)
        {
            strcpy(str, cur -> phnno[i]);

            if (strlen(str) == 0)
            {
                break;
            }

            printf("Number %d = %s\n\t\t", i+1, str);
        }
        printf("\n\t\t");

        /*ADDRESS*/
        printf("Address = %s\n\t\t", cur -> add);
        printf("\n\t\t");

        /*EMAIL ADDRESS*/
        for (i = 0; i < 5; i++)
        {
            strcpy(str, cur->email[i]);

            if (strlen(str) == 0)
            {
                break;
            }

            printf("Email %d = %s\n\t\t", i+1, str);
        }
        printf("\n\t\t");

        /*GROUP*/
        for (i = 0; i < 5; i++)
        {
            strcpy(str, cur -> grp[i]);

            if (strlen(str) == 0)
            {
                break;
            }

            printf("Group %d = %s\n\t\t", i+1, str);
        }
        printf("\n");

        cur = cur -> next;
    }

    char exit_view = 0;

    printf("\n\n\t\tExit viewing and return to menu?(E/e to Exit)\n\t\t");

    fflush(stdin);

    exit_view = getche();

    if (exit_view == 'E' || exit_view == 'e')
    {
        return;
    }
}

void store (struct phonebook *h)
{
    struct phonebook *cur = h;
    FILE *fp;

    if ( (fp=fopen("Contacts.txt", "wb")) == NULL )
    {
        printf("Error in saving contact!\n");
        exit(1);
    }

    while ( cur != NULL )
    {
        if ( fwrite(cur, sizeof(struct phonebook), 1, fp) != 1 )
        {
            printf("Error in writing contact info!\n");
            exit(1);
        }

        cur = cur -> next;
    }

    fclose(fp);

    exit(1);
}

struct phonebook *load (struct phonebook *h)
{
    struct phonebook *cur = (struct phonebook*) malloc (sizeof(struct phonebook));
    FILE *fp;

    if ( (fp=fopen("Contacts.txt", "rb")) == NULL )
    {
        printf("Error in loading contact!\n");
        exit(1);
    }

    while ( fread(cur, sizeof(struct phonebook), 1, fp) == 1 )
    {

        cur -> next = h;
        h = cur;
        cur = (struct phonebook*) malloc (sizeof(struct phonebook));
    }

    fclose(fp);

    return h;
}
