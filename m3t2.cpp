/*
M3T2
CSC 134
Travis Cayton
9/22/2025
*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
//#include <stdlib.h>
#include <ctime>
using namespace std;

int roll();


int main(){
    int num = roll();
    cout << num << endl;

}


int roll() {
    /*
    srand(time(0));

    int number1 = (rand() % 6) + 1;
    cout << number1 << endl;

    int number2 = (rand() % 6) + 1;
    cout << number2 << endl;

    int sum = number1 + number2;
    cout << "sum is: " << sum << endl;
    return 0;
    */
   return 6;
}