class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double curr = x;
        bool inv = false;
        if(n<0){
            inv = true;
            n = -n;
        }
        while(n){
            if(n&1) ans *= curr;
            curr *= curr;
            n >>= 1;
        }
        if(inv) return 1.0/ans;
        return ans;
    }
};
