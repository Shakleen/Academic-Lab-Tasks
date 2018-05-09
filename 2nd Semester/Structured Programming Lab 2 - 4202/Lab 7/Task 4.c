#include <stdio.h>

int a[100][100];

int main(){
    int n = 0, i = 0, j = 0, sx = 0, sy = 0, ex = 0, ey = 0;

    scanf("%d", &n);


    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);

    if (maze(sx, sy, ex, ey, n)){
        printf("Possible\n");
    }
    else{
        printf("Impossible\n");
    }

    return 0;
}

int maze (int sx, int sy, int ex, int ey, int size){
    if (a[sx][sy]){
        a[sx][sy] = 0;

        if (sx == ex && sy == ey){
            return 1;
        }

        int x = 0, y = 0, i = 0, up = 0, down = 0, left = 0, right = 0;

        right = maze(sx+1,sy,ex,ey,size);
        up = maze(sx,sy+1,ex,ey,size);
        left = maze(sx-1,sy,ex,ey,size);
        down = maze(sx,sy-1,ex,ey,size);

        return (up||down||left||right);
    }
    else{
        return 0;
    }
}
