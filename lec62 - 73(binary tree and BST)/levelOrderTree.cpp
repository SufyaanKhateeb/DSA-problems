#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class TreeAncestor {
public:
    Node* root = NULL;
    void insert(int data, queue<Node*>& q) {
        Node* newNode = new Node(data);
        if (root == NULL)
            root = newNode;
        else if (q.front()->left == NULL) {
            q.front()->left = newNode;
        }
        else {
            q.front()->right = newNode;
            q.pop();
        }
        q.push(newNode);
    }
    TreeAncestor(int n, vector<int>& parent) {
        queue<Node*> q;
        for (int i = 0; i < n; i++) {
            insert(parent[i], q);
        }
    }
    Node* solve(Node* myroot, int& k, int node) {
        if (myroot == NULL)
            return NULL;
        if (myroot->data == node)
            return root;
        Node* leftans = solve(myroot->left, k, node);
        Node* rightans = solve(myroot->right, k, node);
        if (leftans != NULL && rightans == NULL) {
            k--;
            if (k == 0) {
                return myroot;
            }
            return leftans;
        }
        if (leftans == NULL && rightans != NULL) {
            k--;
            if (k == 0)
                return myroot;
            return rightans;
        }
        return NULL;
    }
    int getKthAncestor(int node, int k) {
        Node* ans = solve(root, k, node);
        if (ans == NULL || ans->data == node)
            return -1;
        else
            return ans->data;
    }
};

int main() {
    vector<int> parent = { -1,0,0,1,1,2,2 };
    TreeAncestor* mytree = new TreeAncestor(7, parent);
    cout << mytree->getKthAncestor(3,1) << endl;

    return 0;
}