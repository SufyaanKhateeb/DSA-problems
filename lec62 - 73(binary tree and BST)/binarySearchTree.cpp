#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root) {
    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    // base case
    if(root == NULL)
        return root;
    if(root->data == val) {
        // 0 children
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 children
        // left child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    } else if(root->data < val) {
        root->right = deleteFromBST(root->right, val);
    } else {
        root->left = deleteFromBST(root->left, val);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    if (root != NULL) {
        q.push(root);
        q.push(NULL); // spacer for printing newline when one level completes
    }
    while (!q.empty()) {
        Node* temp = q.front();
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

void inorder(Node*& root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderReverse(Node*& root) {
    if (root == NULL)
        return;
    inorderReverse(root->right);
    cout << root->data << " ";
    inorderReverse(root->left);
}

void preorder(Node*& root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*& root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // 10 8 21 7 27 5 4 3 -1
    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: levelorder " << endl;
    levelOrderTraversal(root);

    cout << endl << "Printing the BST: inorder (prints the tree in ascending order)" << endl;
    inorder(root);
    
    cout << endl << "Printing the BST: inorder (prints the tree in descending order)" << endl;
    inorderReverse(root);

    cout << endl << "Printing the BST: preorder" << endl;
    preorder(root);

    cout << endl << "Printing the BST: postorder" << endl;
    postorder(root);
    
    cout << endl << "Min. value in BST: " << minVal(root)->data;
    
    cout << endl << "Max. value in BST: " << maxVal(root)->data;
    
    cout << endl << "Deleting a Node:" << endl;
    root = deleteFromBST(root, 21);
    inorder(root);

    return 0;
}