class Solution {
public:
vector<vector<int>> dp;
    int find(string& s,string& t, int i, int j){
        if(i == s.size() && j<t.size()) return 0;
        if(j == t.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = find(s,t,i+1,j+1) + find(s,t,i+1,j);
        return dp[i][j] = find(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return find(s,t,0,0);
    }
};
