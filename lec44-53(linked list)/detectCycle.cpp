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
        cout << "Node being deleted has data: " << this->data << endl;
    }
};

bool detectLoop(Node* head) {
    if (head == NULL)
        return true;
    map<Node*, bool> visited;
    Node* temp = head;
    while (temp != NULL) {
        if (visited[temp]) {
            cout << "Loop starts at element: " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool floydDetectLoop(Node* head) {
    if (head == NULL)
        return true;
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node* getStartingNode_Floyd(Node* head) {
    if (head == NULL || head == head->next)
        return head;
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeLoop(Node* head) {
    if (head == NULL)
        return;
    Node* start = getStartingNode_Floyd(head);
    Node* temp = start;
    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = NULL;
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

Node* insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;  //this is not needed because temp->next is initialized to null in the constructor but still I put it 
    tail = temp;
    return temp;
}

int main() {
    // creating a LL with a loop
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail, 2);
    Node* temp = insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    tail->next = temp;

    // checking for loop
    bool result = detectLoop(head);
    cout << "Loop present: " << result << endl;

    // floyd's cycle detection algo
    cout << "Loop present: " << floydDetectLoop(head);
    cout << "Loop starts at: " << getStartingNode_Floyd(head)->data << endl;

    // removing loop using the starting node of loop
    removeLoop(head);
    printLL(head);

    return 0;
}