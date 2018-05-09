#include <stdio.h>
int digits[10];
int main(){
    long long int n,a=0,b=0;
    scanf("%lld", &n);

    int i=0,j=0,use1=0,use2=0;
    while(n>0){
        digits[n%10]++;
        n/=10;
    }
    i=9;
    while (i>=0){
//Finding biggest possible no
        if(use1<digits[9-i]){
            a+=(9-i)*(pow(10,j)+0.1);
            use1++;
            j++;
        }
        else{
            use1=0;
            i--;
        }
    }
//Finding Smallest possible number
    j--;
    if (digits[0]){
        i=1;
        while(i<10){
            if(digits[i]){
                b+=i*(pow(10,j)+0.1);
                digits[i]--;
                j--;
                break;
            }
        }
    }
    i=0;
    while (i<10){
        if (use2<digits[i]){
            b+=i*(pow(10,j)+0.1);
            j--;
            use2++;
        }
        else{
            i++;
            use2=0;
        }
    }

    printf("%lld - %lld = 9 * %lld\n",a,b, (a-b)/9);
    return 0;
}
