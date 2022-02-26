// A class’s friend function is defined outside that class’s scope, but it has the right to access all
// private and protected members of the class. Even though the prototypes for friend functions appear 
// in the class definition, friends are not member functions.

#include <iostream>
using namespace std;
class Rectangle {
private:
    int length;
public:
    Rectangle() {
        length = 10;
    }
    friend int printLength(Rectangle); //friend function    
};
int printLength(Rectangle b) {
    b.length += 10;
    return b.length;
}
int main() {
    Rectangle b;
    cout << "Length of Rectangle: " << printLength(b) << endl;
    return 0;
}