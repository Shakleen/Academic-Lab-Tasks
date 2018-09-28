#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int Vertice1, Vertice2, Weight;
};

struct Vertice{
    int Value, Rank;
    Vertice *Parent;
};

int Comp(const void* a, const void *b){
    Edge *a1 = (Edge*)a, *b1 = (Edge*)b;
    return (a1->Weight < b1->Weight);
}

vector <Edge*> EdgeStoreMST, EdgeStore;
map <int, Vertice*> VerticeStore;
int TotalVertices=0;

void MakeSet(int value){
    if (VerticeStore[value])
        return;

    ++TotalVertices;

    Vertice *New = new Vertice;
    New->Parent = New;
    New->Rank = 0;
    New->Value = value;

    VerticeStore[value] = New;

    return;
}

void MakeEdge(int Vertice1, int Vertice2, int Weight){
    Edge *New = new Edge;
    New->Vertice1 = Vertice1;
    MakeSet(Vertice1);
    New->Vertice2 = Vertice2;
    MakeSet(Vertice2);
    New->Weight = Weight;
    EdgeStore.push_back(New);
    return;
}

Vertice* FindParent (Vertice *V){
    Vertice *Parent = V->Parent;

    if (Parent->Value != V->Value)
        V->Parent = Parent = FindParent(Parent);

    return Parent;
}

bool Union(int value1, int value2){
    map <int, Vertice*>::iterator itr1, itr2;

    itr1 = VerticeStore.find(value1);
    itr2 = VerticeStore.find(value2);

    Vertice *V1 = FindParent(itr1->second), *V2 = FindParent(itr2->second);

    if (V1->Value == V2->Value)
        return false;

    if (V1->Rank > V2->Rank)
        V2->Parent = V1->Parent;
    else{
        V1->Parent = V2->Parent;
        V2->Rank++;
    }

    return true;
}

int GenerateTree(){
    int TotalWeight = 0, EdgeCount = 0;
    Edge *E = NULL;

    sort(EdgeStore.begin(), EdgeStore.end(), Comp);

    for(vector <Edge*>::iterator itr = EdgeStore.begin(); itr != EdgeStore.end(); ++itr){
        if (EdgeCount == TotalVertices-1)
            break;

        E = (*itr);

        if (Union(E->Vertice1, E->Vertice2)){
            EdgeStoreMST.push_back(E);
            ++EdgeCount;
            TotalWeight += E->Weight;
        }
    }

    return TotalWeight;
}

int main(){
    MakeEdge(1, 0, 3);
    MakeEdge(2, 0, 1);
    MakeEdge(3, 0, 6);

    MakeEdge(1, 2, 5);
    MakeEdge(1, 4, 3);

    MakeEdge(2, 3, 5);
    MakeEdge(2, 4, 6);
    MakeEdge(2, 5, 4);

    MakeEdge(3, 5, 2);
    MakeEdge(4, 5, 6);

    cout << "Cost of MST " << GenerateTree() << "\nEdges of MST:\n";

    for(vector <Edge*>::iterator itr = EdgeStoreMST.begin(); itr != EdgeStoreMST.end(); itr++){
        Edge *E = *itr;

        cout << E->Vertice1 << " " << E->Vertice2 << " " << E->Weight << endl;
    }

    return 0;
}
