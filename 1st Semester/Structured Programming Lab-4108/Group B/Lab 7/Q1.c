#include <stdio.h>

int fact (int a);
int square (int a);

int main(){
    int marks[10]={2,6,9,7,5,4,2,5,9,8}, i=0, j=0;
    printf("Even Numbered Elements:");
    printf("\nName\t\tvalue\tfactorial\n");
    for (i=0; i<10; i+=2)
        printf("marks[%d]\t%d\t%d\n", i, marks[i], fact(marks[i]));
    printf("Odd Numbered Elements:");
    printf("\nName\t\tvalue\tfactorial\n");
    for (i=1; i<10; i+=2)
        printf("marks[%d]\t%d\t%d\n", i, marks[i], square(marks[i]));

    return 0;
}

int fact (int a){
    if (a<=0)
        return 1;
    else
        return (a*fact(a-1));
}

int square (int a){
    return a*a;
}
