//maine issmein visited DS nhi use kiya kyunki down aur right jaa rhe hai
//kisis bhi halat main hum vapis nhi uss ecell ko visit krne vale

class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1)   // issmein ek check aur dala hai
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(grid, i, j+1, dp);
        int down = solve(grid, i+1, j, dp);

        dp[i][j] = right + down;    // yeh toh mila ke ek path count hua
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};