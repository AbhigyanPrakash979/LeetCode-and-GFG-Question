/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL){
            return NULL;
        }

        // case 1 ==> p and q both are in left
        if(root->val > p-> val && root->val > q-> val){
            return lowestCommonAncestor(root->left, p, q);
        }
        // case 2 ==> p and q both are in right
        else if(root->val < p-> val && root->val < q-> val){
            return lowestCommonAncestor(root->right, p, q);
        }
        // Case 3 ==>  p is in left and q is in right
        else if(root->val > p-> val && root->val < q-> val){
            return root;
        }
        //case 4 ==>  p is in right and q is in left
        else if(root->val > p-> val && root->val < q-> val){
            return root;
        }
        
            return root;
    }
};