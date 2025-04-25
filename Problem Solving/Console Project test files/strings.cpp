//lets Make a simple command pannel application that manages the tasks and also hav some priority system.

#include<iostream>
#include<string>
using namespace std;


class Task {

private:
	string m_task_name;
	string m_task_description;
	int m_task_priority = 0;
	int m_task_id = 0;
	bool m_completion = 0;

public:

	//GETTERS FOR TASKS

	string get_task_name() {
		return m_task_name;
	}
	string get_task_descript() {
		return m_task_description;
	}
	void get_task_id() {
		cout << "Not assigened yet"<<endl;
	}
	int get_task_priority() {
		return m_task_priority;
	}
	bool get_completion_bool() {
		return m_completion;
	}
	string get_completion_status() const{
		string c1 = "completed", c2 = "Not completed";
		if (m_completion) return c1;
		else return c2;
	}
	

	// SETTERS FROM HERE 
	void set_task_name(string s) {
		m_task_name = s;
	}
	void set_task_description(string s) {
		m_task_description = s;
	}
	void set_task_id(int id) {
		m_task_id = id;
	}
	void set_task_priority(int pt) {
		m_task_priority = pt;
	}
	void set_completion_status(bool b) {
		m_completion = b;
	}
};



static void enter_the_task(Task* t[],int& n) {
	Task* temp=new Task();
	string s1, s2;
	int p;
	//Set task name
	cout << "Enter the Task name = ";
	getline(cin, s1);
	temp->set_task_name(s1);

	//Set task Description
	cout << "Enter the Task description =";
	getline(cin, s2);
	temp->set_task_description(s2);

	cin.ignore();
	//Enter the priority number;
	cout << "Enter the Priority number = ";
	cin >> p;
	temp->set_task_priority(p);

	//set completion status
	temp->set_completion_status(false);

	t[n++] = temp;
	cout << "------Your task is added.------";


}


static void show_list_of_tasks(Task* t[],int n) {
	for (int i = 0; i < n; i++) {
		Task* temp = t[i];
		cout << "------Task info------"<<endl;
		cout << "Task Name = " << temp->get_task_name() << endl;
		cout << "Task Description = " << temp->get_task_descript() << endl;
		cout << "Task Priority = " << temp->get_task_priority() << endl;
		cout << "Task completion status = "<<temp->get_completion_status()<<endl;
		cout << "-------------------------------------------------" << endl;
		
	}
}



static void show_completed_tasks(Task* t[], int n) {
	for (int i = 0; i < n; i++) {
		Task* temp = t[i];
		int k = temp->get_completion_bool();
		if (k) {
			cout << "------Completed Task info------" << endl;
			cout << "Task Name = " << temp->get_task_name() << endl;
			cout << "Task Description = " << temp->get_task_descript() << endl;
			cout << "Task Priority = " << temp->get_task_priority() << endl;
			cout << "Task completion status" << temp->get_completion_status() << endl;
		}
		else break;
	}
	cout << " ----------Doesnt found any---------- " << endl;
}


static void show_pending_tasks(Task* t[], int n) {
	for (int i = 0; i < n; i++) {
		Task* temp = t[i];
		int k = temp->get_completion_bool();
		if (k) {
			cout << "------Completed Task info------" << endl;
			cout << "Task Name = " << temp->get_task_name() << endl;
			cout << "Task Description = " << temp->get_task_descript() << endl;
			cout << "Task Priority = " << temp->get_task_priority() << endl;
			cout << "Task completion status" << temp->get_completion_status() << endl;
		}
		else break;

	}
	cout << " ----------Doesnt found any---------- " << endl;
}



int main() {
	//Console start from here
	int no_of_task = 0;
	const int size = 10;
	Task* task_array[size] = {};


	int c = 0;
	cout << "||||||_____________TASK MANAGER_____________||||||" << endl;
	while (true) {
		cout << "   List of operations \n   1.Enter a Task. \n   2.Show list of tasks. \n   3.Show Completed Tasks. \n   4.Show Pending tasks. \n   5.Get Task Details."<<endl;
		cout << "Enter -1 to Exit."<<endl;
		cout << "   Enter your Choice (It Should Be An Integer)." << endl;
		cin >> c;cin.ignore();
		if (c == -1) {
			cout << "===============Exit the Program==============="<<endl;
			break;
		}
		switch (c)
		{
		case 1:
		    enter_the_task(task_array, no_of_task);
			cout << "Your task is added";
			break;
		case 2:
			show_list_of_tasks(task_array, no_of_task);
			break;
		case 3:
			show_completed_tasks(task_array, no_of_task);
			break;
		case 4:
			show_pending_tasks(task_array, no_of_task);
			break;
		default:
			cout << "NAh";
			break;
		}
	}
	return 0;
}