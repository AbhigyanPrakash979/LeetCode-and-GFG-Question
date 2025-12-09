class Solution {
public:
    // directions vector
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int m,
            int n, int i, int j) {

        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});    // q mein push kiya
        visited[i][j] = 1; // visited ko true mark krdo

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();

            //simply area increment krdo
            area++;
            // for every cell saare directions dekho
            for (auto& dir : directions) {
                int newRow = frontNode.first + dir[0];
                int newCol = frontNode.second + dir[1];

                // issi ke andr check krna pdega conditions ki out of bounds na
                // jaaye
                // agr ho rha hai toh skip krdo
                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) {
                    continue;
                }
                if (grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] ==1 && !visited[i][j]) {
                    int area = bfs(grid, visited, m, n, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};