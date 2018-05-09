#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000

void mozek(int pos, int n, int left, int right);

int main(){
    int n = 0;

    scanf("%d", &n);

    mozek(0,n,0,0);

    return 0;
}

void mozek(int pos, int n, int left, int right){
    static char str[MAXSIZE];

    if(right == n){
        printf("%s\n", str);
        return;
    }
    else{
        if(left > right){
            str[pos] = ')';
            mozek(pos+1, n, left, right+1);
        }

        if(left < n){
            str[pos] = '(';
            mozek(pos+1, n, left+1, right);
        }
    }
}
