/*
CSC 134
M3LAB2
Travis Cayton
9/29/2025
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void letter_grader();
void combat();
int roll();

int main(){
    //letter_grader();
    combat();
    return 0;
}


void combat(){
    int attack_roll, attack_bonus, enemy_armor;
    
    cout << "You are fighting a goblin." << endl;
    /*
    cout << "Enter your roll: " << endl;
    cin >> attack_roll;
    cout << "Enter attack bonus" << endl;
    cin >> attack_bonus;
    cout << "Ememy armor class: " << endl;
    cin >> enemy_armor;
    */
    srand(time(0));
    attack_roll = roll();
    attack_bonus = roll();
    enemy_armor = roll();
    cout << "Roll: " << attack_roll << " + " << attack_bonus << " = " << attack_roll+attack_bonus << endl;
    cout << endl;
    cout << "Enemy Armor: " << enemy_armor << endl;
    cout << endl;
    if (attack_roll + attack_bonus >= enemy_armor){
        cout << "Hit!" << endl;
    }
    else {
        cout << "Miss!" << endl;
    }

    cout << "Again? (y/n): ";
    string again;
    cin >> again;
    if (again == "y") {
        combat();
    }
}

void letter_grader(){
    double num_grade;
    string letter_grade;
    cout << "Enter a number grade 0-100: ";
    cin >> num_grade;
    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;
    letter_grade = "A";

    if (num_grade >= A_GRADE) {
        letter_grade = "A";
    }
    else if (num_grade >= B_GRADE) {
        letter_grade = "B";
    }
    else if (num_grade >= C_GRADE) {
        letter_grade = "C";
    }
    else if (num_grade >= D_GRADE) {
        letter_grade = "D";
    }
    else {
        letter_grade = "F";
    }

    cout << "A number of " << num_grade << " is a(n) " << letter_grade;
    cout << endl;
    cout << endl;
}

int roll() {
    const int SIDES = 20;
    int my_roll;
    my_roll = (rand() % SIDES) + 1;
    return my_roll;
}