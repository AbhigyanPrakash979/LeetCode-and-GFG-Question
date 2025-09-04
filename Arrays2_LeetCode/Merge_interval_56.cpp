class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeAns;
        if (intervals.empty())
        return mergeAns;

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Merge
        mergeAns.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= mergeAns.back()[1]) {
                // Overlapping
                mergeAns.back()[1] = max(mergeAns.back()[1], intervals[i][1]);
            } else {
                // No overlap: simply add it
                mergeAns.push_back(intervals[i]);
            }
        }
        return mergeAns;
    }
};
