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



// Brute Force with TLE
//class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxi = 0;
//         int profit;

//         for(int buy=0; buy<n; buy++){
//             int temp1 = prices[buy];

//             for(int sell = buy+1 ; sell<n; sell++){
//                 int temp2 = prices[sell];

//                 if(temp2>temp1){
//                     profit = temp2-temp1;
//                 }
//                 else{
//                     profit =0;
//                 }
//                 maxi = max(maxi, profit);
//             }
//         }
//         return maxi;        
//     }
// };