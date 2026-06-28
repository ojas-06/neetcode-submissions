class Solution {
public:
int m,n;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& v, int i, int j){
        if(i>0){
            if(heights[i-1][j] >= heights[i][j] && !v[i-1][j]){
                v[i-1][j] = true;
                dfs(heights, v, i-1, j);
            }
        }
        if(j<n-1){
            if(heights[i][j+1] >= heights[i][j] && !v[i][j+1]){
                v[i][j+1]= true;
                dfs(heights, v, i, j+1);
            }
        }
        if(i<m-1){
            if(heights[i+1][j] >= heights[i][j] && !v[i+1][j]){
                v[i+1][j] = true;
                dfs(heights, v, i+1, j);
            }
        }
        if(j>0){
            if(heights[i][j-1] >= heights[i][j] && !v[i][j-1] ){
                v[i][j-1]  = true;
                dfs(heights, v, i, j-1);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n,false));
        vector<vector<bool>> atlantic(m, vector<bool>(n,false));

        for(int i=0;i<m;i++) {
            pacific[i][0] = true;
            atlantic[i][n-1] = true;
            dfs(heights, pacific, i,0);
            dfs(heights, atlantic, i,n-1);
        }
        for(int i= 0;i<n;i++){
            pacific[0][i] = true;
            atlantic[m-1][i] = true;
            dfs(heights, pacific, 0,i);
            dfs(heights, atlantic, m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
