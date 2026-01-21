class Solution {
public:
    unordered_set<string> st;
    int n;

    bool solve(int index, string &s, vector<int> &dp) {
        if (index >= n) {
            return true;
        }
        // Check if already answer exist
        if (dp[index] != -1) {
            return dp[index];
        }

        for (int l = 1; l <= n; l++) {
            string temp = s.substr(index, l);
            if (st.find(temp) != st.end() && solve(index + l, s, dp)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        vector<int> dp(n + 1, -1);
        // Hum jaan buch kr set mein insert kr rhe hai kyunki vector<string> diya hua hai
        // aur hum baar traverse krke nhi dekhna chahte ki present hai ki nhi vector mein
        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s, dp);
    }
};