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
    int maxDiameter = 0;

    int height(TreeNode* root){
        // Base case
        if(root == NULL){
            return 0;
        }

        // Recursively compute height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Update the diameter if the path through this node is larger
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  // This will update maxDiameter during traversal
        return maxDiameter;
    }
};
