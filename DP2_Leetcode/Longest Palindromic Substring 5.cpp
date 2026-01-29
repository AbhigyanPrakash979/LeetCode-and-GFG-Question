// Method 1 
class Solution {
public:
    // Check if substring s[i..j] is palindrome
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false; // mismatch found
            }
            i++;
            j--;
        }
        return true; // no mismatches, it's a palindrome
    }

    void findLongest(string& s, int i, int& maxLen, int& start) {
        int n = s.length();
        if (i >= n)
            return; // base case

        // Instead of inner loop, recursion explores substrings
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                if (j - i + 1 > maxLen) {// yeh check krega ki updatekrna hai ki nhi
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }

        // recursive call for next starting index
        findLongest(s, i + 1, maxLen, start);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int start = 0;

        findLongest(s, 0, maxLen, start);

        return s.substr(start, maxLen);
    }
};

//Method 2
class Solution {
public:
    bool solve(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (s[i] == s[j])
            return solve(s, i + 1, j - 1);

        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = INT_MIN;
        int startingPoint = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j) == true) {
                    // agar meri maxLength bddi aajati haitoh update krdo
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        startingPoint = i;
                    }
                }
            }
        }

        return s.substr(startingPoint, maxLen);
    }
};