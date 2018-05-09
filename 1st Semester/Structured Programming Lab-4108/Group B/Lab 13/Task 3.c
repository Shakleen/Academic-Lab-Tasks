#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *fp=fopen("Q3.txt", "r");
    int v=0, c=0;
    while(1){
        char ch=fgetc(fp);
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            v++;
        else if (ch>=97 && ch<=122)
            c++;
        if(ch==EOF) break;
    }
    printf("Number of Vowels=%d\nNumber of Consonants=%d\n", v, c);
    fclose(fp);

    return 0;
}
