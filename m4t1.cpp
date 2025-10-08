/*
M4T1
CSC 134
Travis Cayton
10/08/2025
*/

#include <iostream>
using namespace std;

int main(){
    int count;
    cout << "What number should I count down from? ";
    cin >> count;
    
    while (count >= 0){
        cout << "Number " << count << endl;
        count--;
    }
    cout << endl;
    cout << "Loop complete!" << endl;
    return 0;
}