#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector < vector <char> > b;

string result;

int LCS(string A, string B);
void PrintLCS(int i, int j, string &X);

int main(){
    string X = "AABCBDAB", Y = "BDCABA";

    cout << "Length = " << LCS(X, Y) << endl;

    result.clear();

    PrintLCS(X.length(), Y.length(), X);

    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}

int LCS(string A, string B){
    int n = A.length(), m = B.length();
    vector < vector <int> > c;

    c.resize(n+1);
    b.resize(n+1);

    for (int i = 0; i <= n; ++i){
        c[i].resize(m+1);
        b[i].resize(m+1);
        for (int j = 0; j <= m; ++j)
            c[i].at(j) = b[i][j] = 0;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (A[i-1] == B[j-1]){
                c[i].at(j) = c[i-1].at(j-1) + 1;
                b[i][j] = '\\';
            }
            else if (c[i-1].at(j) >= c[i].at(j-1)){
                c[i].at(j) = c[i-1].at(j);
                b[i][j] = '|';
            }
            else{
                c[i].at(j) = c[i].at(j-1);
                b[i][j] = '-';
            }
        }
    }

    return c[n][m];
}

void PrintLCS(int i, int j, string &X){
    if (b[i][j] == '\\'){
        result += X[i-1];
        PrintLCS(i-1, j-1, X);
    }
    else if (b[i][j] == '-')
        PrintLCS(i, j-1, X);
    else if (b[i][j] == '|')
        PrintLCS(i-1, j, X);

    return;
}
