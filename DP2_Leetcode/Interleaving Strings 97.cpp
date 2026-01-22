class Solution {
public:
    int m, n, N;

    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>> &dp) {
        if(i == m && j == n && k == N) {    // mtlab saare ek saath out of bounds hue toh
            return true;
        }
        if(k >= N) {    // mtlab sirf yahi out of bounds hua aur baaki s1 aur s2 pddi hue hai
            return false;
        }

        if(dp[i][j] != -1) {    // agar already calculate ho chuka hai toh wahi return krdo
            return dp[i][j] == 1;
        }

        bool result = false;    // intialize
        if(s1[i] == s3[k]) {
            result = solve(i+1, j, k+1, s1, s2, s3, dp);
        }
        
        if(result == true){ // mtlab agar yahan tak mein true mil gya toh true return krdo
            dp[i][j] = 1;
            return true;
        }

        if(s2[j] == s3[k]) {
            result = solve(i, j+1, k+1, s1, s2, s3, dp);
        }

        // if(result == true) {
        //     dp[i][j] = 1;
        // } else {
        //     dp[i][j] = 0;
        // }
        // return result;
        dp[i][j] = result;
        return dp[i][j];
    }

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();

        if(m + n != N) 
        return false; // agar length mismatch hai toh false

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1)); // dp table initialize
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};