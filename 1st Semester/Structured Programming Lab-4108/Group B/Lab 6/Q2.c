#include <Stdio.h>
#include <math.h>

int main(){
    int choice=0, x=0, y=0;
    char ch=0,ch1=0;
    do{
        printf("Enter choice:");
        printf("\n1.Addition\n2.Subtraction\n3.Multiplication");
        printf("\n4.Division\n5.Square\n6.Square-root\n7.Exit\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                start1:
                printf("Enter 1st value:\n");
                scanf("%d", &x);
                printf("Press C/c to input the 1st value again or press something else:\n");
                scanf(" %c", &ch1);
                if (ch1=='c' || ch1=='C')   goto start1;
                printf("Enter 2nd value:\n");
                scanf("%d", &y);
                printf("%d + %d = %d", x, y, x+y);
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 2:{
                start2:
                printf("Enter 1st value:\n");
                scanf("%d", &x);
                printf("Press C/c to input the 1st value again or press something else:\n");
                scanf(" %c", &ch1);
                if (ch1=='c' || ch1=='C')   goto start2;
                printf("Enter 2nd value:\n");
                scanf("%d", &y);
                printf("%d - %d = %d", x, y, x-y);
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 3:{
                start3:
                printf("Enter 1st value:\n");
                scanf("%d", &x);
                printf("Press C/c to input the 1st value again or press something else:\n");
                scanf(" %c", &ch1);
                if (ch1=='c' || ch1=='C')   goto start3;
                printf("Enter 2nd value:\n");
                scanf("%d", &y);
                printf("%d X %d = %d", x, y, x*y);
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 4:{
                start4:
                printf("Enter 1st value:\n");
                scanf("%d", &x);
                printf("Press C/c to input the 1st value again or press something else:\n");
                scanf(" %c", &ch1);
                if (ch1=='c' || ch1=='C')   goto start4;
                printf("Enter 2nd value:\n");
                scanf("%d", &y);
                printf("%d / %d = %f", x, y, (double)x/y);
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 5:{
                printf("Enter value:\n");
                scanf("%d", &x);
                printf("%d", x*x);
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 6:{
                printf("Enter value:\n");
                scanf("%d", &x);
                printf("%f", (double)sqrt(x));
                printf("\nAgain?\n");
                scanf(" %c", &ch);
                break;
            }
            case 7:
                break;
        }
    }   while (ch=='B' || ch=='b');
}
