class compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        int distA = a[0]*a[0] + a[1]*a[1];
        int distB = b[0]*b[0] + b[1]*b[1];
        // For min-heap: return true if A is farther than B
        return distA > distB;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap with custom comparator
        priority_queue<vector<int>, vector<vector<int>>, compare> minHeap;

        for (auto& point : points) {
            minHeap.push(point);
        }

        vector<vector<int>> result;
        // Extract k closest points
        if(!minHeap.empty()){
            for (int i = 0; i < k; i++) {
                result.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        return result;
    }
};