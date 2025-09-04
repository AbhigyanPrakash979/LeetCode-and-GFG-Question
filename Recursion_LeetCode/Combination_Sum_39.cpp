class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& output, vector<vector<int>>& ans){
        //base case
        if(target ==0){
            ans.push_back(output);
            return;
        }

        if(target<0 || i >= candidates.size())
        return;

        //include vala case
        output.push_back(candidates[i]);
        solve(candidates, target-candidates[i], i, output, ans);
        //backtrack
        output.pop_back();

        //exclude avla case
        solve(candidates, target, i+1, output, ans);

    }   

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int i =0;
        vector<vector<int> > ans;
        vector<int> output;

        vector<vector<int>> finalAns;
        solve(candidates, target, i, output, ans);
        return ans;
        
    }
};