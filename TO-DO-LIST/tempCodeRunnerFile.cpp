#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct Task
{
    string description;
    bool completed;
};

int main() 
{
    vector<Task> tasks; 

    while (true) 
    {
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)  
        {
            case 1:
                {
                    string taskDescription;
                    cout << "Enter task description: ";
                    cin.ignore(); 
                    getline(std::cin, taskDescription);
                    tasks.push_back({taskDescription, false});
                    cout << "Task added.\n";
                }
                break;
            case 2:
                if (tasks.empty()) 
                {
                    cout << "No tasks in the list.\n";
                } 
                else 
                {
                    cout << "To-Do List:\n";
                    for (size_t i = 0; i < tasks.size(); i++) 
                    {
                        cout << i + 1 << ". ";
                        if (tasks[i].completed)
                        {
                            cout << "[X] ";
                        } 
                        else 
                        {
                            cout << "[ ] ";
                        }
                        cout << tasks[i].description << "\n";
                    }
                }
                break;
            case 3:
                {
                    int taskIndex;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskIndex;
                    if (taskIndex >= 1 && taskIndex <= tasks.size()) 
                    {
                        tasks[taskIndex - 1].completed = true;
                        cout << "Task marked as completed.\n";
                    } else 
                    {
                        cout << "Invalid task number.\n";
                    }
                }
                break;
            case 4:
                {
                    int taskIndex;
                    cout << "Enter the task number to remove: ";
                    cin >> taskIndex;
                    if (taskIndex >= 1 && taskIndex <= tasks.size()) 
                    {
                        tasks.erase(tasks.begin() + taskIndex - 1);
                        cout << "Task removed.\n";
                    } 
                    else 
                    {
                        cout << "Invalid task number.\n";
                    }
                }
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
