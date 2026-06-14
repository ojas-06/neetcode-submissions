class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> pre_max;
        deque<int> post_max;
        pre_max.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            if(height[i] > pre_max[i-1]) pre_max.push_back(height[i]);
            else pre_max.push_back(pre_max[i-1]);
        }
        auto it = height.end() - 1;
        post_max.push_front(*it);
        while(it != height.begin()){
            if(*it > post_max[0]) post_max.push_front(*it);
            else post_max.push_front(post_max[0]);
            it--;
        }
        if(*it > post_max[0]) post_max.push_front(*it);
        else post_max.push_front(post_max[0]);
        for(int i=0;i<height.size();i++){
            res += min(pre_max[i],post_max[i]) - height[i];
        }
        return res;
    }
};
