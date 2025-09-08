// IMPPPPPPPPPPPPPPPPPPPPPPPPPPPP


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // IMPP

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};



// If we use regular sort, it will be O(n log n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // Sort in descending order
        return nums[k - 1]; // k-th largest is at index k-1
    }
};
