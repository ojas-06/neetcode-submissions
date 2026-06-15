class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1) {
            vector<string> s = {"()"};
            return s;
        }
        vector<string> sub = generateParenthesis(n-1);
        unordered_set<string> res;
        for(string &s:sub){
            stack<char> st;
            vector<int> matID;
            for(int i=0; i<s.size();i++){
                if(st.empty()) matID.push_back(i);
                if(s[i] == '(') st.push('(');
                else st.pop();
            }
            matID.push_back(s.size());

            for(int i=0;i<matID.size();i++){
                for(int j=i;j<matID.size();j++){
                    res.insert(s.substr(0, matID[i]) + "(" + s.substr(matID[i], matID[j]-matID[i]) + ")" + s.substr(matID[j]));
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
