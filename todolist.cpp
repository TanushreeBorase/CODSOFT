#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

void displayMenu();
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskAsCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks; 

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            markTaskAsCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Exiting the to-do list manager. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nTO-DO LIST MANAGER" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task> &tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); // Ignore any remaining newline characters
    getline(cin, description);
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "TASKS:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
        }
    }
}

void markTaskAsCompleted(vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to mark as completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}

void removeTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter the task number to remove: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}
