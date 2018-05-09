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
#define MAX                 200001

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Edge{    int Source, Destination, Weight; };

struct Graph{
    int NodeNo, EdgeNo;
    struct Edge *EdgeList;
};

struct Subset{  int parent, rank; };

struct Graph* CreateGraph(int NumberOfNodes, int NumberOfEdges){
    struct Graph *G = new struct Graph;
    G->EdgeNo = NumberOfEdges;
    G->NodeNo = NumberOfNodes;
    G->EdgeList = new struct Edge[G->EdgeNo * sizeof(struct Edge)];
    return G;
}

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

int Comp(const void* a, const void *b){
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;
    return (a1->Weight > b1->Weight);
}

int KruskalMST(struct Graph *G){
    int NodeNo = G->NodeNo, e=0, i=0, x=0, y=0, Total=0;
    struct Edge Result[NodeNo];
    struct Subset SSet[NodeNo];
    qsort(G->EdgeList, G->EdgeNo, sizeof(struct Edge), Comp);

    for (int i=0; i<NodeNo; i++){
        SSet[i].parent = i;
        SSet[i].rank = 0;
    }

    while (e < NodeNo-1){
        struct Edge NewEdge = G->EdgeList[i++];

        x = find(SSet, NewEdge.Source);
        y = find(SSet, NewEdge.Destination);

        if (x != y){
            Result[e++] = NewEdge;
            Union(SSet, x, y);
        }
    }

    for (int i = 0; i < e; i++) Total += Result[i].Weight;

    return Total;
}

int main(){
//    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int Junctions = 0, Roads = 0, Junction1 = 0, Junction2 = 0, Distance = 0, j = 0, Spending = 0;


    while(cin >> Junctions >> Roads){
        Junction1 = Junction2 = Distance = j = Spending = 0;

        if (!Junctions && !Roads){
            break;
        }

        Graph *City = CreateGraph(Junctions, 2*Roads);

        REP(i, Roads){
            cin >> Junction1 >> Junction2 >> Distance;

            Spending += Distance;

            City->EdgeList[j].Source = Junction1;
            City->EdgeList[j].Destination = Junction2;
            City->EdgeList[j++].Weight = Distance;

            City->EdgeList[j].Source = Junction2;
            City->EdgeList[j].Destination = Junction1;
            City->EdgeList[j++].Weight = Distance;
        }

        cout << Spending - KruskalMST(City) << "\n";
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


