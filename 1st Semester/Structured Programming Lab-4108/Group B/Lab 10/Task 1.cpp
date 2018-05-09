#include <bits/stdc++.h>
#define N 1000
char str1[N], str2[N],temp[5];
void mygets(char ch[]);
void myputs(char ch[]);
int mystrlen(char ch[]);
void mystrcat (char ch1[], char ch2[]);
int mystrcmp (char ch1[], char ch2[]);
int mystrrstr (char ch1[], char ch2[]);
void mystrcpy(char ch1[],char ch2[]);
int main(){
    int s1,s2,dif;
    mygets(str1);
    myputs(str1);
    s1=mystrlen(str1);
    printf("\n%d\n",s1);
    mygets(str2);
    myputs(str2);
    s2=mystrlen(str2);
    printf("\n%d\n",s2);
    dif=mystrcmp(str1,str2);
    printf("\n%d\n",dif);
    mystrcat(str1,str2);
    myputs(str1);
    printf("\n");
    myputs(str2);
    printf("\n");
    int x=mystrrstr(str1,str2);
    printf("%d\n",x);
    mystrcpy(str1,str2);
    myputs(str1);
    printf("\n");
    myputs(str2);
    printf("\n");
    return 0;
}
void mygets(char ch[]){
    int i=0;
    for (i=0; i<1000; i++){
        ch[i]=getchar();
        if (ch[i]=='\n')
            break;
    }
    ch[i]='\0';
}
void myputs(char ch[]){
    int i=0;
    for (i=0; i<1000; i++){
        if (ch[i]=='\0')    break;
        printf("%c",ch[i]);
    }
}
int mystrlen(char ch[]){
    int i=0;
    while(1){
        if (ch[i]=='\0')
            break;
        i++;
    }
    return i;
}
void mystrcat(char ch1[],char ch2[]){
    int i=mystrlen(ch1),j=0,k=mystrlen(ch2);
    while(j<=k)    ch1[i++]=ch2[j++];
}
int mystrcmp(char ch1[],char ch2[]){
    int i=0;
    for (i=0; i<=1000; i++)
        if (ch1[i]!=ch2[i])
            return ch1[i]-ch2[i];
}
int mystrrstr(char ch1[],char ch2[]){
    int i=0,j=0,s2=mystrlen(ch2);
    for (i=0;i<1000;i++){
        if (ch1[i]==ch2[j]){
            j++;
            if (j==s2)  break;
        }
        else
            j=0;
    }
    return i-j+1;
}
void mystrcpy(char ch1[],char ch2[]){
    int i=0, s2=mystrlen(ch2);
    for (i=0;i<=s2;i++){
        ch1[i]=ch2[i];
    }
}
