class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> rowCheck(row, false); // of size row and initialize with false
        vector<bool> colCheck(col, false);  // of size col and initialize with false

        //traverse and check for 0 and add to the vector 
        for(int i =0; i<row; i++){
            for(int j =0; j<col; j++){
                if(matrix[i][j] == 0){
                    //if zero found then store in respective vector
                    rowCheck[i] = true;
                    colCheck[j] = true;
                }
            }
        }

        // changing all rows to 0
        for(int i=0; i<row; i++){
            //uss corresponding vector pr true hai toh pure row ko 0 krdo
            if(rowCheck[i] == true){
                for(int j =0; j<col;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        // changing all cols to 0
        for(int j=0; j<col; j++){
            //uss corresponding vector pr true hai toh pure row ko 0 krdo
            if(colCheck[j] == true){
                for(int i =0; i<row; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};