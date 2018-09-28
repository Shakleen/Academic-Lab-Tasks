#include <iostream>
#include <vector>

using namespace std;

class MatrixParenthesis{
    vector < vector <int> > Value;
    vector < vector <int> > Partition;
public:
    void Process(vector <int> &p);
    void Print(int left, int right);
};

void MatrixParenthesis::Process(vector <int> &p){
    int Length=p.size(), left=0, right=0, mid=0, temp=0, len=0, i=0;
    Value.resize(Length+1);
    Partition.resize(Length+1);

    for (i=0; i<=Length; ++i){
        Value[i].resize(Length+1);
        Partition[i].resize(Length+1);
    }

    for (i=1; i<=Length; ++i){
        Value[i].at(i) = 0;
    }

    for (len=2; len<=Length; ++len){
        for(left=1; left<=Length-len; ++left){
            right=left+len-1;
            Value[left].at(right)=INT_MAX;
            for(mid=left; mid<right; ++mid){
                temp = Value[left].at(mid) + Value[mid+1].at(right)
                     + p[left-1]*p[mid]*p[right];

                if (temp < Value[left].at(right)){
                    Value[left].at(right) = temp;
                    Partition[left].at(right) = mid;
                }
            }
        }
    }
}

void MatrixParenthesis::Print(int left, int right){
    if (left == right){
        cout << "A";
    } else {
        cout << "(";
        Print(left, Partition[left].at(right));
        Print(Partition[left].at(right)+1, right);
        cout << ")";
    }
}

int main(){
    vector <int> p = {30, 35, 15, 5, 10, 20, 26};
    MatrixParenthesis obj;
    obj.Process(p);
    obj.Print(1, 6);
    return 0;
}
