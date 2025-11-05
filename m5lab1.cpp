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
            cout << endl;
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
    cout << endl;
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
void room1Choice1();
void room1Choice2();
void room1Choice3();
void room2Choice1();
void room2Choice2();

void gameOver();
void goodEnding();


void game_start() {
    cout << R"(
Two paths appear before you.

The path on the left leads into a bright and sunny field.

The path on the right leads into a dark and gloomy forest.
    )" << endl;

    int choice;
    showChoices("Go left (sunny field)","Go right (gloomy forest)", "Turn back and go home");
    choice = getPlayerChoice(MAX);

    if (choice == 1) {
        room1Choice1();
    }
    if (choice == 2) {
        room1Choice2();
    }
    if (choice == 3) {
        room1Choice3();
    }
}

void room1Choice1(){
        cout << endl;
        cout << "You enter the bright and sunny field." << endl;
        cout << "Unfortunately it was too sunny and you were sunburnt." << endl;
        gameOver();
}

void room1Choice2(){
    cout << endl;
    cout << "You enter the dark and gloomy forest." << endl;
    cout << "You see a light up ahead." << endl;
    int choice;
    showChoices("Go towards the light","Go the opposite way","");
    choice = getPlayerChoice(2);

    if (choice == 1) {
        room2Choice1();
    }
    if (choice == 2) {
        room2Choice2();
    }
}

void room1Choice3(){
        cout << endl;
        cout << "Rather than going down either path, you instead just turn around and leave." << endl;
        gameOver();
}

void room2Choice1(){
    cout << "You go towards the light." << endl;
    cout << "The source of this light was a campfire, a skeleton sat nearby roasting a marshmallow for s'mores." << endl;
    cout << endl;
    cout << "You sat around the campfire with the skeleton and ate s'mores with it." << endl;
    goodEnding();
}

void room2Choice2(){
    cout << "You decide to not go towards the light and instead just leave." << endl;
    cout << "On your way out, however, you tripped on a branch." << endl;
    gameOver();
}


void gameOver(){
    cout << R"(
 ___________________________________________
|                                           |
|                GAME OVER                  |
|___________________________________________|
    )" << endl;
}

void goodEnding(){
    cout << R"(
 ___________________________________________
|                                           |
|               Good Ending                 |
|___________________________________________|
    )" << endl;
}