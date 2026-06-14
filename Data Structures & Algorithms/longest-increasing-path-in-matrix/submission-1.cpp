class Solution {
public:
int m,n;
    vector<pair<int,int>> nbs(int i,int j,int m,int n){
        vector<pair<int,int>> res;
        if(i>0) res.push_back({i-1,j});
        if(j<n-1) res.push_back({i,j+1});
        if(i<m-1) res.push_back({i+1,j});
        if(j>0) res.push_back({i,j-1});
        return res;
    }
    int eval(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if(dp[i][j] > 0) return dp[i][j];
        dp[i][j] = -1;
        for(auto &[x,y]: nbs(i,j,m,n)){
            if(matrix[x][y] <= matrix[i][j]) continue;
            if(dp[x][y] == -1) continue;
            if(dp[x][y] == 0) {
                dp[x][y] = eval(matrix,dp,x,y);
            }
            dp[i][j] = max(dp[i][j], 1+dp[x][y]);
        }
        dp[i][j] = max(dp[i][j], 1);
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int lp = 1;
        vector<vector<int>> dp(m,vector<int>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(dp[i][j] == 0) dp[i][j] = eval(matrix,dp,i,j);
                lp = max(lp, dp[i][j]);
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j = 0;j<n;j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return lp;
    }
};
