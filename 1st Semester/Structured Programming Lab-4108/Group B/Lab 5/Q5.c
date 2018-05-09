#include <stdio.h>
#include <ctype.h>

int main(){
    int w=0;
    printf("Enter weight of watermelon:\n");
    scanf("%d", &w);

    if (w==0 || w==2 || w%2!=0)
        printf("NO");
    else
        printf("YES");

    return 0;
}
