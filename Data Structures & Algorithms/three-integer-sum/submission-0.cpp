class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int n, int target){
        int i=0,j=n;
        vector<vector<int>> result = {};
        while(i<j){
            if(nums[i] + nums[j] == target) {
                result.push_back({nums[i],nums[j],-target});
                // skip duplicates for left pointer
                while (i < j && nums[i] == nums[i+1]) i++;
                // skip duplicates for right pointer
                while (i < j && nums[j] == nums[j-1]) j--;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] < target) i++;
            else j--;
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> soln;
        vector<vector<int>> s;
        for(int i=nums.size()-1;i>=2;i--){
            if (i < nums.size() - 1 && nums[i] == nums[i+1]) continue;
            s = twoSum(nums, i-1, -nums[i]);
            if(s.size()){
                soln.insert(soln.end(),s.begin(),s.end());
            }
        }
        return soln;
    }
};
