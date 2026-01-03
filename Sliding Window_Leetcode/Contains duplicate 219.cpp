class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> st;
        int n = nums.size();
        int i =0;
        int j =0;

        //start the loop
        while(j<n){

            //Step 1: sirf k elements ko rakho
            if(abs(i-j)> k){
                //agar range se bahr jaa rha hai toh set se entry delete krdo
                st.erase(nums[i]);
                // uske baad aage badha do i ko
                i++;
            }

            // aur agar range mein hai toh check krro ki duplicate hai ki nhi
            if(st.find(nums[j]) != st.end()){
                return true;
            }
            //simple flow : aage badho
            st.insert(nums[j]);
            j++;
        }
        return false;
        
    }
};