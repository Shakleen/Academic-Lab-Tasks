#include <stdio.h>

int main(){
    int a;
    char ch;
    float f;
    double dl;

    printf("Enter an int, a char, a float and a double no:");
    scanf("%c %d %f %lf", &ch, &a, &f, &dl);
    printf("\n%c\n%d\n%f\n%lf", ch, a, f, dl);
    return 0;
}
