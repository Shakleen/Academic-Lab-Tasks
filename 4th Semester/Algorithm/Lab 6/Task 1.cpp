// Name - Shakleen Ishfar
// Group - D
// STD ID - 160041029

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    char key;
    int freq;
    Node * left;
    Node * right;
    Node(char _key, int _freq){
        key = _key;
        freq = _freq;
        left = NULL;
        right = NULL;
    }
};

class mycomparison{
    bool reverse;
public:
    mycomparison(const bool& revparam=false){
        reverse=revparam;
    }
    bool operator() (const Node& lhs, const Node& rhs) const{
        if (reverse)
            return (lhs.freq < rhs.freq);
        return (lhs.freq > rhs.freq);
    }
};

priority_queue <Node, vector<Node>, mycomparison> PQ;

void Huffman(int n){
    for (int i = 1; i < n; ++i){
        Node * x = new Node(PQ.top().key, PQ.top().freq);
        x->left = PQ.top().left;
        x->right = PQ.top().right;
        PQ.pop();

        Node * y = new Node(PQ.top().key, PQ.top().freq);
        y->left = PQ.top().left;
        y->right = PQ.top().right;
        PQ.pop();

        Node z(0, x->freq + y->freq);
        z.left = x;
        z.right = y;

        PQ.push(z);
    }
}

void Print(Node * Head){
    if (Head != NULL){
        Print(Head->left);
        if (Head->key != 0)
            cout << Head->key << "\t" << Head->freq << "\n";
        Print(Head->right);
    }
    return;
}


int main(){
    Node NodeArr[6] = {
        Node('F', 5),
        Node('E', 9),
        Node('C', 12),
        Node('B', 13),
        Node('D', 16),
        Node('A', 45)
    };

    for (int i = 0; i < 6; ++i){
        PQ.push(NodeArr[i]);
    }

    Huffman(6);

    Node X = PQ.top();

    Print(&X);

    return 0;
}
