#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

void TakeInput(std::vector<Process> &p, int &round_robin_time);
void ScheduleProcesses(std::vector<Process> &p, int &round_robin_time);
bool compare(Process &p1, Process &p2);
int min(int a, int b);

int main() {
    int round_robin_time = 0;
    std::vector<Process> processes;
    TakeInput(processes, round_robin_time);
    ScheduleProcesses(processes, round_robin_time);
    return 0;
}

void TakeInput(std::vector<Process> &p, int &round_robin_time) {
    int n = 0, at = 0, bt = 0;

    std::cout << "Input round robin time\n";
    std::cin >> round_robin_time;

    std::cout << "Input number of tasks\n";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << "Input AT and BT for process " << i << "\n";
        std::cin >> at >> bt;
        p.push_back(Process(i, at, bt, bt));
    }
}

void ScheduleProcesses(std::vector<Process> &p, int &round_robin_time) {
    int executionTime = 0, elapsedTime = 0;
    bool queued = false;
    Process process = Process();

    std::queue<Process> processQueue;
    std::sort(p.begin(), p.end(), compare);

    processQueue.push(p.at(0));
    p.at(0).assigned = true;

    while(processQueue.size() > 0) {
        process = processQueue.front();
        processQueue.pop();

        executionTime = min(round_robin_time, process.RT);

        process.RT -= executionTime;
        elapsedTime += executionTime;

        for (int i = 0; i < p.size(); ++i) {
            if (p.at(i).RT <= 0 || p.at(i).assigned || p.at(i).AT > elapsedTime)
                continue;

            if (!queued && p.at(i).AT >= elapsedTime && process.RT > 0) {
                processQueue.push(process);
                queued = true;
            }

            p.at(i).assigned = true;
            processQueue.push(p.at(i));
        }

        if (!queued && process.RT > 0)    processQueue.push(process);
        queued = false;

        std::cout << "Process " << process.ID << " executed for " << executionTime << '\n';
    }

    std::cout << "All processes completed execution at time " << elapsedTime << '\n';
}

bool compare(Process &p1, Process &p2) {
    if (p1.AT == p2.AT) return p1.BT <= p2.BT;
    return p1.AT < p2.AT;
}

int min(int a, int b) {
    return (a <= b) ? a : b;
}

/*
2
3
0
7
1
2
4
1
*/
