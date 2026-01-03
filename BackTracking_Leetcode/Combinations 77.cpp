class Solution {
public:
    void solve(int n, int k, int i, vector<int>& output, vector<vector<int>>& ans) {
        // base case: if combination size reached k
        if (output.size() == k ) {
            ans.push_back(output);
            return;
        }
        // if index exceeds n
        if (i > n) return;

        // include vala  case
        output.push_back(i); /// IMPORTANT
        solve(n, k, i+1, output, ans);
        output.pop_back();

        // exclude vala case
        solve(n, k, i+1, output, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(n, k, 1, output, ans);
        return ans;
    }
};