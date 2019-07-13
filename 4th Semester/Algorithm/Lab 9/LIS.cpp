#include <iostream>
#include <vector>

using namespace std;

int BSearch(vector<int> &arr, int lo, int hi, int key){
    while(hi-lo > 1){
        int mid = lo + (hi-lo)/2;

        if (arr[mid] >= key)
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}

void LIS(vector <int> &arr){
    if (arr.size() <= 0){
        cout << "Empty array inputted!" << endl;
        return;
    }

    int length = 1, no = 0;
    vector < vector <int> > LISCombinations;
    vector <int> v;
    v.push_back(arr[0]);

    for(int i = 1; i < arr.size(); ++i){
        if (arr[i] < v[0]){
            LISCombinations.push_back(v);
            v.clear();
            v.push_back(arr[i]);
        }
        else if (arr[i] > v[length-1]){
            length++;
            v.push_back(arr[i]);
        }
        else{
            LISCombinations.push_back(v);
            v[BSearch(v, -1, length-1, arr[i])] = arr[i];
        }
    }

    cout << length << "\n-\n";

    int mx = 0, mxI = 0;

    for(int i = 0; i < LISCombinations.size(); ++i){
        if (LISCombinations[i].size() > mx){
            mx = LISCombinations[i].size();
            mxI = i;
        }
    }
    for(int i = 0; i < LISCombinations[mxI].size(); ++i){
        cout << LISCombinations[mxI][i] << endl;
    }
}

int main(){
    int n = 0;
    vector <int> V;

    while(cin >> n){
        V.push_back(n);
    }

    LIS(V);

    return 0;
}
