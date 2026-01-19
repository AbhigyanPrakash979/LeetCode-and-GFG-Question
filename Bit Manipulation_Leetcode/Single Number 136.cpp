class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int &num : nums) {
            result ^= num;   // XOR krdo sbka
        }
        return result;       // sirf vahi bachega jo  duplicate nhi hoga
    }
};