class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int element = nums[mid];

            if (element == target) {
                return mid;                 // found target
            } else if (target < element) {
                end = mid - 1;              // go left
            } else {
                start = mid + 1;            // go right
            }
        }
        // Agar nhi mila, start return krdo jo ki sbse pass mein hai element ke
        return start;
    }
};