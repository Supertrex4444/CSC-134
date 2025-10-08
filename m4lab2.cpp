/*
M4lab2
CSC 134
Travis Cayton
10/08/2025
*/

#include <iostream>
using namespace std;

int main(){
    int length = 10;
    int height = 10;
    string tile = "👻";

    for (int i=0; i<10; i++) {
        cout << tile;
    }
    cout << endl;

    int count = 0;
    while (count < length)  {
        cout << tile;
        count++;
    }

    for (int i = 0; i < height; i++) {
        cout << tile << endl;
    }

    cout << endl << endl;
    cout << "Draw a Rectangle" << endl;
    cout << "What is the length? ";
    cin >> length;
    cout << "What is the height? ";
    cin >> height;
    cout << "Rectangle " << length << " x " << height << endl;

    for (int i=0; i < height; i++) {
        for (int j=0; j < length; j++){
            cout << tile;
        }
        cout << endl;
    }
 
    return 0;
}