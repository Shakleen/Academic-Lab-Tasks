#include <iostream>

using namespace std;

int main(){
    int n = 0;

    cin >> n;

    while ( !(n%3) ){
        n /= 3;
    }

    if (n != 1){
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }


    return 0;
}
