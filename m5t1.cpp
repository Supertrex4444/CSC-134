/*
CSC 134
m5t1 - Basic functions
Travis Cayton
10/22/25
*/

#include <iostream>
using namespace std;

void say_hello(); //says hi

int get_the_answer(); //provides the answer to everything

double double_a_number(); // num times two

int main() {
    double my_num;
    int another_num;

    cout << "Welcome to the program!" << endl;
    cout << "Please enter a number (with or without a decimal place)" << endl;
    cin >> my_num;
    my_num = my_num * 2;
    cout << "Double the number is: " << my_num << endl;
}