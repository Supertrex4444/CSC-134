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
double question4();
int question5();
void question6();

int main() {
    cout << "--Welcome to the M5HW Program--" << endl << endl;
    question6();
}

void question6() {
    int choice;
        while (choice != 6)
        {
        
        do {
        cout << endl;
        cout << "1. Question 1" << endl;
        cout << "2. Question 2" << endl;
        cout << "3. Question 3" << endl;
        cout << "4. Question 4" << endl;
        cout << "5. Question 5" << endl;
        cout << "6. Quit" << endl << endl;

        cout << "Enter choice: ";
        cin >> choice;

        }
        while (choice < 0 or choice > 6);
        if (choice == 1) {
            question1();
        }
        if (choice == 2) {
            question2();
        }
        if (choice == 3) {
            question3();
        }
        if (choice == 4) {
            question4();
        }
        if (choice == 5) {
            question5();
        }
    }
    cout << "Goodbye!" << endl;
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

double question4() {
    int choice;
    do {
        cout << "Geometry Calculator" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cout << endl;
    }
    while (choice <= 0 or choice > 4);
    
    if (choice == 1){
        double radius;
        cout << "Enter the circle's radius: ";
        cin >> radius;
        while (radius < 0) {
            cin.ignore();
            cin.clear();
            cout << "The radius cannot be less than zero.";
            cin >> radius; 
        }
        cout << endl;
        cout << "The area is: " << 3.14159 * (radius * radius);
    }

    if (choice == 2){
        double width;
        double height;
        cout << "Enter the rectangle's width: ";
        cin >> width;
        while (width < 0) {
            cin.ignore();
            cin.clear();
            cout << "The width cannot be less than zero.";
            cin >> width; 
        }
        cout << "Enter the rectangle's height: ";
        cin >> height;
                while (height < 0) {
            cin.ignore();
            cin.clear();
            cout << "The height cannot be less than zero.";
            cin >> height; 
        }
        cout << endl;
        cout << "The area is: " << width * height;
    }


    if (choice == 3){
        double base;
        double height;
        cout << "Enter the triangle's base: ";
        cin >> base;
        while (base < 0) {
            cin.ignore();
            cin.clear();
            cout << "The base cannot be less than zero.";
            cin >> base; 
        }
        cout << "Enter the triangle's height: ";
        cin >> height;
                while (height < 0) {
            cin.ignore();
            cin.clear();
            cout << "The height cannot be less than zero.";
            cin >> height; 
        }
        cout << endl;
        cout << "The area is: " << 0.5 * base * height;
    }
    return 0.0;
}

int question5() {
    double mph;
    double hours;
    cout << "What is the speed of the vehicle in mph? ";
    cin >> mph;
    cout << "How many hours has it traveled? ";
    cin >> hours;
    cout << R"(
Hour    Distance Traveled
------------------------------------------
)";
    for (int i=1; i < hours+1; i++) {
        cout << "  " << i << "            " << mph*i << endl;
    }
    cout << endl;
    return 0.0;
}