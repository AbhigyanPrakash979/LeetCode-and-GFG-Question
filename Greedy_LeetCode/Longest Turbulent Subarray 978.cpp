class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();
        if(n < 2) 
        return n;

        int up = 1, down = 1, maxLen = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                up = down + 1;
                down = 1;   // reset krdo 1 pr phirse
            } else if(arr[i] < arr[i-1]) {
                down = up + 1;
                up = 1;     // reset krdo 1 pr phirse
            } else {    // mtlab equal hai toh dono ko reset krdo
                up = down = 1;
            }
            maxLen = max(maxLen, max(up, down));
        }

        return maxLen;
    }
};