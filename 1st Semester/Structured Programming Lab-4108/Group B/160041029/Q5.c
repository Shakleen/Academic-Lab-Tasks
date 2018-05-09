#include <stdio.h>

int main(){
    int n=0;
    scanf("%d", &n);
    int i=0,day=1,j=1,k=0,d[7]={},range=1900+n;
    //k = looping through the week
    for(i=1900; i<range; i++){//Going through the years
        for(j=1; j<=12; j++){//Going through the months
            if (j==4 || j==6 || j==8 || j==11){//For 30 day months
                for(day=1; day<=31; day++,k++){
                    if (k==7)   //Resetting the loop
                        k=0;
                    if (day==13)//Counting the 13s
                        d[k]++;
                }
            }
            else if (j==2){//for February
                if (!(i%400) && !(i%4)){//For Leap Years
                    for(day=1; day<=29; day++,k++){
                        if (k==7)
                            k=0;
                        if (day==13){
                            d[k]++;
                        }
                    }
                }
                else{//For normal years
                    for(day=1; day<=28; day++,k++){
                        if (k==7)
                            k=0;
                        if (day==13){
                            d[k]++;
                        }
                    }
                }
            }
            else{//For 31 day months
                for(day=1; day<=31; day++,k++){
                    if (k==7)
                        k=0;
                    if (day==13){
                        d[k]++;
                    }
                }
            }
        }
    }
    for(i=0; i<7; i++){
        switch(i){
        case 0:
            printf("\nMonday ");
            break;
        case 1:
            printf("\nTuesday ");
            break;
        case 2:
            printf("\nWednesday ");
            break;
        case 3:
            printf("\nThursday ");
            break;
        case 4:
            printf("\nFriday ");
            break;
        case 5:
            printf("\nSaturday ");
            break;
        case 6:
            printf("\nSunday ");
            break;
        }
        printf("%d",d[i]);
    }
    return 0;
}
