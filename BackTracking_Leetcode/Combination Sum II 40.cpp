
class Solution {
public:
    void solve(vector<int> &candidates, int target, int start , vector<int> &output, vector<vector<int> >&ans){

        //base case
        if(target == 0){
            ans.push_back(output);
            return;
        }


        for(int i =start; i<candidates.size(); i++){

            //skippping the duplicates
            if(i>start && candidates[i] == candidates[i-1])
            continue;

            if (candidates[i] > target) 
            break;
        
            // include vala case
            output.push_back(candidates[i]);
            solve(candidates, target- candidates[i], i+1, output, ans);
            //backtrack
            output.pop_back();


            // exclude vala case nhi run krna coz for loop ki vajah se next i mein aarhe hai already
            // //exclude vala case
            // solve(candidates, target, i+1, output, ans);

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end()); // sort krdo taaki saare duplicates serial wise aajaye
        int i =0;
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, i, output, ans);
        return ans;
    }
};