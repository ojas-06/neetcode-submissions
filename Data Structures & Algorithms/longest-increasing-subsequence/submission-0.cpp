class Solution {
public:
    int LIS(vector<int>& nums, vector<vector<int>>& lis, int i, int m){
        if(i == nums.size()) return 0;
        if(lis[i][m+1001] != -1) return lis[i][m+1001];

        if(nums[i] <= m) return lis[i][m+1001] = LIS(nums,lis, i+1, m);
        return lis[i][m+1001] = max(1+LIS(nums, lis, i+1, max(m, nums[i])),
                                 LIS(nums, lis, i+1, m));
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> lis(nums.size(), vector<int> (2002,-1));
        return LIS(nums, lis, 0, -1001);
    }
};
