class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {    // Trie sirf pointer hold krti hai root node tak ke liye
        root = new TrieNode('\0'); // root with empty char
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode(ch);
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == NULL) {
            return false;
            }
            node = node->children[index];
        }
        //idhar hai difference
        return node->isTerminal;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->children[index] == NULL){
            return false;
            } 
            node = node->children[index];
        }
                // idhar hai difference

        return true;
    }
};