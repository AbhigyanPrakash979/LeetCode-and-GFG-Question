class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;   // current window characters
        int n = s.size();
        int i = 0, j = 0;         // sliding window pointers
        int maxLen = 0;

        while (j < n) {
            // If duplicate found, shrink from left
            if (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            } else {
                // Expand window
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
        }
        return maxLen;
    }
};