// CSC 134
// M5HW
// Travis Cayton
// 11/12/2025
// Gold

#include <iostream>
using namespace std;

double question1();
double question2();

int main() {
    question1();
    question2();
}

double question1() {
    string month1;
    string month2;
    string month3;
    double rainfall1;
    double rainfall2;
    double rainfall3;
    

    cout << "Enter month: ";
    cin >> month1;
    cout << "Enter rainfall for " << month1 << ": ";
    cin >> rainfall1;
    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter rainfall for " << month2 << ": ";
    cin >> rainfall2;
    cout << "Enter month: ";
    cin >> month3;
    cout << "Enter rainfall for " << month3 << ": ";
    cin >> rainfall3;
    double average = (rainfall1 + rainfall2 + rainfall3) / 3.0;
    cout << "The average rainfall for " << month1 << ", " << month2 << ", " << month3 << " is " << average << " inches." << endl;
    cout << endl;
}

double question2() {
    double width;
    double length;
    double height;

    cout << "Enter the width of hyperrectangle: "
    cin >> width;
    cout << "Enter the length of hyperrectangle: "
    cin >> length;
    cout << "Enter the height of hyperrectangle: "
    cin >> height;
}