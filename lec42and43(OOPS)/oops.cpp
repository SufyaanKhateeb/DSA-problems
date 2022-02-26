#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Hero {
private:    //access modifier
    int health;
public:     //access modifier
    char* name;
    char level;

    //simple constructor, commenting this while there is an oveloaded constructor will give an error
    Hero() {
        cout << "constructor called!!" << endl;
        name = new char[100];
    }

    //parameterised constructor
    Hero(char level, int health) {
        this->level = level;      //use of this keyword
        this->health = health;
        name = new char[100];
    }

    // making our own copying constructor instead of the default one
    Hero(Hero& temp) {
        char* tempname = new char[strlen(temp.name) + 1];
        strcpy(tempname, temp.name);
        cout << "My copying constructor called." << endl;
        this->level = temp.level;
        this->health = temp.health;
        this->name = tempname;
    }

    void print() {
        cout << "[ Name: " << this->name << " ,";
        cout << "Level: " << this->level << " ,";
        cout << "Health: " << this->health << " ]" << endl;
    }
    //getter and setter functions
    void setHealth(int h) {
        health = h;
    }
    void setLevel(char l) {
        level = l;
    }
    int getHealth() {
        return health;
    }
    int getLevel() {
        return level;
    }
    void setName(char name[]) {
        strcpy(this->name, name);
    }

    //destructor
    ~Hero() {
        cout << "Destructor called." << endl;
    }
};

int main() {
    // Hero myhero;    //static allocation of class Hero object
    // Hero* dhero = new Hero();   //dynamic allocation

    // myhero.setHealth(10);
    // myhero.setLevel(100);

    // // cout << myhero.level << endl;
    // // cout << myhero.getHealth() << endl;

    // //accessing the dynamic obj
    // (*dhero).level = 100;   //one method
    // dhero->setHealth(50);   //another method (preffered by me)

    // // cout << dhero->getLevel() << endl;
    // // cout << dhero->getHealth() << endl;

    // myhero.print();
    // //copying an object
    // Hero yourhero(myhero);      //this uses a copying constructor which is automatically created if there is no constructor made by us
    // yourhero.print();

    Hero hero1('A', 100);
    char hero1name[] = "khateeb";
    hero1.setName(hero1name);

    Hero hero2 = hero1;
    cout << "Before change: " << endl;
    hero1.print();
    hero2.print();

    hero1.name[0] = 'B';
    cout << "After change: " << endl;   //comment the copying constructor we created to see the default behaviour
    hero1.print();
    hero2.print();

    return 0;
}