class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;

        // handle k greater than n
        k = k % n;
        if(k == 0) return; // no rotation needed

        // first reverse whole array
        int left = 0, right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        // then reverse first k elements
        left = 0; right = k-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        // finally reverse remaining n-k elements
        left = k; right = n-1;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};