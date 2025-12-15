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
    // Helper function computes rob and notRob for a node
    void dfs(TreeNode* root, int &rob, int &notRob) {
        if (root == NULL) {
            rob = 0;
            notRob = 0;
            return;
        }

        int leftRob, leftNotRob, rightRob, rightNotRob;
        dfs(root->left, leftRob, leftNotRob);
        dfs(root->right, rightRob, rightNotRob);

        // Rob current node → skip children
        rob = root->val + leftNotRob + rightNotRob;

        // Skip current node → children can be robbed or not
        notRob = max(leftRob, leftNotRob) + max(rightRob, rightNotRob);
    }

    int rob(TreeNode* root) {
        int robRoot, notRobRoot;
        dfs(root, robRoot, notRobRoot);
        return max(robRoot, notRobRoot);
    }
};