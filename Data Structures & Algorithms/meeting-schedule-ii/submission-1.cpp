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
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){

            return a.start < b.start;
        });
        if(intervals.empty()) return 0;
        int ans = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<intervals.size(); i++){
            if(pq.empty()){
                pq.push(intervals[i].end);
                continue;
            }
            if(intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
