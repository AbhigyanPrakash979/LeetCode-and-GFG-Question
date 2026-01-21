class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1)
            return grid[i][j];  // end mein pahunch

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m-1) {  //mtlab mein last row mein hoon ab sirf right he jaa skte hai
            return dp[i][j] = grid[i][j] + solve(grid, i, j+1, m, n, dp);
        } 
        else if(j == n-1) {  //mtlab mein last col mein hoon ab sirf down he jaa skte hai
            return dp[i][j] = grid[i][j] + solve(grid, i+1, j, m, n, dp);
        } 
        else {  // Agar beech mein kahin hoon toh minimum 
            // jis cell mein hoon voh value bhi toh add hogi aur baaki minimum of baaki ke bchhe hue cell
            return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j, m, n, dp), solve(grid, i, j+1, m, n, dp));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, m, n, dp);
    }
};