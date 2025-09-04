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
    TreeNode* searchBST(TreeNode* root, int val) {
        //base case
        if(root == NULL){
            return NULL;
        }

        //case 1 -> match found for current element
        if(root->val == val){
            return root;
        }
        //case 2 -> left subtree
        if(root-> val > val){
           return searchBST(root->left, val);
        }

        //case -> right subtree
        if(root->val < val){
           return searchBST(root->right, val);
        }
        //jab yahan tak pahunch gaye hain mtlab ki yeh bst he nhi hai
        //so we can write in the end;
        return NULL;
    }
};