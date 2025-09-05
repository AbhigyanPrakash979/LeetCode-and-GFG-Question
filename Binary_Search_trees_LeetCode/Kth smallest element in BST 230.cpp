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
    int kthSmallest(TreeNode* root, int& k) {
        //base case
        if(root == NULL){
            return -1;
        }

        //InOrder follow krna hai bss
        //left meinnjaao 
        int leftAns = kthSmallest(root->left, k);
        //check krlo ki negetive toh nhi hai
        if(leftAns != -1){
            return leftAns;
        }

        k--;
        //current node ko process
        if(k ==0){
            return root->val;
        }

        //right mein jaao
        int rightAns = kthSmallest(root->right, k);
            return rightAns;
    }
};