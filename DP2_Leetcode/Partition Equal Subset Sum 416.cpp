class Solution {
public:
    int n;

    bool solve(vector<int>& nums, int i, int x, vector<vector<int>>& dp) {
        if (x == 0) {
            return true; // mtlab possible hai
        }

        if (i >= n) {
            return false; // end tak aa gaye aur sum complete nhi hua
        }

        // agar pehle se answer stored hai
        if (dp[i][x] != -1) {
            return dp[i][x];
        }

        // include vala case
        bool include = false;
        if (nums[i] <= x) {
            include = solve(nums, i + 1, x - nums[i], dp);
        }

        // exclude vala case
        bool exclude = solve(nums, i + 1, x, dp);

        // dono mein se koi bhi true ho to answer true
        return dp[i][x] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        if (sum % 2 != 0) {
            return false; // odd sum ka partition equal nhi ho sakta
        }

        int x = sum / 2;
        vector<vector<int>> dp(n, vector<int>(x + 1, -1)); // dp[i][x] => i se x ban sakta hai ya nahi

        return solve(nums, 0, x, dp);
    }
};