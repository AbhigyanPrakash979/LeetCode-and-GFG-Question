class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);   // frequency of each character
        int n = s.length();
        int i = 0, j = 0;
        int maxCount = 0;          // max frequency of any char in window
        int maxLen = 0;

        while (j < n) {
            // include s[j] in window
            freq[s[j] - 'A']++;
            maxCount = max(maxCount, freq[s[j] - 'A']);

            // if window is invalid (too many replacements needed), shrink
            while ((j - i + 1) - maxCount > k) {    // j-i+1 humme window btata hai
                freq[s[i] - 'A']--;
                i++;    // i ko aage badhane pdega bcoz window aage badhani hai
            }

            // update maxLen
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};