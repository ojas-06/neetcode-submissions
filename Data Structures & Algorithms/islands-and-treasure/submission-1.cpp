class Solution {
public:
int m, n;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[i][j] == 0) q.push({i,j});
        }

        int level = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto [x,y] = q.front();
                q.pop();
                grid[x][y] = min(grid[x][y], level);
                if(x>0 && grid[x-1][y] == INT_MAX) q.push({x-1,y});
                if(y<n-1 && grid[x][y+1] == INT_MAX) q.push({x,y+1});
                if(x<m-1 && grid[x+1][y] == INT_MAX) q.push({x+1,y});
                if(y>0 && grid[x][y-1] == INT_MAX) q.push({x,y-1});
            }
            level++;
        }
    }
};
