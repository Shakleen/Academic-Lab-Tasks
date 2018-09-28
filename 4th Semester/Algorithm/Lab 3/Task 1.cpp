#include <iostream>

using namespace std;

struct SubarrayInfo{
    int L, H, S;
    SubarrayInfo(){}
    SubarrayInfo(int l, int h, int s){
        L = l;
        H = h;
        S = s;
    }
};

SubarrayInfo FindMaxSubarray(int *A, int Size){
    int MaxSum = A[0], Sum = A[0], H = 0, L = 0, High = 0, Low = 0;

    for (int i = 1; i < Size; ++i){
        Sum += A[i];

        if (Sum < A[i]){
            Sum = A[i];
            H = L = i;
        }else
            H = i;

        if (MaxSum < Sum){
            MaxSum = Sum;
            High = H;
            Low = L;
        }
    }

    return SubarrayInfo(Low, High, MaxSum);
}

int main(){
    int A[] = {1, 2, -4, -3};

    SubarrayInfo Result = FindMaxSubarray(A, 4);

    cout << "Left Index = " << Result.L << endl;
    cout << "Right index = " << Result.H << endl;
    cout << "Maximum sum of subarray = " << Result.S << endl;

    return 0;
}
