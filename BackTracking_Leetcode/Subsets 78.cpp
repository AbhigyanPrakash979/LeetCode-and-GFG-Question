class Solution {
public:
    void solveRecursion(vector<int> &nums, int i, int n, vector<vector<int>> &ans, vector<int> output){
        // Base case
        if(i >= n){
            ans.push_back(output);
            return;
        }

        // Include nums[i]
        output.push_back(nums[i]);
        solveRecursion(nums, i + 1, n, ans, output);

        // Exclude nums[i]
        output.pop_back(); 
        solveRecursion(nums, i + 1, n, ans, output);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solveRecursion(nums, 0, nums.size(), ans, output);
        return ans;
    }
};
