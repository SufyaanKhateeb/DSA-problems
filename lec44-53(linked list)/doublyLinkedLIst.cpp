#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node() {
        int value = this->data;
        cout << "Data being deleted is: " << value << endl;
    }
};

// print Linked List
void printLL(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getLength(Node*& head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << "Length is: " << count << endl;
}

void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int data, int position) {
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }
    Node* prevNode = head;
    int cnt = 1;

    while (cnt < position - 1) {
        prevNode = prevNode->next;
        cnt++;
    }

    if (prevNode->next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }
    Node* temp = new Node(data);
    temp->next = prevNode->next;
    temp->prev = prevNode;
    prevNode->next->prev = temp;
    prevNode->next = temp;
}

// Delete by position
void deleteAtPostion(Node*& head, Node*& tail, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (temp->next == NULL) {
            tail = NULL;
            head = NULL;
            delete temp;
            return;
        }
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* cur = head;
        int cnt = 1;
        while (cnt < position) {
            cur = cur->next;
            cnt++;
        }
        if (cur->next == NULL) {
            tail = cur->prev;
            cur->prev->next = NULL;
            cur->prev = NULL;
            cur->next = NULL;
            delete cur;
            return;
        }
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        cur->next = NULL;
        cur->prev = NULL;

        delete cur;
    }
}

void deleteByValue(Node*& head, Node*& tail, int key) {
    Node* temp = head;
    if (temp->data == key) {
        head = head->next;
        if (temp->next == NULL) {
            tail = NULL;
            head = NULL;
            delete temp;
            return;
        }
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* cur = head;
        while (cur->data != key && cur->next != NULL) {
            cur = cur->next;
        }
        if (cur->data == key) {
            if (cur->next == NULL) {
                tail = cur->prev;
                cur->prev->next = cur->next;
                cur->prev = NULL;
                cur->next = NULL;
                delete cur;
                return;
            }
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            cur->next = NULL;
            cur->prev = NULL;
            delete cur;
        }
        else {
            cout << "Value not in List." << endl;
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    // Node* node1 = new Node(55);
    // head = node1;
    // tail = node1;

    printLL(head);
    // getLength(head);

    insertAtHead(head, tail, 100);
    printLL(head);
    // cout << "After insert at head:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    insertAtTail(head, tail, 10);
    printLL(head);
    // cout << "After insert at tail:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    insertAtPosition(head, tail, 66, 2);
    printLL(head);
    // cout << "After insert at tail:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    insertAtPosition(head, tail, 2, 4);
    printLL(head);
    // cout << "After insert at tail:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    deleteAtPostion(head, tail, 2);
    printLL(head);
    cout << "After insert at tail:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    deleteByValue(head, tail, 100);
    printLL(head);
    cout << "After insert at tail:\n\t Head: " << head->data << "\n\t Tail: " << tail->data << endl;

    return 0;
}