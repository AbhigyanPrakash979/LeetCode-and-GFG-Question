class Solution {
public:
    int n;
    // humne dp[i][prev + 1] isliye kiya kyunki [prev] ki ek time pr -1 set ki thi jo ki inalid hota index -1

    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        // base case
        if (i >= n) {
            return 0;
        }

        // check if already ans exist
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        // include vala case
        int include = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            include = 1 + solve(nums, i + 1, i, dp);
        }

        // exclude vala case
        int exclude = solve(nums, i + 1, prev, dp);

        // dono mein se max lena hai
        return dp[i][prev + 1] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        // prev can be -1, so shift by +1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // isse TC O(n^2) hojayega vrna O(2^n)
        return solve(nums, 0, -1, dp);
    }
};