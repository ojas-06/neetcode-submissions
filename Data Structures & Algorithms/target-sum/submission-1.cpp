class Solution {
public:
int totalSum;
    int sum(vector<int>& v){
        int ans = 0;
        for(int &i:v) ans+=i;
        return ans;
    }
    int eval(vector<int>&nums, vector<vector<int>>& memo, int target, int i){
        if(i == nums.size()){
            if(target == 0) return 1;
            return 0;
        }
        if (abs(target) > totalSum) return 0;
        if(memo[i][target+totalSum] != -1) return memo[i][target+totalSum];
        return memo[i][target+totalSum] = eval(nums, memo, target-nums[i], i+1)+eval(nums, memo, target+nums[i], i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target, int i=0) {
        totalSum = sum(nums);

        vector<vector<int>> memo(nums.size(), vector<int>(2*totalSum+1, -1));

        return eval(nums, memo, target, 0);
    }
};
