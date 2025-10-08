// CSC 134
// M3HW
// Travis Cayton
// 10/08/2025

#include <iostream>
using namespace std;

int main() {
    cout << endl;
    cout << "--Question 1--" << endl;
    cout << "Hello, I’m a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no: ";
    string choice = "";
    cin >> choice;
    if (choice == "yes"){
        cout << "That’s great! I’m sure we’ll get along." << endl;
    }
    else if (choice == "no"){
        cout << "Well, maybe you’ll learn to like me later." << endl;
    }
    else{
        cout << "If you’re not sure… that’s OK." << endl;
    }
    cout << endl;
    cout << "--Question 2--" << endl;
    // Declare variables
    double meal_cost = 5.99;
    int order;
    double cost;
    double tax_owed;
    double total_cost;

    
    // Calculate the values
    cout << "Welcome to The Restaurant!" << endl;
    cout << endl;
    cout << "How much does your meal cost?: ";
    cin >> meal_cost;
    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    cin >> order;
    if (order == 1){
        cost = meal_cost + (meal_cost * 0.15);
    }
    else {
        cost = meal_cost;
    }
    
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
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "--Question 3--" << endl;
    cout << endl;
    cout << "Two paths appear before you." << endl;
    cout << endl;
    cout << "The path on the left leads into a bright and sunny field." << endl;
    cout << "The path on the right leads into a dark and gloomy forest." << endl;
    cout << endl;
    cout << "Enter 1 to go left, or 2 to go right: ";
    cin >> 


    cout << endl;
    cout << "--Question 4--" << endl;
    return 0;
}