/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Travis Cayton
11/5/2025
*/

#include <iostream>
using namespace std;

int getPlayerChoice(int maxChoice);

int main() {
    int choice;
    int max = 3;
    cout << "Testing: 1,2, or 3." << endl;
    int choice = getPlayerChoice();
    cout << "You chose: " << choice << endl;
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

        cout << "Please choose between 1 and " << maxChoice << ".\n";
    }
}