class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            // agar alphanumeric nhi hai toh simple left aage badha do
            if (!isalnum(s[left])) {
                left++;
            }
            // agar alphanumeric nhi hai toh simple right piche krdo
            else if (!isalnum(s[right])) {
                right--;
            }
            // phir agar upper hai toh lower case krdo
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } 
            //  normal flow
            else {
                left++;
                right--;
            }
        }
        return true;
    }
            
};