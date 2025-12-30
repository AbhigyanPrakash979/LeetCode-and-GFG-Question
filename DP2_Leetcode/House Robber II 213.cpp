class Solution {
public:
    int findHouseRobber(vector<int>& nums, int i, int end, vector<int>& dp) {
        // base case
        if (i > end) {
            return 0;
        }

        // check memo
        if (dp[i] != -1) {
            return dp[i];
        }

        // recursive relation
        int include = nums[i] + findHouseRobber(nums, i+2, end, dp);
        int exclude = findHouseRobber(nums, i+1, end, dp);

        dp[i] = max(include, exclude);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
        return nums[0]; // only one house
        
        if (n == 2) 
        return max(nums[0], nums[1]); // two houses

    // Humne 2 alag alag dp create kiya hai

        // Case 1: rob from 0 to n-2
        vector<int> dp1(n, -1);
        int case1 = findHouseRobber(nums, 0, n-2, dp1);

        // Case 2: rob from 1 to n-1
        vector<int> dp2(n, -1);
        int case2 = findHouseRobber(nums, 1, n-1, dp2);

        return max(case1, case2);
    }
};