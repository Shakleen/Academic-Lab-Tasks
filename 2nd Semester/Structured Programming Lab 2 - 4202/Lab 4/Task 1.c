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
void phn_search (struct phonebook *h);
struct phonebook *phn_delete (struct phonebook *h);

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
        if (i == 3)            printf("%s3->Search Contacts\n\n", po);
        else                   printf("%s3->SEARCH CONTACTS\n\n", str);
        if (i == 4)            printf("%s4->Delete Contact\n\n", po);
        else                   printf("%s4->DELETE CONTACT\n\n", str);
        if (i == 5)            printf("%s5->EXIT\n\n", po);
        else                   printf("%s5->Exit\n\n", str);
        printf("\n\nPress UP or DOWN arrow key to navigate\n\n");

        ch = getche();

        if (ch == 72)
        {
            if (i > 1)  i--;
            else        i = 5;
        }
        else if (ch == 80)
        {
            if (i < 5)  i++;
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
                phn_search(head);
            }
            else if (i == 4)
            {
                system("cls");
                head = phn_delete(head);
            }
            else if (i == 5)
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
                prev -> next = cur;
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
    struct phonebook *cur = (struct phonebook*) malloc (sizeof(struct phonebook)), *prev = NULL;
    FILE *fp;
    int i = 0;

    if ( (fp=fopen("Contacts.txt", "rb")) == NULL )
    {
        printf("Error in loading contact!\n");
        exit(1);
    }

    while ( fread(cur, sizeof(struct phonebook), 1, fp) == 1 )
    {

        if ( !i )
        {
            h = prev = cur;
            i++;
        }
        else
        {
            prev -> next = cur;
            prev = cur;
        }

        cur = (struct phonebook*) malloc (sizeof(struct phonebook));
    }

    fclose(fp);

    return h;
}

