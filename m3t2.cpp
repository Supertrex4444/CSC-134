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
    //int num = roll();
    //cout << num << endl;
    int roll1 = 5;
    int roll2 = 2;
    int point;

    cout << "Enter two dice (press Enter between) ";
    cin >> roll1;
    cin >> roll2;
    int sum = roll1+roll2;

    if (( sum == 7) || (sum == 11)){
        cout << "🎲 Seven or Eleven -- You win!" << endl;
    }

    else if ( (sum == 2) || (sum == 3) || (sum == 12)) {
        cout << "🎲 2,3,12 -- Sorry, you lose." << endl;
    }

    else {
        
        point = sum;
        cout << "Rolled a point." << endl;
        cout << "your point is: " << point << endl;
    }
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