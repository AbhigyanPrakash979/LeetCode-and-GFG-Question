//Approach-1 (Using Max-heap)
class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        int n = s.length();
        
        vector<int> freq(26, 0);
        for(char &ch : s) {
            freq[ch-'a']++;

            // ceiling value check krna hai, jyaada aayi toh possible he nhi hai
            if(freq[ch-'a'] > (n+1)/2) 
                return "";
        }
        
        priority_queue<P, vector<P>> pq;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(freq[ch-'a'] > 0) {
                pq.push({freq[ch-'a'], ch});

            }
         }
            //final result mein push krna hai
        string result = "";
        
        while(pq.size() >= 2) {  // >=2 bcoz adjacent na ho ek dusre ke same elements
            auto P1 = pq.top(); 
            pq.pop();
            
            auto P2 = pq.top();
            pq.pop();
            
            result.push_back(P1.second);
            result.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            
            if(P1.first > 0)
                pq.push(P1);
            
            if(P2.first > 0)
                pq.push(P2);
        }
        
        if(!pq.empty())
            result.push_back(pq.top().second);
        
        return result;
    }
};

