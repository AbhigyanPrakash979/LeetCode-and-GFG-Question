class Solution {
public:
    void solveUsingRecursion(vector<int>& nums, int index, vector<int>& current,
                             vector<vector<int>>& result) {

        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);
            solveUsingRecursion(nums, i + 1, current, result);
            current.pop_back();
        }
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        solveUsingRecursion(nums, 0, current, result);
        return result;
    }
};

// // Method 2
// class Solution {
// public:
//      void solveRecursion(vector<int> &nums, int i, int n, vector<vector<int>>
//      &ans, vector<int> output){
//         // Base case
//         if(i >= n){
//             ans.push_back(output);
//             return;
//         }

//         // Include nums[i]
//         output.push_back(nums[i]);
//         solveRecursion(nums, i + 1, n, ans, output);

//         // Exclude nums[i]
//         output.pop_back();
//         solveRecursion(nums, i + 1, n, ans, output);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         vector<int> output;
//         solveRecursion(nums, 0, nums.size(), ans, output);

//         //if we use set
//         set<vector<int>> s;

//         for(auto& subset: ans){
//             s.insert(subset);
//         }
//         ans.assign(s.begin(), s.end());
//         return ans;

//     }
// };