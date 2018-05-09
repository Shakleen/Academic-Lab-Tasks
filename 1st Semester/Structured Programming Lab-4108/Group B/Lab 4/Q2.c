    #include <stdio.h>

int main(){
    int n=0, sum=0, i=0;

    printf("Enter an integer:\n");
    scanf("%d", &n);

    for (n; n>0; n=n/10){
        i=n%10;
        sum+=i;
    }

    printf("\nSum: %d", sum);

    return 0;
}
