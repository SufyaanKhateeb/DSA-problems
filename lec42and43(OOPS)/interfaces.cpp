// interfaces
// abstract classes connot have objects
// if there is virtual function in the parent class then that has to implemented otherwise the child class becomes abstract and no objs of that class can be created
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Animal {
public:
    //Pure Virtual Function
    virtual void sound() = 0;
    //Normal member Function
    void sleeping() {
        cout << "Sleeping";
    }
};
// NOTE : any class containing virtual functions becomes an abstract class, therefore we cannot create an object of this class

class Dog : public Animal {
public:
    void sound() {                  // try commenting this function, you will see that you cannot create an obj of this class below
        cout << "Woof" << endl;
    }
};
int main() {
    Dog obj;
    obj.sound();
    obj.sleeping();
    return 0;
}