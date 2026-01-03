class Solution {
public:
    vector<vector<int>> result;

    void solveUsingRecursion(vector<int>& nums, int index, int n) {
        // Base case
        if (index >= n) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> uniqueSet; // track elements used at this depth

        for (int i = index; i < n; i++) {
            // Skip duplicates: only swap once per unique value at this level
            //mtlab ki agar exist krta hai set mein toh skip krdo
            if (uniqueSet.find(nums[i]) != uniqueSet.end()) 
            continue;

            uniqueSet.insert(nums[i]);
            swap(nums[i], nums[index]);                 // choose
            //RR
            solveUsingRecursion(nums, index + 1, n);    // explore
            //Backtrack
            swap(nums[i], nums[index]);                 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to group duplicates
        int n = nums.size();
        solveUsingRecursion(nums, 0, n);
        return result;
    }
};