#include <bits/stdc++.h>

int main(){
    int n = 0;

    scanf("%d", &n);

    int a[n+1][n+1], vis[n+1][n+1];
    memset(vis,0,sizeof(vis));

    for (int i = 1, k = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = k++;
//            printf("%d ", a[i][j]);
        }
//        printf("\n");
    }

    int i = 1, j = 1, cnt = 0, si = 1, sj = 1, ei = n, ej = n;

    while (cnt != n*n){
        if (i == si && j == sj){
            for (j = sj; j <= ej; j++){
                if (!vis[i][j]){
                    printf("%d ", a[i][j]);
                    vis[i][j] = 1;
                }
                cnt++;
            }

            j = ej;
            si++;
            i = si;
        }
        else if (i == si && j == ej){
            for (i = si; i <= ei; i++){
                if (!vis[i][j]){
                    printf("%d ", a[i][j]);
                    vis[i][j] = 1;
                }
                cnt++;
            }

            i = ei;
            ej--;
            j = ej;
        }
        else if (i == ei && j == ej){
            for (j = ej; j >= sj; j--){
                if (!vis[i][j]){
                    printf("%d ", a[i][j]);
                    vis[i][j] = 1;
                }
                cnt++;
            }

            j = sj;
            ei--;
            i = ei;
        }
        else if (i == ei && j == sj){
            for (i = ei; i >= si; i--){
                if (!vis[i][j]){
                    printf("%d ", a[i][j]);
                    vis[i][j] = 1;
                }
                cnt++;
            }

            i = si;
            sj++;
            j = sj;
        }
    }

    return 0;
}
