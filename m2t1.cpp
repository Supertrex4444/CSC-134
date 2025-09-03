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
    double cost_per = 0.25;

    // Give our sales pitch
    cout << "Welcome to The " << item_name << " store!" << endl;

    cout << "\n";

    cout << "Each " << item_name << " is $" << cost_per << endl;
    cout << "We have " << num_items << " total." << endl;

    // do the processing
    double total_cost = num_items * cost_per;

    // Print the output
    cout << "There are $" << total_cost << " worth of " << item_name << "s" << endl;
    cout << "\n";
    cout << "Thanks for shopping with us!" << endl;
    cout << "\n";

    // end program
    return 0;
}