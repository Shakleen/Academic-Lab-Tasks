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
#define MAX                 21

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector <int> CountryList [MAX];
bool vis [MAX];
int dist [MAX], Start, End;

void MakeConnection(int u, int v){
    CountryList[u].pb(v);
    CountryList[v].pb(u);
    return;
}

int BFS(int Source, int Destination){
    ms(vis, false);
    ms(dist, 0);
    queue <int> CountryQueue;
    int Popped = 0;

    dist[Source] = 0;
    vis[Source] = true;
    CountryQueue.push(Source);

    while(!CountryQueue.empty()){
        Popped = CountryQueue.front();
        CountryQueue.pop();

        REP(i, CountryList[Popped].size()){
            if (!vis[CountryList[Popped][i]]){
                vis[CountryList[Popped][i]] = true;
                CountryQueue.push(CountryList[Popped][i]);
                dist[CountryList[Popped][i]] = dist[Popped] + 1;
            }
        }
    }

    return dist[Destination];
}

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int NoOfEdges = 0, Edge = 0, CountryPairs = 0, tc = 1;

    while (1){
        NoOfEdges = Edge = CountryPairs = Start = End = 0;
        FOR(i, 0, 20)   CountryList[i].clear();

        FOR(i, 1, 19){
            cin >> NoOfEdges;

            FOR(j, 1, NoOfEdges){
                cin >> Edge;

                MakeConnection(i, Edge);
            }
        }

        cin >> CountryPairs;

        printf("Test Set #%d\n", tc++);

        REP(i, CountryPairs){
            cin >> Start >> End;

            printf("%2d to %2d: %d\n", Start, End, BFS(Start, End));
        }
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


