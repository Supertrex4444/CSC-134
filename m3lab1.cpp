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
        merchantShop();
    }
        
    else if (choice == 2){
        casinoRoom();
    }

    else if (choice == 3){
        bossRoom();
    }
}

void bossRoom(){
    cout << "\n" << characterName << " arrives at the Dragon Lair." << endl;
}

void casinoRoom(){
    cout << "\n" << characterName << " arrives at the Casino." << endl;
}

void merchantShop(){
    cout << "\n" << characterName << " stands in front of a Merchant." << endl;
    cout << endl;
    cout << "1. Try to purchase Fiery Greatsword" << endl;
    cout << "2. Try to purchase Dragonscale Armor" << endl;
    cout << "3. Return to Town Center" << endl;
    cout << "4. Beg the merchant for 'Free Stuff'" << endl;
    cout << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;
    if (choice == 1){
        if (gold >= 500){
            cout << "You purchased the Fiery Greatsword! (gained 50 Attack Damage!)";
            attackDamage = attackDamage + 50;

        }
        else if ((gold < 500)){
            cout << "Merchant: You cant afford a Fiery Greatsword!";
        }
    }
        
    else if (choice == 2){
        if (gold >= 500){
            cout << "You purchased the Dragonscale Armor! (gained 100 Health!)";
            playerHealth = playerHealth + 100;
        }
        else if ((gold < 650)){
            cout << "Merchant: You cant afford Dragonscale Armor!";
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
}

int main() {
    gameLoop();
}
