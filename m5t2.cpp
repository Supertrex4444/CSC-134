/*
CSC 134
m5t2
Travis Cayton
11/03/25
*/

#include <iostream>
using namespace std;



double square(double); // num squared
void printAnswerLine();

int main() {
    for (int i = 1; i <= 10; i++)
    {
        printAnswerLine();
        cout << i << " is " << square(i) << endl;
    }
}

double square(double num) {
    // num times two
    double answer = num * num;
    return answer;
}

void printAnswerLine() {
    cout << "The square of ";
}