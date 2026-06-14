class Solution {
public:
    int helper(vector<int>& height,int i,int j){
        int max = 0;
        while(i<j){
            if(height[i]<=height[j]){
                int area = height[i]*(j-i);
                if(area>max) max = area;
                i++;
                continue;
            }
            else if(height[j]<height[i]){
                int area = height[j]*(j-i);
                if(area>max) max = area;
                j--;
                continue;
            }
        }
        return max;
    }
    int maxArea(vector<int>& height) {
        return helper(height,0,height.size()-1);
    }
};
