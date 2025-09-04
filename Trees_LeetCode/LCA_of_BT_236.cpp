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

        //base case
        if(root == NULL){
            return NULL;
        }

        //conditions
        if(root-> val == p-> val){
            return p;
        }
        if(root-> val == q->val){
            return q;
        }
        //rr
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // checking for all 4 possible cases
        if(leftAns == NULL && rightAns == NULL)
        return NULL;

        else if(leftAns != NULL && rightAns == NULL)
        return leftAns;

        else if(leftAns == NULL && rightAns != NULL)
        return rightAns;

        else /*(leftAns != NULL && rightAns != NULL) */
        return root;
    }
};