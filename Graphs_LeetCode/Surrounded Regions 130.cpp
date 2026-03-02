class Solution {
public:
    
    void convert(vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'B'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    bool isValid(int i , int j, int m, int n, vector<vector<char>>& board){
        if(i>=0 && i<m && j>=0 && j<n && board[i][j] == 'O'){
            return true;
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& board, int i , int j, int m, int n){
        //sbse pehle 'B' set krdo
        board[i][j] = 'B';
        
        if(isValid(i+1, j, m, n, board)){
            dfs(board, i+1, j, m, n);
        }
        if(isValid(i-1, j, m, n, board)){
            dfs(board, i-1, j, m, n);
        }
        if(isValid(i, j+1, m, n, board)){
            dfs(board, i, j+1, m, n);
        }
        if(isValid(i, j-1, m, n, board)){
            dfs(board, i, j-1, m, n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // humlog boundary se andar ki taraf jaa rhe hai
        for(int i=0; i<m; i++){
            
            // topmost row
            int j =0;
            if(board[i][j] == 'O'){
                dfs(board, i, j, m, n);
            }
            
            j = n-1;
            // bottom most row
            if(board[i][j] == 'O'){
                dfs(board, i, j, m, n);
            }
        }
        
        for(int j=0; j<n; j++){
            
            //leftmost column
            int i =0;
            if(board[i][j] == 'O'){
                dfs(board, i, j, m, n);
            }
            
            i = m-1;
            //rightmost column
            if(board[i][j] == 'O'){
                dfs(board, i, j, m, n);
            }
        }
        
        convert(board);
    }
};