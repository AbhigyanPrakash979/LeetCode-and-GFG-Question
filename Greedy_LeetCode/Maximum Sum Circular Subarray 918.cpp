class Solution {
public:
    
    int kadanesMax(vector<int>& nums, int n) {
        int sum     = nums[0];
        int maxSum  = nums[0];
        
        for(int i = 1; i<n; i++) {
            sum     = max(sum + nums[i], nums[i]);
            maxSum  = max(maxSum, sum);
        }
        return maxSum;
    }
    
    int kadanesMin(vector<int>& nums, int n) {
        int sum     = nums[0];
        int minSum  = nums[0];
        
        for(int i = 1; i<n; i++) {
            sum     = min(sum + nums[i], nums[i]);
            minSum  = min(minSum, sum);
        }
        return minSum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int SUM = accumulate(begin(nums), end(nums), 0); 
        int minSum = kadanesMin(nums, n);
        int maxSum = kadanesMax(nums, n);
        
        int circSum = SUM - minSum; // Yeh important hai // maan letein hian max sum circular sum hai
        
        if(maxSum > 0) {        // check krro ki negetive na ho
            return max(maxSum, circSum);
        }
        
        return maxSum;
    }
};