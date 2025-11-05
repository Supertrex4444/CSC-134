/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Travis Cayton
11/5/2025
*/

#include <iostream>
using namespace std;

int getPlayerChoice(int maxChoice);
void showChoices(string choice1, string choice2, string choice3);

void game_start();
const int MAX = 3;

int main() {
    /*
    int choice;
    int max = 3;
    showChoices("1","2","3");
    cout << "Testing: 1,2, or 3." << endl;
    choice = getPlayerChoice(max);
    cout << "You chose: " << choice << endl;
    */
   // Start Game
   game_start();
}

// ============================================================================
// GAME LOGIC FUNCTIONS
// ============================================================================
// These functions handle the mechanics of running the game.

/**
 * Get a valid choice from the player.
 *
 */
int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice: ";
        cin >> choice;

        // Validate range
        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }
        else {
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
            cout << endl;
        }

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}

void showChoices(string choice1, string choice2, string choice3) {

    cout << "--- MAKE YOUR CHOICE ---" << endl;
    int num = 1;
    cout << num << ". " << choice1 << endl;
    num++;

    if (choice2 != "") {
        cout << num << ". " << choice2 << endl;
        num++;
    }

        if (choice3 != "") {
        cout << num << ". " << choice3 << endl;;
        num++;
    }
}

/////////////////////////
// Story functions
////////////////////////
void game_start() {
    int choice;

    cout << R"(
    Two paths appear before you.

    The path on the left leads into a bright and sunny field.

    The path on the right leads into a dark and gloomy forest.
    )" << endl;

    showChoices("Go left","Go right", "Turn back and go home");
    choice = getPlayerChoice(MAX);

    if (choice == 1) {
        cout << "You go left" << endl;
    }
    if (choice == 2) {
        cout << "You go right" << endl;
    }
    if (choice == 3) {
        cout << "You go home" << endl;
    }
}
