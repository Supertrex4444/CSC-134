/*
CSC 134
m6hw1 - Dungeon Decide
Travis Cayton
11/24/25
Gold
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
void screenUpdate();
int statPoints(int unspentPoints);



void createCharacter() {
cout << "-CHARACTER CREATOR-" << endl; 
cout << endl;
cout << "Enter character name: ";
cin >> player_name;
statPoints(5);
cout << "Nice! now you have all your talent points";
}

int statPoints(int unspentPoints){
    while (unspentPoints > 0) {
        screenUpdate();
        cout << "You have " << unspentPoints << " unspent stat points." << endl << "1 -> Strength(" << player_str << ")" << endl << "2 -> Intelligence(" << player_int << ")" << endl << "3 -> Agility(" << player_agi << ")" << endl << "4 -> Charisma(" << player_char << ")" << endl;
        cout << endl;
        string choice = "";
        cout << "Enter Choice: ";
        cin >> choice;
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" ) {
            cout << "TRY AGAIN, Enter Choice: ";
            cin >> choice;
        }
        if (choice == "1") {
            player_str = player_str + 1;
            unspentPoints = unspentPoints - 1;
        }
        if (choice == "2") {
            player_int = player_int + 1;
            unspentPoints = unspentPoints - 1;
        }
        if (choice == "3") {
            player_agi = player_agi + 1;
            unspentPoints = unspentPoints - 1;
        }
        if (choice == "4") {
            player_char = player_char + 1;
            unspentPoints = unspentPoints - 1;
        }
        
    }
    return 0;
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


void screenUpdate() {
    cout << R"(
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    )" << endl;
}

int main() {
    gameStart();
}