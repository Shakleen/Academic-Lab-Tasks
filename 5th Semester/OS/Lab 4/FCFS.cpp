#include <iostream>
#include <vector>
#include <algorithm>

class Process{
private:
    int PID;
    int AT;
    int BT;
    int WT;
    int CT;
    int TT;

public:
    Process(int pid, int at, int bt) {
        PID = pid;
        AT = at;
        BT = bt;
        WT = CT = TT = 0;
    }

    int getPID(){return PID;}
    int getAT(){return AT;}
    int getBT(){return BT;}
    int getWT(){return WT;}
    int getCT(){return CT;}
    int getTT(){return TT;}

    void setPID(int pid){PID = pid;}
    void setAT(int at){AT = at;}
    void setBT(int bt){BT = bt;}
    void setWT(int wt){WT = wt;}
    void setCT(int ct){CT = ct;}
    void setTT(int tt){TT = tt;}
};

bool CompareProcess(Process p1, Process p2) {
    return (p1.getAT() <= p2.getAT());
}

void TakeInput(std::vector<Process> &Processes) {
    int n = 0, PID = 0, AT = 0, BT = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> PID >> AT >> BT;

        Process process(PID, AT, BT);

        Processes.push_back(process);
    }
}

void PrintProcess(std::vector<Process> &Processes) {
    std::cout << "PID\t\tAT\t\tBT\t\tWT\t\tCT\t\tTT\n";

    for (int i = 0; i < Processes.size(); ++i) {
        std::cout <<
        Processes[i].getPID() << "\t\t" <<
        Processes[i].getAT() << "\t\t" <<
        Processes[i].getBT() << "\t\t" <<
        Processes[i].getWT() << "\t\t" <<
        Processes[i].getCT() << "\t\t" <<
        Processes[i].getTT() << "\n";
    }
}

void ScheduleProcessFCFS(std::vector<Process> &Processes) {
    int timeOfExecution = 0;

    for (int i = 0; i < Processes.size(); ++i) {
        Processes[i].setWT(timeOfExecution - Processes[i].getAT());

        timeOfExecution += Processes[i].getBT();

        Processes[i].setCT(timeOfExecution);

        Processes[i].setTT(Processes[i].getCT() - Processes[i].getAT());
    }
}

void CalculateAverage(std::vector<Process> &Processes, double &avgWT, double &avgTT) {
    double TotalWT = 0.0, TotalTT = 0.0;

    for (int i = 0; i < Processes.size(); ++i) {
        TotalWT += Processes[i].getWT();
        TotalTT += Processes[i].getTT();
    }

    avgWT = TotalWT / Processes.size();
    avgTT = TotalTT / Processes.size();
}

int main() {
    std::vector<Process> Processes;

    double AverageWT = 0, AverageTT = 0;

    TakeInput(Processes);

    std::sort(Processes.begin(), Processes.end(), CompareProcess);

//    PrintProcess(Processes);

    ScheduleProcessFCFS(Processes);

    PrintProcess(Processes);

    CalculateAverage(Processes, AverageWT, AverageTT);

    std::cout << "Average WT: " << AverageWT << "\nAverage TT: " << AverageTT << "\n";

    return 0;
}

/*
3
1 3 5
2 0 4
3 2 1
*/
