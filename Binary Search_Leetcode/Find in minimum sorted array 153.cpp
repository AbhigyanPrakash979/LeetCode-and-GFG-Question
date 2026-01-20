class Solution {
public:
    int findPivot(vector<int>& nums) {
        int mid;
        int l = 0;
        int r = nums.size()-1;
        while(l < r) {  // hum jaan buch kr l<=r nhi le rhe kyunki agar liya toh loop mein fss jayenge
                        // kyunki mid bhi vahi point krega aur right bhi
            mid = l + (r-l)/2;
          
            if(nums[mid] > nums[r]) { //mtlab right mein bdda hona chaheye tha, lekin hai chotta
                l = mid+1;            //mid ko isliye nhi liya kyunki voh toh already sorted way mein bdda hai
            } 
            else {
                r = mid;   // yeh hai important // chances hai ki mid miss hojaye
                // because yeh nhi answerho skta hai
            }
        }
        return nums[l]; // we can also return nums[r] here as l==r at end of loop
    }
    
    int findMin(vector<int>& nums) {
        return findPivot(nums);
    }
};