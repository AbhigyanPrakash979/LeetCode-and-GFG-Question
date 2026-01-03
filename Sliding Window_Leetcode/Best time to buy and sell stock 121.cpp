

// Using Array

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit =0;

        for(int i=0; i<prices.size(); i++){
            int temp = prices[i];
            minPrice = min(temp, minPrice);
            profit = max(profit, ( temp-minPrice) );
        }
        return profit;
        
    }
};

