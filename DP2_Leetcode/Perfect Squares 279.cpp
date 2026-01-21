class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // base case
        if (n == 0) {
            return 0;
        }
        // agar pehle se answer stored hai
        if (dp[n] != -1) {
            return dp[n];
        }

        int minCount = INT_MAX;

        // har perfect square try karo
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - i * i, dp);
            minCount = min(minCount, result);
        }

        // answer store karke return karo
        return dp[n] = minCount;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1); // dp[n] => minimum squares to make n
        return solve(n, dp);
    }
};