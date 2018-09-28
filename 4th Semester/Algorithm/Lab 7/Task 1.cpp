#include <iostream>
#include <vector>

using namespace std;

class Convert{
private:
    vector <string> input;
    vector <string> result;
    string temp;
    int size;

public:
    Convert(int size);
    void addString(string & x);
    void makeNormal();
    void scramble();
    string & getTemp(){return temp;}
    void printResult();
};

Convert::Convert(int size){
    this->size = size;

    string x = "";

    for(int i = 0; i < size; ++i){
        x += "0";
    }

    for(int j = 0; j < size; ++j){
        result.push_back(x);
    }
}

void Convert::addString(string & x){
    input.push_back(x);
}

void Convert::makeNormal(){
    int i = 0, j = 0, lim = size-1, pos = 0;
    bool con2 = false;
    int right = 0, leftDown = 1, down = 2, rightUp = 3;

    while(i <= lim && j <= lim){
        temp += input[i][j];


        if (pos == right){
            // Go right
            i = i;
            j = j + 1;
        }
        else if (pos == leftDown){
            // Go left corner
            i = i + 1;
            j = j - 1;
        }
        else if (pos == down){
            // Go down
            i = i + 1;
            j = j;
        }
        else if (pos == rightUp){
            // Go right corner
            i = i - 1;
            j = j + 1;
        }

        if (!con2){
            if (j == 4){
                down = 0;
                right = 2;
                con2 = true;
            }
        }

        if (((pos == 0) || (pos == 2) || !i || !j) || (con2 && i == lim) || (con2 && j == lim))
            pos = (pos + 1) % 4;
    }
}

void Convert::scramble(){
    int topMost = 1, bottomMost = size-1, leftMost = 0, rightMost = size-1, pos = 0,
        right = 0, down = 1, left = 2, up = 3, i = 0, j = 0, k = 0, mul = 1, lim = size-1;

    while(k < temp.length()){
        cout  << "LM = " << leftMost << " RM = " << rightMost << " TM = " << topMost << " BM " << bottomMost <<
             " mul = " << mul << " lim = " << lim << " lim*mul = " << lim*mul << endl;
        cout << "Start I = " << i << " J = " << j << " K = " << k << " pos = " << pos << " temp = " << temp[k] << endl;

        result[i][j] = temp[k];

//        if (){
            if (j == rightMost){
                rightMost--;
                pos = (pos + 1) % 4;
            }
            else if (i == bottomMost){
                bottomMost--;
                pos = (pos + 1) % 4;
            }
            else if (j == leftMost){
                leftMost++;
                pos = (pos + 1) % 4;
            }
            else if (i == topMost){
                topMost++;
                pos = (pos + 1) % 4;
            }
//            mul++;
//        }

        k++;

        cout << "Mid I = " << i << " J = " << j << " K = " << k << " pos = " << pos << endl;

        if (pos == right){
            i = i;
            j = j + 1;
        }
        else if (pos == down){
            i = i + 1;
            j = j;
        }
        else if (pos == left){
            i = i;
            j = j - 1;
        }
        else if (pos == up){
            i = i - 1;
            j = j;
        }
        cout << "End I = " << i << " J = " << j << " K = " << k << " pos = " << pos << endl;

        cout << "\n\n";
        printResult();
        cout << "\n\n";
    }
}

void Convert::printResult(){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cout << result[i][j];
        }
        cout << "\n";
    }
}

int main(){
    int n = 0;
    string x;

    while(cin >> n){
        if (n == 0){
            break;
        }

        Convert obj(n);

        for (int i = 0; i < n; ++i){
            cin >> x;

            obj.addString(x);
        }

        obj.makeNormal();

        cout << obj.getTemp() << endl;

        obj.scramble();

        cout << "IN MAIN\n";

        obj.printResult();
    }
    return 0;
}

/*
5
THSAD
IIVOP
SEOOH
RGETI
YMINK
*/
