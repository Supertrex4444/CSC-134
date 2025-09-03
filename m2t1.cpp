/*
CSC 134
m2t1
Travis Cayton
9/3/2025
Purpose: The "shiny rock" sales program
*/

#include <iostream>
using namespace std;

int main() {
    // start prgram
    // declare all of our variables ("whiteboards")
    string item_name = "shiny rock";
    int    num_items = 71;
    double cost_per = 0.99;
    int amount_purchased;
    double total_cost = 0.0;
    
    // Give our sales pitch
    cout << "Welcome to The " << item_name << " store!" << endl;

    cout << "\n";

    cout << "Each " << item_name << " is $" << cost_per << endl;
    cout << "We have " << num_items << " total." << endl;
    cout << endl;
    cout << "How many would you like to buy? ";

    //cin = input
    cin >> amount_purchased;
    total_cost = amount_purchased * cost_per;

    // Print the output
    cout << "You are buying " << amount_purchased << " " << item_name << endl;
    cout << "The total is: $" << total_cost << endl;
    cout << "Thanks for shopping with us!" << endl;
    cout << "\n";

    // end program
    return 0;
}