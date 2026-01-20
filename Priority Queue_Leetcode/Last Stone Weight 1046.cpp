//Approach-2 (Using Heap)- TC : (nlog(n))
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq; //max-heap  // kyunki upar max chaheye smash krne ke liye a and b
        for(int &stone: stones)
        {
            pq.push(stone);
        }
            
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            // ab a aur b ka abs minus insert krdo
            pq.push(abs(a-b));
        }
        
            return pq.top();
    }
};


// //Approach-1 (Brute Force TC : (n^2 * log(n))
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
        
//         while(stones.size()>1) // kyunki hum ek eke krke kam kr rhe hain
//         {
//             sort(stones.begin(),stones.end());  // ab jab end mein push kr rhe hain toh, sort bhi phirse krna pdega
            
//             int a = stones.back(); stones.pop_back();
//             int b = stones.back(); stones.pop_back();

//             stones.push_back(abs(a-b));
//         }
//         return stones[0];
//     }     
// };