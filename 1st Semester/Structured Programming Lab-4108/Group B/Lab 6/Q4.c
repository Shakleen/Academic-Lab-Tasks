#include <stdio.h>

int com(int x, int y);

int main(){
    int a, b;
    printf("Please enter two values:\n");
    scanf("%d %d", &a, &b);
    printf("The bigger value is %d", com(a, b));
    return 0;
}

int com(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}
