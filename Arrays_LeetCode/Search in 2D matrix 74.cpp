class Solution {
public:
    bool solve(vector<vector<int>>& matrix, int start, int end, int target, int col){
        //base case
        if(start>end){
            return false;
        }
        //cal mid
        int mid = start + (end - start) / 2;
        //I have to define row and col
        //Importantttttttttttttttttttttttttttttttttttttttttttttt
        int r = mid/col;
        int c = mid%col;

        //check for answer
        if(matrix[r][c] == target){
            return true;
        }

        //toh left mein jaao
        else if(target<matrix[r][c]){
           return solve(matrix, start, mid-1, target, col);
        }
        else {  /* (target> matrix[r][c])*/
           return solve(matrix, mid+1,end, target, col);
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        int start =0;
        int end = (row*col)-1;

        return solve(matrix, start, end, target, col);
    }
};