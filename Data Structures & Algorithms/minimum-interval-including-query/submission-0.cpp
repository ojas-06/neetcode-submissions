class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,int> m;
        for(auto &in:intervals){
            for(int i=in[0];i<=in[1];i++){
                if(!m.count(i) || m[i] > in[1]-in[0]+1) 
                    m[i] = in[1]-in[0]+1;
            }
        }
        vector<int>res;
        for(int &i:queries){
            if(!m.count(i)) res.push_back(-1);
            else res.push_back(m[i]);
        }
        return res;
    }
};
