class Solution {
public:
    int solve(int n, vector<int> &dp){
        // base case
        if(n == 0 || n == 1){
            return 1;
        }
        // check whether the answer already exist
        if(dp[n] != -1){
            return dp[n];
        }

        // recursive relation
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return dp[n];
    }

    int climbStairs(int n) {

        vector<int> dp(n+1, -1);

        int result = solve(n,dp);
        return result;
    }
};







//tle

class Solution {
public:
    int solve(int n){
        // base case
        if(n == 0 || n == 1){
            return 1;
        }

        // recursive relation
        int ans = solve(n-1) + solve(n-2);
        return ans;
    }

    int climbStairs(int n) {
        int result = solve(n);
        return result;
    }
};
