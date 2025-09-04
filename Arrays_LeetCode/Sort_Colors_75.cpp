class Solution {
public:
    void solve(vector<int> &nums , int n){
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;

        for(int i =0; i<n; i++){
            if (nums[i] == 0){
                countZero++;
            }
            if(nums[i] == 1){
                countOne++;
            }
            if(nums[i] == 2){
                countTwo++;
            }
        }
        int i =0;
        while(countZero--){
            nums[i] = 0;
            i++;
        }
        while(countOne--){
            nums[i] = 1;
            i++;
        }
        while(countTwo--){
            nums[i] = 2;
            i++;
        }
        return;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        solve(nums, n);
    }
};