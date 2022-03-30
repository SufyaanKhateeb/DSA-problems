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
        int value = this->data;
        cout << "Data being deleted is: " << value << endl;
    }
};

// inserting after an element, no concept of start and end as it is a circular list but still maintaining a tail pointer for inserting purpose
void insertNode(Node*& tail, int before, int data) {
    // empty
    if (tail == NULL) {
        Node* temp = new Node(data);
        tail = temp;
        tail->next = temp;
    }
    // not empty
    else {
        Node* cur = tail;
        do {
            cur = cur->next;
        } while (cur->data != before && cur != tail);
        if (cur->data == before) {
            Node* temp = new Node(data);
            temp->next = cur->next;
            cur->next = temp;
        }
        else {
            cout << "No position with that value!!!" << endl;
        }
    }
}

// Delete by value because no concept of positioning in a circular list
void deleteByValue(Node*& tail, int key) {
    // empty case
    if (tail == NULL) {
        cout << "The list is empty!!!" << endl;
    }
    // not empty 
    else {
        Node* prevNode = tail;
        Node* cur = tail;
        do {
            prevNode = cur;
            cur = cur->next;
        } while (cur->data != key && cur != tail);
        if (cur->data == key) {
            // if only one element in list and that has to be deleted
            if (cur == prevNode) {
                tail = NULL;
            }
            // more than one element in list
            else {
                if (cur == tail) {
                    tail = prevNode;
                }
            }
            prevNode->next = cur->next;
            cur->next = NULL;
            delete cur;
        }
        else {
            cout << "No element found with value " << key << endl;
        }
    }
}

// Print Linked List
void printLL(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!!!" << endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    //Insert
    // parameters are tail pointer, before element value (the element after which the data will be inserted), data to be inserted
    insertNode(tail, 3, 50); // you can give any before position When list is empty
    insertNode(tail, 50, 40);
    insertNode(tail, 50, 45);
    insertNode(tail, 40, 90);
    insertNode(tail, 90, 100);
    printLL(tail);

    //delete
    deleteByValue(tail, 90);
    deleteByValue(tail, 80);
    printLL(tail);

    return 0;
}