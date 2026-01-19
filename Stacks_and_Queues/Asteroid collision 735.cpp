class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.top() > 0) {   // yahan pr check ki collision hpga ki nhi
                // sum isliye nikal rhe hai taaki -ve aur +ve pta chale uss direction mein jaaye
                int sum = a + st.top();
                
                if(sum < 0) {   // Agar -ve aaya toh pop krna pdega
                    st.pop();   // pop krtein jayenge jab tak ho rha hai
                } 
                else if(sum > 0) {    // Agar +ve hua 
                    a = 0; // mtlab stack mein push nhi krna
                    break;
                }
                else {  // sum == 0
                    st.pop();
                    a = 0;  // mtlab stack mein push nhi krna
                }
            }
            
            if(a != 0)
                st.push(a);
            
        }
        
        int s = st.size();
        // stack mein the element isliye piche se insert krna shuru kiya
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};