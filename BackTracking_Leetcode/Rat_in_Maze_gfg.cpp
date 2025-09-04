class Solution {
  public:
    bool isSafe(vector<vector<int>> &maze, int row, int col, int i, int j, vector<vector<bool>> &visited){
        // 3 conditions
        if((i>=0 && i< row)  && (j>=0 && j<col)
                            &&
                    (maze[i][j] == 1)
                            &&
                (visited[i][j] == false)            ){
            return true;        
                }
        else{
            return false;
        }        
                
    }
  
    void solveMaze(vector<vector<int> >& maze, int row, int col, int i, int j, string output, vector<string> &ans, vector<vector<bool> >&visited){
        //base case
        if(i == row-1 && j == col-1){
            ans.push_back(output);
            return;
        }
        
        //case 1 -- Down
        if(isSafe(maze, row, col, i+1, j, visited )){
            visited[i+1][j] = true;
            //rr
            solveMaze(maze, row, col, i+1, j, output+"D", ans, visited);
            //bactrack
            visited[i+1][j] = false;
            
        }
        
        //case 2 -- Up
        if(isSafe(maze, row, col, i-1, j, visited )){
            visited[i-1][j] = true;
            //rr
            solveMaze(maze, row, col, i-1, j, output+"U", ans, visited);
            //bactrack
            visited[i-1][j] = false;
            
        }
        //case 2 -- Right
        if(isSafe(maze, row, col, i, j+1, visited )){
            visited[i][j+1] = true;
            //rr
            solveMaze(maze, row, col, i, j+1, output+"R", ans, visited);
            //bactrack
            visited[i][j+1] = false;
            
        }
        //case 4 -- Left
        if(isSafe(maze, row, col, i, j-1, visited )){
            visited[i][j-1] = true;
            //rr
            solveMaze(maze, row, col, i, j-1, output+"L", ans, visited);
            //bactrack
            visited[i][j-1] = false;
            
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        int row =maze.size();
        int col = maze[0].size();
        
        //visited ds
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        vector<string> ans;
        string output= "";
        
        //mark the source first
        if(maze[0][0] == 1){
            visited[0][0] = true;
            solveMaze(maze, row, col, 0, 0, output, ans, visited);
        }
        
        //for lexicographical smallest order
        sort(ans.begin(), ans.end());
        return ans;
    }
};