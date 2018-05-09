#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, length = 0, r = 0, f = 0, lim = 0;
    string str;

    cin >> n >> str;

    length = str.size();
    lim = (length+1)/2;

    if (n>lim){
        printf("IMPOSSIBLE");
    }
    else{
        for(int i = 0; i < length; i++){
            r = length-i-1;

            if (i == r && str[i] == '?'){
                str[i] = 'a'+f;
            }
            else if (str[i] != str[r] && str[i] != '?' && str[r] != '?'){
                printf("IMPOSSIBLE");
                return 0;
            }
            else if (str[i] == '?' && str[r] != '?'){
                str[i] = str[r];
            }
            else if (str[i] != '?' && str[r] == '?'){
                str[r] = str[i];
            }
            else if (str[i] == '?' && str[r] == '?'){
                str[i] = str[r] = 'a'+f;
            }

            if (str[i] == ('a'+f)){
                f++;
            }
        }

        cout << str;
    }


    return 0;
}
