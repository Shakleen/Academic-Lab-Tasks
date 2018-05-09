#include <bits/stdc++.h>

int main(){
    int DD, MM, YY, BD, BM, BY, t, temp;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d.%d.%d %d.%d.%d", &DD, &MM, &YY, &BD, &BM, &BY);

//        printf("Program date = %d.%d.%d\n", DD, MM, YY);
        printf("B Birth date = %d.%d.%d\n", BD, BM, BY);

        // can change with month or day
        if(BY<=12){
            if(BD<BY && BD<BM)          temp=BY, BY=BD, BD=temp;
            else if (BM<BY && BM<BD)    temp=BY, BY=BM, BM=temp;
        }
        // can change with only day
        else if (BY<=31){
            if(BD<BY && BD<BM)          temp=BY, BY=BD, BD=temp;
            else if (BM<BD && BM<BY){
                temp=BY, BY=BM, BM=temp;
                temp=BD, BD=BM, BM=temp;
            }
        }

        if(BD<BM)                       temp=BM, BM=BD, BD=temp;

        printf("A Birth date = %d.%d.%d\n", BD, BM, BY);
    }

    return 0;
}
