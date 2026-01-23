//T.C : O( 2*(m*n) ) => O(m*n)
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) { //nhi jaa skte
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])// jaa nhi skte vapis aajao
            return;
        // agar aisa nhi hai toh current ko true mark krdo
        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); //rows
        int n = heights[0].size(); //cols

        vector<vector<int>> result;
        //pacificVisited[i][j] = true, means [i][j] water can go to Pacific //m*n
        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false)); 
        //atlanticVisited[i][j] = true, means [i][j] water can go to atlantic //m*n
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); 


        //Top Row and Bottom Row
        //Top Row : Pacific connected already
        //Bottom Row : atlantic connected already

        // INT_MIN kyunki prevCell value bhi bhejni hai, aur voh chotti honi chahehye
        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited); //Top Row
            DFS(heights, m-1, j, INT_MIN, atlanticVisited); //Top Row
        }

        //First col and last column
        //First col : Pacific connected already
        //Last col : atlantic connected already
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited); //First column
            DFS(heights, i, n-1, INT_MIN, atlanticVisited); //Last Column
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
