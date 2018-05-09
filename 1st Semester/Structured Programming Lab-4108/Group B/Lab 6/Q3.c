#include <stdio.h>

void fibonacci(int x);
int isprime (int y);

int main(){
    int n=0;
    printf("Enter n:\n");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}

void fibonacci(int x){
    int i=1, j=1, k=i+j, index=3;
    printf("%d %d ", i, j);
    while (index<=x){
        if (isprime(k))
            printf("%d ", k);
        k=i+j;
        i=j;
        j=k;
        index++;
    }
}

int isprime(int y){
    int i=2;
    for (i=2; i<=y/2; i++){
        if (y%i==0)
            return 0;
    }
    return 1;
}
