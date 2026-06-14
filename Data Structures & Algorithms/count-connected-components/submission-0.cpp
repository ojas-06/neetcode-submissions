class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto&e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int comp = 0;
        vector<bool> visited(n+1, false);

        queue<int> q;

        for(int i=0;i<n;i++){
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                comp++;

                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for(int nbs:graph[x]){
                        if(!visited[nbs]){
                            visited[nbs] = true;
                            q.push(nbs);
                        }
                    }
                }
            }
        }
        return comp;


    }
};
