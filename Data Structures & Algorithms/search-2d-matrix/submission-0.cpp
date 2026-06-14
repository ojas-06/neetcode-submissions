class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size();
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(hi-lo == 1){
                if(matrix[mid][0] > target) return false;
                if(matrix[mid][0] <= target) hi = lo;
                if(matrix[mid+1][0] <= target) lo = hi;
                break;
            }
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] > target) hi = mid;
            else lo = mid;
        }
        if(matrix[lo][0] > target) return false;
        int i = lo;
        lo = 0, hi = matrix[0].size();
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(matrix[i][mid] == target) return true;
            if(matrix[i][mid] > target) hi = mid;
            else lo = mid+1;
        }
        return false;
    }
};
