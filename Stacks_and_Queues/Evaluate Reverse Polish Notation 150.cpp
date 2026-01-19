class Solution {
public:
    int operate(int &a, int &b, string &s) {
        if(s == "+")
            return a+b;
        
        if(s == "-")
            return a-b;
        
        if(s == "*")
            return (long)a*(long)b; // kyunki multiply krke range se bahr jaa skta hai
        
        if(s == "/")
            return a/b;
        
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int result = 0;

        for(string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {

                int b = st.top();   // b pehle isliyr liya kyunki stack mein push kr rhe hain
                st.pop();
                int a = st.top();
                st.pop();
                
                result = operate(a, b, s);
                st.push(result);
            } 
            else {  // mtlab string vala number hai
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};