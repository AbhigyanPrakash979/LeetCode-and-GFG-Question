class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // making vector to store to the 2d vector 
        vector<vector<int> > ans;

        // for traversing num of rowa
        for (int i = 0; i<numRows; i++){
            // store in a vector
            vector<int> tempRow(i+1, 1);
            
            //j=1 se shuru 
            // because j = 0 pr aur last element toh already 1 hai
            for(int j=1; j<i; j++){
                tempRow[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(tempRow);
        }
        return ans;
    }
};