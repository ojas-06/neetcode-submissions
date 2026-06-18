class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(), [](const vector<int>& a,const vector<int>& b ) {
            if(a[1]!=b[1]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int ans = 0;
        int last_end = in[0][1];
        for(int i=1;i<in.size();i++){
            if(in[i][0] < last_end) ans++;
            else last_end = in[i][1];
        }
        return ans;
    }   
};
