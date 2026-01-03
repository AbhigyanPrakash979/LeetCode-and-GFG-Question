class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while (j < n) {
            sum += nums[j]; // expand window

            //agar window se bahr jaayein toh
            while (sum >= target) { // shrink window
                int currLen = j - i + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }

        if (minLen == INT_MAX) {
            return 0;
        } else {
            return minLen;
        }
    }
};