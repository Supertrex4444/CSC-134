/*
CSC 134
m1lab
Travis Cayton
8/27/2025
Purpose: The "shiny rock" sales program
*/

#include <iostream>
using namespace std;

int main() {
    // start prgram
    // declare all of our variables ("whiteboards")
    string item = "shiny rock";
    int    num_items = 71;
    double cost_per = 0.25;

    cout << "Welcome to the " << item << " store!" << endl;
    // do the processing
    double total_cost = num_items * cost_per;
    // end program
    return 0;
}