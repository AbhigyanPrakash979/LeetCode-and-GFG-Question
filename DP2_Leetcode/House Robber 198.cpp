class Solution {
public:

    // int findHouseRobber(vector<int>& nums, int i, int sum, int& maxi){

    //     // base case 
    //     if (i>= nums.size()){
    //     maxi = max(sum, maxi);
    //     return maxi;
    //     }
        
    //     // RR
    //     // include
    //     findHouseRobber(nums, i+2, sum+nums[i], maxi);

    //     // exclude
    //     findHouseRobber(nums, i+1, sum, maxi);

    //     return maxi;
    // }


    int findHouseRobber(vector<int>& nums, int i, int sum, int& maxi, vector<int>& dp){

        // base case 
        if (i>= nums.size()){
        return sum;
        }

        // check whether the anser already exists
        if(dp[i] != -1){
            return dp[i];
        }
        
        // RR
        // include
        int include = nums[i] + findHouseRobber(nums, i+2, sum, maxi, dp);
        // exclude
        int exclude =findHouseRobber(nums, i+1, sum, maxi, dp);

        dp[i] = max(include, exclude);
        return dp[i];
    }

    int rob(vector<int>& nums) {

        int sum= 0;
        int maxi = 0;
        int i= 0;
        int n = nums.size();
        // int ans= findHouseRobber(nums, i, sum, maxi);

        vector<int> dp(n+1, -1);
        int ans= findHouseRobber(nums, i, sum, maxi, dp);
        return ans;
        
    }
};