/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MaxVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp ->right != NULL){
            temp = temp->right;
        }
        return temp->val;
    }
   
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root == NULL){
            return NULL;
        }

        //case 1 == issi root node ko delete krna hai
        if(root->val == key){

                // We have 4 Possible cases
                //case A == leaf Node
                if(root->left == NULL && root->right == NULL){
                    return NULL;
                }
                //case B ==>left Sub Tree mein delete krna hai
                if(root->left != NULL && root->right == NULL){
                    TreeNode* child = root->left;
                    //delete krne ke liye return child krdo
                    return child;
                }
                //case C ==> right Sub Tree mein delete krna hai
                if(root-> left == NULL && root-> right != NULL){
                    TreeNode* child = root-> right;
                    return child;
                }
                //case D ==> both child are there 
                else{       /* root-> left != NULL && root-> right != NULL */
                    int LeftSubTreeMaxVal = MaxVal(root->left);
                    root -> val = LeftSubTreeMaxVal;

                    // ab left subtree ke max val liye call krdo
                    //kyunki usse delete krna hai
                    root-> left = deleteNode(root-> left , LeftSubTreeMaxVal);
                }
        }
        
        //case 2 == left subtree hai
        if(root->val > key){
            root-> left = deleteNode(root->left, key);
        }

        //case 3 == rightSubtree mein hai
        if(root->val <key){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};