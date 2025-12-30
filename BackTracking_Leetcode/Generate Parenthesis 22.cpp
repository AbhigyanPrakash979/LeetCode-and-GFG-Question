class Solution {
public:

    void solve(vector<string> &ans, int open, int close, string output){

        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }

        // include
        if(open>0){
            output = output + "(";
            //RR
            solve(ans, open-1, close, output);
            //BT
            output.pop_back();
        }

        //exclude
        if(close> open){
            output = output + ")";
            //RR
            solve(ans, open, close-1, output);
            //BT
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        int open = n;
        int close = n;
        string output ="";
        vector<string> ans;

        // calling the function
        solve(ans, open, close, output);
        return ans;

    }
};