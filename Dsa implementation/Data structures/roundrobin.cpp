#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a structure to represent a process
struct Process {
    int id;
    int burst_time;
    int remaining_time; // Remaining time to complete execution

    Process(int i, int b) : id(i), burst_time(b), remaining_time(b) {}
};

// Function to simulate the Round Robin scheduling algorithm
void round_robin(vector<Process>& processes, int quantum) {
    queue<Process*> process_queue;
    int current_time = 0;

    // Add processes to the queue
    for (Process& process : processes) {
        process_queue.push(&process);
    }

    cout << "Gantt Chart:" << endl;
    while (!process_queue.empty()) {
        Process* current_process = process_queue.front();
        process_queue.pop();

        // Execute the process for a time slice (quantum) or until completion
        int execution_time = min(quantum, current_process->remaining_time);
        current_process->remaining_time -= execution_time;

        // Print the process execution
        cout << "|P" << current_process->id << "(" << current_time << "-" << current_time + execution_time << ")";

        // Update current time
        current_time += execution_time;

        // Check if the process is completed
        if (current_process->remaining_time > 0) {
            // Add the process back to the queue if it's not completed
            process_queue.push(current_process);
        }
    }
    cout << "|" << endl;
}

int main() {
    int n; // Number of processes
    int quantum; // Quantum time slice

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the quantum time slice: ";
    cin >> quantum;

    vector<Process> processes;
    for (int i = 1; i <= n; ++i) {
        processes.push_back(Process(i, 5)); // Assuming burst time of 5 units for all processes
    }

    round_robin(processes, quantum);

    return 0;
}
