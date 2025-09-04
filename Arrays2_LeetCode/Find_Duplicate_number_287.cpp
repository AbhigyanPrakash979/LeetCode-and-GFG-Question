// method 2 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
            break;
        }
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];

        }
        return slow;
    }
};





// TLE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++){
            for(int j=i+1; j<n ; j++){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
                
            }
        }
            return {};
    }
};