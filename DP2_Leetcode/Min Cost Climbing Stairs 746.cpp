class Solution {
public:
    int solve(vector<int>& cost, int i, int n, vector<int>& dp){
        //base case
        if(i>=n){
            return 0;
        }
        // check whether answer already exists
        if(dp[i] != -1){
            return dp[i];
        }

        //case 1 = using 1 step
        int ans1 = cost[i] + solve(cost,i+1, n, dp);
        //case 2 = using  2 steps
        int ans2 = cost[i] + solve(cost, i+2, n, dp);

        dp[i] = min(ans1, ans2);
        return dp[i];

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int>dp(n+1, -1);
        // index 0 se bhi check krro aur index 1 se bhi
        int ans = min(solve(cost, 0, n, dp), solve(cost, 1, n, dp));
        return ans;
    }
};



// class Solution {
// public:
//     int solve(vector<int>& cost, int i, int n){
//         //base case
//         if(i>n){
//             return 0;
//         }

//         //case 1 = using 1 step
//         int ans1 = cost[i] + solve(cost,i+1, n);
//         //case 2 = using  2 steps
//         int ans2 = cost[i] + solve(cost, i+2, n);

//         int minCost = min(ans1, ans2);
//         return minCost;

//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n= cost.size();
//         // index 0 se bhi check krro aur index 1 se bhi
//         int ans = min(solve(cost, 0, n), solve(cost, 1, n));
//         return ans;
//     }
// };