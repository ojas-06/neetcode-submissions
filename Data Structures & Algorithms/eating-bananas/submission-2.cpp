class Solution {
public:
    bool canEatInTime(vector<int>& piles, int h, int k) {
        long long hours_needed = 0; 
        for (int pile : piles) {
            hours_needed += (pile - 1) / k + 1; 
        }
        return hours_needed <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9; 
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (canEatInTime(piles, h, mid)) {
                hi = mid; 
            } else {
                lo = mid + 1; 
            }
        }
        
        return lo;
    }
};