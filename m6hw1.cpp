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
int player_xp = 0;
int player_level = 1;
string enemy_name = "NAME";
int enemy_str = 1;
int enemy_int = 1;
int enemy_agi = 1;
int enemy_char = 1;
int enemy_health = 100;
string currentRoomName = "";




void createCharacter();
void gameStart();
void screenUpdate();
void characterProfile();
void createRoom();
void createEnemy();
void roomGameplay();
void combat();
int statPoints(int unspentPoints);
int rng(int num);


void createEnemy() {
    string name[48] = {"Bob", "Tom", "Jerry", "Sue", "Jane", "Bill", "Jim", "Sam", "Pat", "Joe", "Nancy", "Ann", "Tim", "Rick", "Fred", "Lucy", "Maggie", "Frank", "Ted", "Kate", "Linda", "Betty", "Charlie", "Dave", "Eve", "Helen", "George", "Paul", "Chris", "Mary", "John", "Carl", "Jack", "Diane", "Steve", "Martha", "Alan", "Ruth", "Clara", "Bruce", "Ned", "Vince", "Laura", "Shirley", "Tommy", "Walt", "Ed"};
    string enemy_type[5] = {"Elemental","Evil Knight","Witch","Wraith","Dragon"};
    enemy_str = 1 + rng(8);
    enemy_int = 1 + rng(8);
    enemy_agi = 1 + rng(8);
    enemy_char = 1 + rng(8);
    enemy_health = 25 + rng(75);
    int randomNumber1 = rng(47);
    int randomNumber2 = rng(5);
    enemy_name = name[randomNumber1] + " the " + enemy_type[randomNumber2];
    cout << endl;
    screenUpdate();
}

void createRoom() {
    string room_type[5] = {"Chamber","Dungeon","Cave","Mountain","Field"};
    string room_modifier[5] = {"Fire","Wind","Valor","Shadows","The Dragon"};
    int randomNumber1 = rng(5);
    int randomNumber2 = rng(5);
    currentRoomName = room_type[randomNumber1] + " of " + room_modifier[randomNumber2];
    cout << currentRoomName;
    
    roomGameplay();
}

int rng(int num) {
    srand(time(0));
    int rand_num = (rand() % num);
    return rand_num;
}

void roomGameplay() {
    createEnemy();
    combat();
}

void combat() {
    cout << player_name << " is fighting " << enemy_name << "!" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Your Health: " << player_health << " | " << "Enemy's Health: " << enemy_health << endl;
    cout << R"(

What will you do?
    
1. Fight
2. Act
3. Retreat
)";

    cout << "Enter choice: ";
    string choice = "";
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3") {
        cout << "TRY AGAIN, Enter Choice: ";
        cin >> choice;
    }
    if (choice == "1") {
        if (player_str > player_agi && player_str > player_int && player_str > player_char) {
            cout << player_name << " deals a mighty blow to " << enemy_name << " dealing " << player_str << " damage!";
        }
    }

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
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
                                               
              DUNGEON DECIDE

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
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