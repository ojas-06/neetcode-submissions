class Solution {
public:
    vector<vector<int>> dp;
    int check(vector<int>& nums, bool first, int i){
        if(i > nums.size()-1) return 0;
        if(dp[first][i] != -1) return dp[first][i];
        if(i == nums.size()-1) {
            if(!first) return dp[first][i] = nums.back();
            return dp[first][i] = 0;
        }
        return dp[first][i] = max(check(nums, first, i+1), nums[i] + check(nums, first, i+2));
    }
    int rob(vector<int>& nums) {
        dp = vector<vector<int>>(2, vector<int>(nums.size(), -1));
        return max(nums[0]+check(nums, true, 2), check(nums, false, 1));
    }
};
