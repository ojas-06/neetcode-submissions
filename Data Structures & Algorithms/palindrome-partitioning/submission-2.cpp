class Solution {
public:
    vector<vector<int>> pal;
    vector<vector<string>> res;
    int isPal(string& s, int i , int j){
        if(i>j || j>=s.size()) return 0;
        if(pal[i][j] != -1) return pal[i][j];
        while(i<j){
            if(s[i] != s[j]) return pal[i][j] = 0;
            i++;
            j--;
        }
        return pal[i][j] = 1;
    }
    void helper(string&s, int st, vector<string>& v){
        if(st == s.size()) {
            res.push_back(v);
            return;
        }
        for(int i=st;i<s.size();i++){
            if(isPal(s,st,i)){
                v.push_back(s.substr(st, i-st+1));
                helper(s,i+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        pal = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        vector<string> v;
        helper(s,0,v);
        return res;
    }
};
