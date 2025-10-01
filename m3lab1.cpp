// CSC 134
// M3LAB1
// Travis Cayton
// 9/24/2025


#include <iostream>
using namespace std;


int playerHealth = 100;

int attackDamage = 1;
int roomNumber = 0;
double gold = 20.0;
string characterName = "a";

string createCharacter();
void merchantShop();
void bossRoom();
void casinoRoom();
int roll();
void townCenter();
void screenShift();


string createCharacter(){
    string characterName;
    cout << "Welcome to Dragon Decide!" << endl;
    cout << endl;
    cout << "Character Name: ";
    cin >> characterName;
    return characterName;
}




void bossRoom(){
    int dragonHealth = 10000;
    int dragonDamage = 80;
    cout << "\n" << characterName << " arrives at the Dragon Lair." << endl;
    cout << endl;
    cout << characterName << " begins fighting the Dragon!" << endl;
    cout << endl;
    while (dragonHealth > 0 && playerHealth > 0){
        cout << "==============================================" << endl;
        cout << "Dragon's Health: " << dragonHealth << endl;
        cout << endl;
        cout << "The Dragon Attacks " << characterName << "!" << endl;
        cout << characterName << " takes " << dragonDamage << " damage!" << endl;
        playerHealth = playerHealth - dragonDamage;
        cout << "==============================================" << endl;
        cout << characterName << "'s Health: " << playerHealth << endl;
        cout << endl;
        cout << "1) Attack!" << endl;
        cout << "2) Run!" << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;
        screenShift();
        cout << endl;
        if (choice==1){
            cout << characterName << " deals " << attackDamage << " damage to the Dragon!" << endl;
            dragonHealth = dragonHealth - attackDamage;
        }
        if (choice==2){
            cout << characterName << " tries to run..." << endl;
            srand(time(0)); //seed RNG before roll
            int roll1;
            roll1 = (rand() % 3) + 1;
            if (roll1 == 1){
                cout << characterName << " escaped!" << endl;
                townCenter();
            }
            else{
                cout << "Escape failed!" << endl;
            }
        }
    }
    if (playerHealth <= 0){
        cout << characterName << " has died..." << endl;
        cout << endl;
        cout << "===GAME OVER===" << endl;
    }
    if (dragonHealth <= 0){
        cout << "The Dragon has been defeated!" << endl;
        cout << endl;
        cout << "===You Win!===" << endl;
    }
    /*
    if (playerHealth > 110){
        cout << characterName << "'s armor protected them from the Dragon's attack!" << endl;
        if (attackDamage > 10){
            cout << characterName << " attacks the dragon with their weapon!" << endl;
            cout << endl;
            cout << "The Dragon was Defeated!" << endl;
            cout << endl;
            cout << "You Win!" << endl;
        }
    }
    else{
        cout << "The Dragon attacks " << characterName << " and their lack of armor proved to be fatal." << endl;
        cout << endl;
        cout << "GAME OVER!" << endl;
    }
        */
}

void casinoRoom(){
    cout << "\n" << characterName << " arrives at the Casino." << endl;
    int roll1 = 5;
    int roll2 = 2;
    int point;
    cout << "1. Gamble!" << endl;
    cout << "2. Quit while your ahead." << endl;
    cout << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    screenShift();
    cout << endl;
    if (choice == 1){
        srand(time(0)); //seed RNG before roll
        roll1 = (rand() % 2) + 1;
        int sum = roll1;
        cout << "ROLL: " << sum << endl;

        if ( sum == 2){
            cout << "🎲 2 -- You win!" << endl;
            gold = gold * 2;
            cout << "Gold: " << gold << endl;
            casinoRoom();
        }

        else if ( (sum == 1) || (sum == 3) || (sum == 12)) {
            cout << "🎲 1 -- Sorry, you lose." << endl;
            gold = gold / 2;
            cout << "Gold: " << gold << endl;
            casinoRoom();
        }
        cout << endl;
    }
    if (choice == 2){
        cout << "\n" << characterName << " leaves at the Casino." << endl;
        townCenter();
    }
    else{
        casinoRoom();
    }
}
int roll() {
    int my_roll;
    my_roll = (rand() % 2) + 1;
    return my_roll;
}


void townCenter(){
    cout << "\n" << characterName << " arrives at The Town Center" << endl;
    cout << "1. Go to Merchant's Shop" << endl;
    cout << "2. Go to Casino" << endl;
    cout << "3. Travel to Dragon's Lair" << endl;
    cout << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    screenShift();
    if (choice == 1){
        merchantShop();
    }
        
    else if (choice == 2){
        casinoRoom();
    }

    else if (choice == 3){
        bossRoom();
    }
    else{
        screenShift();
        townCenter();
    }
}

void merchantShop(){
    cout << "\n" << characterName << " stands in front of a Merchant." << endl;
    cout << endl;
    cout << "1. Try to purchase $500 Damage Increase Potion " << endl;
    cout << "2. Try to purchase $500 Health Increase Potion " << endl;
    cout << "3. Return to Town Center" << endl;
    cout << "4. Beg the merchant for 'Free Stuff'" << endl;
    cout << "CURRENT GOLD: " << gold << endl;
    cout << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    screenShift();
    if (choice == 1){
        if (gold >= 500){
            cout << "You purchased the Damage Increase Potion! (gained 50 Attack Damage!)" << endl;
            attackDamage = attackDamage + 50;
            cout << "CURRENT ATTACK DAMAGE: " << attackDamage << endl;
            gold = gold - 500;
            merchantShop();
        }
        else if ((gold < 500)){
            cout << "Merchant: You cant afford a Damage Increase Potion!";
            merchantShop();
        }
    }
        
    else if (choice == 2){
        if (gold >= 500){
            cout << "You purchased the Health Increase Potion! (gained 100 Health!)" << endl;
            playerHealth = playerHealth + 100;
            cout << "CURRENT HEALTH: " << playerHealth << endl;
            gold = gold - 500;
            merchantShop();
        }

        else if ((gold < 500)){
            cout << "Merchant: You cant afford a Health Increase Potion!";
            merchantShop();
        }
    }

    else if (choice == 3){
        townCenter();
    }

    else if (choice == 4){
        cout << "\n" << characterName << " begs the Merchant." << endl;
        cout << endl;
        cout << "\n" << "The Merchant doesn't give "  << characterName << " any 'free stuff' and now " << characterName << " feels awkward." << endl;
        cout << endl;
        merchantShop();
    }
    else{
        screenShift();
        merchantShop();
    }
}

void screenShift(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}

void gameLoop(){
    characterName = createCharacter();
    screenShift();
    merchantShop();
}

int main() {
    gameLoop();
}
