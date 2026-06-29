class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto&e:times){
            graph[e[0]].push_back({e[2], e[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, k});

        vector<int> reach(n+1, INT_MAX);
        reach[k] = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int src = p[1], t = p[0];
            if(t > reach[src]) continue;

            for(auto &e:graph[src]){
                if(t+e.first < reach[e.second]){
                    reach[e.second] = t+e.first;
                    pq.push({reach[e.second], e.second});
                }
            }
        }
        int max_time = 0;
        for(int i=1;i<=n;i++){
            if(reach[i] == INT_MAX) return -1;
            max_time = max(max_time, reach[i]);
        }
        return max_time;
    }
};
