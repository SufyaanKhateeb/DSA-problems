#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Vector {
private:
    int* arr;
    int Size;
    int limit;
public:
    Vector(int s) : arr(new int[s]), Size(0), limit(s) {}
    Vector(const Vector& rhs) {
        arr = new int[rhs.limit];
        Size = rhs.Size;
        limit = rhs.limit;
        for (int i = 0; i < Size; i++) arr[i] = rhs.arr[i];
    }
    Vector(Vector&& rhs) {
        arr = rhs.arr;
        Size = rhs.Size;
        limit = rhs.limit;
        rhs.arr = nullptr;
        rhs.Size = 0;
        rhs.limit = 0;
    }
    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            int* temp = this->arr;
            Size = rhs.Size;
            limit = rhs.limit;
            arr = new int[limit];
            for (int i = 0; i < Size; i++) arr[i] = rhs.arr[i];
            delete[] temp;
        }
        return *this;
    }
    Vector& operator=(Vector&& rhs) {
        arr = rhs.arr;
        Size = rhs.Size;
        limit = rhs.limit;
        rhs.arr = nullptr;
        rhs.Size = 0;
        rhs.limit = 0;
        return *this;
    }
    void push(int ele) {
        if (Size == limit) return;
        arr[Size] = ele;
        Size++;
    }
    void pop() {
        if (!Size) return;
        arr[Size - 1] = 0;
        Size--;
    }
    int size() {
        return Size;
    }
    friend ostream& operator<<(ostream& out, Vector& vec);
    ~Vector() {
        if(arr) {
            delete[] arr;
            Size = 0;
            limit = 0;
        }
    }
};

ostream& operator<<(ostream& out, Vector& vec) {
    cout << "[";
    for (int i = 0; i < vec.Size; i++) {
        if(i == vec.Size - 1) {
            cout << vec.arr[i];
            break;
        }
        cout << vec.arr[i] << ",";
    }
    cout << "]";
    return out;
}

int main() {
    Vector vec1(5);
    cout << vec1 << endl;
    vec1.push(1);
    vec1.push(2);

    Vector vec2 = vec1; //same as copy constructor i.e. Vector vec2(vec1);
    cout << vec1 << endl;
    cout << vec2 << endl;

    Vector vec3(6);
    vec3.push(6);
    vec3.push(5);
    vec3.push(4);
    vec2 = vec3;
    cout << vec1 << " Size: " << vec1.size() << endl;
    cout << vec2 << " Size: " << vec2.size() << endl;
    cout << vec3 << " Size: " << vec3.size() << endl;

    Vector vec4 = vec1;
    cout << vec4 << " Size: " << vec4.size() << endl;    
    cout << vec1 << " Size: " << vec1.size() << endl;    

    Vector vec5 = std::move(vec3);
    cout << vec5 << " Size: " << vec5.size() << endl;
    cout << vec3 << " Size: " << vec3.size() << endl;

    vec2 = std::move(vec1);
    cout << vec2 << " Size: " << vec2.size() << endl;
    cout << vec1 << " Size: " << vec1.size() << endl;
    
    return 0;
}