class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n;

    bool possibleToReach(vector<vector<int>>& grid, int i, int j, int t,
                         vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] == true || grid[i][j] > t) {
            return false;   // mtlab range mein nhi hai
        }

        visited[i][j] = true;

        //base case
        if (i == n - 1 && j == n - 1) {
            return true;
        }

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (possibleToReach(grid, i_, j_, t, visited)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int l = grid[0][0];
        int r = n * n - 1; // n^2 - 1;

        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (possibleToReach(grid, 0, 0, mid, visited)) { // BFS, DFS
                result = mid;
                r = mid - 1;    //left vale mein chale jaao
            } else {
                l = mid + 1;    //right vale mein chale jaao
            }
        }

        return result;
    }
};