#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Process{
    int pid=0;
    int arrival_time=0;
    int burst_time=0;
    int start_time=0,end_time=0;
    bool complete=false;

    public:

    //getters
    int get_pid(){
        return pid;
    }
    int get_arrivaltime() const{
        return arrival_time;
    }

    int get_burstime(){
        return burst_time;
    }

    bool is_complete(){
        return complete;
    }

    int get_starttime(){
        return start_time;
    }

    void show_data(){
        cout<<"PID = "<<pid<<endl; 
        cout<<"Arrival time = "<<arrival_time<<endl;
        cout<<"Burst time = "<<burst_time<<endl;
        cout<<"_____________________"<<endl;
    }

    //setters

    void set_pid(int d){
        pid=d;
    }
    void set_at(int d){
        arrival_time=d;
    }
    void set_bt(int d){
        burst_time=d;
    }
    void set_start_time(int d){
        start_time=d;
    }
    void set_end_time(int d){
        end_time=d;
    }
    void mark_complete(){
        complete=true;
    }

};

void inputing_processses(vector<Process*> &p,Process &obj,int n){
    int a,b,c;
    for(int i=0;i<n;i++){
        cout<<"Enter the id = "<<endl;cin>>a;
        cout<<"Enter the arrival time = "<<endl;cin>>b;
        cout<<"Enter the burst time = "<<endl;cin>>c;
        Process* obj = new Process();
        obj->set_pid(a);
        obj->set_at(b);
        obj->set_bt(c);
        p[i] = obj;
    }
}
void print_gantt_chart(vector<Process*> &p );
void fcfs(vector<Process*> &p){
    int n=p.size();
    int min_index=0,idle_time=0;
    for(int i=min_index+1;i<n;i++){
        if(!(p[i]->is_complete()) && (p[i]->get_arrivaltime() < p[min_index]->get_arrivaltime())){
            min_index=i;
        }
    }
    Process* selected_process = p[min_index];

    // Determine start and end time for the selected process
    int start_time = max(selected_process->get_arrivaltime(), selected_process->get_starttime());
    int end_time = start_time + selected_process->get_burstime();

    // Update completion status of the process
    selected_process->set_start_time(start_time);
    selected_process->set_end_time(end_time);
    selected_process->mark_complete();

    // Perform any actions associated with processing the process
    // For example, you can print out the details of the processed process
    cout << "Processed the following process:" << endl;
    selected_process->show_data();
    print_gantt_chart(p );

    
}
void print_gantt_chart(vector<Process*>& p) {
    // Sort processes based on arrival time
    sort(p.begin(), p.end(), [](const Process* a, const Process* b) {
        return a->get_arrivaltime() < b->get_arrivaltime();
    });

    // Calculate the total execution time
    int total_time = 0;
    for (Process* process : p) {
        total_time += process->get_burstime();
    }

    // Create the Gantt chart header
    cout << "Gantt Chart:" << endl;
    cout << "+";
    for (int i = 0; i < total_time; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    // Print the timeline
    int current_time = 0;
    for (Process* process : p) {
        cout << "|";
        for (int i = 0; i < process->get_burstime(); ++i) {
            cout << "P" << process->get_pid();
        }
        current_time += process->get_burstime();
    }
    cout << "|" << endl;

    // Print the time labels
    cout << "0";
    current_time = 0;
    for (Process* process : p) {
        for (int i = 0; i < process->get_burstime(); ++i) {
            cout << " ";
            ++current_time;
        }
        cout << current_time;
    }
    cout << endl;
}




int main(){
    Process p;int n;
    cout<<"Enter number of processes = "<<endl;cin>>n;
    vector<Process*> processes(n);
    inputing_processses(processes,p,n);
    // for (int i = 0; i < n; i++)
    // processes[i]->show_data();
    fcfs(processes);

  return 0;
}