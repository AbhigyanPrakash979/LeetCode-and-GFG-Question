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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) 
        return NULL;

        // Post-order: process children first
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // hum condition isliye end mein likh rahe hain coz humme leaf nodes delete krni hai
        // If current node becomes a leaf and matches target, delete it
        if (root->left == NULL && root->right == NULL && root->val == target) {
            return NULL;
        }

        return root;
    }
};
