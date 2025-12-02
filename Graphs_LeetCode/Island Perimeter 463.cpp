class Solution {
public:
    void dfsTraverse(vector<vector<int>> &grid, int m, int n, int i, int j, int &perimeter){
        //base case
        // agar out of bounds jaya i aur j toh perimeter +1 krdo
        if( (i<0) || (j<0)  ||  (i>=m) || (j>=n)  ||  (grid[i][j] == 0) ){
            perimeter++;
            return ;
        }

        // base case 2
        // if already visited just simply return
        if(grid[i][j] == -1){
            return;
        }

        // mark visited // here using -1
        grid[i][j] = -1;

        // explore all the side
        dfsTraverse(grid, m , n, i-1, j, perimeter); // up
        dfsTraverse(grid, m , n, i+1, j, perimeter); // down
        dfsTraverse(grid, m , n, i, j-1, perimeter); //left
        dfsTraverse(grid, m , n, i, j+1, perimeter); //right

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter =0;

        //traverse through grid
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){

                if(grid[i][j] == 1){
                    dfsTraverse(grid,m,n, i, j, perimeter);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};





class Solution {
public:
    vector<vector<int>> directions{ {1,0}, {-1,0}, {0,-1}, {0,1} };

    int bfsTraverse(vector<vector<int>> &grid, int m, int n, int i, int j){
        int perimeter =0;

        queue<pair<int, int>> q;
        q.push({i,j});         // queue mein push kiya
        grid[i][j] = -1;        // visited amrk krdo

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            // here
            // frontNode.first = i;
            // frontNode.second = j;

            for(auto &dir: directions){
                int i_ = frontNode.first + dir[0];
                int j_ = frontNode.second + dir[1];
            

                if( (i_<0) || (j_<0)  ||  (i_>=m) || (j_>=n)  ||  (grid[i_][j_] == 0) ){
                    perimeter++;
                }
                else if(grid[i_][j_] == -1){
                    continue;
                }
                else{
                    q.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //traverse through grid
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){

                if(grid[i][j] == 1){
                    return bfsTraverse(grid,m,n, i, j);
                }
            }
        }
        return -1;
    }
};

