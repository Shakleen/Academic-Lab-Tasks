#include <iostream>
#include <vector>
#include <algorithm>

class Process {
public:
    int id, size;

    Process(int i, int s) {
        id = i;
        size = s;
    }
};

class MemoryBlock {
public:
    std::vector<int> allocatedProcesses;
    int size, id;
    MemoryBlock(int i, int s) {
        id = i;
        size = s;
    }
};

void TakeInput(std::vector<Process> &processes, std::vector<MemoryBlock> &blocks) {
    int n = 0, size = 0;

    std::cout << "How many processes?" << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << "Size of process " << i << ": ";
        std::cin >> size;

        Process p = Process(i, size);
        processes.push_back(p);
    }

    std::cout << "How many memory blocks?" << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << "Size of memory block " << i << ": ";
        std::cin >> size;

        MemoryBlock m = MemoryBlock(i, size);
        blocks.push_back(m);
    }
}

void PrintInput(std::vector<Process> &processes, std::vector<MemoryBlock> &blocks) {
    std::cout << "\nProcesses info\n";
    for (int i = 0; i < processes.size(); ++i)
        std::cout << processes[i].id << " process has size " << processes[i].size << "\n";

    std::cout << "\nMemory Block info\n";
    for (int i = 0; i < blocks.size(); ++i)
        std::cout << blocks[i].id << " block has size " << blocks[i].size << "\n";
}

void FirstFit(std::vector<Process> processes, std::vector<MemoryBlock> blocks) {
    std::cout << "\nFirst Fit memory allocation\n";

    for (int i = 0; i < processes.size(); ++i) {
        for (int j = 0; j < blocks.size(); ++j) {
            if (blocks[j].size >= processes[i].size) {
                blocks[j].size -= processes[i].size;
                blocks[j].allocatedProcesses.push_back(processes[i].id);
                std::cout << "Process " << processes[i].id << " allocated to " <<
                blocks[j].id << " memory block!\n";
                break;
            }
        }
    }
}

void BestFit(std::vector<Process> processes, std::vector<MemoryBlock> blocks) {
    std::cout << "\nBest Fit memory allocation\n";

    for (int i = 0; i < processes.size(); ++i) {
        int selectedBlock = 0, minDif = 999999, dif = 0;

        for (int j = 0; j < blocks.size(); ++j) {
            dif = blocks[j].size - processes[i].size;

            if (dif >= 0 && dif < minDif) minDif = dif, selectedBlock = j;
        }

        blocks[selectedBlock].size -= processes[i].size;
        std::cout << "Process " << processes[i].id << " is allocated to " <<
        blocks[selectedBlock].id << " memory block!\n";
    }
}

void WorstFit(std::vector<Process> processes, std::vector<MemoryBlock> blocks) {
    std::cout << "\nWorst Fit memory allocation\n";

    for (int i = 0; i < processes.size(); ++i) {
        int selectedBlock = 0, maxDif = -1, dif = 0;

        for (int j = 0; j < blocks.size(); ++j) {
            dif = blocks[j].size - processes[i].size;

            if (dif >= 0 && dif > maxDif) maxDif = dif, selectedBlock = j;
        }

        blocks[selectedBlock].size -= processes[i].size;
        std::cout << "Process " << processes[i].id << " is allocated to " <<
        blocks[selectedBlock].id << " memory block!\n";
    }
}

int main() {
    std::vector<Process> processes;
    std::vector<MemoryBlock> blocks;
    TakeInput(processes, blocks);
    PrintInput(processes, blocks);
    FirstFit(processes, blocks);
    BestFit(processes, blocks);
    WorstFit(processes, blocks);
    return 0;
}

/*
5
300
30
120
220
80
5
200
500
250
100
50
*/
