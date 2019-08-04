#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Edge information
struct Edge
{
    int Vertice1;   // Vertice on one side
    int Vertice2;   // Vertice on opposite side
    int Weight;     // Weight of the edge
};

// Vertice information
struct Vertice
{
    int Value;      // Value of the vertice
    int Rank;       // Rank of the vertice
    Vertice *Parent;// Parent of the vertice
};

// For sorting purpose
int Comp(const void* a, const void *b)
{
    Edge *a1 = (Edge*)a;
    Edge *b1 = (Edge*)b;
    return (a1->Weight < b1->Weight);
}

class KruskalMST
{
public:
    void MakeEdge(int Vertice1, int Vertice2, int Weight);
    // For Merging sets
    bool Union(int value1, int value2);
    // Making the minimum spanning tree. Return total weight of MST.
    int GenerateTree();
    vector <Edge*> EdgeStoreMST;                // Storing edges of MST
private:
    vector <Edge*> EdgeStore;                   // Storing edges
    map <int, Vertice*> VerticeStore;           // Store the vertices
    vector <Edge*>::iterator itr;               // Used for iteration
    map <int, Vertice*>::iterator itr1, itr2;   // Used for iteration
    Vertice *V1, *V2;   // Used for processing purposes
    Edge *E;            // Used for processing purposes
    int TotalWeight;    // Store the Total weight of MST
    int EdgeCount;      // No of edges added to MST
    int TotalVertices=0;// Total number of vertices created
    int TotalEdges=0;   // Total number of edges created

    // For making a set with one element
    void MakeSet(int value);
    // Find parent. Applies path compression.
    Vertice* FindParent (Vertice *V);
};

void KruskalMST::MakeEdge(int Vertice1, int Vertice2, int Weight)
{
    Edge *New = new Edge;       // Create new edge
    New->Vertice1 = Vertice1;   // Add vertice 1 value
    MakeSet(Vertice1);          // Create set for vertice 1
    New->Vertice2 = Vertice2;   // Add vertice 2 value
    MakeSet(Vertice2);          // Create set for vertice 2
    New->Weight = Weight;       // Add weight of the edge
    EdgeStore.push_back(New);   // Store the edge
    ++TotalEdges;               // Increase total edges
    return;
}

void KruskalMST::MakeSet(int value)
{
    // Check if vertice already exists or not
    if (VerticeStore[value])
        return; // It does. So do nothing.

    Vertice *New = new Vertice; // Creating new set
    New->Parent = New;          // Parent is the vertice itself
    New->Rank = 0;              // Rank is initially zero
    New->Value = value;         // Setting vertice value
    VerticeStore[value] = New;  // Storing into map for easy access later
    ++TotalVertices;            // Increase total number of vertices

    return;
}

Vertice* KruskalMST::FindParent (Vertice *V)
{
    // Getting parent of V
    Vertice *Parent = V->Parent;

    /* Check if V is parent of itself.
       If so then it's the root node or identity value holder.
       Otherwise find the parent and update through path compression. */
    if (Parent->Value != V->Value)
        V->Parent = Parent = FindParent(Parent);

    // Return the parent.
    return Parent;
}

bool KruskalMST::Union(int value1, int value2)
{
    // Find the nodes of value 1 and value 2
    itr1 = VerticeStore.find(value1);
    itr2 = VerticeStore.find(value2);

    // Find the parent of the nodes
    V1 = FindParent(itr1->second);
    V2 = FindParent(itr2->second);

    // Check if the vertices belong to the same set
    if (V1->Value == V2->Value)
        return false; // They are of the same set. So do nothing.

    // Union by rank. Higher rank becomes parent of lower rank.
    // Rank increases if both ranks are equal
    if (V1->Rank > V2->Rank)
        V2->Parent = V1->Parent;
    else
    {
        V1->Parent = V2->Parent;
        V2->Rank++;
    }
    return true;
}

int KruskalMST::GenerateTree()
{
    // Initialize values
    TotalWeight = EdgeCount = 0;

    // sort the edge list.
    sort(EdgeStore.begin(), EdgeStore.end(), Comp);

    // Go through each Edge until n-1 edges have been merged.
    for(itr = EdgeStore.begin(); itr != EdgeStore.end(); ++itr)
    {
        // n-1 edges added? If so break. MST already achieved.
        if (EdgeCount == TotalVertices-1)
            break;

        E = (*itr);

        // Check if union is possible. If possible then do the following.
        if (Union(E->Vertice1, E->Vertice2))
        {
            EdgeStoreMST.push_back(E);  // Include the edge in MST
            ++EdgeCount;                // Increase edge count added to MST
            TotalWeight += E->Weight;   // Increase the total weight of MST
        }
    }

    return TotalWeight;
}

int main()
{
    KruskalMST KMST;

    KMST.MakeEdge(1, 2, 1);
    KMST.MakeEdge(1, 3, 3);
    KMST.MakeEdge(2, 3, 2);
    KMST.MakeEdge(2, 4, 1);
    KMST.MakeEdge(3, 4, 1);
    KMST.MakeEdge(3, 5, 4);
    KMST.MakeEdge(5, 6, 1);
    KMST.MakeEdge(1, 6, 3);

    cout << KMST.GenerateTree() << endl;
    return 0;
}
