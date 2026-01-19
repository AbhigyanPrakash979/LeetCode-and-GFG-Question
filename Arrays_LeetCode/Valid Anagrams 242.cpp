class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);       //mapping he create krdo vector mein

        for (char& ch : s) {    // mark string s ki present hai
            freq[ch - 'a']++;
        }

        for (char& ch : t) {
            freq[ch - 'a']--;  // remove krdo marking
        }

        // iterate krdo loop ke through ki zero hai ki nhi
        for (int c : freq) {
            if (c != 0) 
            return false; // mismatch found
        }

        return true; // all freqs balanced

    }
};