#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st; // set to track visited numbers

        while (true) {
            int sum = 0;

            // Step 1: digits ke square ka sum nikalte hain
            while (n != 0) {
                int digit = n % 10;
                sum += digit * digit; // Math.pow ka C++ version
                n = n / 10;
            }

            // Step 2: agar sum == 1 hai → happy number
            if (sum == 1) 
            return true;

            // Step 3: agar sum already visited hai → cycle aa gayi → not happy
            if (st.count(sum)){
                return false;
            }
            else{
                // Step 4: sum ko set mein daal do aur n ko update karo
                st.insert(sum);
                n = sum;
            }
            
        }
    }
};