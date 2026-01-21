class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    int leftProduct = 1;
    int rightProduct = 1;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        // Reset products if zero is encountered
        if (leftProduct == 0) { // Agar mera leftproduct 0 aaye toh usse 1 bnana hai
            leftProduct = 1;
        }
        if (rightProduct == 0) {// Agar mera rightproduct 0 aaye toh usse 1 bnana hai
            rightProduct = 1;
        }

        // Prefix product
        leftProduct *= nums[i]; //left se start krro

        // Suffix product
        rightProduct *= nums[n - 1 - i];// right se start krro

        ans = max(ans, max(leftProduct, rightProduct));
    }
    return ans; 
    }
};