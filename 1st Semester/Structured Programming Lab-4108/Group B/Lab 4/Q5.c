#include <stdio.h>

int main(){
    int q[5]={0},ms,s,at,i,j,sum;
    printf("Enter the quiz marks: ");
    scanf("%d %d %d %d", &q[0], &q[1], &q[2], &q[3]);
    printf("\nEnter Attendance Marks: ");
    scanf("%d", &at);
    printf("\nEnter mid semester marks: ");
    scanf("%d", &ms);
    printf("\nEnter Semester Final Marks: ");
    scanf("%d", &s);
    printf("\nThe best three quiz marks are: ");
    for (i=0; i<4; i++){
        if (q[i]>q[i+1])
            continue;
        else{
            j=q[i];
            q[i]=q[i+1];
            q[i+1]=j;
        }
    }
    printf("%d %d %d", q[0],q[1],q[2]);
    sum=at+ms+s+q[0]+q[1]+q[2];
    printf("\nTotal marks: %d", sum);
    sum=sum/3;
    printf("\nPercentage: %d%%", sum);
    if (sum>=80)
        printf("\nGrade: A+");
    else if (sum>=75)
        printf("\nGrade: A");
    else if (sum>=70)
        printf("\nGrade: A-");
    else if (sum>=65)
        printf("\nGrade: B+");
    else if (sum>=60)
        printf("\nGrade: B");
    else if (sum>=55)
        printf("\nGrade: B-");
    else if (sum>=50)
        printf("\nGrade: C");
    else
        printf("\nF");
    return 0;
}
