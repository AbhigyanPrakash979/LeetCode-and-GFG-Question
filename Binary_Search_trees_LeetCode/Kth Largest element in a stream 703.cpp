class KthLargest {
public:
// using Min Heap
//Because it stores Min element a the top
priority_queue<int, vector<int>, greater<int>> pq;
int K;

    KthLargest(int k, vector<int>& nums) {
        K = k; // when an array is passed the pointer is passed
        for(int num : nums){
            pq.push(num);

            //check for condition ki agar pq ka size k se jyaada na hojaye
            if(pq.size()> k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {

        //simply pushing data
        pq.push(val);

        if(pq.size()> K){
            pq.pop();
        
        }
        
         return pq.top();

        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */