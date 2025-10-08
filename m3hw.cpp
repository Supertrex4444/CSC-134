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

    string path;
    string option;
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
    cin >> path;
    cout << endl;
    cout << endl;
    if (path == "1"){
        cout << endl;
        cout << "You enter the bright and sunny field." << endl;
        cout << "Unfortunately it was too sunny and you were sunburnt." << endl;
        cout << "GAME OVER" << endl;
    }
    else if (path == "2"){
        cout << endl;
        cout << "You enter the dark and gloomy forest." << endl;
        cout << "You see a light up ahead." << endl;
        cout << "Enter 1 to go towards the light, or 2 to go the opposite way: ";
        cin >> option;
        cout << endl;
        cout << endl;
        if (option == "1"){
            cout << "You go towards the light." << endl;
            cout << "The source of this light was a campfire, a skeleton sat nearby roasting a marshmallow for s'mores." << endl;
            cout << endl;
            cout << "You sat around the campfire with the skeleton and ate s'mores with it." << endl;
            cout << "YOU WIN!" << endl;
        }
        if (option == "2"){
            cout << "You decide to not go towards the light and instead just leave." << endl;
            cout << "On your way out, however, you tripped on a branch." << endl;
            cout << "GAME OVER" << endl;
        }
    }
    else{
        cout << "Rather than going down either path, you instead just turn around and leave.";
    }
    srand(time(0)); //seed RNG before roll
    int answer;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "--Question 4--" << endl;
    int number1 = (rand() % 9) + 1;
    cout << number1 << endl;
    int number2 = (rand() % 9) + 1;
    cout << number2 << endl;
    cout << "What is " << number1 << " plus " << number2 << "?" << endl;
    cin >> answer;
    if (answer == number1 + number2) {
        cout << "Correct!" << endl;
    }
    else {
        cout << "Incorrect." << endl;
    }
    return 0;
}