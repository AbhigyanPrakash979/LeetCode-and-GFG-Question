class Solution {
public:

   void solve(vector<string> &ans, string output, int index, string digits,vector<string> mapping){

        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        // include
        int digit = digits[index] -'0';
        //find mapping ke correspondance value
        string value = mapping[digit];

        for(int i =0; i<value.length(); i++){
            char ch = value[i];

            //include krna
            output.push_back(ch);
            // recursive call
            solve(ans, output, index+1, digits, mapping);
            // backtracking
            output.pop_back();

        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        //handling an expectional case
        if(digits.length() ==0)
        return ans;

        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        int index = 0;
        string output ="";
        solve(ans, output, index, digits, mapping);
        return ans;

        
    }
};