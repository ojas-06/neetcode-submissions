using pdi = pair<double,int>; 

class Solution {
public:
    double dist(vector<int>& v){
        return sqrt(v[0]*v[0] + v[1]*v[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pdi> pq;
        for(int i=0;i<points.size();i++){
            pq.push({dist(points[i]) , i});
            if(pq.size() == k+1) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            res.push_back(points[p.second]);
        }
        return res;
    }
};
