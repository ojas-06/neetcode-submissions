class Solution {
public:
    int searchMin(vector<int>& nums, int start, int end){
        if(nums[start] < nums[end]) return nums[start];
        if(end-start<=1) return nums[end];
        int mid = (start+end)/2;
        if(nums[start] < nums[mid]) return searchMin(nums,mid,end);
        return searchMin(nums,start,mid);
    }
    int findMin(vector<int>& nums) {
        return searchMin(nums,0,nums.size()-1);
    }
};
