class Solution {
public:
     void solveRecursion(vector<int> &nums, int i, int n, vector<vector<int>> &ans, vector<int> output){
        // Base case
        if(i >= n){
            ans.push_back(output);
            return;
        }

        // Include nums[i]
        output.push_back(nums[i]);
        solveRecursion(nums, i + 1, n, ans, output);

        // Exclude nums[i]
        output.pop_back(); 
        solveRecursion(nums, i + 1, n, ans, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        solveRecursion(nums, 0, nums.size(), ans, output);

        //use of set to ignore duplicates
        //as we are using recursion, we can have duplicates in ans
        //so we will use set to remove duplicates
        set<vector<int>> s;

        for(auto& subset: ans){
            s.insert(subset);
        }
        ans.assign(s.begin(), s.end());
        return ans;
        
    }
};