class Solution {
public:
    int solve(vector<int> &nums, int left, int right, vector<vector<int>> &dp) {
        // agar left aur right ke beech koi balloon hi nahi bacha
        if(left + 1 == right){
            return 0;   // do remember humme pehla aur last pop nhi krna i.e (1, -----, 1)
        }

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = 0;

        // har ek balloon ko try karenge as last burst between left and right
        for(int i = left+1; i < right; i++){
            // coins milenge jab i ko last burst karenge
            int coins = nums[left] * nums[i] * nums[right];

            // left aur right ke beech ke baaki balloons ko recursively burst karenge
            int leftPart = solve(nums, left, i, dp);
            int rightPart = solve(nums, i, right, dp);

            ans = max(ans, coins + leftPart + rightPart);
        }

        // dp mein store krdo aur return kro
        dp[left][right] = ans;
        return dp[left][right];
    }

    int maxCoins(vector<int>& nums) {
        // boundary balloons add karenge (value = 1) for easy calculation
        // humne staring mein aur end mein 1 add krdiya 
        // kyunki index 0 apne 0-1 se multiply hokr data galat answer dega kyunki voh exist he nhi krta
        // same for last element apne n+1 se multiply hoga jo ki exist nhi krta toh galat ans dega
        nums.insert(nums.begin(), 1);   
        nums.push_back(1);

        int n = nums.size();
        // dp table banayenge aur -1 se initialize krdenge
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // recursion start hoga full range se
        return solve(nums, 0, n-1, dp);
    }
};