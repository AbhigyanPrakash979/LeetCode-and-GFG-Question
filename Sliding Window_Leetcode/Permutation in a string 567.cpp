// Using Sliding window Approach

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (n > m) {
            return false;
        }

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        // s1 ki freq store krlo kitni baar aaya hai
        for (char& ch : s1) {
            s1_freq[ch - 'a']++;
        }

        // yahan se sliding window ka kaam shuru
        int i = 0;
        int j = 0;

        while (j < m) {
            // s2 ki freq store krlo kitni baar aaya hai
            s2_freq[s2[j] - 'a']++;

            // out of window check krro
            if (j - i + 1 > n) { // time to shrink the window
                s2_freq[s2[i] - 'a']--;
                i++;
            }
            // same aagya toh return true krdo
            if (s1_freq == s2_freq) {
                return true;
            }

            j++;
        }

        return false;
    }
};

    // // Approach 1 : good simple approach
    // class Solution {
    // public:
    //     bool checkInclusion(string s1, string s2) {
    //         int n = s1.length();
    //         int m = s2.length();

    //         if (n > m) {
    //             return false;
    //         }

    //         sort(begin(s1), end(s1));

    //         for (int i = 0; i <= m - n; i++) {
    //             string substring = s2.substr(i, n);
    //             sort(begin(substring), end(substring));

    //             if (s1 == substring) {
    //                 return true;
    //             }
    //         }

    //         return false;
    //     }
    // };

    // TLE : do read

    // class Solution {
    // public:
    //     int n;
    //     bool result;

    //     void solve(int index, string& s1, string& s2) {
    //         if (index == n) {
    //             if (s2.find(s1) != string::npos) {
    //                 result = true;
    //             }
    //             return;
    //         }

    //         for (int i = index; i < n; i++) {
    //             swap(s1[i], s1[index]);   // choose character at i
    //             solve(index + 1, s1, s2); // explore next position
    //             swap(s1[i], s1[index]);   // backtrack

    //             if (result == true)
    //                 return; // early exit if match found
    //         }
    //     }

    //     bool checkInclusion(string s1, string s2) {
    //         n = s1.length();
    //         result = false;
    //         solve(0, s1, s2);
    //         return result;
    //     }
    // };