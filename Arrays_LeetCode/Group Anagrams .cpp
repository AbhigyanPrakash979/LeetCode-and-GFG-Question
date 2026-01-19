class Solution {
public:
    
    string generate(string &s) {
        int freq[26] = {0};
        
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        
        string new_String;
        
        for(int i = 0; i<26; i++) {
            
            if(freq[i] > 0) {
                new_String += string(freq[i], i+'a');
            }
        }
        
        return new_String;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string &s : strs) {
            string new_String = generate(s);
            
            mp[new_String].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &it : mp) {
            result.push_back(it.second);
        }
        
        return result;
        
    }
};