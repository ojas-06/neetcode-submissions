class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen_values;
        for(int i=0;i<nums.size();i++){
            int t= seen_values[target-nums[i]];
            if(t) return {t-1,i};
            seen_values[nums[i]] = i+1;
        }
        return {-1,-1};
    }
};
