#include<iostream>
using namespace std;
// Parent class
class Animal {
public:
    void eat() {
        cout << "eating" << endl;
    }
};
// Child class
class Dog : public Animal {
public:
    void bark() {
        cout << "barking" << endl;
    }
};
// child class2
class Cat : public Animal {
public:
    void meow() {
        cout << "meowing" << endl;
    }
};

// multilevel
class BabyDog : public Dog {
public:
    void weep() {
        cout << "weeping" << endl;
    }
};

// multiple
// Inherited class
class BabyDog : public Animal, public Dog {
public:
    void weep() {
        cout << "weeping";
    }
};



int main() {
    // single inheritance : In single inheritance, one class can extend the functionality of another class. In single inheritance, there is only one parent class and one child class.
    // Dog obj1;
    // obj1.eat();
    // obj1.bark();

    // multilevel inheritance : When a class inherits from a derived class, and the derived class becomes the base class of the new class, it is called multilevel inheritance. In multilevel inheritance, there is more than one level.
    // BabyDog obj2;
    // obj2.eat();
    // obj2.bark();
    // obj2.weep();

    // multiple : In multiple inheritance, a class can inherit more than one class. This means that in this type of inheritance, a single child class can have multiple parent classes.
    // BabyDog obj3;
    // obj3.eat();
    // obj3.bark();
    // obj3.weep();

    // hierarchical : In hierarchical inheritance, one class serves as a base class for more than one derived class.
    // animal is inherited by both dog and cat
    Cat obj4;
    obj4.eat();
    obj4.meow();

    //hybrid : combination of more than one type of inheritance
}

