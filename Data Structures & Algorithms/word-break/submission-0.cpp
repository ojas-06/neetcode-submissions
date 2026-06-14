class Solution {
public:
unordered_set<string> st;
vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict, bool init = true, int index = 0) {
        if(index == s.size()) return true;
        if(init) {
            st = unordered_set<string>(wordDict.begin(), wordDict.end());
            dp = vector<int>(s.size(), -1);
        }
        if(dp[index] == 1) return true;
        else if( dp[index] == 0) return false;
        for(int i=1; i<=s.size()-index;i++){
            if(st.find(s.substr(index, i)) != st.end() && wordBreak(s,wordDict, false, index + i)) {dp[index] = 1; return true;}
        }
        dp[index] = 0;
        return false;
    }
};
