class Solution {
public:

    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j) {
    while(i < j) {
        if(nums[i] + nums[j] > target)
            j--;
        else if(nums[i] + nums[j] < target)
            i++;
        else {
            // first we will remove duplicates from either end (i, j)
            //mtlab yahi answer hai
            //lekin usse pehle check krro ki i ke aage aur j se pehle koi same element toh nhi hai
            while(i < j && nums[i] == nums[i+1]){
                i++;
            }
            while(i < j && nums[j] == nums[j-1]){
                j--;
            } 

            result.push_back({-target, nums[i], nums[j]});
            i++;
            j--;
        }
    }
}
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        if(n < 3) //Mtlab 3 se kam elements hai
            return {};
        

        result.clear();

        // Phir sort krdiya
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size()-2; i++) {  //(i<nums.size()-2) because we need at least 2 elements after i for 3Sum
            if(i!= 0 && nums[i] == nums[i-1]) { //T agr i =0 hai aur i-1 check kkre toh negetive hojayega
                continue;  // iss vale ko skip krna pdega
            }
            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i+1, n-1);
        }
        return result;
    }
};
