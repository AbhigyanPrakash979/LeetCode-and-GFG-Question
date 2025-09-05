class Solution {
public:
    void solve(vector<vector<int>>& matrix, int n){
        //in place transposition
        for(int i =0; i<n; i++){
            for(int j= i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse the matrix column wise
        for(int i=0; i<n; i++){
            int left =0;
            int right = n-1;
            while(left<right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
        return;
    }

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        return solve( matrix, n);
    }
};