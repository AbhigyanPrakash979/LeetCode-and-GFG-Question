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
    TreeNode* solve(vector<int>& nums, int start, int end){
        //base case
        if(start > end){
            return NULL;
        }
        int mid = start + (end - start) / 2;
        int element = nums[mid];

        //creating root node from that element
        TreeNode* root = new TreeNode(element);
        //call for left subTree
        root-> left = solve(nums, start, mid-1);
        //call for right subtree
        root-> right = solve(nums, mid+1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start =0;
        int end = nums.size()-1;
        return solve(nums, start, end);

    }
};