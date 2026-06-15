//2147483647 -2147483648
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        bool neg = false;
        if(x<0){
            if(x == INT_MIN) return 0;
            neg = true;
            x = -x;
        }
        while(x){
            if(rev > 214748364) return 0;
            if(rev == 214748364){
                if(neg && x >= 9) return 0;
                if(!neg && x>=8) return 0;
            }
            rev*=10;
            rev+=(x%10);
            x/=10;
        }
        if(!neg) return rev;
        return -rev;
    }
};
