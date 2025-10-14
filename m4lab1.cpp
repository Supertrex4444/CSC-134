/*
M4LAB1
CSC 134
Travis Cayton
10/14/2025
*/

#include <iostream>
#include <string>
using namespace std;

void exercise1_healthRegen();
void exercise2_levelUpStats();
void exercise3_inventorySystem();

int main()
{
int choice;

cout << "==================================" << endl;
cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
cout << "==================================" << endl;
cout << "1. Exercise 1: Health Regeneration" << endl;
cout << "2. Exercise 2: Level Up Stats" << endl;
cout << "3. Exercise 3: Inventory System" << endl;
cout << "4. Run All Exercises" << endl;
cout << "5. Exit" << endl;
cout << "==================================" << endl;
cout << "Choice: ";
cin >> choice;

switch(choice)
{
    case 1:
        exercise1_healthRegen();
        break;
    case 2:
        exercise2_levelUpStats();
        break;
    case 3:
        exercise3_inventorySystem();
        break;
    case 4:
        exercise1_healthRegen();
        cout << endl;
        exercise2_levelUpStats();
        cout << endl;
        exercise3_inventorySystem();
        break;
    case 5:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
}

return 0;
}


void exercise1_healthRegen()
{
cout << “\n=== EXERCISE 1: HEALTH REGENERATION ===” << endl;

int health = 30;
int maxHealth = 100;

cout << "Starting health: " << health << "/" << maxHealth << endl;
cout << "Resting to recover health..." << endl << endl;

// TODO: Implement your while loop here
// HINT: while (health < maxHealth)
// {
//     health = health + 10;
//     // Display current health
//     // BONUS: Add a visual health bar
// }



// TODO: Display "Fully recovered!" message