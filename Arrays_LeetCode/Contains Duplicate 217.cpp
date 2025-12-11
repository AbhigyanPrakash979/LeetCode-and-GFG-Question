class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;

        sort(nums.begin(), nums.end()); // sort first

        int i = 0, j = 1;
        while(j < n) {
            if(nums[i] == nums[j]) {
                return true; // duplicate found
            }
            i++;
            j++;
        }
        return false; // no duplicates
    }
};