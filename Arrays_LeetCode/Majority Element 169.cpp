class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majorElement = NULL;

        for(int i = 0; i<n; i++) {
            if(nums[i] == majorElement) {
                count++;
            } 
            else if(count == 0) {
                majorElement = nums[i];
                count = 1;
            } 
            else {
                count--;
            }

        }

        return majorElement;
    }
};