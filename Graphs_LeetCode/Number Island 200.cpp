class Solution {
public:
    void dfsTraverse(vector<vector<char>> &grid, int m, int n, int i, int j){
        //base case
        // agar out of bounds jaye
        if( (i<0) || (j<0)  ||  (i>=m) || (j>=n)  ||  (grid[i][j] == '0') ){
            return ;
        }

        // base case 2
        // if already visited just simply return
        if(grid[i][j] == '$'){
            return;
        }

        // mark visited // 
        grid[i][j] = '$';

        // explore all the side
        dfsTraverse(grid, m , n, i-1, j); // up
        dfsTraverse(grid, m , n, i+1, j); // down
        dfsTraverse(grid, m , n, i, j-1); //left
        dfsTraverse(grid, m , n, i, j+1); //right

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        //traverse through grid
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){

                if(grid[i][j] == '1'){
                    dfsTraverse(grid,m,n, i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;    
    }
};