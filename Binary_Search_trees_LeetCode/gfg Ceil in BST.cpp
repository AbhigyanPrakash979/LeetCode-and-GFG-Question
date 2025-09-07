class Solution {
  public:
    int findCeil(Node* root, int x) {
        if (root == NULL) {
            return -1;
        }

        if (root->data == x) {
            return root->data;
        }

        if (root->data < x) {
            // Ceil must be in right subtree
            return findCeil(root->right, x);
        }

        //possible ceil, but check left subtree for closer one
        if(root->data > x){
            
            int leftCeil = findCeil(root->left, x);
                if (leftCeil >= x && leftCeil != -1) {
                    return leftCeil;
                }
                else {
                    return root->data;
                }
        }
       
    }
};
