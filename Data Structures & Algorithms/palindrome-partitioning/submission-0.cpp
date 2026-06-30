class Solution {
public:
    bool isPal(string& s, int i , int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s, int st = 0) {
        if(st == s.size()) return {{}};
        // if(st == s.size()-1) return {{string(1,)}};
        vector<vector<string>> res;
        for(int i=st;i<s.size();i++){
            if(isPal(s,st,i)){
                vector<vector<string>> sub = partition(s, i+1);
                for(auto &v:sub) v.insert(v.begin(), s.substr(st, i-st+1));
                res.insert(res.end(), sub.begin(), sub.end());
            }
        }
        return res;
    }
};
