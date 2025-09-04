class Solution {
public:
    unordered_map<int, bool>leftCheck;
    unordered_map<int, bool>UpperLeftDiagonalCheck;
    unordered_map<int, bool>BottomLeftDiagonalCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans){
        //har ek row ko string mein convert krna hai 
        // phir ans mein usko insert krna hai

        ///Important
        vector<string> temp;
        for(int i=0; i<n; i++){
            string output = "";
            for(int j=0; j<n; j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(vector<vector<char>> board, int row, int col, int n){

        if(leftCheck[row] == true){
        return false;
        }

        if(UpperLeftDiagonalCheck[n-1+row-col] == true){
        return false;
        }

        if(BottomLeftDiagonalCheck[row+col] == true){
        return false;
        } 

        return true;
    }

    void solve(vector<vector<char>> &board, int n, int col, vector<vector<string>> &ans){
        //base case
        if(col>=n){
            storeSolution(board, n, ans);
            return;
        }

        //check for every row and col
        for(int row =0; row<n; row++){
            
            if(isSafe(board, row, col, n)){

                //mark Q
                board[row][col] = 'Q';
                leftCheck[row] = true;
                UpperLeftDiagonalCheck[n-1+row-col] = true;
                BottomLeftDiagonalCheck[row+col] = true;

                // rr
                solve(board, n, col+1, ans);

                //backtracking everything
                board[row][col] = '.';
                leftCheck[row] = false;
                UpperLeftDiagonalCheck[n-1+row-col] = false;
                BottomLeftDiagonalCheck[row+col] = false;

            }
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col =0;
        solve(board, n, col, ans);
        return ans;
    }
};

