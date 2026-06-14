class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int start = 0, end = k-1;
        for(int i = 0;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int> res;
        res.push_back(pq.top().first);
        for(int i = k;i<nums.size();i++){
            start++;
            end++;
            pq.push({nums[i], i});
            while(pq.top().second < start) pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};
