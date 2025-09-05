class Solution {
  public:
    void findPreSucHelper(Node* root, int key, Node*& pre, Node*& suc) {
        if (!root) return;

        if (root->data == key) {
            // Predecessor: max value in left subtree
            if (root->left) {
                Node* temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }

            // Successor: min value in right subtree
            if (root->right) {
                Node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
        }
        else if (key < root->data) {
            suc = root; // potential successor
            findPreSucHelper(root->left, key, pre, suc);
        }
        else {
            pre = root; // potential predecessor
            findPreSucHelper(root->right, key, pre, suc);
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        findPreSucHelper(root, key, pre, suc);
        return {pre, suc};
    }
};
