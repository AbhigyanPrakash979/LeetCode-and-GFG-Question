class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> m;
        stack<int> s;
        //initial push 
        s.push(-1);

        int n = nums2.size();
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            int currElement = nums2[i];
                while (!s.empty() && s.top() <= currElement) {
                    s.pop();
                }
                if (s.empty()) {
                    ans[i] = -1;
                } 
                else {
                    ans[i] = s.top();
                }

            s.push(currElement);
            m[currElement] = ans[i];
        }

        // vector 
        vector<int> finalAns;
        for(int i =0; i<nums1.size(); i++){
            int temp = nums1[i];

            //push in final ans w.r.t to nums 1 array
            finalAns.push_back(m[temp]);
        }
        return finalAns;
    }
};