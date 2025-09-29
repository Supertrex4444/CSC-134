/*

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

    letter_grade = "A";

    cout << "A number of " << num_grade << " is a(n) " << letter_grade;
}