class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        // agar t pura match ho gaya hai aur hum end tak pahunch gaye
        if(j >= t.size()){
            return 1;
        }

        // agar s khatam ho gaya aur t abhi bacha hai
        if(i == s.size()){
            return 0;
        }

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // agar characters match ho rahe hain
        if(s[i] == t[j]){
            // 2 choices: include current char OR exclude it
            int include = solve(s, t, i+1, j+1, dp);
            int exclude = solve(s, t, i+1, j, dp);
            dp[i][j] = include + exclude;
        } 
        else {
            // agar match nahi ho raha toh sirf exclude karenge
            dp[i][j] = solve(s, t, i+1, j, dp);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        // dp table banayenge aur -1 se initialize krdenge
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

        // recursion start hoga dono strings ke 0th index se
        return solve(s, t, 0, 0, dp);
    }
};