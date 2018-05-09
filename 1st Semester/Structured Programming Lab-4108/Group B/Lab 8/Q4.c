#include <stdio.h>

int main(){
    int i,j;
    char a[3][3];
    printf("Enter Tic Tac Toe:\n");
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            scanf(" %c", &a[i][j]);
    printf("\n");
//    printf("%c\n", a[0][0]);
//    for (i=0; i<3; i++){
//        for (j=0; j<3; j++)
//            printf("%c ", a[i][j]);
//        printf("\n");
//    }
    i=0;
    j=0;
    if (a[i][j]==a[i+1][j+1] && a[i][j]==a[i+2][j+2]){
//        printf("Tac 1");
        if (a[i][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j]=='o')
            printf("Player 2 Wins\n");
    }
    else if (a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]){
        if (a[i][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j]=='o')
            printf("Player 2 Wins\n");
//        printf("Tac 2");
    }
    else if (a[i+1][j]==a[i+1][j+1] && a[i+1][j]==a[i+1][j+2]){
        if (a[i+1][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i+1][j]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 3");
    }
    else if (a[i+2][j]==a[i+2][j+1] && a[i+2][j]==a[i+2][j+2]){
        if (a[i+2][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i+2][j]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 4");
    }
    else if (a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]){
        if (a[i][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 5");
    }
    else if (a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]){
        if (a[i][j]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 6");
    }
    else if (a[i][j+1]==a[i+1][j+1] && a[i][j+1]==a[i+2][j+1]){
        if (a[i][j+1]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j+1]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 7");
    }
    else if (a[i][j+2]==a[i+1][j+2] && a[i][j+2]==a[i+2][j+2]){
        if (a[i][j+2]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j+2]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 8");
    }
    else if (a[i][j+2]==a[i+1][j+1] && a[i][j+2]==a[i+2][j]){
        if (a[i][j+2]=='x')
            printf("Player 1 Wins\n");
        else if (a[i][j+2]=='o')
            printf("Player 2 Wins\n");
//            printf("Tac 9");
    }
    else
        printf("Draw!");
    return 0;
}
