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

double double_a_number(double); // num times two

int main() {
    double my_num;
    int another_num;

    say_hello();
    cout << "Please enter a number (with or without a decimal place)" << endl;
    cin >> my_num;
    //my_num = my_num * 2;
    my_num = double_a_number(my_num);
    cout << "Double the number is: " << my_num << endl;
    cout << "But the only answer you need is: " << endl;
    cout << get_the_answer() << endl;
}

void say_hello() {
    //says hi
    cout << "Welcome to the program!" << endl;
}
int get_the_answer() {
    //provides the answer to everything
    return 42;
}


double double_a_number(double the_num) {
    // num times two
    double answer = the_num * 2;
    return answer;
}