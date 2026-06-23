class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        
        for (int j = left; j < right; j++) {
            if (nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int target) {
        int pivotIdx = partition(nums, left, right);
        
        if (pivotIdx == target) {
            return nums[pivotIdx];
        } 
        else if (pivotIdx < target) {
            return quickSelect(nums, pivotIdx + 1, right, target);
        } 
        else {
            return quickSelect(nums, left, pivotIdx - 1, target);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};