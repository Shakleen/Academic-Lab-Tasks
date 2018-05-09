#include <bits/stdc++.h>
using namespace std;
int digit[10],d[10];

int main(){
    int n = 0, i = 0, j = 10, temp = 0, temp2 = 0, f = 0;

    scanf("%d", &n);

    for (i = 0; i < 10; i++,n/=10){
        d[i] = digit[i] = (n%10);

        if (!n){
            break;
        }
    }

    j = i;

    sort(d, d+j);

    for (i = j-1; i >= 0; i--){
        if (f){
            if (digit[i] == temp2){
                digit[i] = temp;
                break;
            }
        }
        else{
            if (d[i] == digit[i]){
                continue;
            }
            else{
                temp = digit[i];
                temp2 = d[i];
                digit[i] = d[i];
                f = 1;
            }
        }
    }

    for (i = j-1; i >= 0; i--){
        n += digit[i];

        if (i != 0){
            n*=10;        }
    }

    printf("%d", n);
    return 0;
}
