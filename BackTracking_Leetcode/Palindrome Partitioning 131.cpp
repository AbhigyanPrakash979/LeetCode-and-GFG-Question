// Approach (Recursion + Memoization for Palindrome + Backtracking)
// T.C : O(2^n) -> exploring all partitions
// S.C : O(n^2) -> memo table for palindrome checks
class Solution {
public:
    int n;
    vector<vector<int>> dp; // -1 = not computed, 0 = false, 1 = true

    bool isPalindrome(string& s, int l, int r) {
        if (l >= r) {
            return true;
        }

        if (dp[l][r] != -1) {
            if (dp[l][r] == 1) {
                return true;
            } else {
                return false;
            }
        }

        if (s[l] != s[r]) {
            dp[l][r] = 0;
            return false;
        }

        bool ans = isPalindrome(s, l + 1, r - 1);

        if (ans == true) {
            dp[l][r] = 1;
        } else {
            dp[l][r] = 0;
        }

        return ans;
    }

    void solve(string& s, int index, vector<string>& curr,
               vector<vector<string>>& result) {
        if (index == n) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                solve(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        dp.assign(n, vector<int>(n, -1)); // initialize memo table

        vector<vector<string>> result;
        vector<string> curr;

        solve(s, 0, curr, result);

        return result;
    }
};

// // Approach 2
// class Solution {
// public:
//     int n;

//     bool isPalindrome(string& s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;
//     }

//     void solve(string& s, int index, vector<string> curr,
//                vector<vector<string>>& result) {
//         // Base case
//         if (index == n) {
//             result.push_back(curr);
//             return;
//         }

//         for (int i = index; i < n; i++) {
//             if (isPalindrome(s, index, i)) {
//                 curr.push_back(s.substr(index, i - index + 1));
//                 // RR
//                 solve(s, i + 1, curr, result);
//                 // backtrack
//                 curr.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         n = s.length();
//         vector<vector<string>> result;
//         vector<string> curr;
//         solve(s, 0, curr, result);
//         return result;
//     }
// };