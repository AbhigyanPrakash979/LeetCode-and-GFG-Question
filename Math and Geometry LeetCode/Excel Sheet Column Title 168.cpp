#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {

            columnNumber--; // adjust for 1-based indexing
            int remainder = columnNumber % 26;
            char ch = remainder + 'A' ; // convert remainder to char
            result.push_back(ch);
            columnNumber = columnNumber / 26;
        }
        reverse(result.begin(), result.end()); // reverse the string
        return result;
    }
};