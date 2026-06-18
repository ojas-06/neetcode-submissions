class Solution {
public:
    int res = 0;
    void find_and_replace(vector<int>& lis, int k){
        int lo = 0, hi = lis.size()-1;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(lis[mid] < k) lo = mid+1;
            else hi = mid;
        }
        lis[lo] = k;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0;i<nums.size();i++){
            if(lis.empty() || nums[i] > lis.back()){
                res++;
                lis.push_back(nums[i]);
            }
            else{
                find_and_replace(lis,nums[i]);
            }
        }
        return res;
    }
};
