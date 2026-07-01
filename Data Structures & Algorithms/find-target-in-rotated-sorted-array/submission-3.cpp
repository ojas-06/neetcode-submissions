class Solution {
public:
    int search(vector<int>& nums, int target) {
        int rotpt = findrot(nums);
        int lo, hi;
        if(rotpt == 0) {
            lo = 0;
            hi = nums.size()-1;
        }
        else if(target >= nums[0]){
            lo = 0;
            hi = rotpt-1;
        }
        else {
            lo = rotpt;
            hi = nums.size()-1;
        }
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
private:
    int findrot(vector<int>& nums){
        int lo = 0, hi = nums.size()-1;
        if(nums[lo] <= nums[hi]) return 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(mid >0 && nums[mid]<nums[mid-1]) return mid;
            if(nums[mid]>nums.back()) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};
