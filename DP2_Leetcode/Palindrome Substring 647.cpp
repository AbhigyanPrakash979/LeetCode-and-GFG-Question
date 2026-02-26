class Solution {
public:
    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        // Jab tak characters match karte hain, palindrome milta hai
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;      // ek palindrome mila
            left--;       // left ko piche le jao
            right++;      // right ko aage le jao
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for (int center = 0; center < n; center++) {
            // Odd length palindromes ke liye center ek character hoga
            totalCount = totalCount + expandAroundIndex(s, center, center);

            // Even length palindromes ke liye center do characters ke beech hoga
            totalCount = totalCount + expandAroundIndex(s, center, center + 1);
        }

        return totalCount;
    }
};