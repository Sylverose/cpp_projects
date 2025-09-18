#include<iostream>
#include<cmath>
using namespace std;
int main(){
    //defined variables
string operator;
int firstnum, secondnum;
//ask user for input
    count<<"Write a value for the first number: ";
    cin>>firstnum;
    count<<"Write a value for the second number: ";
    cin>>secondnum;
    count<<"Write an operator (+, -, *, /, ^): ";
    cin>>operator;
//calculate based on operator
    if (operator == "+"){
        count<<firstnum + secondnum;
    }
    else if (operator == "-"){
        count<<firstnum - secondnum;
    }
    else if (operator == "*"){
        count<<firstnum * secondnum;
    }
    else if (operator == "/"){
        count<<firstnum / secondnum;
    }
    else if (operator == "^"){
        count<<pow(firstnum, secondnum);
    }
    else{
        count<<"Invalid operator";
    }
    return 0;
}
