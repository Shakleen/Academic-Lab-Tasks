#include <iostream>

using namespace std;

int main(){
    int n = 0, s = 0, g = 1;;

    cin >> n >> s;

    int a[n+1][n+1] = {};

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int up = i-s, down = i+s, left = j-s, right = j+s, avg = 0, total = 0, cnt = 0;

            for (int k = up; k <= down; k++){
                for (int l = left; l <= right; l++){
                    if (k>=0 && k<n && l>=0 && l<n){
                        total += a[k][l];
                        cnt++;
//cout << "k = " << k << " l = " << l << " a = " << a[k][l] << " Total = " << total << " Cnt = " << cnt << endl;
                    }
                }
            }
            avg = total/cnt;
            cout << avg << " ";
//cout << "T = " << total << " Cnt = " << cnt << " Avg = " << avg << endl;
        }
        cout << endl;
    }

    return 0;
}
