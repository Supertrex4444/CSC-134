/*
CSC 134
m6hw1 - Dungeon Decide
Travis Cayton
11/24/25
Gold
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


string player_name = "NAME";
int player_str = 1;
int player_int = 1;
int player_agi = 1;
int player_char = 1;
int player_health = 100;
string currentRoomName = "";

void createCharacter();
void gameStart();
void screenUpdate();
void characterProfile();
void createRoom();
int statPoints(int unspentPoints);


void createRoom() {
    string room_type[5] = {"Chamber","Dungeon","Cave","Mountain","Field"};
    string room_modifier[5] = {"Fire","Wind","Valor","Shadows","The Dragon"};
    int min = 0;
    int max = 5;
    int randomNumberInRange1 = min + (rand() % (max - min + 1));
    int randomNumberInRange2 = min + (rand() % (max - min + 1));
    currentRoomName = room_type[randomNumberInRange1] + " of " + room_modifier[randomNumberInRange2];
    cout << currentRoomName;
}


void createCharacter() {
    cout << "-CHARACTER CREATOR-" << endl; 
    cout << endl;
    cout << "Enter character name: ";
    cin >> player_name;
    statPoints(5);
    characterProfile();
    cout << "|-Press any key to begin-|" << endl;
    cout << "The game started" << endl;
    createRoom();
}

void characterProfile(){
    screenUpdate();
    cout << "             Character Profile" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Name: " << player_name << endl << "Strength: (" << player_str << ")" << endl << "Intelligence: (" << player_int << ")" << endl << "Agility: (" << player_agi << ")" << endl << "Charisma: (" << player_char << ")" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl;
    cout << endl;
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
     =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
                                               
                  DUNGEON DECIDE 

     =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
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