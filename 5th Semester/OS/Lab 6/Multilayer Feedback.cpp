#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Process {
public:
    int ID, AT, BT, RT;
    bool assigned;

    Process(int id, int at, int bt, int rt) {
        assigned = false;
        ID = id;
        AT = at;
        BT = bt;
        RT = rt;
    }

    Process() {}
};

bool CompareProcess(Process &p1, Process &p2);
void TakeInput(std::vector<Process> &p, int &rr1, int &rr2);
void Calculate(std::vector<Process> &p);

int main() {
    std::vector<Process> processes;
    int rr1 = 0, rr2 = 0;
    TakeInput(processes, rr1, rr2);
    std::sort(processes.begin(), processes.end(), CompareProcess);
    Calculate(processes);
    return 0;
}

void TakeInput(std::vector<Process> &p, int &rr1, int &rr2) {
    int n = 0, at = 0, bt = 0;

    std::cout << "Input round robin times (2)\n";
    std::cin >> rr1 >> rr2;

    std::cout << "Input number of tasks\n";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << "Input AT and BT for process " << i << "\n";
        std::cin >> at >> bt;
        p.push_back(Process(i, at, bt, bt));
    }
}

bool CompareProcess(Process &p1, Process &p2) {
    return (p1.AT <= p2.AT);
}

void Calculate(std::vector<Process> &p) {
    for (Process &process : p) {

    }
}
