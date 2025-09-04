// User function Template for C++

class Solution {
  public:
    void solve(stack<int>& st, int x){
         
        
        //base case
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        
        //rr
        solve(st, x);
        
        //backtrack
        st.push(temp);
    }
    
    stack<int> insertAtBottom(stack<int> st, int x) {
        
    solve(st, x);
    return st;
    }
};