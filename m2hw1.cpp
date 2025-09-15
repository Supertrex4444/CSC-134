/*
M2HW1
CSC 134
Travis Cayton
9/15/2025
*/

#include <iostream>
#include <iomanip>
using namespace std;


void question1(){
    string name;
    int starting_balance;
    int deposit;
    int withdrawal;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account balance: $";
    cin >> starting_balance;
    cout << "Enter the amount you want to deposit: $";
    cin >> deposit;
    cout << "Enter the amount you want to withdraw: $";
    cin >> withdrawal;

}

void question2(){
    cout << "Question 2" << endl;
}

int main() {
    question1();
    question2();

    cout << "Example of printing out correct money values" << endl;
    double cost = 8.5;
    //cout << setprecision();
    cout << "The  cost is: $" << cost << endl;

    return 0;
}