class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st;
        for(int i =0; i<s.length(); i++){
            char ch = s[i];

            //check for condition whether open or closed bracket
            if(ch == '{' || ch == '(' || ch == '['){
                st.push(ch);
            }
            else{
                if(!st.empty())
                {
                
                    int topElement = st.top();
                    // mtlab closed bracket hai
                    // aur top element open bracket

                    if(ch == ')' && topElement == '('){
                    st.pop();
                    }
                    else if (ch == '}' && topElement == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && topElement == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
                
            }
        }
         // check whether stack id empty or not
            if(st.empty()){
                return true;
            }
            else{
                return false;
            }
        
    }
};