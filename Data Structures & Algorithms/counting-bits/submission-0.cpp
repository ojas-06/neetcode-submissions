class Solution {
public:
    int bits(int n){
        int ans = 0;
        while(n){
            if(n&1) ans++;
            n>>=1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            res[i] = bits(i);
        }
        return res;
    }
};
