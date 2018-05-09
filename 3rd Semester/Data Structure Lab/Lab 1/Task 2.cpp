#include <bits/stdc++.h>

int main(){
    char numbers[101][101], number[101], answer[200];
    int no=0, i=0, j=0, k=0, sum=0, carry=0;
    bool f=false;

    for(i=0; i<101; i++){
        memset(numbers[i], sizeof(numbers[i]), 0);
    }
    memset(number, sizeof(number), 0);
    memset(answer, sizeof(answer), 0);

    while(1){
        scanf("%s", &number);
        if(strlen(number)==1 && number[0]=='0')     break;
        for(j=strlen(number)-1, k=0; j>=0; j--, k++)
            numbers[no][k] = number[j];
        no++;
    }

//    for(int i=0; i<no; i++){
//        for(int j=0; j<strlen(numbers[i]); j++)
//            printf("%c",numbers[i][j]);
//        printf("\n");
//    }

    sum = carry = 0;

    for(i=0; i<101; i++){
        sum = carry;
        for(int j=0; j<no; j++)
            if(i<strlen(numbers[j]))
                sum += (numbers[j][i]-'0');
        answer[i] = sum%10 + '0';
        carry = sum/10;
    }

    while (carry){
        answer[++i] = carry%10+'0';
        carry /= 10;
    }

    for(i--; i>=0; i--){
        if(answer[i]!='0' || f){
            printf("%c", answer[i]);
            f = true;
        }
    }

    return 0;
}
