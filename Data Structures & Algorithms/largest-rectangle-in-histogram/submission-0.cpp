class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        left[0] = -1;
        right[n-1] = n;

        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) left[i] = st.top();
            else left[i] = -1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) right[i] = st.top();
            else right[i] = n;
            st.push(i);
        }
        int largest = 0;
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            largest = max(largest, heights[i]*(right[i] - left[i] -1));
        }
        return largest;
    }
};
