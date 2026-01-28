class Solution {
public:
    // DP table: -1 means not calculated yet, 0 means false, 1 means true
    vector<vector<int>> dp;

    bool solve(int index, int open, string& s, int n) {
        if(index == n) {
            // Tabhi valid hoga jab open brackets bilkul khatam ho chuki ho
            return open == 0;
        }
        if(dp[index][open] != -1) {
            return dp[index][open];
        }

        bool isValid = false;

        // Agar current character '*' hai
        if(s[index] == '*') {
            // '*' ko '(' treat karo, ek open bracket badh gaya
            isValid |= solve(index+1, open+1, s, n);

            // '*' ko empty treat karo, kuch nahi badla
            isValid |= solve(index+1, open, s, n);

            // '*' ko ')' treat karo, ek open bracket close ho gaya
            if(open > 0) { // yahn pr check dala hai
                isValid |= solve(index+1, open-1, s, n);
            }
        }
        // Agar current character '(' hai
        else if(s[index] == '(') {
            // Open bracket mila, count badhao
            isValid |= solve(index+1, open+1, s, n);
        }
        // Agar current character ')' hai
        else if(open > 0) {
            // Close bracket mila, ek open bracket ko match kar diya
            isValid |= solve(index+1, open-1, s, n);
        }
        return dp[index][open] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.length();
        dp.assign(n+1, vector<int>(n+1, -1));

        return solve(0, 0, s, n);
    }
};