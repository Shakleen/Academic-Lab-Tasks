#include <stdio.h>

int s(int i);

int main(){
    int num=0;
    printf("Enter number:\n");
    scanf("%d", &num);
    printf("The sum of the digits are: %d\n", s(num));
    return 0;
}

int s(int i){
    if (i>0){
        int n=i%10;
        i/=10;
        return n+s(i);
    }
}
