class Solution {
public:
    int sum; // to handle negative sums safely
    // IMPORTANT

    //hum -ve index nhi jana chahte vrna segmentation fault aajayegi
    //eg minimum sum ho skta hai iska eg. ka -5 aur max +5
    // in short, basically humne range aage shift krdiya hai 
    //yahan pr memoization mein sum isliye add kiya hai kyunki sum minimum number hai to give us +ve no.

    int solve(vector<int>& nums, int target, int i, int currSum, vector<vector<int>> &dp) {
        if(i == nums.size()) {
            if(currSum == target) {
                return 1; // mtlab 1 way mil gya
            } else {
                return 0; // nhi mila
            }
        }

        if(dp[i][currSum + sum] != -1) {
            return dp[i][currSum + sum];
        }

        int plus = solve(nums, target, i+1, currSum + nums[i], dp);
        int minus = solve(nums, target, i+1, currSum - nums[i], dp);

        dp[i][currSum + sum] = plus + minus;
        return dp[i][currSum + sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));
        return solve(nums, target, 0, 0, dp);
    }
};