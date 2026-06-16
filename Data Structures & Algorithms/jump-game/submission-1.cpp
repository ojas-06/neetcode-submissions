class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int g = n-1;
        for(int i = n-2;i>=0;i--){
            if(i+nums[i] >= g) g = i;
        }
        return (g == 0);
    }
};
