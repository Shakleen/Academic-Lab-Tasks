#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;

    scanf("%d", &n);

    int s[n+1] = {}, m[n+1] = {};

    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
        m[i] = (s[i])*(-1);
    }


    sort(s, s+n);
    sort(m, m+n);

    for (int i = 0, j = 0, k = 0; i < n; i++){
        if (s[j] || m[k]){
            if (i%2){
                printf("%d ", (-1)*(m[j]));
                s[n-1-j] = 0;
                j++;
            }
            else{
                printf("%d ", s[k]);
                m[n-1-k] = 0;
                k++;
            }
        }
    }

    return 0;
}
