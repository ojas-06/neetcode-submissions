class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& reached, int i){
        for(int nb:graph[i]){
            if(!reached[nb]){
                reached[nb] = true;
                dfs(graph, reached, nb);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<bool> reached(n, false);
        reached[0] = true;
        vector<vector<int>> graph(n);
        for(auto&e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(graph, reached, 0);
        for(int i=0;i<n;i++){
            if(!reached[i]) return false;
        }
        return true;
    }
};
