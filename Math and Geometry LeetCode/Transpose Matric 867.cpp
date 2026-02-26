//Method 1 with SC: O(1) but will only run squared matrix

// class Solution {
// public:
//     vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//         int m = matrix.size(); 
//         int n = matrix[0].size();

//         // Diagonal ke across swap karna hai
//         for (int i = 0; i < m; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 // swap row-col elements
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         return matrix;
//     }
// };

// Method 2 with SC O(m*n)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();             
        int cols = matrix[0].size();           

        // Important: Result matrix banani hai with swapped dimensions kyunki transpose kr rhe hai
        vector<vector<int>> result(cols, vector<int>(rows));

        // Fill karna hai by swapping indices
        for (int i = 0; i < rows; i++) {       
            for (int j = 0; j < cols; j++) {   
                result[j][i] = matrix[i][j];   
            }
        }

        // Step 4: Result return kar do
        return result;
    }
};