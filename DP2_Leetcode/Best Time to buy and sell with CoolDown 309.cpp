// Very Important and tricky

class Solution {
public:
    int solve(vector<int>& prices, int day, int n, bool buy, vector<vector<int>> &dp) {
        if (day >= n)
            return 0;

        if(dp[day][buy] != -1)
            return dp[day][buy];

        int profit = 0;

        if (buy) { // buy
            // solve(prices, day + 1, n, false) => yeh selling hai apni
            //selling - prices[day] gives us profit
            int take = solve(prices, day + 1, n, false, dp) - prices[day];
            int not_take = solve(prices, day + 1, n, true, dp); // buying

            profit = max({profit, take, not_take});
        } 
        else { // sell
            // prices[day] + solve(prices, day + 2, n, true) => yeh buying hai apni
            int sell = prices[day] + solve(prices, day + 2, n, true, dp);
            int not_sell = solve(prices, day + 1, n, false, dp);//selling

            profit = max({profit, sell, not_sell});
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 2 isliye liya hai dp mein kyunki buy ke liye 2 he possible hai true or false
        vector<vector<int>> dp(n+1, vector<int>(2, -1)); // dp[day][buy] 
        bool buy = true;
        return solve(prices, 0, n, buy, dp);
    }
};