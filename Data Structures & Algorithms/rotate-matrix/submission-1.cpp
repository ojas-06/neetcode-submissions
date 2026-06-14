class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n/2;i++){
            for(int j = i; j < n-i-1 ; j++){  
                int k = 4;
                int x = i,y = j;
                int nxt = matrix[x][y];
                while(k--){
                    swap(matrix[y][n-1-x], nxt);
                    swap(x,y);
                    y = n-1-y;
                }
            }
        }
    }
};