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

// Insert
void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;  //this is not needed because temp->next is initialized to null in the constructor but still I put it 
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int data, int position) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* prev = head;
    int cnt = 1;

    while (cnt < position - 1) {
        prev = prev->next;
        cnt++;
    }

    if (prev->next == NULL) {
        insertAtTail(tail, data);
        return;
    }
    Node* temp = new Node(data);
    temp->next = prev->next;
    prev->next = temp;

}

// Delete by position
void deleteAtPostion(Node*& head, Node*& tail, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* cur = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        if (cur->next == NULL) {
            tail = prev;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

void deleteByValue(Node*& head, Node*& tail, int key) {
    Node* temp = head;
    if (temp->data == key) {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* cur = head;
        Node* prev = NULL;
        while (cur->data != key && cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        if (cur->data == key) {
            if (cur->next == NULL) {
                tail = prev;
            }
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
        }
        else {
            cout << "Value not in List." << endl;
        }
    }
}

// Print Linked List
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// get middle node
Node* getMiddle(Node*& head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast == NULL)
            break;
        slow = slow->next;
    }
    return slow;
}

// revese list
void reverseList(Node*& head) {
    Node* prev = NULL, * cur = head, * temp;
    while (cur != NULL) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}

// recursive reverse
void reverseListRecursive1(Node*& head, Node* cur, Node* prev) {
    if (cur == NULL) {
        head = prev;
        return;
    }
    Node* forward = cur->next;
    reverseListRecursive1(head, forward, cur);
    cur->next = prev;
}
// preferred ⬇️ because smallest
Node* reverseListRecursive2(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* chotaListKaHead = reverseListRecursive2(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaListKaHead;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* node1 = new Node(34);
    // cout << node1->data << " " << node1->next << endl;
    head = tail = node1;

    //Insert
    insertAtHead(head, 53);
    // printLL(head);

    insertAtTail(tail, 10);
    // printLL(head);

    insertAtPosition(head, tail, 70, 2);
    cout << "Linked list is: ";
    printLL(head);

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // Delete
    // deleteAtPostion(head, tail, 3);
    // printLL(head);

    // deleteByValue(head, tail, 70);
    // printLL(head);
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // finding middle node
    Node* middle = getMiddle(head);
    cout << "Middle Node data: " << middle->data << endl;

    // reversing linked list
    // reverseList(head);   // iterative
    // printLL(head);
    // Node* prev = NULL;
    // Node* cur = head;
    // reverseListRecursive1(head, cur, prev);   // recursive 1
    // printLL(head);
    Node* temp = reverseListRecursive2(head);   // recursive 2
    printLL(temp);

    return 0;
}