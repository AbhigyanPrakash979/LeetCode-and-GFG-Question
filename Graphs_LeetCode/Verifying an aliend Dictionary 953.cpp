class Solution {
public:
    // helper function: compare two words according to alien order
    bool compareWords(string &w1, string &w2, vector<int> &rank) {
        int i = 0;
        int j = 0;
        int m = w1.size();
        int n = w2.size();

        // dono words ko character by character compare karenge
        while(i < m && j < n) {
            int c1 = rank[w1[i] - 'a'];   // alien order mein position of w1[i]
            int c2 = rank[w2[j] - 'a'];   // alien order mein position of w2[j]

            if(c1 < c2) return true;       // w1 < w2 → correct order
            else if(c1 > c2) return false; // w1 > w2 → wrong order

            // agar equal hai toh next character compare karenge
            i++;
            j++;
        }

        // agar ek word dusre ka prefix hai
        // toh shorter word pehle aana chahiye
        if (m <= n)
            return true;
        else
            return false;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        // alien order ko rank array mein store karenge
        vector<int> rank(26);
        for(int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }

        // har consecutive pair ko check karenge
        for(int i = 0; i < words.size()-1; i++) {
            if(!compareWords(words[i], words[i+1], rank)) {
                return false;
            }
        }
        return true;
    }
};