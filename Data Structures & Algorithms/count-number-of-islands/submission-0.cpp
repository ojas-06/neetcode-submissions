class Solution {
public:
    // vector<pair<int,int>> get_neighbours(int i,int j,int m, int n){
    //     vector<pair<int,int>> nbs;
    //     if(i>0) nbs.push_back({i-1,j});
    //     if(j<n-1) nbs.push_back({i,j+1});
    //     if(i<m-1) nbs.push_back({i+1,j});
    //     if(j>0) nbs.push_back({i,j-1});
    //     return nbs;
    // }
    void DFS(vector<vector<char>>& grid, int i,int j, int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != '1') return;
        //visited[i][j]=true;
        grid[i][j] = '0';
        //vector<pair<int,int>> nbs = get_neighbours(i,j,grid.size(),grid[0].size());
        // for(auto nb : nbs){
        //     if(grid[nb.first][nb.second] == '1' && !visited[nb.first][nb.second]){
        //         DFS(grid,nb.first,nb.second,visited);
        //     }
        // }
        DFS(grid, i-1, j,m,n);
        DFS(grid, i+1, j,m,n);
        DFS(grid, i, j-1,m,n);
        DFS(grid, i, j+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1') {
                    count++;
                    DFS(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};