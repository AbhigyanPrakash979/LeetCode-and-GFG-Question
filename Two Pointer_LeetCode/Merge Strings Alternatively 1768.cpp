class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0;
        int j = 0;
        
        // OR operator isliye use kiya coz second word2 bdda ho skta hai length mein word1 se
        while (i < word1.size() || j < word2.size()) {
            // pehle yeh push hua
            if (i < word1.size()){
                result.push_back(word1[i++]);
            } 
            // phir yeh push hua
            if (j < word2.size()){
                result.push_back(word2[j++]);
            } 
        }
        
        return result;
    }
};