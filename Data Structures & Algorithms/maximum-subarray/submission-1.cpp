class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0], maxSum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(currSum<0){
                maxSum = max(maxSum, currSum);
                currSum = nums[i];
                maxSum = max(maxSum, currSum);
            }
            else if(currSum+nums[i] < 0) {
                maxSum = max(maxSum, currSum);
                currSum = nums[i];
                maxSum = max(maxSum, currSum);
            }
            else{
                currSum += nums[i];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};
