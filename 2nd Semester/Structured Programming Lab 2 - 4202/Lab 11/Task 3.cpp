#include <iostream>

using namespace std;

int main(){
    int n = 0, d = 0, x = 0, y = 0, fact = 1, l = 0, r = 0, u = 0;

    cin >> n >> d;

    bool di[n+1] = {};

    for (int i = 2; i <= n; i++){
        fact *= i;
    }

    y = fact/n;
    x = d/y;

    if (d%y)    x++;

    di[x] = 1;

    l = n-(x*y-d);

cout << "L = " << l << " x = " << x << " y = " << y << endl;
    if (l == 0){
        l++;
    }

cout << "L = " << l << " x = " << x << " y = " << y << endl;
    di[l] = 1;

    for (int i = 1; i <= n; i++){
        if (!di[i] && !r){
            r = i;
        }
        else if (!di[i]){
            u = i;
            break;
        }
    }

    if (!(d%2)){
        swap(r,u);
    }

    cout << x << l << r << u;

    return 0;
}
