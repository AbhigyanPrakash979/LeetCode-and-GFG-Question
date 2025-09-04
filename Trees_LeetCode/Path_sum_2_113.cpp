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
    void solve(TreeNode* root, int targetSum, int sum, 
    vector<vector<int>>& ans, vector<int>& path){
        //base case
        if(root == NULL){
            return;
        }

        // leaf nodes ke liye
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->val);
            sum += root->val;

            //jaise je leaf node pr paunche check for targetSum
            if(sum == targetSum){
                ans.push_back(path);
            }

            // now backtracking , agar targetSum nhi mila toh
            path.pop_back();
            sum -= root->val;
        }

        // for other nodes
        path.push_back(root->val);
        sum+= root->val;

        //rr
        solve(root->left, targetSum, sum, ans, path);
        solve(root->right, targetSum, sum, ans, path);

        //backtrack;
        path.pop_back();
        sum-= root->val;

    }




    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;
        int sum =0;
        solve(root, targetSum, sum, ans, path);
        return ans;
        
    }
};