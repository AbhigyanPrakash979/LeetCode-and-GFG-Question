#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode(); 
    }

    bool searchHelper(string& word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->isTerminal;
        }

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL &&
                    searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a'; 
            if (node->children[idx] == NULL) return false;
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode(); 
            }
            node = node->children[idx];
        }
        node->isTerminal = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Example usage:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord("bad");
 * obj->addWord("dad");
 * obj->addWord("mad");
 * cout << obj->search("pad") << endl; // false
 * cout << obj->search("bad") << endl; // true
 * cout << obj->search(".ad") << endl; // true
 * cout << obj->search("b..") << endl; // true
 */