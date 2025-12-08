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
    int dfs(TreeNode* root, int maxVal, int &count){
        //base case
        if(root == NULL){
            return 0;
        }

        //condition to check 
        if(root->val >= maxVal){
            count++;
        }

        //update count
        int maxi = max(maxVal, root->val);

        //RR
        //Left ki call
        dfs(root->left, maxi, count );
        //right ki call
        dfs(root->right, maxi, count );

        //yahi galti hogi****** Humme count(No fof good nodes return krna hai)
        //naaki maxi;
        return count;
    }

    int goodNodes(TreeNode* root) {
        int count =0;
        int maxVal = root->val;
        //dfs call
        return dfs(root, maxVal, count);
        
    }
};