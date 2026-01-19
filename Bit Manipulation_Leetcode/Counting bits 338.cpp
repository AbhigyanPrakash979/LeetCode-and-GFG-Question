//Approach-2 - 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        
        if(n == 0)
            return result;
        
        result[1] = 1;
        
        for(int i = 2; i < n+1; i++) {
            
            if(i%2 == 0) {  // Agar even hai toh
                result[i] = result[i/2];
            } 
            else {  // agar odd hai toh bss 1 aur add krna hai
                result[i] = result[i/2] + 1;
            }
        }
        return result;
        
    }
};


// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> result(n+1);
        
//         for(int i = 0; i<n+1; i++) {
//             result[i] = __builtin_popcount(i); //log(n)
//         }
        
//         return result;
//     }
// };