#include <stdio.h>

int main(){
    int n = 0, cnt = 0, no = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        no = i;
        if ( !(no%5) ){
            while ( !(no%5) ){
                no/=5;
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}
