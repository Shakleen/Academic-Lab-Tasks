#include <stdio.h>

int main(){
    float f;

    printf("Enter a float no:");
    scanf("%f", &f);

    printf("%+08.3f", f);
    return 0;
}
