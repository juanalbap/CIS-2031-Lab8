//I edited the fight function so a fight would not take place if either of the monsters or  both of them were dead. Also, if a monster wins in one round, previously, the word //"rounds!" was output to the console. Now, if round == 1, "round!" is output to the console. Also, a winner is announced at the end.


#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

//Create a struct type named Monster
struct Monster {
    string name;
    int attack;
    int hitpoints;
};

//Create an array of five monsters
Monster monsters[5] = {
    Monster{"Godzilla", 5, 62}, //These values are in the same order as in the struct!
    Monster{"Mothra", 10, 37},
    Monster{"Babadook", 3, 101},
    Monster{"Frankenstein", 2, 23},
    Monster{"ProfessorBill", 1, 3}
};

// This function takes a monster and prints it's name and hitpoints
// to the console, and prints "DEAD" if it has negative HP
void printMonsterStats(Monster m){
    // ❓❓ Lab Question 1 ❓❓

    cout << m.name << ": " << m.hitpoints << " ";

    if (m.hitpoints <= 0) {
        cout << "DEAD!";
    }


}

//Fight two monsters!
void fight(Monster &m1, Monster &m2){
    cout << m1.name << " Fights " << m2.name << "!" << endl;
    int round = 0;
    while ( m1.hitpoints > 0 && m2.hitpoints > 0 ){
        round++;
        m1.hitpoints = m1.hitpoints - m2.attack;
        m2.hitpoints = m2.hitpoints - m1.attack;
    }
    if ( m1.hitpoints > 0 && m2.hitpoints <= 0 ){
        if (round == 0){
            cout << "No fight! " << m2.name << " is already dead!" << endl;
        } else if (round == 1) {
            cout << m1.name << " wins in " << round << " round!" << endl;
        } else {
            cout << m1.name << " wins in " << round << " rounds!" << endl;
        }
        
    } else if ( m1.hitpoints <= 0 && m2.hitpoints > 0 ){
        if (round == 0){
            cout << "No fight! " << m1.name << " is already dead!" << endl;
        } else if (round == 1){
            cout << m2.name << " wins in " << round << " round!" << endl;
        } else {
            cout << m2.name << " wins in " << round << " rounds!" << endl;
        }
    } else {
        if (round == 0){
            cout << "No fight! Both " << m2.name << " and " << m1.name << " are already dead!" << endl;
        } else {
        cout << "It's a tie in " << round << " rounds!" << endl;
    }
  }
}

int main(){
//Battle Royale

for (int i = 0; i < 5; i++) {
    for (int x = 0; x < 5; x++) {
        if (i != x) {
        fight(monsters[i], monsters[x]);
        }
    }
}

cout << endl << "Final Results: " << endl;
printMonsterStats(monsters[0]);
if (monsters[0].hitpoints > 0) {
    cout << " Winner!";
}
cout << endl;

printMonsterStats(monsters[1]);
if (monsters[1].hitpoints > 0) {
    cout << " Winner!";
}
cout << endl;

printMonsterStats(monsters[2]);
if (monsters[2].hitpoints > 0) {
    cout << " Winner!";
}
cout << endl;

printMonsterStats(monsters[3]);
if (monsters[3].hitpoints > 0) {
    cout << " Winner!";
}
cout << endl;

printMonsterStats(monsters[4]);
if (monsters[4].hitpoints > 0) {
    cout << " Winner!";
}
cout << endl;

   return 0; 
}