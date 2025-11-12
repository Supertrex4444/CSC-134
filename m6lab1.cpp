/*
CSC 134
m6lab1
Travis Cayton
11/12/25
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

// ============================================================================
// GLOBAL VARIABLES - Accessible to all functions
// ============================================================================
vector<char> cardDeck;

// Player scores
int playerScore = 3;
int opponentScore = 3;

// Game state
string currentPlayer = "Player";
bool gameOver = false;

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
void setupGame();
void loadCardDeck(int redCardCount, int blackCardCount);
void shuffleCardDeck();
void displayGameState();
void displayCardDeck(bool showContents);
char fireShot();
void playerTurn();
void opponentTurn();
void checkGameOver();

// ============================================================================
// MAIN GAME LOOP
// ============================================================================
int main() {
    srand(time(0));  // Seed random number generator
    
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║             CARD ROULETTE              ║" << endl;
    cout << "║                                        ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "\nRules:" << endl;
    cout << "♦️ Red cards = You get another turn!" << endl;
    cout << "♣️ Black cards = lose a point!" << endl;
    cout << "First to 0 points loses!\n" << endl;
    
    setupGame();
    
    // Main game loop
    while (!gameOver) {
        if (currentPlayer == "Player") {
            playerTurn();
        } else {
            opponentTurn();
        }
        
        checkGameOver();
        
        // If super soaker is empty, reload for next round
        if (cardDeck.empty() && !gameOver) {
            cout << "\nCard Deck is out! Reshuffling for next round..." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            setupGame();
        }
    }
    
    // Game over
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║            GAME OVER!                  ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    
    if (playerScore <= 0) {
        cout << "Opponent wins!" << endl;
    } else {
        cout << "You win!" << endl;
    }
    
    return 0;
}

// ============================================================================
// GAME SETUP FUNCTIONS
// ============================================================================

void setupGame() {
    // Clear any existing cartridges
    cardDeck.clear();
    
    // Load the super soaker with random cartridges
    int redCardCount = 2 + rand() % 3;  // 2-4 water cartridges
    int blackCardCount = 2 + rand() % 2;  // 2-3 slime cartridges
    
    loadCardDeck(redCardCount, blackCardCount);
    shuffleCardDeck();
    
    cout << "\nCard deck reshuffled!" << endl;
    displayCardDeck(false);  // Show counts but not order
}

void loadCardDeck(int redCardCount, int blackCardCount) {
    // Add water cartridges
    for (int i = 0; i < redCardCount; i++) {
        cardDeck.push_back('W');
    }
    
    // Add slime cartridges
    for (int i = 0; i < blackCardCount; i++) {
        cardDeck.push_back('S');
    }
}

void shuffleCardDeck() {
    // Shuffle the cartridges so players don't know the order
    random_shuffle(cardDeck.begin(), cardDeck.end());
}

// ============================================================================
// DISPLAY FUNCTIONS
// ============================================================================

void displayGameState() {
    cout << "\n┌─────────────────────────────────────────┐" << endl;
    cout << "│  Player: " << playerScore << " points   Opponent: " << opponentScore << " points  │" << endl;
    cout << "└─────────────────────────────────────────┘" << endl;
}

void displayCardDeck(bool showContents) {
    int redCardCount = 0;
    int blackCardCount = 0;
    
    // Count each type using a range-based for loop
    for (char cartridge : cardDeck) {
        if (cartridge == 'W') redCardCount++;
        else blackCardCount++;
    }
    
    cout << "Card Deck contents: ";
    cout << "♦️ " << redCardCount << " Red, ";
    cout << "♣️ " << blackCardCount << " Black";
    cout << " (" << cardDeck.size() << " total)" << endl;
    
    // For debugging/demonstration - show actual order
    if (showContents) {
        cout << "Actual order: ";
        for (char cartridge : cardDeck) {
            cout << (cartridge == 'W' ? "♦️" : "♣️") << " ";
        }
        cout << endl;
    }
}

// ============================================================================
// CORE GAME MECHANICS
// ============================================================================

char fireShot() {
    // Fire the next cartridge (remove from front of vector)
    // This is why we use a vector - easy to remove from front!
    
    if (cardDeck.empty()) {
        return 'E';  // Empty!
    }
    
    // Get the first cartridge
    char cartridge = cardDeck.front();
    
    // Remove it from the super soaker
    cardDeck.erase(cardDeck.begin());
    
    return cartridge;
}

// ============================================================================
// TURN LOGIC
// ============================================================================

void playerTurn() {
    displayGameState();
    displayCardDeck(false);
    
    cout << "\n>>> YOUR TURN <<<" << endl;
    cout << "Who should draw a card?: [1] Yourself  [2] Opponent" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    // Input validation
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Enter 1 or 2: ";
        cin >> choice;
    }
    
    cout << "\nThe card is... ";
    char result = fireShot();
    
    if (result == 'W') {
        cout << "♦️ Red " << endl;
        if (choice == 1) {
            cout << "You draw a red card! You get another turn!" << endl;
            // Player keeps their turn (currentPlayer stays "Player")
        } else {
            cout << "Opponent draws a red card!" << endl;
            currentPlayer = "Opponent";  // Switch turns
        }
    } else if (result == 'S') {
        cout << "♣️ Black" << endl;
        if (choice == 1) {
            cout << "You draw a black card! -1 point!" << endl;
            playerScore--;
        } else {
            cout << "Opponent draws a black card! -1 point!" << endl;
            opponentScore--;
        }
        currentPlayer = "Opponent";  // Switch turns after slime
    }
}

void opponentTurn() {
    displayGameState();
    displayCardDeck(false);
    
    cout << "\n>>> OPPONENT'S TURN <<<" << endl;
    cout << "Press Enter to see opponent's choice...";
    cin.ignore();
    cin.get();
    
    // Simple AI: 50/50 chance to fire at self or player
    int choice = 1 + rand() % 2;
    
    if (choice == 1) {
        cout << "Opponent draws a card for themself" << endl;
    } else {
        cout << "Opponent makes you draw a card" << endl;
    }
    
    cout << "\nThe card is... ";
    char result = fireShot();
    
    if (result == 'W') {
        cout << "♦️ Red" << endl;
        if (choice == 1) {
            cout << "Opponent gets another turn!" << endl;
            // Opponent keeps their turn
        } else {
            cout << "You get a turn!" << endl;
            currentPlayer = "Player";  // Switch turns
        }
    } else if (result == 'S') {
        cout << "♣️ Black" << endl;
        if (choice == 1) {
            cout << "Opponent draws a black card! -1 point!" << endl;
            opponentScore--;
        } else {
            cout << "You draw a black card! -1 point!" << endl;
            playerScore--;
        }
        currentPlayer = "Player";  // Switch turns after slime
    }
}

void checkGameOver() {
    if (playerScore <= 0 || opponentScore <= 0) {
        gameOver = true;
    }
}