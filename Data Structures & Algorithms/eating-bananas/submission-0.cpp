class Solution {
public:
    unordered_map<int,unsigned long int> memo;
    unsigned long int computeTime(vector<int>& piles, int speed){
        if(memo[speed]) return memo[speed];
        unsigned long int s = 0;
        for(int k:piles) s+= ceil(k/(double)speed);
        memo[speed] = s;
        
        return s;
    }

    int searchMin(vector<int>& piles, int h, int start,int end){
        if(start == end) return start;
        if(end-start == 1){
            if(computeTime(piles, start) <= h) return start;
            return end;
        }
        int mid = (start+end)/2;
        if(computeTime(piles, mid) > h) return searchMin(piles,h,mid+1,end);
        return searchMin(piles,h,start,mid);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 1;
        while(computeTime(piles,m) > h) m *=2;
        return searchMin(piles,h,m/2+1,m);
    }
};
