// Compile time polymorphism
// two type: fuction overloading and operator overriding

//fuctino overloading
#include <iostream>
using namespace std;
// Function with two integer parameters
int add(int num1, int num2) {
    return num1 + num2;
}
// Function with two double parameters
double add(double num1, double num2) {
    return num1 + num2;
}
int main(void) {
    cout << add(10, 20) << endl;
    cout << add(10.4, 20.5);
    return 0;
}

//operator overriding
#include<iostream>
using namespace std;
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    // This is automatically called when '+' is used with 
    // between two Complex objects 
    Complex operator + (Complex
        const& b) {
        Complex a;
        a.real = real + b.real;
        a.imag = imag + b.imag;
        return a;
    }
    void print() {
        cout << real << " + i" << imag << endl;
    }
};
int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+" 
    c3.print();
}