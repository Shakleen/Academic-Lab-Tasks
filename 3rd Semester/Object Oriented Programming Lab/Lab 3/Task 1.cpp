 #include <bits/stdc++.h>

using namespace std;

class patientInfo{
    char *name;
    int testCount;
    float *testResults;

public:
    patientInfo(){
        name = "\0";
        testCount = 5;
        testResults = (float *) malloc(sizeof(float) * testCount);
        for(int i=0; i<5; i++){
            *(testResults+i) = 0.0;
//            cout << testResults+i << ' ' << *(testResults+i) << endl;
        }
    }

    patientInfo(char *Name, int TestCount, float *TestResults){
        int len = strlen(Name);
        name = (char *) malloc(sizeof(char) * len);
        strcpy(name, Name);

        testResults = (float *) malloc(sizeof(float) * testCount);
        testCount = TestCount;
        for(int i=0; i<testCount; i++){
            *(testResults+i) = *(TestResults+i);
//            cout << testResults+i << ' ' << *(testResults+i) << endl;
        }
    }

    ~patientInfo(){
        cout << "Freeing up memory held by ";
        printf("%s with %d test results\n", name, testCount);
        free(name);
        free(testResults);
    }

    float calculateAvgRes(){
        float sum = 0.0;
        for(int i=0; i<testCount; i++){
            sum += *(testResults+i);
        }
        return sum/testCount;
    }

    void showPatientName(){
        printf("Name = %s\n", name);
    }

    float *getTestRes(){
        return testResults;
    }
};

class hospital{
    patientInfo *patients;
    int patientCount;

public:
    hospital(int cnt){
        float *num;
        char *name;
        int val;

        patientCount = cnt;

        patientInfo *patients = (patientInfo *) malloc (sizeof(patientInfo) * patientCount),
                    *p = patients;

        for(int i=0; i<patientCount; i++){
            cout << "Enter Name : ";
            cin >> name;
            cout << "Enter number of test cases : ";
            cin >> val;
            cout << "Enter " << val << " values : ";
            num = (float *) malloc (sizeof(float) * val);
            for(int j=0; j<val; j++){
                cin>>num[j];
            }

            p = new patientInfo(name,val,num);
            p++;
        }
    }

//    patientInfo *get(){
//        cout << patients << endl;
//        return patients;
//    }
};

int main(){
//    float num[] = {1.0, 2.0, 3.0, 4.0, 5.0};
//    patientInfo obj("Ishrak", 5, num);
//
//    float *p = obj.getTestRes();
//    for(int i=0; i<5; i++){
//        cout << *(p+i) << endl;
//    }
//    cout << "Average test Result : " << obj.calculateAvgRes() << endl;
//    printf("Name = %s\n", obj.showPatientName());

    hospital obj(3);
//    patientInfo *p = obj.get();
//    for(int i=0; i<3; i++,p++){
//        p->showPatientName();
//    }

//    for(int i=0; i<3; i++){
//        p->showPatientName;
//        p++;
//    }
    return 0;
}
/*
documentation

1. why we need dynamic memory allocation in context of this example?
2. why we can't call an
3. What happens when we free using destructor?
*/

