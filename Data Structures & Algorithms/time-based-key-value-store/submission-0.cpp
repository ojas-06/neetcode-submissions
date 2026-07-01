class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>> st;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        st[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!st.count(key) || st[key][0].first > timestamp) return "";
        auto &v = st[key];
        int lo = 0, hi = v.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid].first > timestamp) hi = mid-1;
            else{
                if(lo == mid){
                    if(v[hi].first <= timestamp) return v[hi].second;
                    return v[lo].second;
                }
                lo = mid;
            }
        }
    }
};
