class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    bool isSafe(int x_, int y_, int m, int n) {
        if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n) {
            return true;
        } else {
            return false;
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int diff = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_, m, n)) {
                    int newDiff =
                        max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if (result[x_][y_] > newDiff) {
                        result[x_][y_] = newDiff;
                        pq.push({result[x_][y_], {x_, y_}});
                    }
                }
            }
        } 
        return result[m - 1][n - 1];
    }
};