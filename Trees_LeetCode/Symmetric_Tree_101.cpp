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
    bool solve(TreeNode* leftSubtree, TreeNode* rightSubtree){

         if(leftSubtree == NULL && rightSubtree == NULL){
            return true;
        }
        if(leftSubtree == NULL || rightSubtree == NULL){
            return false;
        }


        bool ansCheck = leftSubtree->val == rightSubtree->val;
        //rr
        return ansCheck
                    &&
         solve(leftSubtree->left, rightSubtree->right) 
                    &&
         solve (leftSubtree->right, rightSubtree-> left);
        

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return solve(root->left, root->right);    
    }
};