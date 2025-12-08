/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULL), right(NULL) {}
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
     bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if( (p == NULL) && (q == NULL) ){
            return true;
        }
        //base case
        if( (p == NULL) || (q == NULL) ){
            return false;
        }
        //base case2
        if(p->val != q->val){
            return false;
        }
        // RR call
        bool leftSubTree = isSameTree(p->left, q->left);
        bool rightSubTree = isSameTree(p->right, q->right);

        return leftSubTree && rightSubTree;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) 
        return false;

        // If trees match at this node
        if (isSameTree(root, subRoot)) 
        return true;

        // Otherwise, check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};