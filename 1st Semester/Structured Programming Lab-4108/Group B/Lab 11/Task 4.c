#include <stdio.h>

int main(){
    int m=300;  float fx=300.60006;   char cht='z';
    printf("Using & Operator\n");
    printf("---------------------\n");
    printf("address of m = 0x%x\n",&m);
    printf("address of fx = 0x%x\n",&fx);
    printf("address of cht = 0x%x\n",&cht);
    printf("\nUsing & and * Operator\n");
    printf("---------------------\n");
    printf("Value at the address of m = %d\n", *&m);
    printf("Value at the address of fx = %f\n", *&fx);
    printf("Value at the address of cht = %c\n", *&cht);
    int *ma=&m;
    float *afx=&fx;
    char *acht=&cht;
    printf("Using only Pointer variable\n");
    printf("---------------------\n");
    printf("address of m = 0x%x\n",ma);
    printf("address of fx = 0x%x\n",afx);
    printf("address of cht = 0x%x\n",acht);
    printf("Using only Pointer operator\n");
    printf("---------------------\n");
    printf("address of m = %d\n",*ma);
    printf("address of fx = %f\n",*afx);
    printf("address of cht = %c\n",*acht);
    return 0;
}
