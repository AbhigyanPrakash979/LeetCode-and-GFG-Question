
//Method 1
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // manual swap using a temp variable
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;

            start++;
            end--;
        }
    }
};

// Method 2
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int start =0;
//         int end = s.size()-1;

//         while(start<end)
//         {
//             swap (s[start++], s[end--]);
//         }
        
        
//     }
// };