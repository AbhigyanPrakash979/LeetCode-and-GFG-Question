//TC : O(nlogn)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // yaha pr array mein amendment krke 3 cheezein daaldi 
        // 2nd index pr index daal diya diya track rakhne ke liye
        vector<array<int, 3>> sortedTasks;
        
        for(int i = 0; i<n; i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            
            sortedTasks.push_back({start_time, processing_time, i});
        }
        
        //sort it
        sort(begin(sortedTasks), end(sortedTasks)); //O(nlogn)
        
        // Final vector bnado 
        vector<int> result;
        
        long long curr_time = 0;
        int index             = 0;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq; //min_heap
        
        while(index < n || !pq.empty()) {
            // Agar mera curret time 0 se shuru nhi hota balki 4 ya 5 baje se shuru hoga
            // toh current time ko vaha tak le aao
            if(pq.empty() && curr_time < sortedTasks[index][0]) {
                curr_time = sortedTasks[index][0];
            }
            
            //pq mein push krdo
            while(index < n && sortedTasks[index][0] <= curr_time) {
                pq.push({sortedTasks[index][1], sortedTasks[index][2]}); //log(n)
                index++;
            }
            
            pair<int, int> curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first; //processing time
            result.push_back(curr_task.second);
        }
        return result;
    }
};