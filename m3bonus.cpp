#include <iostream>
#include <string>

using namespace std;

// --- Player and Game State Variables ---
int playerHealth = 100;
int playerAttack = 15;
int dungeonLevel = 1;

// A function to handle the core combat loop.
// It returns a 'bool' (boolean) value: true if the player won, false if they died.
bool startEncounter(int& health, int& level) {
    // 1. Define the Enemy (Simple, fixed stats for now)
    string enemyName = "Angry Goblin";
    int enemyHealth = 20;
    int enemyAttack = 8;
    
    cout << "\n-------------------------------------\n";
    cout << "LEVEL " << level << ": You stumble upon an " << enemyName << "!\n";
    cout << "Its health: " << enemyHealth << "\n";
    cout << "-------------------------------------\n";

    // 2. The Combat Loop (Uses a 'while' loop)
    // The loop continues as long as both the player AND the enemy are alive.
    // The '&&' means BOTH conditions must be true to keep looping.
    while (health > 0 && enemyHealth > 0) {
        
        // Display current status
        cout << "\n--- Your Turn (Level " << level << ") ---\n";
        cout << "Your Health: " << health << " | " << enemyName << " Health: " << enemyHealth << endl;
        cout << "What do you do? (1: Attack, 2: Run)\n> ";
        
        int choice;
        cin >> choice;

        // 3. Decision Logic using if/else
        if (choice == 1) {
            // Player attacks
            enemyHealth -= playerAttack;
            cout << "\nYou swing your sword! You strike the " << enemyName << " for " << playerAttack << " damage!\n";
            
            // Check if the enemy survived
            if (enemyHealth > 0) {
                // Enemy retaliates
                health -= enemyAttack;
                cout << "The " << enemyName << " shrieks and hits you back for " << enemyAttack << " damage!\n";
            }
        
        } else if (choice == 2) {
            // Run option (simple version)
            cout << "You successfully run away! (Dungeon level remains " << level << ").\n";
            return true; // Treat running as a successful exit from the encounter for now
            
        } else {
            // Invalid input
            cout << "Invalid choice. You hesitate, losing your turn!\n";
        }
    }

    // 4. Combat Outcome (After the 'while' loop ends)
    if (health <= 0) {
        // Player died
        cout << "\n[!!!] YOU HAVE FALLEN! GAME OVER at Level " << level << ".\n";
        return false;
    } else {
        // Player won
        cout << "\n[+] VICTORY! You defeated the " << enemyName << "!\n";
        
        // Reward and Level Up
        level++;
        health += 10; // Heal a little bit
        cout << "You gather your strength, restoring 10 Health (Current Health: " << health << ").\n";
        cout << "You proceed to Level " << level << ".\n";
        return true;
    }
}

// The main loop that runs the game until the player dies
void gameLoop() {
    bool isAlive = true;
    while (isAlive) {
        // 'isAlive' is updated by the result of the encounter function
        isAlive = startEncounter(playerHealth, dungeonLevel);
    }
}

int main() {
    cout << "======================================\n";
    cout << "  C++ TEXT DUNGEON CRAWLER: MINIMAL \n";
    cout << "======================================\n";
    cout << "Press Enter to descend into the dungeon...\n";
    cin.get(); // Wait for user input (consumes the initial newline)
    cin.ignore(); // Clear any leftover characters from the buffer

    gameLoop();
    
    return 0;
}