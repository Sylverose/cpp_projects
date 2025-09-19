#include<iostream>
#include<cmath>
using namespace std;
int main(){
string operation;
double firstnum, secondnum;

    cout<<"Write a value for the first number: ";
    cin>>firstnum;
    cout<<"Write a value for the second number: ";
    cin>>secondnum;
    cout<<"Write an operation (+, -, *, /, ^, ¤): ";
    cin>>operation;

    if (operation == "+"){
        cout<<firstnum + secondnum;
    }
    else if (operation == "-"){
        cout<<firstnum - secondnum;
    }
    else if (operation == "*"){
        cout<<firstnum * secondnum;
    }
    else if (operation == "/"){
        cout<<firstnum / secondnum;
    }
    else if (operation == "^"){
        cout<<pow(firstnum, secondnum);
    }
    else if (operation == "¤"){
        cout<<sqrt(firstnum);
    }
    else{
        cout<<"Invalid operation";
    }
    return 0;
}
