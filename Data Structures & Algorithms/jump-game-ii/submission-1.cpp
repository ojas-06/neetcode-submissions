class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,2000);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            for(int j = 1;j<=nums[i] && i+j<n;j++){
                dp[i] = min(dp[i], 1+dp[i+j]);
            }
        }
        return dp[0];
    }
};
