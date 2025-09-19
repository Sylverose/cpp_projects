// Features

// The user can add a new task
// Update the existing task
// Delete a task from the list of todo
// View all the tasks
// All the data is preserved as we use file handling

#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;

int ID;
// Custom type todo which has two fields id and task

struct todo {
    int id;
    string task;
};

// Add New Task Method
void addTodo() {
    system("cls");
	cout<<"====================\n";
    cout<<"Add a new To Do item\n";
    cout<<"====================\n";
    todo todo;

    cout << "\n\tEnter new task : ";
    cin.get();
    getline(cin, todo.task); 
    ID++; 

    // Write this task to the todo.txt file
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    //write the id to a new file so that we can use this id later to add new task
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"\n\tDo you want to add more task? y or n : "; cin>> ch;


    //if user wants to add a new task again then call the same function else return
    if(ch == 'y'){
        addTodo();
    }
    else{
        cout << "\n\tTask has been added successfully";
        return;
    }
}

// Display Added Tasks Method
void print(todo s) {
    cout << "\tID is : " << s.id;
    cout << "\tEnter task : " << s.task;
}

// Read Added Tasks from todo.txt Method
void readData() {
    system("cls");
    cout<<"====================\n";
    cout<<"Add a new To Do item\n";
    cout<<"====================\n";
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t\t\tExisting tasks\n";
    
    // while we dont reach the end of file keep on printing the data on screen
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

// Search for a specific task from the todo.txt file Method
int searchData() {
    system("cls");
    cout<<"====================\n";
    cout<<"Search task\n";
    cout<<"====================\n";
    int id;
    cout << "\n\tEnter task id: ";     cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    // while we dont reach end of file keep or searching for the id to match to the user input id
    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

// // Delete Task Method
void deleteData() {
    system("cls");
    cout<<"====================\n";
    cout<<"Task clear\n";
    cout<<"====================\n";
    int id = searchData();
    cout << "\n\tDo you want to delete this task? y or n : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");
        // while we dont reach the end of file keep on searching for the id to delete the task
        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}


int main()
{
    system("cls");
	system("Color E0"); // "Color XY", X - backgroung color, Y - text color
    system("title todoapp @copyassignment");
    cout<<"====================\n";
    cout<<"To do\n";
    cout<<"====================\n";
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    
}
