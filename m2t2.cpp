/*
CSC 134
m2t2
Travis Cayton
9/11/2025
*/

#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double meal_cost = 5.99;
    int amount_purchased;
    double cost;
    double tax_owed;
    double total_cost;

    
    // Calculate the values
    cout << "Welcome to The Restaurant!" << endl;
    cout << endl;
    cout << "How many meals would you like?: ";
    cin >> amount_purchased;
    cost = amount_purchased * meal_cost;
    tax_owed = cost * 0.08;
    total_cost = cost + tax_owed;
    cout << endl;
    cout << "---Costs---" << endl;
    cout << endl;


    // Print the results
    cout << "Cost of meals: $" << cost << endl;
    cout << endl;
    cout << "Tax Owed: $" << tax_owed << endl;
    cout << endl;
    cout << "Your total after taxes is: $" << total_cost << endl;
    cout << endl;
    cout << "-----------" << endl;

}