class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n:nums){
            freq[n] = 1;
        }
        int max = 0;
        int t=0; //tested
        while(t<nums.size()){
            if (freq[nums[t]] ==2) {
                t++;
                continue;
            }
            if(!freq[nums[t]-1]){
                int curr = 1,i=nums[t]+1;
                freq[nums[t]] = 2;
                while(freq[i]) {
                    curr++;
                    freq[i] = 2;
                    i++;
                }
                if(curr>max) max = curr;
                t +=1 ;
            }
            else t++;
        }
        return max;
    }
};