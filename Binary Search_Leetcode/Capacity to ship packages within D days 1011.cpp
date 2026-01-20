
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int minCap = 0;
        int maxCap = 0;

        // Find the minimum and maximum possible capacity
        for (int i = 0; i < weights.size(); i++) {
            minCap = max(minCap, weights[i]); // sbse bdde box ki value
            maxCap += weights[i];             // saare boxes ka sum
        }

        // Binary search for the minimum capacity
        while (minCap < maxCap) {
            int mid = minCap + (maxCap - minCap) / 2;

            int days = 1;
            int sum = 0;

            // Try shipping with capacity = mid
            for (int i = 0; i < weights.size(); i++) {
                if (sum + weights[i] > mid) { // pehele condition hogi har baar tabhi enter krenge
                    days++;      // need one more day
                    sum = 0;     // reset sum for next day
                }
                sum += weights[i];
            }

            // If more days are needed, increase capacity
            if (days > D) {
                minCap = mid + 1;
            } else {
                maxCap = mid;
            }
        }

        return maxCap;
    }
};