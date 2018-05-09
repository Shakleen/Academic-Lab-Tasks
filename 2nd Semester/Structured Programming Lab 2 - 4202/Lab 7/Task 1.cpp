#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, i = 0, flag = 1, mx = 0, start = -1, cnt = 0, j = 0, l = 0, ed = -1;

    scanf("%d", &n);

    int a[n], temp[n], sub[n];

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a+n);

    for (int i = 1, j=l=-1; i < n; i++){
        if (a[i] - a[i-1] <= 1){
            if (flag){
                j = i-1;
                flag = 0;
            }

            cnt++;
        }
        else{
            l = i-1;
            flag = 1;

            if (cnt > mx){
                start = j;
                ed = l;
                mx = cnt;
            }
            cnt = 1;

            l = j = i;
        }

        if (i == n-1 && !flag){
            l = i;

            if (cnt > mx){
                start = j;
                ed = l;
            }
        }
    }

    if (start != -1 && ed != -1){
        for (int i = start; i <= ed; i++){
            printf("%d ", a[i]);
        }
    }


    return 0;
}
