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

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

class Graph{
    list <int> *adj;
    int Nodes;
public:
    Graph(int NodeNo);
    void AddEdge(int src, int dst);
    void TopSort();
};

Graph::Graph(int NodeNo){
    this->Nodes = NodeNo;
    adj = new list<int>[Nodes];
}

void Graph::AddEdge(int src, int dst){
    adj[src].push_back(dst);
    return;
}

void Graph::TopSort(){
    vector <int> InDegree (Nodes, 0), TopOrder;
    priority_queue <int> ProcessQueue;
    list <int> :: iterator ListItr;
    vector <int> :: iterator VecItr;
    int CurrentNode = 0, cnt = 0;

    for (int i = 0; i < Nodes; i++)
        for (ListItr : adj[i])
            InDegree[ListItr]++;

    for (int i = 0; i < Nodes; i++)
        if (!InDegree[i])
            ProcessQueue.push((-1)*i);

    while (!ProcessQueue.empty()){
        CurrentNode = (-1)*ProcessQueue.top();
        ProcessQueue.pop();
        TopOrder.push_back(CurrentNode);
        for (ListItr : adj[CurrentNode])
            if (--InDegree[ListItr] == 0)
                ProcessQueue.push((-1)*ListItr);
        cnt++;
    }

    if (cnt != Nodes){
        cout << "Sandro fails.\n";
        return;
    }

    for (VecItr : TopOrder)
        cout << VecItr+1 << ' ';
    cout << "\n";
    return;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n=0, m=0, x=0, y=0;

    while(cin >> n >> m){
        Graph G(n);

        FOR(i, 1, m){
            cin >> x >> y;

            G.AddEdge(x-1, y-1);
        }

        G.TopSort();
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}
