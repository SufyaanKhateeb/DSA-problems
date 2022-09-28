#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption all word in caps
        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        //base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // assumption all word in caps
        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode* root, string word) {
        //base case
        if (word.length() == 0) {
            bool ans = root->isTerminal;
            root->isTerminal = false;
            return ans;
        }

        // assumption all word in caps
        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        // recursion
        return removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        bool isPresent = removeUtil(root, word);
        if (isPresent)
            cout << "Removed word" << endl;
        else
            cout << "Word is not present in Trie" << endl;
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("HELLO");
    t->insertWord("TIME");
    t->insertWord("DO");

    cout << t->searchWord("TIME") << endl;

    t->removeWord("TIME");

    return 0;
}