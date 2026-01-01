class Solution {
  public:
    vector<int> solve(vector<int>& arr, int k, vector<int> ans) {
        deque<int> dq;

        // Step 1: process first k elements
        for(int i=0; i<k; i++){
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }

        // Step 2: process remaining windows
        for(int i=k; i<arr.size(); i++){
            // record answer for current window
            if(dq.empty()){
                ans.push_back(0);
            } else {
                ans.push_back(arr[dq.front()]);
            }

            // remove out-of-window index
            while(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }

            // add new element if negative
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }

        // Step 3: process last window
        if(dq.empty()){
            ans.push_back(0);
        } else {
            ans.push_back(arr[dq.front()]);
        }

        return ans;
    }

    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        return solve(arr, k, ans);
    }
};