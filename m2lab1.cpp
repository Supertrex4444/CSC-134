// CSC 134
// M2LAB1
// Travis Cayton
// 9/8/2025

#include <iostream>
using namespace std;

int main(){
    //create variables
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;
    double length;
    double height;
    double width;
    double volume;
    double cost;
    double charge;
    double profit;

    //get crate info
    cout << "Enter the length of the crate: ";
    cin >> length;
    cout << "Enter the width of the crate: ";
    cin >> width;
    cout << "Enter the height of the crate: ";
    cin >> height;
    
    // calculate the cost
    volume = length*width*height;
    cost = volume * COST_PER_CUBIC_FOOT;
    charge = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge-cost;

    cout << endl;
    cout << "The volume of the crate is: " << volume << endl;
    cout << "The cost of the crate is: " << cost << endl;
    cout << "Your charge for the crate is: " << charge << endl;
    cout << "The profit made from the crate is: " << profit << endl;

    
    return 0;
}