class Solution {
public:
    vector<vector<int>> pal;
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
    vector<vector<string>> helper(string&s, int st){
        if(st == s.size()) return {{}};
        vector<vector<string>> res;
        for(int i=st;i<s.size();i++){
            if(isPal(s,st,i)){
                vector<vector<string>> sub = helper(s, i+1);
                for(auto &v:sub) v.insert(v.begin(), s.substr(st, i-st+1));
                res.insert(res.end(), sub.begin(), sub.end());
            }
        }
        return res;
    }
    vector<vector<string>> partition(string s) {
        pal = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return helper(s,0);
    }
};
