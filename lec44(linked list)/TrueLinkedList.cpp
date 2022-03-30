// Some common Functions that can be implemented on a Linked List
// size() - returns number of data elements in list
// empty() - bool returns true if empty
// value_at(index) - returns the value of the nth item(starting at 0 for first)
// push_front(value) - adds an item to the front of the list
// pop_front() - remove front item and return its value
// push_back(value) - adds an item at the end
// pop_back() - removes end item and returns its value
// front() - get value of front item
// back() - get value of end item
// insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
// erase(index) - removes node at given index
// clear() - removes all the nodes in the list
// value_n_from_end(n) - returns the value of the node at nth position from the end of the list
// reverse() - reverses the list
// remove_value(value) - removes the first item in the list with this value

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        // cout << "Deleting node with data: " << this->data << endl;
    }
};

class LinkedList {
private:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
public:
    LinkedList(int data) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        size++;
    }

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int data) {
        Node* temp = new Node(data);
        if (head == NULL)
            tail = temp;
        temp->next = head;
        head = temp;
        size++;
    }

    void push_back(int data) {
        Node* temp = new Node(data);
        if (size == 0) {
            head = tail = temp;
            size++;
        }
        else {
            tail->next = temp;
            tail = temp;
            size++;
        }
    }

    void insert(int index, int data) {
        if (index > size || index < 0) {
            cout << "Index not available or invalid index." << endl;
            return;
        }
        if (index == 0) {
            push_front(data);
            return;
        }
        else if (index == size) {
            push_back(data);
            return;
        }
        else {
            Node* temp = head;
            int cnt = index - 1;
            while (cnt--) {
                temp = temp->next;
            }
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
            return;
        }
    }

    void pop_front() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        else {
            Node* temp = head;
            if (temp->next == NULL)
                tail = NULL;
            head = temp->next;
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }
    }

    void pop_back() {
        if (size == 0) {
            cout << "List is empty." << endl;
            return;
        }
        else {
            Node* temp = head;
            if (head == tail) {
                head = tail = NULL;
                temp->next = NULL;
                delete temp;
                size--;
                return;
            }
            else {
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = NULL;
                tail->next = NULL;
                delete tail;
                tail = temp;
                size--;
                return;
            }
        }
    }

    void erase(int index) {
        if (index >= size || index < 0) {
            cout << "Index not available or invalid index." << endl;
            return;
        }
        if (index == 0) {
            pop_front();
            return;
        }
        else if (index == size - 1) {
            pop_back();
            return;
        }
        else {
            Node* temp = head;
            int cnt = index - 1;
            while (cnt--) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delNode->next = NULL;
            delete delNode;
            size--;
            return;
        }
    }

    void remove_value(int data) {
        if (size == 0)
            return;
        if (head->data == data) {
            pop_front();
            return;
        }
        else if (tail->data == data) {
            pop_back();
            return;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->data != data) {
                temp = temp->next;
            }
            if (temp->next == NULL)
                return;
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delNode->next = NULL;
            delete delNode;
            size--;
        }
    }

    void reverse() {
        if (size == 0)
            return;
        Node* prev = NULL, * cur = head, * temp;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        tail = head;
        head = prev;
    }

    int value_at(int index) {
        if (index >= size || index < 0) {
            cout << "Index not available or invalid index." << endl;
            return -3000;
        }
        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }
        return temp->data;

    }

    int front() {
        if (size == 0)
            return -3000;
        return head->data;
    }

    int back() {
        if (size == 0)
            return -3000;
        return tail->data;
    }

    void printLL() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "LL : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void clear() {
        if (size == 0) return;
        Node* temp = head;
        Node* cur = head;
        while (temp != NULL) {
            temp = temp->next;
            cur->next = NULL;
            delete cur;
            cur = temp;
            size--;
        }
        head = NULL;
        cout << "List cleared" << endl;
    }

    ~LinkedList() {
        this->clear();
    }
};

int main() {
    LinkedList mylist = *(new LinkedList()); //dereferencing beacuse I wanted to use . operator😁
    // LinkedList* mylist = new LinkedList(); // alternatively this can be done
    // mylist->push_front(40);  // and use this to access functions

    // Insert operations
        // push_front(value) - adds an item to the front of the list
        // push_back(value) - adds an item at the end
        // insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index

    mylist.push_front(50);
    mylist.push_front(40);
    mylist.push_front(30);
    mylist.push_front(20);
    mylist.push_back(60);
    mylist.push_back(70);
    mylist.push_back(80);
    mylist.push_back(90);
    mylist.insert(8, 100);
    mylist.printLL();


    // Delete operations
        // pop_front() - remove front item and return its value
        // pop_back() - removes end item and returns its value
        // erase(index) - removes node at given index
        // remove_value(value) - removes the first item in the list with this value

    mylist.pop_front();
    mylist.pop_back();
    mylist.erase(2);
    mylist.remove_value(40);
    mylist.printLL();


    // Access operatoins
        // front() - get value of front item
        // back() - get value of end item
        // value_at(index) - returns the value of the nth item(starting at 0 for first)
        // value_n_from_end(n) - returns the value of the node at nth position from the end of the list
        // printLL() - prints the linked list

    cout << "Element at front position: " << mylist.front() << endl;
    cout << "Element at back position: " << mylist.back() << endl;
    cout << "Element at index 3: " << mylist.value_at(3) << endl;
    mylist.printLL();


    // reverse() - reverses the list
    // getSize() - returns number of data elements in list
    // isEmpty() - bool returns true if empty
    // clear() - removes all the nodes in the list

    mylist.reverse();
    cout << "List after reversing: " << endl;
    mylist.printLL();
    cout << "Size of list: " << mylist.getSize() << endl;
    cout << "Is the list empty: " << mylist.isEmpty() << endl;
    mylist.clear();
    mylist.printLL();

    // delete mylist;  // use this when using pointer to access list

    return 0;
}