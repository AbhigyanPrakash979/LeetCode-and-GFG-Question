

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &num : nums){
            freq[num]++;
        }

        // Max heap: pair<frequency, element>
        priority_queue<pair<int,int>> maxHeap;
        for(auto &p : freq){
            maxHeap.push({p.second, p.first}); // frequency ke baisis m\pr sort krna chahta hoon
        }

        vector<int> result;

        while(k > 0 && !maxHeap.empty()){  // ab sidha max heap  mein daaldo
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return result;
    }
};