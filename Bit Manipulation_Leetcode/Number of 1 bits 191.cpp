class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        for(int i = 31; i>=0; i--) {
            if(((n >> i) & 1) == 1) {
                count++;
            }
        }
        return count;
    }
};

// // Approach 2 
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
        
//         while(n>0) {
//             n = (n&(n-1)); //This expression is used to turn off the rightmost set bit in n. 
//             count++;
//         }
//         return count;
//     }
// };

// // Approach 3
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
        
//         while(n>0) {
//             count += (n%2);
//             n /= 2;
//         }
        
//         return count;
//     }
// };


