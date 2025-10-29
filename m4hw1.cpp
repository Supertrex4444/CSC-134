// CSC 134
// M4HW1
// Travis Cayton
// 10/29/2025
// Gold

#include <iostream>
using namespace std;

int main() {
    int input_num = 0;
    int multiply_num = 0;
    input_num = 0;
    while (input_num > 12 or input_num < 1) {
        if (input_num > 12 or input_num < 1) {
            input_num = 1;
        }
        cout << "Enter a number from 1 to 12: ";
        cin >> input_num;
    }

    cout << endl;


    while (multiply_num < 12 && input_num >= 1 && input_num <= 12) {
        multiply_num = multiply_num + 1;
        cout << input_num << " times " << multiply_num << " is " << input_num * multiply_num << endl;
    }
    
    cout << endl;
    
}