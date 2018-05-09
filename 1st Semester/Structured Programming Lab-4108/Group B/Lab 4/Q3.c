#include <stdio.h>

int main(){
    int i=0,cl=0, f=0, n1=0, n2=0;
    char scale=0;
    printf("Enter range:\n");
    scanf("%d %d", &n1, &n2);
    printf("\nEnter unit:\n");
    scanf(" %c", &scale);
    printf("Sample Output:\n");
    if (scale=='F'){
        for (i=n1; i<=n2; i+=20){
            cl=(5*(i-32))/9;
            printf("%d\t%d\n", i, cl);
        }
        cl=(5*(n2-32))/9;
        printf("%d\t%d\n", n2, cl);
    }
    else if (scale == 'C'){
        for (i=n1; i<=n2; i+=20){
            f=(9*i)/5+32;
            printf("%d\t%d\n", i, f);
        }
        f=(9*n2)/5+32;
        printf("%d\t%d\n", n2, f);
    }
    return 0;
}
