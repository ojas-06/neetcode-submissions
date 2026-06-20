class Solution {
public:
    int ans = 0;
    void f(vector<int>& nums, int target, int i, int cur){
        if(i == nums.size()){
            if(cur == target) ans++;
            return;
        }
        f(nums, target, i+1, cur+nums[i]);
        f(nums, target, i+1, cur-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        f(nums,target, 0,0);
        return ans;
    }
};
