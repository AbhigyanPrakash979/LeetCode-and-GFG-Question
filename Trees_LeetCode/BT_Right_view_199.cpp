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
    void solve(TreeNode* root, int level, vector<int>& ans){
        //base case
        if(root== NULL){
            return ;
        }

        //condition
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        //pehle right ki call phir left ki call
        solve(root->right, level+1, ans);
        solve(root->left, level+1, ans);

    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        int level =0;

        solve(root, level, ans);
        return ans;
    }   
};