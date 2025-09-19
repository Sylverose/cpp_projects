#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int ID=0;

struct todo {
    int id;
    string task;
};

void addTodo() {
    system("cls");

    cout<<"====================\n";
    cout<<"Add a new To Do item\n";
    cout<<"====================\n";

    todo newTodo;
    newTodo.id = ID++;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, newTodo.task);

    ofstream file("todos.txt", ios::app);
    if (file.is_open()) {
        file << newTodo.id << " " << newTodo.task << endl;
        file.close();
        cout << "Task added with ID: " << newTodo.id << endl;
    } else {
        cout << "Unable to open file";
    }
    system("pause");
}
