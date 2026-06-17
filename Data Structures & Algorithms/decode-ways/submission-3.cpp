class Solution {
public:
vector<int> dp;
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1){
            if(s[0] == '0') return 0;
            return 1;
        }
        dp = vector<int>(s.size(), 0);

        if(s[n-1] != '0') dp[n-1] = 1;
        if(s[n-2] == '0') dp[n-2] = 0;
        else if((s[n-2] == '1' || (s[n-2] == '2' && s[n-1] <= '6')) && s[n-1] > '0') dp[n-2] = 2;
        else dp[n-2] = 1;

        for(int i = n-3;i>=0;i--){
            if(s[i] == '0') dp[i] = 0;
            else if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                if(s[i+1] > '0') dp[i] = dp[i+1]+dp[i+2];
                else dp[i] = dp[i+2];    
            }

            
            else dp[i] = dp[i+1];
        }
        return dp[0];
    }
};
