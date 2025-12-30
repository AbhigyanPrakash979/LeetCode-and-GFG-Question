class Solution {
public:
    int solve(int i, string& s, int& n, vector<int>& dp) {
        if (i == n) {
            return 1; // one valid split done
        }

        if (s[i] == '0') {
            return 0; // not possible to split
        }

        // answer already exists
        if(dp[n] != -1){
            return dp[n];
        }

        // First recursive branch: take one digit
        int result1 = solve(i + 1, s, n, dp);

        // Second recursive branch: take two digits (if valid)
        int result2 = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                result2 = solve(i + 2, s, n, dp);
            }
        }

        dp[n] =result1 + result2;
        return dp[n] ;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(0, s, n, dp);
    }
};