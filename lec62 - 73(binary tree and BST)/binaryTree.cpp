#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data (-1 if end): " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    root = new node(data);
    cout << "Left Node of " << data << ", ";
    root->left = buildTree(root->left);
    cout << "Right Node of " << data << ", ";
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    if (root != NULL) {
        q.push(root);
        q.push(NULL); // spacer for printing newline when one level completes
    }
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(node* root) {
    queue<node*> q;
    stack<node*> s;
    if (root != NULL) {
        q.push(root);
        q.push(NULL); // spacer for printing newline when one level completes
    }
    while (!q.empty()) {
        node* temp = q.front();
        s.push(temp);
        q.pop();
        if (temp == NULL) {
            // cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            // cout << temp->data << " ";
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    while (!s.empty()) {
        node* temp = s.top();
        s.pop();
        if (temp == NULL)
            cout << endl;
        else
            cout << temp->data << " ";
    }
}

void inorder(node*& root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node*& root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*& root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void iterativeInorder(node*& root) {
    stack<node*> st;
    node* cur = root;
    while (cur != NULL || !st.empty()) {
        while (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        // now cur is NULL
        cur = st.top();
        st.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}

void iterativePreorder(node*& root) {
    // stack<node*> st;
    // if(root == NULL)
    //     return;
    // st.push(root);
    // while(!st.empty()) {
    //     node* cur = st.top();
    //     cout << cur->data << " ";
    //     st.pop();
    //     if(cur->right)
    //         st.push(cur->right);
    //     if(cur->left)
    //         st.push(cur->left);
    // }
    stack<node*> st;
    node* cur = root;
    if (cur == NULL)
        return;
    while (!st.empty() || cur != NULL) {
        while (cur != NULL) {
            cout << cur->data << " ";
            if (cur->right)
                st.push(cur->right);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            st.pop();
        }
    }
}

void iterativePostorder(node*& root) {
    stack<node*> st;
    node* cur = root;
    do {
        while (cur != NULL) {
            st.push(cur);
            st.push(cur);
            cur = cur->left;
        }
        // if the above while loop didnot excecute even once
        if (st.empty())
            return;
        // now cur is NULL
        cur = st.top();
        st.pop();
        if (!st.empty() && st.top() == cur) {
            cur = cur->right;
        }
        else {
            cout << cur->data << " ";
            cur = NULL;
        }
    } while (!st.empty());
}

void morrisTraversalInorder(node* root) {
    node* current = root;
    while (current != NULL) {
        if (!current->left) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            node* pred = current;
            pred = pred->left;
            while (pred->right && pred->right != current)
                pred = pred->right;

            if (pred->right == NULL) {
                pred->right = current;
                current = current->left;
            }
            else {
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void morrisTraversalPreorder(node* root) {
    node* current = root;
    while (current != NULL) {
        if (!current->left) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            node* pred = current;
            pred = pred->left;
            while (pred->right && pred->right != current)
                pred = pred->right;

            if (pred->right == NULL) {
                cout << current->data << " ";
                pred->right = current;
                current = current->left;
            }
            else {
                pred->right = NULL;
                current = current->right;
            }
        }
    }
}

node* kthsmallest(node* root, int& k)
{
    if (root == NULL)
        return NULL;

    node* left = kthsmallest(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if (k == 0)
        return root;

    return kthsmallest(root->right, k);
}

int main() {
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Reverse Level order traversal: " << endl;
    reverseLevelOrderTraversal(root);

    cout << endl << "Recursive: " << endl;
    cout << "Inorder traversal: " << endl;
    inorder(root);
    cout << endl << "Preorder traversal: " << endl;
    preorder(root);
    cout << endl << "Postorder traversal: " << endl;
    postorder(root);

    cout << endl << endl << "Iterative: " << endl;
    cout << "Inorder traversal: " << endl;
    iterativeInorder(root);
    cout << endl << "Preorder traversal: " << endl;
    iterativePreorder(root);
    cout << endl << "Postorder traversal: " << endl;
    iterativePostorder(root);

    cout << endl << "Inorder traversal using Morris traversal: " << endl;
    morrisTraversalInorder(root);
    cout << endl << "Preorder traversal using Morris traversal: " << endl;
    morrisTraversalPreorder(root);

    cout << endl << "finding the kth smallest in bst: " << endl;
    int k = 3;
    cout << kthsmallest(root, k)->data << endl;


    return 0;
}