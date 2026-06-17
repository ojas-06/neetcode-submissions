class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<n){
            vector<vector<int>> dp(m ,vector<int> (2));
            for(int i=0;i<m;i++) dp[i][0] = 1;
            for(int i = 0; i < n-1; i++){
                for(int j = m-2; j>=0 ;j--){
                    dp[j][1] = dp[j][0];
                    dp[j][0] = dp[j+1][0]+dp[j][1];
                }
            }
            return dp[0][0];
        }
        else{
            vector<vector<int>> dp(2 ,vector<int> (n));
            for(int i=0;i<n;i++) dp[0][i] = 1;
            for(int i = 0; i < m-1;i++){
                for(int j = n-2; j>=0 ;j--){
                    dp[1][j] = dp[0][j];
                    dp[0][j] = dp[0][j+1]+dp[1][j];
                }
            }
            return dp[0][0];
        }
    }
};
