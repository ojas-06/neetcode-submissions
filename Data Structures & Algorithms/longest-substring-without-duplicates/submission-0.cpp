class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        vector<int> seen(128,-1);
        int lo=0,hi=0;
        int ans = 1;

        while(hi <= s.size()){
            if(hi == s.size()) {
                ans = max(ans,hi-lo);
                break;
            }
            if(seen[s[hi]] < lo){
                seen[s[hi]] = hi;
                hi++;
            }
            else{
                ans = max(ans, hi-lo);
                lo = seen[s[hi]]+1;
                seen[s[hi]] = hi;
                hi++;
            }
        }
        return ans;
    }
};