void phn_search (struct phonebook *h)
{
    int brk = 0;

    while (1)
    {
        struct phonebook *cur = h;
        int in = 0, j = 0, flag = 0, i = 0;
        char str [51] = {}, ch = 0;

        if (brk == 1)
        {
            break;
        }

        /*MENU of search*/
        {
        printf("\t\tSEARCH MENU\n\n");
        printf("\t\tSelect option:\n\n");
        printf("\t\t1->Search By Name\n\n");
        printf("\t\t2->Search By Group\n\n");
        printf("\t\t3->Back\n\n\t\t");
        }

        /*Function*/
        {
        scanf("%d", &i);

        switch (i)
        {
        case 1:
        {
        printf("\t\tEnter name of contact to search\n\n\t\t");
        fflush(stdin);
        gets(str);

        while (cur != NULL)
        {
            if ( !strcmp(str, cur -> name) )
            {
                flag = 1;

                /*Name*/
                printf("\n\n\t\tName : %s\n\n\t\t", cur -> name);

                /*Phone No*/
                for (in = 0; in < 5; in++)
                {
                    if ( strlen(cur -> phnno[in]) )
                    {
                        printf("Phone no %d : %s\n\n\t\t", in+1, cur -> phnno[in]);
                    }
                    else
                    {
                        break;
                    }
                }

                /*Address*/
                printf("Address : %s\n\n\t\t", cur -> add);

                /*Email No*/
                for (in = 0; in < 5; in++)
                {
                    if ( strlen(cur -> email[in]) )
                    {
                        printf("Email Address no %d : %s\n\n\t\t", in+1, cur -> email[in]);
                    }
                    else
                    {
                        break;
                    }
                }

                /*Group*/
                for (in = 0; in < 5; in++)
                {
                    if ( strlen(cur -> grp[in]) )
                    {
                        printf("Group no %d : %s\n\n\t\t", in+1, cur -> grp[in]);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            cur = cur -> next;
        }

        if ( !flag )
        {
            printf("No Contacts Found by that Name!\n\n\t\t");
        }

        printf("Enter e\E exit or b/B to go back\n\n\t\t");

        ch = getche();

        if (ch == 'E' || ch == 'e')
        {
            system("cls");
            break;
        }
        else
        {
            brk = 1;
            break;
        }
        }
        case 2:
        {
        char str [51] = {};

        printf("\n\n\t\tEnter the group of contact to search!\n\n\t\t");
        fflush(stdin);
        gets(str);

        while (cur != NULL)
        {
            for (in = 0; in < 5; in++)
            {
                if ( !strcmp(str, cur->grp[in]) )
                {
                    if (!flag)
                    {
                        printf("\n\n\t\tThe following contact(s) are in the %s group\n\n\t\t", cur -> grp);
                        flag = 1;
                    }

                    /*Name*/
                    printf("Name : %s\n\n\t\t", cur -> name);

                    /*Phone no*/
                    for (j = 0; j < 5; j++)
                    {
                        if ( strlen(cur -> phnno[j]) )
                        {
                            printf("Phone no %d : %s\n\n\t\t", j+1, cur -> phnno[j]);
                        }
                        else
                        {
                            break;
                        }
                    }

                    /*Address*/
                    printf("Address : %s\n\n\t\t", cur -> add);

                    /*Email no*/
                    for (j = 0; j < 5; j++)
                    {
                        if ( strlen(cur -> email[j]) )
                        {
                            printf("Email Address no %d : %s\n\n\t\t", j+1, cur -> email[j]);
                        }
                        else
                        {
                            break;
                        }
                    }

                    /*Group name*/
                    for (j = 0; j < 5; j++)
                    {
                        if ( strlen(cur -> grp[j]) )
                        {
                            printf("Group name %d : %s\n\n\t\t", j+1, cur -> grp[j]);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }

            cur = cur -> next;
        }

        if ( !flag )
        {
            printf("No matches Found!!!\n\n\t\t");
        }

        printf("Enter e\E exit or b/B to go back\n\n\t\t");

        ch = getche();

        if (ch == 'E' || ch == 'e')
        {
            system("cls");
            break;
        }
        else
        {
            brk = 1;
            break;
        }
        break;
        }
        case 3:
        {
            brk = 1;
            break;
        }
        }
        }
    }
    return;
}

struct phonebook *phn_delete (struct phonebook *h)
{
    char str[51] = {}, ch = 0;
    int i = 0, j = 0, k = 0, in = 0, flag = 0;
    struct phonebook *cur = h, *prev = h, *nxt = NULL;

    printf("\n\n\t\tEnter a name to search and delete\n\n\t\t");
    fflush(stdin);
    gets(str);

    while (cur != NULL)
    {
        if ( !stricmp(str, cur -> name) )
        {
            flag = 1;

            /*Name*/
            printf("\n\n\t\tName : %s\n\n\t\t", cur -> name);

            /*Phone No*/
            for (in = 0; in < 5; in++)
            {
                if ( strlen(cur -> phnno[in]) )
                {
                    printf("Phone no %d : %s\n\n\t\t", in+1, cur -> phnno[in]);
                }
                else
                {
                    break;
                }
            }

            /*Address*/
            printf("Address : %s\n\n\t\t", cur -> add);

            /*Email No*/
            for (in = 0; in < 5; in++)
            {
                if ( strlen(cur -> email[in]) )
                {
                    printf("Email Address no %d : %s\n\n\t\t", in+1, cur -> email[in]);
                }
                else
                {
                    break;
                }
            }

            /*Group*/
            for (in = 0; in < 5; in++)
            {
                if ( strlen(cur -> grp[in]) )
                {
                    printf("Group no %d : %s\n\n\t\t", in+1, cur -> grp[in]);
                }
                else
                {
                    break;
                }
            }

            printf("Do you want to delete contact? (d/D) to delete contact\n\n\t\t");

            ch = getche();

            if (ch == 'd' || ch == 'D')
            {
                if (cur == h)
                {
                    h = cur -> next;
                }
                else if (nxt == NULL)
                {
                    prev -> next = NULL;
                }
                else
                {
                    prev -> next = nxt;
                }
                break;
            }
        }

        prev = cur;
        cur = cur -> next;
        if (cur != NULL)    nxt = cur -> next;
    }

    if (!flag)
    {
        printf("\n\n\t\tNo contacts were found!\n\n\t\t");
        printf("Exit?(e/E)");
        k = getche();
    }

    return h;
}
