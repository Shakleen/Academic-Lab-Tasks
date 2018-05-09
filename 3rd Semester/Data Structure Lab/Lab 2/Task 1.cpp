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

int main()
{
    FAST();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n=0,x1=0,x2=0,x3=0,x4=0,y1=0,y2=0,y3=0,y4=0,hi=0,lo=0,un=0;
    int mat[101][101];

    cin>>n;

    for(int tc=1; tc<=n; tc++){
        for(int i=0; i<101; i++)    ms(mat[i], 0);
        hi=lo=un=0;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                mat[i][j]++;
            }
        }

        for(int i=x3; i<x4; i++){
            for(int j=y3; j<y4; j++){
                mat[i][j]++;
            }
        }

        for(int i=1; i<=100; i++){
            for(int j=1; j<=100; j++){
//                cout<<mat[i][j];
                if(!mat[i][j]){
                    un++;
                }
                else if (mat[i][j]==1){
                    lo++;
                }
                else if (mat[i][j]==2){
                    hi++;
                }
            }
//            cout<<'\n';
        }
        cout<<"Night "<<tc<<": "<<hi<<' '<<lo<<' '<<un<<'\n';
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}

/*
4
10 10 20 20
15 15 25 25
10 10 20 20
20 20 30 30
10 10 20 20
5 5 9 9
10 10 20 20
15 5 16 26
*/
