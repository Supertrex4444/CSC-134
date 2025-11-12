// CSC 134
// M5HW
// Travis Cayton
// 11/12/2025
// Gold

#include <iostream>
using namespace std;

double question1();
double question2();
void question3();

int main() {
    //question1();
    //question2();
    question3();
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
    return 0.0;
}

double question2() {
    double width;
    double length;
    double height;

    cout << "Enter the width of hyperrectangle: ";
    cin >> width;
    while (width <= 0) {
    cin.ignore();
    cin.clear();
    cout << "Enter the width of hyperrectangle: ";
    cin >> width; 
    }
    
    cout << "Enter the length of hyperrectangle: ";
    cin >> length;
    while (length <= 0) {
    cin.ignore();
    cin.clear();
    cout << "Enter the length of hyperrectangle: ";
    cin >> length; 
    }

    cout << "Enter the height of hyperrectangle: ";
    cin >> height;
    while (height <= 0) {
    cin.ignore();
    cin.clear();
    cout << "Enter the height of hyperrectangle: ";
    cin >> height; 
    }
    double volume = width * length * height;
    cout << "The volume of the hyperrectangle is: " << volume << endl;
    cout << endl;
    return 0.0;
}

void question3() {
    int value;
    string roman_num = "";
    cout << "Enter value between 1 and 10: ";
    cin >> value;
    int base_value = value;
    while (value < 0 && value > 10) {
        cin.ignore();
        cin.clear();
        cout << "Enter value between 1 and 10: ";
        cin >> value; 
    }

    while (value > 0) {
        if (value == 10){
            roman_num = roman_num + "X";
            value = value - 10;
        }
        if (value >= 5 && value < 10){
            roman_num = roman_num + "V";
            value = value - 5;
        }
        if (value >= 1 && value < 5 && value < 10){
            roman_num = roman_num + "I";
            value = value - 1;
        }
    }
    cout << base_value << " as a roman numeral is " << roman_num << endl;
    cout << endl;
}
