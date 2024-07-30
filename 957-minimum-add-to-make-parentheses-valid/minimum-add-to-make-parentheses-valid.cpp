class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int c =0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    c++;
                }
            }
        }
        c+=st.size();
        return c;
    }
};