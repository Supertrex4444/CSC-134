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
    cout << "---Question 1---" << endl;
    string name;
    int starting_balance;
    int deposit;
    int withdrawal;
    int account_number = rand();
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account balance: $";
    cin >> starting_balance;
    cout << "Enter the amount you want to deposit: $";
    cin >> deposit;
    cout << "Enter the amount you want to withdraw: $";
    cin >> withdrawal;
    int balance_final = starting_balance + deposit - withdrawal;
    cout << endl;
    cout << "-------Account Information-------" << endl;
    cout << endl;
    cout << "Account Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Final Account Balance: $" << balance_final << endl;
    cout << endl;
    cout << "---------------------------------" << endl << endl;
}

void question2(){
    cout << "---Question 2---" << endl;
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;
    double length;
    double height;
    double width;
    double volume;
    double cost;
    double charge;
    double profit;

    //get crate info
    cout << "Enter the length of the crate: ";
    cin >> length;
    cout << "Enter the width of the crate: ";
    cin >> width;
    cout << "Enter the height of the crate: ";
    cin >> height;
    
    // calculate the cost
    volume = length*width*height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge-cost;

    cout << endl;
    cout << "Your crate is: " << volume << " cubic feet." << endl;
    cout << "Cost to Build: $" << cost << endl;
    cout << "Customer Price: $" << charge << endl;
    cout << "The profit made from the crate is: $" << profit << endl;
}

int main() {
    question1();
    question2();
    double cost = 8.5;
    cout << setprecision(2) << fixed;
    cout << "The  cost is: $" << cost << endl;

    return 0;
}