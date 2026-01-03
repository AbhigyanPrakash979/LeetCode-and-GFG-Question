class Solution {
public:
    vector<vector<int> > result;
    void solve(vector<int> &nums, int index){
        //base case
        if(index>= nums.size()){
            result.push_back(nums);
            return;
        }

        //rr
        for(int j =index; j<nums.size(); j++){
            swap(nums[index], nums[j]);

            solve(nums, index+1);
        
            // backtrack
            swap(nums[index], nums[j]);
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        solve(nums, index);
        return result;
    }
};