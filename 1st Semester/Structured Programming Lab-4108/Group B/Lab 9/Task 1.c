#include <stdio.h>
void func1(int n);
void func2(int n);
int main(){
    int num=0;
    scanf("%d", &num);
    printf("Printing left to right\n");
    func2(num);
    printf("\nPrinting right to left:\n");
    func1(num);
    return 0;
}
void func1(int n){//Right to left
    printf("%d", n%10);
    n/=10;
    if (n>0)
        func1(n);
}
void func2(int n){//Left to right
    if (n>0){
        func2(n/10);
        printf("%d", n%10);
    }
}
