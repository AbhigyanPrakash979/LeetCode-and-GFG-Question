class Solution{
    public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLength = 0;
        for(int i =0; i<s.length(); i++){
            char ch = s[i];

            // if i get the opening bracket
            if(ch == '('){
                st.push(i);
            }
            // if i get the closing bracket
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxLength = max(len, maxLength);
                }
            }
        }
        return maxLength;
    }
};
