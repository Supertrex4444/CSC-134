/*
M3T1
CSC 134
Travis Cayton
9/17/2025
*/



#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double length1, length2, width1, width2;
    double area1, area2;
    cout << "Enter the length and width of two rectangles." << endl;
    cout << endl;
    cout << "---First rectangle---" << endl;
    cout << "Length: ";
    cin >> length1;
    cout << "Width: ";
    cin >> width1;
    cout << endl;
    cout << "---Second rectangle---" << endl;
    cout << "Length: ";
    cin >> length2;
    cout << "Width: ";
    cin >> width2;
    cout << endl;

    // Calculate the area
    area1 = length1 * width1;
    area2 = length2 * width2;

    // Print the output
    cout << "The area of the first rectangle is: " << area1 << endl;
    cout << endl;
    cout << "The area of the second rectangle is: " << area2 << endl;

    return 0;
}
