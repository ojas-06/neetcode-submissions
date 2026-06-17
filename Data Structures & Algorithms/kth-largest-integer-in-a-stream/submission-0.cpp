class KthLargest {
public:
int k;
priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<k && i<nums.size();i++) pq.push(nums[i]);
        for(int i = k;i<nums.size();i++){
            pq.push(nums[i]);
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k) pq.pop();
        return pq.top();
    }
};
