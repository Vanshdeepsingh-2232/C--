#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Process class representing each process
class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    bool completed;

public:
    Process(int id, int at, int bt, int pri) : pid(id), arrival_time(at), burst_time(bt), priority(pri), completed(false) {}

    int get_pid() const {
        return pid;
    }

    int get_arrival_time() const {
        return arrival_time;
    }

    int get_burst_time() const {
        return burst_time;
    }

    int get_priority() const {
        return priority;
    }

    bool is_completed() const {
        return completed;
    }

    void set_completed(bool status) {
        completed = status;
    }
};

// Function to perform priority scheduling
void priority_scheduling(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;

    // Sort processes based on priority (higher priority first)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.get_priority() > b.get_priority();
    });

    // Execute processes based on priority
    while (true) {
        bool all_completed = true;
        for (int i = 0; i < n; ++i) {
            if (!processes[i].is_completed() && processes[i].get_arrival_time() <= current_time) {
                cout << "Executing process P" << processes[i].get_pid() << " at time " << current_time << endl;
                current_time += processes[i].get_burst_time();
                processes[i].set_completed(true);
                all_completed = false;
                break;
            }
        }
        if (all_completed) {
            // No process to execute
            bool done = true;
            for (int i = 0; i < n; ++i) {
                if (!processes[i].is_completed()) {
                    done = false;
                    break;
                }
            }
            if (done) break;
            else {
                int next_arrival = INT_MAX;
                for (int i = 0; i < n; ++i) {
                    if (!processes[i].is_completed() && processes[i].get_arrival_time() < next_arrival) {
                        next_arrival = processes[i].get_arrival_time();
                    }
                }
                current_time = next_arrival;
            }
        }
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 5, 3},   // Process ID, Arrival Time, Burst Time, Priority
        {2, 2, 4, 1},
        {3, 3, 2, 4},
        {4, 5, 3, 2}
    };

    priority_scheduling(processes);

    return 0;
}
