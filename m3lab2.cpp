/*
CSC 134
M3LAB2
Travis Cayton
9/29/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void letter_grader();
void combat();

int main(){
    letter_grader();
    return 0;
}

void letter_grader(){
    double num_grade;
    string letter_grade;
    cout << "Enter a number grade 0-100: ";
    cin >> num_grade;
    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;
    letter_grade = "A";

    if (num_grade >= A_GRADE) {
        letter_grade = "A";
    }
    else if (num_grade >= B_GRADE) {
        letter_grade = "B";
    }
    else if (num_grade >= C_GRADE) {
        letter_grade = "C";
    }
    else if (num_grade >= D_GRADE) {
        letter_grade = "D";
    }
    else {
        letter_grade = "F";
    }

    cout << "A number of " << num_grade << " is a(n) " << letter_grade;
    cout << endl;
    cout << endl;
}