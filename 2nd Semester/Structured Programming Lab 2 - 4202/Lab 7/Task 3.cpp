#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2,i,j,a[101],b[101],m,c,x;
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a,a+n1);
    sort(b,b+n2);

    if((n1+n2)%2)
        m=((n1+n2)/2)+1;
    else
        m=(n1+n2)/2;
    i=0;
    j=0;
    for(c=0;c<m;c++)
    {
        if(a[i]<b[j])
        {
            x=a[i];
            i++;
        }
        else
        {
            x=b[j];
            j++;
        }
    }
    printf("%d",x);
    return 0;
}
