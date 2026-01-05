class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
        return x;   // base cases

        int start = 1;
        int end = x;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // To avoid overflow, compare mid with x/mid instead of mid*mid
            if (mid == x / mid) {
                return mid;               // perfect square
            } 
            else if (mid < x / mid) {    // kyunki floor value btani hai
                ans = mid;                // mid is a candidate
                start = mid + 1;          // go right
            } 
            else {
                end = mid - 1;            // go left
            }
        }
        return ans; // floor of sqrt(x)
    }
};