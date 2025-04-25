#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

bool compareArrivalTime(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}

bool compareBurstTime(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}

void sjf(vector<Process>& processes) {
    int n = processes.size();
    int waiting_time = 0;
    int turnaround_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<bool> executed(n, false);
    vector<Process> ready_queue;

    int current_time = 0;

    while (true) {
        bool allExecuted = true;

        for (int i = 0; i < n; ++i) {
            if (!executed[i] && processes[i].arrival_time <= current_time) {
                ready_queue.push_back(processes[i]);
                executed[i] = true;
            }
            if (!executed[i]) {
                allExecuted = false;
            }
        }

        if (allExecuted) {
            break;
        }

        if (!ready_queue.empty()) {
            sort(ready_queue.begin(), ready_queue.end(), compareBurstTime);

            Process current_process = ready_queue.front();
            ready_queue.erase(ready_queue.begin());

            waiting_time += current_time - current_process.arrival_time;
            turnaround_time += waiting_time + current_process.burst_time;

            current_time += current_process.burst_time;

            cout << "Process " << current_process.id << "\tBurst Time: " << current_process.burst_time
                 << "\tWaiting Time: " << waiting_time - current_process.arrival_time
                 << "\tTurnaround Time: " << turnaround_time - current_process.arrival_time << endl;
        } else {
            current_time++;
        }
    }

    cout << "\nAverage Waiting Time: " << static_cast<float>(waiting_time) / n << endl;
    cout << "Average Turnaround Time: " << static_cast<float>(turnaround_time) / n << endl;
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> processes[i].burst_time;
    }

    sjf(processes);

    return 0;
}
