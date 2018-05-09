#include <bits/stdc++.h>

using namespace std;

int a[11],b[11],c[11];

int main(){
    int n = 0, m = 0, o = 0, i = 0, j = 0, k = 0, l = 0, s = 0, e = 0, r = INT_MAX;

    scanf("%d", &n);
    for (i = 0; i < n; i++)    scanf("%d", &a[i]);

    scanf("%d", &m);
    for (i = 0; i < m; i++)    scanf("%d", &b[i]);

    scanf("%d", &o);
    for (i = 0; i < o; i++)    scanf("%d", &c[i]);


    for (i = 0; i < n; i++){
        int num1 = a[i];

        for (j = 0; j < m; j++){
            int num2 = b[j];

            for (k = 0; k < o; k++){
                int num3 = c[k],
                    mx = max(num1,max(num2,num3)),
                    mn = min(num1,min(num2,num3));

                if (r > (mx-mn)){
                    e = mx;
                    s = mn;
                    r = mx-mn;
                }
            }
        }
    }

    printf("%d %d\n", s, e);

    return 0;
}
