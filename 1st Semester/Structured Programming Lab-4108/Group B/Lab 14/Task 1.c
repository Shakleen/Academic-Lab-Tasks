#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player{
    char name[100];
    char clubname[25];
    int goals;
    int assists;
};

int main(){
    int i=0,j=0;
    FILE *fp;
    if ( (fp=fopen("players.txt","r")) == NULL ){
        printf("Error opening file!\n");
        exit(1);
    }
    struct player p[15]={};
    for(i=0; i<15; i++){
        //Taking name input
        char ltr=0, cnt=0;
        while(1){
            ltr=fgetc(fp);
            if (ltr == EOF){
                printf("Error reading name!\n");
                exit(1);
            }
            if (ltr == '\n')    break;
            p[i].name[cnt]=ltr;
            cnt++;
        }
        p[i].name[cnt]='\0';
        //Taking club name input
        cnt=0;
        ltr=0;
        while (1){
            ltr=fgetc(fp);
            if (ltr == EOF){
                printf("Error reading club name!\n");
                exit(1);
            }
            if (ltr == '\n')    break;
            p[i].clubname[cnt]=ltr;
            cnt++;
        }
        p[i].clubname[cnt]='\0';
        //Taking goals input
        int j=0;
        char g[3]={},ch=0;
        for (j=0; j<3; j++){
            ch=fgetc(fp);
            if(ch==' '){
                g[j]='\0';
                break;
            }
            g[j]=ch;
        }
        p[i].goals=atoi(g);
        //Taking assists input
        j=0;
        g[0]='\0';
        for (j=0; j<3; j++){
            ch=fgetc(fp);
            if(ch=='\n'){
                g[j]='\0';
                break;
            }
            g[j]=ch;
        }
        p[i].assists=atoi(g);
    }
    //Sorting the structure
    for(i=0; i<14; i++){
        for (j=0; j<14-i; j++){
            if (strcmp(p[j].clubname, p[j+1].clubname) == 1){
                char temp[100]={};
                //moving the club name
                strcpy(temp,p[j].clubname);
                strcpy(p[j].clubname, p[j+1].clubname);
                strcpy(p[j+1].clubname, temp);
                //moving the player name
                strcpy(temp,p[j].name);
                strcpy(p[j].name, p[j+1].name);
                strcpy(p[j+1].name, temp);
                //moving the player goals
                int tmp=p[j].goals;
                p[j].goals=p[j+1].goals;
                p[j+1].goals=tmp;
                //moving assists
                tmp=p[j].assists;
                p[j].assists=p[j+1].assists;
                p[j+1].assists=tmp;
            }
            else{
                if (p[j].goals<p[j+1].goals){
                char temp[100]={};
                //moving the player name
                strcpy(temp,p[j].name);
                strcpy(p[j].name, p[j+1].name);
                strcpy(p[j+1].name, temp);
                //moving the player goals
                int tmp=p[j].goals;
                p[j].goals=p[j+1].goals;
                p[j+1].goals=tmp;
                //moving assists
                tmp=p[j].assists;
                p[j].assists=p[j+1].assists;
                p[j+1].assists=tmp;
                }
            }
        }
    }
    //Printing the sorted structure
    for(i=0; i<14; i++)
        printf("%s %s %d %d\n",p[i].clubname,p[i].name,p[i].goals,p[i].assists);
    return 0;
}
