class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int ma = 0;
        while(i<j){
            ma = max(ma, min(heights[i],heights[j])*(j-i));
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return ma;
    }
};
