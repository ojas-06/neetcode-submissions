/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){

        //     return a.start < b.start;
        // });
        vector<pair<int,int>> v;
        for(auto &i:intervals){
            v.push_back({i.start, 0});
            v.push_back({i.end, 1});
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        int curr = 0;
        int mx = 0;
        for(auto &p: v){
            if(!p.second) curr++;
            else curr--;
            mx = max(mx, curr);
        }
        return mx;
        
    }
};
