class Solution {
public:
    int n;

    int solve(int index, vector<int>& nums, int target, vector<vector<int>> &dp) {
        if(target == 0)
            return 1;

        if(index >= n || target < 0)    // range se bahr chal jaaye ya target he negetive hojaye
            return 0;

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int include = solve(0, nums, target - nums[index], dp); // phir se 0 se shuru krna hai //IMP
        int exclude = solve(index + 1, nums, target, dp);

        return dp[index][target] = include + exclude;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        // dp table banayenge aur -1 se initialize krdenge
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        return solve(0, nums, target, dp);
    }
};