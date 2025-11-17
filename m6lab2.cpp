/*
CSC 134
m6lab2
Travis Cayton
11/17/2025
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    TOWN_CENTER = 0,
    MERCHANT_SHOP = 1,
    FOREST = 2,
    ALLEY_WAY = 3,
    DRAGON_LAIR = 4,
    NUM_ROOMS = 5
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Town Center",
        "Merchant Shop",
        "Forest",
        "Dark Alley Way",
        "Dragon's Lair"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "There is a fountain with multiple pathways on each side.",
        "The Merchant isn't selling anything because someone already bought all of his wares.",
        "Trees suround a long dirt pathway.",
        "A dark alleyway that leads nowhere.",
        "The dragon informs you that combat wasn't implemented in this game yet."
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    // Entrance Hall connections
    connections[TOWN_CENTER][NORTH] = MERCHANT_SHOP;    // Entrance Hall -> North -> MERCHANT_SHOP
    connections[TOWN_CENTER][EAST] = FOREST;     // Entrance Hall -> East -> FOREST
    connections[TOWN_CENTER][SOUTH] = -1;         // No connection south
    connections[TOWN_CENTER][WEST] = ALLEY_WAY;      // Entrance Hall -> West -> ALLEY_WAY
    
    // MERCHANT_SHOP connections
    connections[MERCHANT_SHOP][NORTH] = -1;               // No connection north
    connections[MERCHANT_SHOP][EAST] = -1;                // No connection east
    connections[MERCHANT_SHOP][SOUTH] = TOWN_CENTER;    // MERCHANT_SHOP -> South -> Entrance Hall
    connections[MERCHANT_SHOP][WEST] = -1;                // No connection west
    
    // FOREST connections
    connections[FOREST][NORTH] = -1;               // No connection north
    connections[FOREST][EAST] = -1;                // No connection east
    connections[FOREST][SOUTH] = DRAGON_LAIR;         // FOREST -> South -> DRAGON_LAIR
    connections[FOREST][WEST] = TOWN_CENTER;     // FOREST -> West -> Entrance Hall
    
    // ALLEY_WAY connections
    connections[ALLEY_WAY][NORTH] = -1;                // No connection north
    connections[ALLEY_WAY][EAST] = TOWN_CENTER;      // ALLEY_WAY -> East -> Entrance Hall
    connections[ALLEY_WAY][SOUTH] = -1;                // No connection south
    connections[ALLEY_WAY][WEST] = -1;                 // No connection west
    
    // DRAGON_LAIR connections
    connections[DRAGON_LAIR][NORTH] = FOREST;         // DRAGON_LAIR -> North -> FOREST
    connections[DRAGON_LAIR][EAST] = -1;               // No connection east
    connections[DRAGON_LAIR][SOUTH] = -1;              // No connection south
    connections[DRAGON_LAIR][WEST] = -1;               // No connection west
    
    // Game state
    int currentRoom = TOWN_CENTER; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}