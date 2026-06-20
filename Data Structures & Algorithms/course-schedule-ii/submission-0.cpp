class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        for(auto& v:prerequisites) {
            graph[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();

            inDegree[x] = -1;
            res.push_back(x);
            for(int nb:graph[x]){
                inDegree[nb]--;
                if(!inDegree[nb]) q.push(nb);
            }
        }
        if(res.size() != numCourses) return {};
        return res;


    }
};
