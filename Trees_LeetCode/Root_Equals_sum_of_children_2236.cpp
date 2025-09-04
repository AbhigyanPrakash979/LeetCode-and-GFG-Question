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
    bool solve(TreeNode* root, TreeNode* leftSubtree, TreeNode* rightSubtree){

        //check for every left and right  subtree
        if(leftSubtree == NULL && rightSubtree == NULL){
            return true;
        }
        if(leftSubtree == NULL || rightSubtree == NULL){
            return false;
        }

        if( (root->val ) == leftSubtree->val + rightSubtree->val){
            return true;
        }
        else{
            return false;
        }
    }

    bool checkTree(TreeNode* root) {

        //base case
        if(root == NULL){
            return true;
        }
        int sum =0;
         return solve( root, root->left, root->right);
    }
};