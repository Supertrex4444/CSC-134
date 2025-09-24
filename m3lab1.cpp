// CSC 134
// M3LAB1
// Travis Cayton
// 9/24/2025


#include <iostream>
using namespace std;


int playerHealth = 100;
int attackDamage = 1;
double gold = 20.0;

string createCharacter(){
string characterName;
cout << "Welcome to Dragon Decide!" << endl;
cout << endl;
cout << "Character Name: ";
cin >> characterName;
return characterName;
}

string characterName = createCharacter();

void bossRoom(){
    cout << "\n" << characterName << " arrives at the Dragon Lair." << endl;
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
    cout << endl;
    if (choice == 1){
        srand(time(0)); //seed RNG before roll
        roll1 = (rand() % 6) + 1;
        roll2 = (rand() % 6) + 1;
        int sum = roll1+roll2;
        cout << "ROLL: " << sum << endl;

        if (( sum == 7) || (sum == 11)){
            cout << "🎲 Seven or Eleven -- You win!" << endl;
            gold = gold * 2;
            cout << "Gold: " << gold << endl;
            casinoRoom();
        }

        else if ( (sum == 2) || (sum == 3) || (sum == 12)) {
            cout << "🎲 2,3,12 -- Sorry, you lose." << endl;
            gold = gold / 2;
            cout << "Gold: " << gold << endl;
            casinoRoom();
        }

        else {
            
            point = sum;
            cout << "🎲 Rolled a point." << endl;
            cout << "Your point is: " << point << endl;
            casinoRoom();
        }
        cout << endl;
    }
    if (choice == 2){
        cout << "\n" << characterName << " leaves at the Casino." << endl;
    }
}
int roll() {
    int my_roll;
    my_roll = (rand() % 6) + 1;
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
    if (choice == 1){
        //return(merchantShop());
    }
        
    else if (choice == 2){
        casinoRoom();
    }

    else if (choice == 3){
        bossRoom();
    }
}

void merchantShop(){
    cout << "\n" << characterName << " stands in front of a Merchant." << endl;
    cout << endl;
    cout << "1. Try to purchase Fiery Greatsword " << endl;
    cout << "2. Try to purchase Dragonscale Armor" << endl;
    cout << "3. Return to Town Center" << endl;
    cout << "4. Beg the merchant for 'Free Stuff'" << endl;
    cout << characterName << endl;
    cout << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    if (choice == 1){
        if (gold >= 500){
            cout << "You purchased the Fiery Greatsword! (gained 50 Attack Damage!)";
            attackDamage = attackDamage + 50;
            merchantShop();
        }
        else if ((gold < 500)){
            cout << "Merchant: You cant afford a Fiery Greatsword!";
            merchantShop();
        }
    }
        
    else if (choice == 2){
        if (gold >= 500){
            cout << "You purchased the Dragonscale Armor! (gained 100 Health!)";
            playerHealth = playerHealth + 100;
            merchantShop();
        }

        else if ((gold < 650)){
            cout << "Merchant: You cant afford Dragonscale Armor!";
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
}

void gameLoop(){
    merchantShop();
    //TODO fix 'declared in this scope' error by returning values back to gameLoop()
    //TODO add 'Dragon Lair and completion to game'
    //TODO show gold during shop
}

int main() {
    gameLoop();
}
