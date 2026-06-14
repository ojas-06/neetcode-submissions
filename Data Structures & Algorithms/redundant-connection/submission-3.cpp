class DSU{
public:
// 0 1 2 3 4 5
// 0 1 1 3 1 5
    vector<int> d;
    DSU(int n){
        d.reserve(n);
        for(int i=0;i<n;i++) d.push_back(i);
    }
    int find(int n){
        if(d[n] == n) return n;
        d[n] = find(d[n]);
        return d[n];
    }
    void uni(int a,int b){
        int x = find(a), y = find(b);
        if(x < y) d[y] = x;
        else d[x] = y;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(auto &e:edges){
            n = max(n, max(e[0],e[1]));
        }
        DSU dsu(n+1);
        for(auto &e:edges){
            if(dsu.find(e[0]) == dsu.find(e[1])){
                return e;
            }
            dsu.uni(e[0],e[1]);
        }
        return {};
    }
};
