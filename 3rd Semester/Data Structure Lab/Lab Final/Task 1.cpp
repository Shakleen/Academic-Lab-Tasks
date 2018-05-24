#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

char Room[85][85];

void FloodFill(int StartX, int StartY){
    if (Room[StartY][StartX] == ' ' || Room[StartY][StartX] == '*'){
        Room[StartY][StartX] = '#';

        REP(i, 4){
            FloodFill(StartX+fx[i], StartY+fy[i]);
        }
    }

    return;
}

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0, idx=0, StartX=0, StartY=0;
    string str;

    cin >> t;

    FOR(tc, 1, t){
        REP(i, 35) REP(j, 85) Room[i][j] = 0;

        while (getline(cin, str)){
            REP(i, str.size()){
                if (str[i]=='*') StartX = i, StartY = idx;
                Room[idx][i] = str[i];
            }

            if (str[0] == '_') break;

            idx++;
        }

        FloodFill(StartX, StartY);

        REP(i, idx) cout << Room[i] << endl;;
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}

/*
3
XXXXXXXXX
X   X   X
X *     X
X   X   X
XXXXXXXXX
X   X
X   X
X   X
XXXXX
_____
AAAAAAAAA
A   A   A
A * A   A
A   A   A
AAAAAAAAA
_________
BBBBB BBBBB
B   B B   B
B * B B   B
B   B B   B
BBBBB BBBBB
_________

*/

