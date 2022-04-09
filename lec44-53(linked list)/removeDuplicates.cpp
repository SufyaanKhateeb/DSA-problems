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

    //removing duplis
    void removeDuplicates() {
        if (head == NULL)
            return;
        Node* cur = head;
        while (cur->next != NULL && cur != NULL) {
            Node* temp = cur->next;
            Node* prev = cur;
            while (temp != NULL) {
                if (cur->data == temp->data) {
                    prev->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    temp = prev->next;
                }
                else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            cur = cur->next;
        }
    }

    ~LinkedList() {
        this->clear();
    }
};

int main() {
    LinkedList mylist = *(new LinkedList());
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(2);
    mylist.push_back(2);
    mylist.push_back(7);
    mylist.push_back(7);
    mylist.printLL();
    mylist.removeDuplicates();
    mylist.printLL();

}