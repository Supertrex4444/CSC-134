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
int initial_enemy_health = 0;
string currentRoomName = "";




void createCharacter();
void gameStart();
void screenUpdate();
void characterProfile();
void createRoom();
void createEnemy();
void roomGameplay();
void combat();
void gameover();
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
    initial_enemy_health = enemy_health;
    int randomNumber1 = rng(47);
    int randomNumber2 = rng(5);
    enemy_name = name[randomNumber1] + " the " + enemy_type[randomNumber2];
    cout << endl;
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
    cout << player_name << " encounters " << enemy_name << " in The " << currentRoomName << endl << endl;
    combat();
    if (player_health > 0) {
        cout << currentRoomName << " has been cleared!" << endl;
        characterProfile();
        cout << "1. Enter the next room" << endl << "2. Restore HP (Costs XP)" << endl;
        string choice = "";
        cin >> choice;
        screenUpdate();
        while (choice != "1" && choice != "2") {
            cout << "TRY AGAIN, Enter Choice: ";
            cin >> choice;
        }
        if (choice == "1") {
            createRoom();
        }
        if (choice == "2") {
            cout << "You restored " << player_xp << " health!" << endl;
            player_health = player_health + player_xp;
            if (player_health > 100) {
                player_health = 100;
            }
            cout << "Current HP: " << player_health << endl;
            player_xp = 0;
        }
    }
}

void gameover() {
    cout << endl << endl;
    cout << player_name << " had died!" << endl;
    cout << R"(
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
                                               
               GAME OVER

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    )" << endl;
}

void combat() {
    while (enemy_health > 0 && player_health > 0){
        
        int damage_dealt = 0;
        int enemy_damage = 0;
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
        screenUpdate();
        if (choice == "1") {
            damage_dealt = player_str;
            //if strength is greatest
            if (player_str > player_agi && player_str > player_int && player_str > player_char) {
                damage_dealt = player_str + rng(8);
                cout << player_name << " strikes " << enemy_name <<  " powerfully with their weapon, dealing " << damage_dealt << " damage!";
            }
            //if intelligence is greatest
            if (player_int > player_agi && player_int > player_str && player_int > player_char) {
                damage_dealt = player_int + rng(6);
                cout << player_name << " casts a frostbolt at " << enemy_name <<  ", dealing " << damage_dealt << " damage!";
            }
            //if agility is greatest
            if (player_agi > player_str && player_agi > player_int && player_agi > player_char) {
                damage_dealt = player_agi + rng(4);
                cout << player_name << " preforms a swift attack to " << enemy_name <<  ", dealing " << damage_dealt << " damage!";
                
            }
            //if charisma is greatest
            if (player_char > player_str && player_char > player_int && player_char > player_agi) {
                damage_dealt = player_char + rng(2);
                cout << player_name << " insults " << enemy_name <<  ", dealing " << damage_dealt << " emotional damage!";
                
            }
            enemy_health = enemy_health - damage_dealt;
        }
        cout << endl << endl;

        if (enemy_health > 0) {
            enemy_damage = 5 + rng(5);
            cout << enemy_name << " deals " << enemy_damage << " damage to you!";
            player_health = player_health - enemy_damage;
        }
        
        else{
            screenUpdate();
            cout << enemy_name << " has been defeated!" << endl;
            player_xp = player_xp + initial_enemy_health;
            cout << "You gained " << player_xp << " XP!" << endl;
            if (player_xp >= 100) {
                player_level = player_level + 1;
                player_health = player_health + 30;
                cout << player_name << " has reached level " << player_level << "!" << endl << endl;
                statPoints(2);
                player_xp = 0;
            }
        }
        
        
        cout << endl << endl;
    }
}


void createCharacter() {
    cout << "-CHARACTER CREATOR-" << endl; 
    cout << endl;
    cout << "Enter character name: ";
    cin >> player_name;
    screenUpdate();
    statPoints(5);
    screenUpdate();
    characterProfile();
    cout << "Type '1' to start game" << endl << endl;
    string choice = "";
    cin >> choice;

    while (choice != "1") {
        cout << "TRY AGAIN, Enter Choice: ";
        cin >> choice;
    }
    if (choice == "1") {
        cout << "The game has started" << endl;
        while (player_health > 0){
            screenUpdate();
            createRoom();
        }
        if (player_health <= 0) {
            gameover();
        }
    }
}

void characterProfile(){
    cout << "             Character Profile" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Name: " << player_name << endl << "Health: " << player_health << endl << "Strength: (" << player_str << ")" << endl << "Intelligence: (" << player_int << ")" << endl << "Agility: (" << player_agi << ")" << endl << "Charisma: (" << player_char << ")" << endl;
    cout << "Level: " << player_level << endl << "XP: " << player_xp << "/100" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl;
    cout << endl;
}

int statPoints(int unspentPoints){
    while (unspentPoints > 0) {
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
        screenUpdate();
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