class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n == 1){
            return 1;   // agar n hai he 1 toh kuch kr nhi skte return krdo
        }

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[n] != -1){
            return dp[n];
        }

        int result = INT_MIN;

        for(int i = 1; i <= n-1; i++) {

            /* in short hum nikal rhe hain MAX of (i, n-1) ka aur (i, solve(n-i) )
                 kyunki ho skta hai (i, n-i) ka max product he max ho
            */  
            int prod = i * max(n-i, solve(n-i, dp));
            result = max(result, prod);
        }

        return dp[n] = result;
    }

    int integerBreak(int n) {
        // dp table banayenge aur -1 se initialize krdenge
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};