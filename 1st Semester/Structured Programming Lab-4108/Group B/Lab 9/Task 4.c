#include <stdio.h>
long long int fact(int num);
int main(){
    int n=0;
    printf("Enter number:\n");
    scanf("%d", &n);
    printf("Fatorial of %d is %lld\n", n, fact(n));
    return 0;
}
long long int fact(int num){
    if (num==0)
        return 1;
    else
        return num*fact(num-1);
}
