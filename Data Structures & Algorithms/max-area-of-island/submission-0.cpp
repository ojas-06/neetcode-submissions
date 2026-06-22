class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 0;
        int ans = 1;
        if(i>0 && grid[i-1][j]) ans += dfs(grid, i-1, j);
        if(j<grid[0].size()-1 && grid[i][j+1]) ans += dfs(grid, i, j+1);
        if(i< grid.size()-1 && grid[i+1][j]) ans += dfs(grid, i+1, j);
        if(j>0 && grid[i][j-1]) ans += dfs(grid, i, j-1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size(); j++){
                if(grid[i][j]) ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
