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
#define N                   26*26
string input[N+5];
//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Edge{    int Source, Destination; };

struct Subset{  int parent, rank; };

int find (struct Subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union (struct Subset Subsets[], int x, int y){
    int xroot = find(Subsets, x), yroot = find(Subsets, y);
    if (Subsets[xroot].rank < Subsets[yroot].rank)
        Subsets[xroot].parent = yroot;
    else if (Subsets[yroot].rank < Subsets[xroot].rank)
        Subsets[yroot].parent = xroot;
    else
        Subsets[yroot].parent = xroot,  Subsets[xroot].rank++;
    return;
}

void ProcessForest(int NumberOfNodes, int NumberOfEdges){
    int Nodes = NumberOfNodes, Edges = NumberOfEdges, x = 0, y = 0, tree=0, acorn=0, No=1;
    int CNT[Nodes] = {};
    struct Edge* EdgeList = new struct Edge [Edges * sizeof(struct Edge)];
    struct Subset *SSet = new struct Subset [Nodes * sizeof(struct Subset) ];
    map <char, int> MyMap;

    REP(i,Edges){
            if (!MyMap[input[i][1]]) MyMap[input[i][1]] = ++No;
            if (!MyMap[input[i][3]]) MyMap[input[i][3]] = ++No;

            EdgeList[i].Source = MyMap[input[i][1]];
            EdgeList[i].Destination = MyMap[input[i][3]];
    }

    for (int i=0; i<Nodes; i++){
        SSet[i].parent = i;
        SSet[i].rank = 0;
    }

    for (int i=0; i<Edges; i++){
        x = find(SSet, EdgeList[i].Source);
        y = find(SSet, EdgeList[i].Destination);
        if (x != y) Union(SSet, x, y);
    }

    for(int i=0; i<Nodes; i++)        CNT[SSet[i].parent]++;

    for (int i=0; i<Nodes; i++)
        if (CNT[i]>1)           tree++;
        else if (CNT[i]==1)     acorn++;

    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";

    return;
}

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0, Edges=0, Nodes=0, No=0;
    string str;

    cin >> t;

    FOR(tc, 1, t){
        ms(input, 0);
        Nodes = Edges = No = 0;

        while(1){
            cin >> str;
            if (str[0] == '*')  break;
            input[Edges++] = str;
        }

        cin >> str;

        for (int i=0; i<str.size(); i+=2)   Nodes++;

        ProcessForest(Nodes, Edges);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


