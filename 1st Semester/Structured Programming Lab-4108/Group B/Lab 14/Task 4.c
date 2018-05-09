#include <stdio.h>
#include <string.h>
int main(){
    int n=0,o=2018,yo=0,m1,d1,m2,d2;
    char oname[100]={}, yname[100]={};
    scanf("%d", &n);
    while(n--){
        int d,m,y;
        char pname[100]={};
        scanf(" %s %d %d %d", &pname, &d, &m, &y);
        //For Oldest
        if(y<o){
            strcpy(oname,pname);
            o=y;
            m1=m;
            d1=d;
        }
        else if(y==o){
            if(m<m1){
                strcpy(oname,pname);
                o=y;
                m1=m;
                d1=d;
            }
            else if (m==m1){
                if(d<d1){
                    strcpy(oname,pname);
                    o=y;
                    m1=m;
                    d1=d;
                }
            }
        }
        //For Youngest
        if(y>yo){
            strcpy(yname,pname);
            yo=y;
            m2=m;
            d2=d;
        }
        else if(y==o){
            if(m<m2){
                strcpy(yname,pname);
                yo=y;
                m2=m;
                d2=d;
            }
            else if (m==m2){
                if(d<d2){
                    strcpy(yname,pname);
                    yo=y;
                    m2=m;
                    d2=d;
                }
            }
        }
    }
    printf("%s\n%s",yname,oname);
    return 0;
}
