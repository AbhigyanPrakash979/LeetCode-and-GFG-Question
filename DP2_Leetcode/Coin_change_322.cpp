class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp){
        //base case
        if(amount == 0){
            return 0;
        }

        if (amount< 0){
            return -1;
        }
        //check whether answer already exist
        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX;
        //traverse the whole array
        for(int i =0; i<coins.size() ;i++){
            int ans = solve(coins, amount-coins[i],dp);

            //remove invalid identity
            if( ans>=0 && ans != INT_MAX){
                mini = min (mini, ans+1);
            }
        }
        dp[amount]= mini;
        if(dp[amount] == INT_MAX)
        return -1;
        else{
            return dp[amount];
        }
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,-1);

        int ans = solve(coins,amount,dp);
        return ans;
        
    }
};