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
    TreeNode* invertTree(TreeNode* root) {

        //base case
        if(root == NULL){
            return NULL;
        }

        TreeNode* temp1 = root->left;
        TreeNode* temp2 = root->right;

        // now simply interchange the values
        root->left = temp2;
        root->right = temp1;

        // RR Call kiya for left and subtree
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};