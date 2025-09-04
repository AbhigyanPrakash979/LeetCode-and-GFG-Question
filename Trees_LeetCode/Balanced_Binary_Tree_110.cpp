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
    int checkHeight(TreeNode* &root){
        //base case
        if(root == NULL){
            return 0;
        }

        //calculating the height
        int leftSubTree = checkHeight(root -> left);
        int rightSubTree = checkHeight(root -> right);
        int ans = max(leftSubTree, rightSubTree) + 1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {

        //base case
        // agar single root hai toh already balanced hai
        if(root == NULL){
            return true;
        }

        // check absolute difference
        int leftSubTreeAns = checkHeight(root->left);
        int rightSubTreeAns = checkHeight(root-> right);
        int diff = abs(leftSubTreeAns - rightSubTreeAns);
        int ans = (diff <= 1);
        
        

        //Recursive calls
        bool leftAns = isBalanced(root-> left);
        bool rightAns = isBalanced(root-> right);

        if (leftAns && rightAns && ans){
            return true;
        }
        else{
            return false;
        }


    }
};