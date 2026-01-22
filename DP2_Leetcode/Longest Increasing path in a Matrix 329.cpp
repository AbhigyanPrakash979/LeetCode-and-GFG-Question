class Solution {
public:
    int dfs(vector<vector<int>> &matrix, int i, int j, int parent, vector<vector<int>> &dp) {
        // boundary check + increasing condition
        // matrix[i][j] <= parent => this is to ensure next element bdda ho
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= parent){
            return 0;
        }

        // agar dp mein already answer pada hai toh wahi return krdo
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // har direction mein jaake max path nikalenge
        int down = dfs(matrix, i+1, j, matrix[i][j], dp);
        int up = dfs(matrix, i-1, j, matrix[i][j], dp);
        int right = dfs(matrix, i, j+1, matrix[i][j], dp);
        int left = dfs(matrix, i, j-1, matrix[i][j], dp);

        // dp mein store krdo aur return kro
        dp[i][j] = 1 + max({up, down, left, right});
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxPath = 0;

        // dp table banayenge aur -1 se initialize krdenge
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // har ek element ke liye check krenge max path
        // isliye har ek element ek ek krke bhejenge
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxPath = max(maxPath, dfs(matrix, i, j, -1, dp));
            }
        }
        return maxPath;
    }
};