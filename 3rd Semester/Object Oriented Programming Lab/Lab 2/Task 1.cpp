#include <bits/stdc++.h>

using namespace std;

class salaryStatement{
    int salary[5];
    double avg;

public:
    //Constructors
    salaryStatement(){
        cout<<"\nSalary Values:\n";
        for(int i=0; i<5; i++){
            salary[i] = 0;
            cout<<salary[i]<<' ';
        }
        avg = 0.0;
        cout<<"\nAverage: "<<avg<<endl;
    }

    salaryStatement(int s[5]){
        cout<<"\nSalary Values:\n";
        int sum = 0;
        for(int i=0; i<5; i++){
            salary[i] = s[i], sum += salary[i];
            cout<<salary[i]<<' ';
        }
        avg = (sum/5);
        cout<<"\nAverage: "<<avg<<endl;
    }

    bool compareSalary(int *s){
        int sum = 0;
        for(int i=0; i<5; i++)  sum += *s,   *s++;
        sum /= 5;
        if(sum > avg)    return 0;
        return 1;
    }

    bool compareSalary(salaryStatement obj){
        return compareSalary(obj.salary);
    }
};

int main(){
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {60, 70, 80, 90, 100};

    cout<<"First Object";
    salaryStatement ob1(a); //Initializing with array a via parametered constructor
    cout<<"\nSecond Object";
    salaryStatement ob2(b); //Initializing with array c via parametered constructor
    cout<<"\nThird Object";
    salaryStatement ob3;    //Initializing with zeros via default constructor

    cout<<ob1.compareSalary(ob2)<<endl;
    return 0;
}
