class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' ||s[i] == '[' ) st.push(s[i]);
            else{
                if(!st.size()) return false;
                if(s[i] == ')' && st.top() != '(') return false;
                if(s[i] == '}' && st.top() != '{') return false;
                if(s[i] == ']' && st.top() != '[') return false;
                else st.pop();
            }
        }
        if(!st.size()) return true;
        return false;
    }
};
