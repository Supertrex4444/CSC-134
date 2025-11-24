/*
CSC 134
m6hw1 - Dungeon Decide
Travis Cayton
11/24/25
*/


#include <iostream>
using namespace std;


string player_name = "NAME";
int player_str = 1;
int player_int = 1;
int player_agi = 1;
int player_char = 1;
int player_health = 100;

void createCharacter();
void gameStart();
int statPoints(int unspentPoints);

void createCharacter() {
cout << "-CHARACTER CREATOR-" << endl; 
cout << endl;
cout << "Enter character name: ";
cin >> player_name;
statPoints(5);
}

int statPoints(int unspentPoints){
    cout << "You have " << unspentPoints << " unspent stat points." << endl << "1 -> Strength(" << player_str << ")" << endl << "2 -> Intelligence(" << player_int << ")" << endl << "3 -> Agility(" << player_agi << ")" << endl << "4 -> Charisma(" << player_char << ")" << endl;
    cout << endl;
    
}

void gameStart() {
    cout << R"(
     ___________________________________________
    |                                           |
    |              DUNGEON DECIDE               |
    |___________________________________________|
    )" << endl;
    cout << endl << endl << endl;
    createCharacter();
}


int main() {
    gameStart();
}