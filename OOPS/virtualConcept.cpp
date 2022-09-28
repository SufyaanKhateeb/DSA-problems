#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Emp {
public:
    Emp() {
        cout << "Emp constructor" << endl;
    }
    virtual void RaiseSalary() {
        cout << "RaiseSalary by 20" << endl;
    }
    static void promote() {
        cout << "Promoted" << endl;
    }
    virtual ~Emp() {
        cout << "Emp Destructor" << endl;
    }
};

class Engineer : public Emp {
public:
    Engineer() {
        cout << "Engineer constructor" << endl;
    }
    void RaiseSalary() {
        cout << "RaiseSalary by 40" << endl;
    }
    static void promote() {
        cout << "Engineer promoted" << endl;
    }
    ~Engineer() {
        cout << "Engineer destructor" << endl;
    }
};

int main() {
    Emp* e = new Engineer();
    // Engineer* e = new Engineer();
    e->RaiseSalary();
    Engineer::promote();
    delete e;



    return 0;
}