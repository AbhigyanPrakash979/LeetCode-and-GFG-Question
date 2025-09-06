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
    // Helper class to store subtree info
    class NodeData {
    public:
        int size;
        int minVal;
        int maxVal;
        bool validBST;
        int subtreeSum;

        NodeData() {}

        NodeData(int size, int minVal, int maxVal, bool validBST, int subtreeSum) {
            this->size = size;
            this->minVal = minVal;
            this->maxVal = maxVal;
            this->validBST = validBST;
            this->subtreeSum = subtreeSum;
        }
    };

    int maxSum = 0;

    NodeData* solve(TreeNode* root) {
        // Base case: empty subtree is a valid BST
        if (root == NULL) {
            return new NodeData(0, INT_MAX, INT_MIN, true, 0);
        }

        NodeData* leftSubTree = solve(root->left);
        NodeData* rightSubTree = solve(root->right);

        NodeData* currNode = new NodeData();

        currNode->size = leftSubTree->size + rightSubTree->size + 1;
        currNode->minVal = min(root->val, leftSubTree->minVal);
        currNode->maxVal = max(root->val, rightSubTree->maxVal);

        if (leftSubTree->validBST && rightSubTree->validBST &&
            root->val > leftSubTree->maxVal &&
            root->val < rightSubTree->minVal) {

            currNode->validBST = true;
            currNode->subtreeSum = leftSubTree->subtreeSum + rightSubTree->subtreeSum + root->val;

            // Update global maxSum if current subtree is a valid BST
            maxSum = max(maxSum, currNode->subtreeSum);
        } else {
            currNode->validBST = false;
            currNode->subtreeSum = 0; // invalid BST, don't count its sum
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
