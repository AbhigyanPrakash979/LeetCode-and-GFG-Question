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
    TreeNode* buildTreeFromPreorder(vector<int>& preorder, int& preOrderStart, int bound) {
        // base case
        if (preOrderStart >= preorder.size() || preorder[preOrderStart] > bound) {
            return NULL;
        }

        // taking element one by one
        int element = preorder[preOrderStart++];
        // making root
        TreeNode* root = new TreeNode(element);

        // call for left subTree with updated bound
        root->left = buildTreeFromPreorder(preorder, preOrderStart, element);
        // call for right subTree with inherited bound
        root->right = buildTreeFromPreorder(preorder, preOrderStart, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preOrderStart = 0;
        return buildTreeFromPreorder(preorder, preOrderStart, INT_MAX);
    }
};
